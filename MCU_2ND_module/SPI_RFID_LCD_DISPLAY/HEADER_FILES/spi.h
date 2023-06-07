/*
 * spi.h
 *
 *  Created on: May 2, 2023
 *      Author: BIPUL BARMA ROUL
 */

#ifndef INC_SPI_H_
#define INC_SPI_H_

#include "stdint.h"
void SPI_Init(void);
int8_t SPI_Transmit(uint8_t *data, uint32_t size);
int8_t SPI_Receive(uint8_t *data, uint32_t size);

#endif /* INC_SPI_H_ */
