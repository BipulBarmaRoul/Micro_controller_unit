/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : interrupt_register.c
  * Author          : BIPUL BARMA ROUl
  * @brief          : To enable the interrupt in falling edge by using only register code
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
//#include "main.h"
//void EXTI15_10_IRQHandler(void)
//{
//	GPIOA->ODR ^= 0x20;     //ISR functionality
//	for(int i=0;i<30000;i++);   //delay
//	EXTI->PR |= 0x2000;    //clear         //Return back from ISR to MAIN program
//}
//int main()
//{
//	__disable_irq();         //disable IRQ
//	RCC->AHB1ENR |= 0x5;     //Enable the clock for PA and PC
//	GPIOA->MODER |= 0x400;   //Set output for PA
//	RCC->APB2ENR |= 0x4000;       //To set external interrupt in RCC
//	SYSCFG->EXTICR[3] |= 0x20;    //Enable SYSCFG for trigger the interrupt
//	EXTI->IMR |= 0x2000;        //Make mask pin set to 1 of corresponding IRQ - PIN
//	EXTI->FTSR |= 0x2000;      //Trigger the interrupt on falling edge
//	NVIC_EnableIRQ(EXTI15_10_IRQn);     //Generate the IRQ
//	__enable_irq();       ////Enable the request line
//	while(1);
//}


//using external Switch or Button (PB12) and LED(PA6)
#include "main.h"
void EXTI15_10_IRQHandler(void)
{
	GPIOA->ODR ^= 0x40;     //ISR functionality
	for(int i=0;i<30000;i++);   //delay
	EXTI->PR |= 0x1000;    //clear         //Return back from ISR to MAIN program
}
int main()
{
	__disable_irq();         //disable IRQ
	RCC->AHB1ENR |= 0x3;     //Enable the clock for PA and PB
	GPIOA->MODER |= 0x1000;   //Set output for PA
	RCC->APB2ENR |= 0x4000;       //To set external interrupt in RCC
	SYSCFG->EXTICR[3] |= 0x1;    //Enable SYSCFG for trigger the interrupt
	EXTI->IMR |= 0x1000;        //Make mask pin set to 1 of corresponding IRQ - PIN
	EXTI->FTSR |= 0x1000;      //Trigger the interrupt on falling edge
	NVIC_EnableIRQ(EXTI15_10_IRQn);     //Generate the IRQ
	__enable_irq();       ////Enable the request line
	while(1);
}
