/*
 * bmp180.h
 *
 *  Created on: Feb 27, 2024
 *      Author: metin
 */

#ifndef INC_BMP180_H_
#define INC_BMP180_H_

#include "stm32f4xx_hal.h"

extern I2C_HandleTypeDef hi2c1;

int16_t AC1, AC2, AC3, AC4, AC5, AC6, B1, B2, MB, MC, MD;


//int32_t tx1;
//int32_t tx2;
//int32_t tB5;
int32_t unCompTemperature;
float temperature;

/* BMP180 Devices addresses */
#define BMP180_DEVICE_WRITE_REGISTER_ADDRESS 0xEE
#define BMP180_DEVICE_READ_REGISTER_ADDRESS 0xEF

/* BMP180 Calibration address */
#define BMP180_CALIBRATION_START_ADDRESS 0xAA

/*BMP180 Calibration value length */
#define BMP180_CALIBRATION_VALUE_LENGTH 22

/* calibration values */

 // int16_t AC1, AC2, AC3, AC4, AC5, AC6, B1, B2, MB, MC, MD;



/* temperature values */

int16_t unCompTemperature;

float temperature;

int32_t tx1, tx2, tB5;


void BMP180_Init(void);
void BMP180_GetCalibration(void);
void BMP180_Get_Calibration_Value(void);
void BMP180_Get_Uncompansated_Temperature(void);
void BMP180_Get_Temperature(void);
void BMP180_Get_Uncompensated_Presure(void);
void BMP180_Get_Presure(void);





#endif /* INC_BMP180_H_ */
