/*
 * bmp180.h
 *
 *  Created on: Feb 28, 2024
 *      Author: metin
 */

#ifndef SRC_BMP180_H_
#define SRC_BMP180_H_

#include "stm32f4xx_hal.h"

extern I2C_HandleTypeDef hi2c1;

//* BMP180 Devices addresses */
#define BMP180_DEVICE_WRITE_REGISTER_ADDRESS 0xEE
#define BMP180_DEVICE_READ_REGISTER_ADDRESS 0xEF

/* BMP180 Calibration address */
#define BMP180_CALIBRATION_START_ADDRESS 0xAA

/*BMP180 Calibration value length */
#define BMP180_CALIBRATION_VALUE_LENGTH 22

/*calibration values */
extern int16_t AC1;
extern int16_t AC2;
extern int16_t AC3;
extern int16_t AC4;
extern int16_t AC5;
extern int16_t AC6;
extern int16_t B1;
extern int16_t B2;
extern int16_t MB;
extern int16_t MC;
extern int16_t MD;

/*temperature values*/
extern uint16_t unCompTemperature;
extern uint16_t temperature;


void BMP180_Init(void);
void BMP180_GetCalibration(void);
void BMP180_Get_Calibration_Value(void);
void BMP180_Get_Uncompansated_Temperature(void);
void BMP180_Get_Temperature(void);
void BMP180_Get_Uncompensated_Pressure(void);
void BMP180_Get_Pressure(void);







#endif /* SRC_BMP180_H_ */
