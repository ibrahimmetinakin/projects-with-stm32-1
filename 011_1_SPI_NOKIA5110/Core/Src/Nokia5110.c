/*
 * Nokia_5110.c
 *
 *  Created on: Aug 1, 2023
 *      Author: ASUS
 */


#include "Nokia5110.h"

extern SPI_HandleTypeDef hspi2;
extern DMA_HandleTypeDef hdma_spi2_tx;
uint8_t frameBuff[504];

void Init(void)
{
	Reset();
	Write(0x21,0);
	Write(0xC0,0);
	Write(0x07,0);
	Write(0x13,0);
	Write(0x20,0);
	Write(0x0C,0);
}

void Reset(void)
{
	HAL_GPIO_WritePin(GPIOD, GPIO_PIN_8, GPIO_PIN_RESET);
	HAL_Delay(100);
	HAL_GPIO_WritePin(GPIOD, GPIO_PIN_8, GPIO_PIN_SET);
}



void Write(uint8_t data, uint8_t mode)
{
	HAL_GPIO_WritePin(GPIOD, GPIO_PIN_9, GPIO_PIN_RESET);
	if(mode == 0)
	{
		HAL_GPIO_WritePin(GPIOD, GPIO_PIN_10, GPIO_PIN_RESET);
	}
	else if (mode == 1)
	{
		HAL_GPIO_WritePin(GPIOD, GPIO_PIN_10, GPIO_PIN_SET);
	}

	HAL_SPI_Transmit_DMA(&hspi2, &data, 1);

}
void clear(void)
{
	for (int i =0 ; i<504 ; i++)
		frameBuff[i]=0x00;
}

void Uptade(void)
{
	Write(0x80, 0);
	Write(0x40, 0);
	Buffer_Write(frameBuff, 504);
}

void Buffer_Write(uint8_t* adress, uint16_t size)
{
	HAL_GPIO_WritePin(GPIOD, GPIO_PIN_9, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOD, GPIO_PIN_10, GPIO_PIN_SET);
	HAL_SPI_Transmit_DMA(&hspi2, adress, size);

}

void SetPixel(uint8_t x, uint8_t y, bool set )
{
	uint8_t Bi;
	uint16_t By;

	if(x<0 || x>=64 || y < 0 || y>=84)
		return;
	By = (y / 8) * 84 + x;
	Bi = y % 8 ;

	if(set)
	{
		frameBuff[By] |= (1 << Bi);
	}
	else
	{
		frameBuff[By] &= ~(1 << Bi);
	}
}



