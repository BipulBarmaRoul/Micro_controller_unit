/**
 ******************************************************************************
 * @file           : assemblycode_assignment2.c
 * @author         : BIPUL BARMA ROUl
 * @brief          : Addition of two numbers and it's result will stored in third variable using inline assembly code
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
//int add(int a,int b);
int main(void)
{
	int x=1;
	int y=2;
	int z=0;
	__asm volatile("ADD %0, %1, %2":"=r"(z):"r"(x),"r"(y));
	//z=add(x,y);
    /* Loop forever */
	for(;;);
}
//int add(int a,int b)
//{
//	int res=0;
//	__asm volatile("ADD %0, %1, %2":"=r"(res):"r"(a),"r"(b));
//	return res;
//}
