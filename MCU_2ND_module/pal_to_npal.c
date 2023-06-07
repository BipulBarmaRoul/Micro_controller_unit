/**
 ******************************************************************************
 * @file           : pal_to_npal.c
 * @author         : BIPUL BARMA ROUL
 * @brief          : To change the access level from privilized to unprivilized 
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
void generate_interrupt()
{
	uint32_t *pSTIR = (uint32_t *)0xE000EF00;//This are some arm cortex M4 processors system control register addresses which can only be accessed in PAL any attempt to change the contents of this registers from being in NPAL will cause a Processor fault exception.
    uint32_t *pISER0 = (uint32_t *)0xE000E100;

    //enable IRQ# interrupt
    *pISER0 |= (1 << 3);

    //generate an interrupt from software for IRQ3
    *pSTIR = (3 & 0x1FF);
}

void change_access_level_unpriv()
{
	__asm volatile("MRS R0,CONTROL");
	__asm volatile("ORR R0,R0,#0x01");
	__asm volatile("MSR CONTROL,R0");
}
//void change_access_level_priv()
//{
//	__asm volatile("MRS R0,CONTROL");
//	__asm volatile("AND R0,R0,#0x00");
//	__asm volatile("MSR CONTROL,R0");
//}
int main(void)
{
    /* Loop forever */
	printf("in thread mode : before interrupts\n");
	change_access_level_unpriv();
	generate_interrupt();
	//change_access_level_priv();
	printf("in thread mode : after interrupts\n");
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
