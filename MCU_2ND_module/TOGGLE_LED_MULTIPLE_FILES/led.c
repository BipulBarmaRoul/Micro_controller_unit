/*
 * led.c
 *
 *  Created on: Apr 10, 2023
 *      Author: BIPUL BARMA ROUL
 */


#include"stm32f4xx.h"
#include"led.h"
#include"stdio.h"
#include"led_cfg.h"



void led_task(void)
{
	static uint8_t num=0;
		  uint8_t count=0;
		  	  while(count<3)
		  	  	  {
		  	  		  if(!(HAL_GPIO_ReadPin(LED_CfgParam.SW_GPIO,LED_CfgParam.S1_PIN)))
		  	  		  {
		  	  			  num++;
		  	  			  count++;
		  	  			  if(num>3)
		  	  			  {
		  	  				  printf("Switch Pressed %dth Time!\r\n",num);
		  	  			  }

		  	  			  if(count==1)
		  	  			  {
		  	  				  if(num==1)
		  	  				  {
		  	  					  printf("Switch pressed %dst Time!\r\n",num);
		  	  				  }
		  	  				  printf("Led1 toggle %d Times!\r\n",count);
		  	  				  printf("Led2 toggle %d Times!\r\n",3*count);
		  	  				  led1_toggle(count);
		  	  				  led2_toggle(count);

		  	  			  }
		  	  			  else if(count==2)
		  	  			  {
		  	  				  if(num==2)
		  	  				  {
		  	  					  printf("Switch pressed %dnd Time!\r\n",num);
		  	  				  }
		  	  				  printf("Led1 toggle %d Times!\r\n",count);
		  	  				  printf("Led2 toggle %d Times!\r\n",3*count);
		  	  				  led1_toggle(count);
		  	  				  led2_toggle(count);
		  	  			  }
		  	  			  else if(count==3)
		  	  			  {
		  	  				  if(num==3)
		  	  				  {
		  	  					  	printf("Switch pressed %drd Time!\r\n",num);
		  	  				  }
		  	  				  printf("Led1 toggle %d Times!\r\n",count);
	  	  				  	  printf("Led2 toggle %d Times!\r\n",3*count);
		  	  				  led1_toggle(count);
		  	  				  led2_toggle(count);
		  	  			  }
		  	  		  }
		  	  		  else
		  	  		  {
		  	  			  led_reset();
		  	  		  }
		  	  	  }
}


void led1_toggle(int count)
{
	for(int i=0;i<count;i++)
	{
		HAL_GPIO_WritePin(LED_CfgParam.LED_GPIO,LED_CfgParam.D1_PIN,GPIO_PIN_SET);
		HAL_Delay(200);
		HAL_GPIO_WritePin(LED_CfgParam.LED_GPIO,LED_CfgParam.D1_PIN,GPIO_PIN_RESET);
		HAL_Delay(200);
	}
}


void led2_toggle(int count)
{
	for(int i=0;i<3*count;i++)
	{
		HAL_GPIO_WritePin(LED_CfgParam.LED_GPIO,LED_CfgParam.D2_PIN,GPIO_PIN_SET);
		HAL_Delay(200);
		HAL_GPIO_WritePin(LED_CfgParam.LED_GPIO,LED_CfgParam.D2_PIN,GPIO_PIN_RESET);
		HAL_Delay(200);
	}
}

void led_reset()
{
	printf("Switch not pressed\r\n");
	HAL_GPIO_WritePin(LED_CfgParam.LED_GPIO,LED_CfgParam.D1_PIN,GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LED_CfgParam.LED_GPIO,LED_CfgParam.D1_PIN,GPIO_PIN_RESET);
	HAL_Delay(100);
}
