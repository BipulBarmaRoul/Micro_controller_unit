/**
 ******************************************************************************
 * @file           : check_stack_pointer.c
 * @author         : BIPUL BARMA ROUl
 * @brief          : addition of four numbers to check stack pointer register
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
int add_func(int a,int b,int c,int d);
int main(void)
{
    int res;
    res=add_func(1,2,3,4);
    printf("result is=%d\n",res);
    /* Loop forever */
	for(;;);
}
int add_func(int a,int b,int c,int d)
{
	return a+b+c+d;
}


