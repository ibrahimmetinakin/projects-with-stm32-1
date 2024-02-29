/*
 * Nokia_5110.h
 *
 *  Created on: Aug 1, 2023
 *      Author: ASUS
 */

#ifndef INC_NOKIA_5110_H_
#define INC_NOKIA_5110_H_

#include "stm32f4xx_hal.h"
#include <stdbool.h>
extern SPI_HandleTypeDef hspi2;
extern DMA_HandleTypeDef hdma_spi2_tx;


void Init(void);
void Reset(void);
void Write(uint8_t data, uint8_t mode);
void clear(void);
void Uptade(void);
void Buffer_Write(uint8_t* adress, uint16_t size);
void SetPixel(uint8_t x, uint8_t y, bool set );


#endif /* INC_NOKIA_5110_H_ */
