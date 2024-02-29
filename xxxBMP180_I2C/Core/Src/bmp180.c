/*
 * bmp180.c
 *
 *  Created on: Feb 27, 2024
 *      Author: metin
 */

#include "bmp180.h"

/* calibration values */

 int16_t AC1, AC2, AC3, AC4, AC5, AC6, B1, B2, MB, MC, MD;


int32_t tx1;
int32_t tx2;
int32_t tB5;



/* temperature values */


//int32_t unCompTemperature;
float temperature;

int32_t tx1;
int32_t tx2;
int32_t tB5;


void BMP180_Init()
{
   if(HAL_I2C_IsDeviceReady(&hi2c1, BMP180_DEVICE_WRITE_REGISTER_ADDRESS, 1, 100000) != HAL_OK )

		HAL_GPIO_WritePin(GPIOD, GPIO_PIN_14, GPIO_PIN_SET);

   BMP180_Get_Calibration_Value();
}

void BMP180_Get_Calibration_Value()
{
	 int a=0;
	uint8_t calibBuff[BMP180_CALIBRATION_VALUE_LENGTH]= {0} ;

	HAL_I2C_Mem_Read(&hi2c1, BMP180_DEVICE_READ_REGISTER_ADDRESS , BMP180_CALIBRATION_START_ADDRESS , 1 , calibBuff , BMP180_CALIBRATION_VALUE_LENGTH , 100000);

	AC1 =  (int16_t)((calibBuff[a] << 8) | calibBuff[a+1]); a+=2;
	AC2 =  (int16_t)((calibBuff[a] << 8) | calibBuff[a+1]); a+=2;
	AC3 =  (int16_t)((calibBuff[a] << 8) | calibBuff[a+1]); a+=2;
	AC4 =  (int16_t)((calibBuff[a] << 8) | calibBuff[a+1]); a+=2;
	AC5 =  (int16_t)((calibBuff[a] << 8) | calibBuff[a+1]); a+=2;
	AC6 =  (int16_t)((calibBuff[a] << 8) | calibBuff[a+1]); a+=2;
	B1 =   (int16_t)((calibBuff[a] << 8) | calibBuff[a+1]); a+=2;
	B2 =   (int16_t)((calibBuff[a] << 8) | calibBuff[a+1]); a+=2;
	MB =   (int16_t)((calibBuff[a] << 8) | calibBuff[a+1]); a+=2;
	MC =   (int16_t)((calibBuff[a] << 8) | calibBuff[a+1]); a+=2;
	MD =   (int16_t)((calibBuff[a] << 8) | calibBuff[a+1]); a+=2;


	if(AC1 == 0X0000 | AC1 == 0xFFFF)
	{
		HAL_GPIO_WritePin(GPIOD, GPIO_PIN_13, GPIO_PIN_SET);
		while(1);


	}
	if(AC2 == 0X0000 | AC2 == 0xFFFF)
	{
			HAL_GPIO_WritePin(GPIOD, GPIO_PIN_13, GPIO_PIN_SET);
			while(1);
		}
	if(AC3 == 0X0000 | AC3 == 0xFFFF)
	{
			HAL_GPIO_WritePin(GPIOD, GPIO_PIN_13, GPIO_PIN_SET);
			while(1);
		}
	if(AC4 == 0X0000 | AC4 == 0xFFFF)
	{
			HAL_GPIO_WritePin(GPIOD, GPIO_PIN_13, GPIO_PIN_SET);
			while(1);
		}
	if(AC5 == 0X0000 | AC5 == 0xFFFF)
	{
			HAL_GPIO_WritePin(GPIOD, GPIO_PIN_13, GPIO_PIN_SET);
			while(1);
		}
	if(AC6 == 0X0000 | AC6 == 0xFFFF)
	{
			HAL_GPIO_WritePin(GPIOD, GPIO_PIN_13, GPIO_PIN_SET);
			while(1);
	}
	if(B1 == 0X0000 | B1 == 0xFFFF)
	{
			HAL_GPIO_WritePin(GPIOD, GPIO_PIN_13, GPIO_PIN_SET);
			while(1);
	}
	if(B2 == 0X0000 | B2 == 0xFFFF)
	{
			HAL_GPIO_WritePin(GPIOD, GPIO_PIN_13, GPIO_PIN_SET);
			while(1);
	}
	if(MB == 0X0000 | MB == 0xFFFF)
	{
			HAL_GPIO_WritePin(GPIOD, GPIO_PIN_13, GPIO_PIN_SET);
			while(1);
	}
	if(MC == 0X0000 | MC == 0xFFFF)
	{
			HAL_GPIO_WritePin(GPIOD, GPIO_PIN_13, GPIO_PIN_SET);
			while(1);
	}
	if(MD == 0X0000 | MD == 0xFFFF)
	{
			HAL_GPIO_WritePin(GPIOD, GPIO_PIN_13, GPIO_PIN_SET);
			while(1);
	}


}


void BMP180_Get_Temperature(void)
{
	BMP180_Get_Uncompansated_Temperature();

	tx1 = (((int32_t)unCompTemperature - (int32_t)AC6 ) * (int32_t)AC5 ) / 32768;

    tx2 = ((int32_t)MC * 2048) / (tx1 + (int32_t)MD);

    if(tx1==0 | MD==0)
    {
    	HAL_GPIO_WritePin(GPIOD, GPIO_PIN_13,GPIO_PIN_SET );
    	while(1);
    }
    tB5 = tx1 + tx2;
    temperature = (float)(tB5 + 8) / 16 * 0.1 ;


}

void BMP180_Get_Uncompansated_Temperature(void)
{
	uint8_t rData[2]={0};
	uint8_t wData[1];
	wData[0]= 0x2E;

	HAL_I2C_Mem_Write(&hi2c1, BMP180_DEVICE_WRITE_REGISTER_ADDRESS , 0xF4 , 1 , wData , 1 , 100000);
	HAL_Delay(5);
	HAL_I2C_Mem_Read(&hi2c1, BMP180_DEVICE_READ_REGISTER_ADDRESS, 0xF6, 1, rData , 2 , 100000);
    unCompTemperature= (int16_t) ((rData[0] << 8) | rData[1]);
}



