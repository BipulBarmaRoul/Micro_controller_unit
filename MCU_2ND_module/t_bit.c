/**
 ******************************************************************************
 * @file           : t_bit.c
 * @author         : BIPUL BARMA ROUL
 * @brief          : to check T_bit by using assembly code
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

#include <stdint.h>
#include <stdio.h>
#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif
void change_access_level_unpriv()
{
	__asm volatile("MRS R0,CONTROL");
	__asm volatile("ORR R0,R0,#0x01");
	__asm volatile("MSR CONTROL,R0");
}
int main(void)
{
    /* Loop forever */
	printf("in tread mode : before interrupts\n");
	void (*funptr)(void);
	funptr=8000204;
	//generate_interrupt();
	funptr();
	printf("in tread mode : after interrupts\n");
	for(;;);
}
void RTC_WKUP_IRQHandler(void)
{
    printf("in handler mode : ISR\n");
}

void HandFault(void)
{
    printf("Hard Fault detected\n");
    while(1);
}
