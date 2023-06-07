/*
 * led.h
 *
 *  Created on: Apr 10, 2023
 *      Author: BIPUL BARMA ROUL
 */

#ifndef SRC_LED_H_
#define SRC_LED_H_
#include "stm32f4xx_hal.h"

typedef struct
{
	uint32_t LED_GPIO;
	uint32_t SW_GPIO;
	uint16_t D1_PIN;
	uint16_t D2_PIN;
	uint16_t S1_PIN;
}LED_CfgType;


void led1_toggle(int count);
void led2_toggle(int count);
void led_reset();
void led_task(void);
#endif /* SRC_LED_H_ */
