/*
 Application : To toggle LED's using BSRR register given by GPIO pin
 GPIO's

 Step1 : First i had enable the AHB1 bus and selected the required GPIO port
 Step2 : Then after i had selected pin number and set mode to output
 Step3 : After that in an infinite loop i had toggled using GPIOx_BSRR instruction.


 file : BSRR_register_using_GPIO.c
 Author : BIPUL BARMA ROUL
 DATE : 12/04/2023
 */


#include"main.h"
void delay(int);
void delay(int a)
{
	int i;
	while(a--)
	{
		for(i=0;i<4000;i++);
	}
}
int main()
{
	RCC->AHB1ENR |= 0x1;
    GPIOA->MODER |= 0x400;
	while(1)
	{
		GPIOA->BSRR |= 0x20;
		delay(500);
		GPIOA->BSRR |= 0x200000;
		delay(500);

	}
}
