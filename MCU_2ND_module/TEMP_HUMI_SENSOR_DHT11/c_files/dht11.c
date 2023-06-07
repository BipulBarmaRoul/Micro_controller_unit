/*
 * dht11.c
 *
 *  Created on: May 2, 2023
 *      Author: sankalp
 */


#include"main.h"

void Set_Pin_Output (GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin)
{
	GPIO_InitTypeDef GPIO_InitStruct = {0};
	GPIO_InitStruct.Pin = GPIO_Pin;
	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
	HAL_GPIO_Init(GPIOx, &GPIO_InitStruct);
}

void Set_Pin_Input (GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin)
{
	GPIO_InitTypeDef GPIO_InitStruct = {0};
	GPIO_InitStruct.Pin = GPIO_Pin;
	GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
	GPIO_InitStruct.Pull = GPIO_PULLUP;
	HAL_GPIO_Init(GPIOx, &GPIO_InitStruct);
}
void dht11_start()
{
	Set_Pin_Output (GPIOC, GPIO_PIN_10);
	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_10, 0);  //Get The Pin Low
	Delay(18000);
	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_10, 1);  //Get The Pin High
	Delay(20);
	Set_Pin_Input(GPIOC, GPIO_PIN_10);

}
uint8_t check_response()
{
	uint8_t response=0;
	Delay(40);
	if (!(HAL_GPIO_ReadPin(GPIOC,GPIO_PIN_10)))
	{
		Delay(80);
		if ((HAL_GPIO_ReadPin(GPIOC,GPIO_PIN_10)))
			response = 1;
		else
			response = -1;
	}
	while ((HAL_GPIO_ReadPin (GPIOC,GPIO_PIN_10))); // Wait for pin to go low
	return response;
}

uint8_t data_read()
{
	uint8_t i,j;
	for (j=0;j<8;j++)
	{
		while (!(HAL_GPIO_ReadPin (GPIOC,GPIO_PIN_10)));   // wait for the pin to go high
			Delay(40);
			if (!(HAL_GPIO_ReadPin (GPIOC,GPIO_PIN_10)))   // if the pin is low
			{
				i&= ~(1<<(7-j));   // write 0
			}
			else i|= (1<<(7-j));  // if the pin is high, write 1
			while ((HAL_GPIO_ReadPin (GPIOC,GPIO_PIN_10)));  // wait for the pin to go low
		}
		return i;

}
