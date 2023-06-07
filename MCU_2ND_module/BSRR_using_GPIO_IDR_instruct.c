/*
 Application : To toggle LED's using BSRR register given by GPIO pin with IDR instruction and switch
 GPIO's

 Step1 : Enable the port clock on AHB1 for both port A and port C
 Step2 : Set the mode PA and PC
 Step3 : read the pin status of PC


 file : BSRR_using_GPIO_IDR_instruct.c
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
//int main()
//{
//	RCC->AHB1ENR |= 0x1;
//	RCC->AHB1ENR |= 0x4;
//	GPIOA->MODER |= 0x400;
//	GPIOC->MODER |= 0x0;
//	while (1)
//	  {
//		  if(!(HAL_GPIO_ReadPin(GPIOC,GPIO_PIN_13)))
//		  {
//			 GPIOA->BSRR |= 0x20;
//		     delay(500);
//		  }
//		  else
//		  {
//			  GPIOA->BSRR |= 0x200000;
//
//		  }
//	  }
//}
int main()
{
	RCC->AHB1ENR |= 0x1;
	RCC->AHB1ENR |= 0x4;
	GPIOA->MODER |= 0x400;
	GPIOC->MODER |= 0x0;
	while (1)
	  {
		  if(GPIOC->IDR & 0x2000)
		  {
			  GPIOA->BSRR |= 0x200000;
		  }
		  else
		  {
			  GPIOA->BSRR |= 0x20;

		  }
	  }
}
