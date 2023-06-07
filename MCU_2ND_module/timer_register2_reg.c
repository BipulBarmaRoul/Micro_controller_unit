/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : timer_register2_reg.c
  * Author          : BIPUL BARMA ROUl
  * @brief          : To toggle LED on every one second of timer interrupt by using register code
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
#include "main.h"
void delay()
{
	RCC->APB1ENR |= 0x1;
	TIM2->PSC = 1600-1;
	TIM2->ARR = 10000-1;
	TIM2->CNT = 0;
	TIM2->CR1 = 1;
}
int main()
{
	RCC->AHB1ENR |= 0x1;
	GPIOA->MODER |= 0x400;
	delay();
	while(1)
	{
		while(!(TIM2->SR & 1));
		GPIOA->ODR ^= 0x20;
		TIM2->SR = 0;
	}
}
