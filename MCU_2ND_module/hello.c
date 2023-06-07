/**
 ******************************************************************************
 * @file           : hello.c
 * @author         : BIPUL BARMA ROUL
 * @brief          : To print hello world using debbuger and SWV tool
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
#include <stdio.h>
int main(void)
{
    /* Loop forever */
	//for(;;);
	printf("hello world\n");
}
