/*
 Application : To toggle LED's using different GPIO pins with register programming
 GPIO's

 Step1 : First i had enable the AHB1 bus and selected the required GPIO port
 Step2 : Then after i had selected pin number and set mode to output
 Step3 : After that in an infinite loop i had toggled using GPIOx_ODR instruction

 Author : BIPUL BARMA ROUL
 DATE : 11/04/2023
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
	//for PA5 pin
//	RCC->AHB1ENR |= 0x1;
//	GPIOA->MODER |= 0x400;
//	while(1)
//	{
//		GPIOA->ODR |= 0x20;
//		delay(1000);
//		GPIOA->ODR &= ~(0x20);
//		delay(1000);
//	}

	//for PA6 pin
//	RCC->AHB1ENR |= 0x1;
//	GPIOA->MODER |= 0x1000;
//	while(1)
//	{
//		GPIOA->ODR |= 0x40;
//		delay(1000);
//		GPIOA->ODR &= ~(0x40);
//		delay(1000);
//	}
//}
	 //for PC6 pin
//	RCC->AHB1ENR |= 0x4;
//	GPIOC->MODER |= 0x1000;
//	while(1)
//	{
//		GPIOC->ODR |= 0x40;
//		delay(1000);
//		GPIOC->ODR &= ~(0x40);
//		delay(1000);
//	}
//}

      //for PB6 pin
//    RCC->AHB1ENR |= 0x2;
//	  GPIOB->MODER |= 0x1000;
//	  while(1)
//	  {
//			GPIOB->ODR |= 0x40;
//			delay(1000);
//			GPIOB->ODR &= ~(0x40);
//			delay(1000);
//	  }
//}


	RCC->AHB1ENR |= 0x1;
    GPIOA->MODER |= 0x400;
	RCC->AHB1ENR |= 0x4;
	GPIOC->MODER |= 0x1000;
	RCC->AHB1ENR |= 0x1;
	GPIOA->MODER |= 0x1000;
	RCC->AHB1ENR |= 0x2;
	GPIOB->MODER |= 0x1000;
	while(1)
	{
		GPIOA->ODR |= 0x20;
		delay(1000);
		GPIOA->ODR &= ~(0x20);
		delay(1000);
		GPIOC->ODR |= 0x40;
		delay(1000);
		GPIOC->ODR &= ~(0x40);
		delay(1000);
		GPIOA->ODR |= 0x40;
		delay(1000);
		GPIOA->ODR &= ~(0x40);
		delay(1000);
		GPIOB->ODR |= 0x40;
		delay(1000);
		GPIOB->ODR &= ~(0x40);
		delay(1000);
	}
}
