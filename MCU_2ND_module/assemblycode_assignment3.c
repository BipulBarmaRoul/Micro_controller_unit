/**
 ******************************************************************************
 * @file           : assemblycode_assignment3.c
 * @author         : BIPUL BARMA ROUL
 * @brief          : Copy the content of one variable to another variable using assmebly code
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
//	int var1=20, var2=30;
	int var1,*var2;
	var2=(int *)0x20000000;
	__asm volatile("LDR %0,[%1]":"=r"(var1):"r"(var2));
    /* Loop forever */
	for(;;);
}
