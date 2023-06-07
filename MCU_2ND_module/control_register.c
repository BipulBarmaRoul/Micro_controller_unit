/**
 ******************************************************************************
 * @file           : control_register.c
 * @author         : BIPUL BARMA ROUL
 * @brief          : To give or check input and output to the register using MOV instruction
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

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

int main(void)
{
	//int val=40;
	//__asm volatile("MOV R0,%0"::"r"(0x50));
	//__asm volatile("MOV R0,%0"::"i"(0x50));
	uint32_t control_reg;
	__asm volatile("MRS %0,CONTROL":"=r"(control_reg));
    /* Loop forever */
	for(;;);
}
