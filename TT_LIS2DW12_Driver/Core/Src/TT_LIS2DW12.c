/*
 * TT_LIS2DW12.c
 *
 *  Created on: 24 Ağu 2023
 *      Author: talha
 */
#include "TT_LIS2DW12.h"


uint8_t message[1] = { 0 };
uint8_t Acce_Data[6] = { 0 };
int16_t Raw_Acce_X, Raw_Acce_Y, Raw_Acce_Z;
float Acce_X, Acce_Y, Acce_Z, angle_x, angle_y, Angle_Roll, Angle_Pitch;
uint8_t tabb[1] = { 0 };
uint8_t FALL[1] = { 0 };

void TT_LIS2DW12_Init_Free_Fall(void) {

	message[0] = 0x00;
	HAL_I2C_Mem_Write(&hi2c1, LIS2DW12_Adrr, CTRL6, 1, message, 1, 1000);
	message[0] = 0x10;
	HAL_I2C_Mem_Write(&hi2c1, LIS2DW12_Adrr, CTRL4_INT1_PAD_CTRL, 1, message, 1,1000);
	message[0] = 0x00;
	HAL_I2C_Mem_Write(&hi2c1, LIS2DW12_Adrr, WAKE_UP_DUR, 1, message, 1, 1000);
	message[0] = 0x99;
	HAL_I2C_Mem_Write(&hi2c1, LIS2DW12_Adrr, FREE_FALL, 1, message, 1, 1000);
	message[0] = 0x50;
	HAL_I2C_Mem_Write(&hi2c1, LIS2DW12_Adrr, CTRL1, 1, message, 1, 1000);
	message[0] = 0x20;
	HAL_I2C_Mem_Write(&hi2c1, LIS2DW12_Adrr, CTRL7, 1, message, 1, 1000);

}

void TT_LIS2DW12_Init_Single_TAP(void) {
	message[0] = 0x04;
	HAL_I2C_Mem_Write(&hi2c1, LIS2DW12_Adrr, CTRL6, 1, message, 1, 1000);
	message[0] = 0x23;
	HAL_I2C_Mem_Write(&hi2c1, LIS2DW12_Adrr, CTRL4_INT1_PAD_CTRL, 1, message, 1,1000);
	message[0] = 0x09;
	HAL_I2C_Mem_Write(&hi2c1, LIS2DW12_Adrr, TAP_THS_X, 1, message, 1, 1000);
	message[0] = 0x09;
	HAL_I2C_Mem_Write(&hi2c1, LIS2DW12_Adrr, TAP_THS_Y, 1, message, 1, 1000);
	message[0] = 0xE9;
	HAL_I2C_Mem_Write(&hi2c1, LIS2DW12_Adrr, TAP_THS_Z, 1, message, 1, 1000);
	message[0] = 0x02;
	HAL_I2C_Mem_Write(&hi2c1, LIS2DW12_Adrr, INT_DUR, 1, message, 1, 1000);
	message[0] = 0x74;
	HAL_I2C_Mem_Write(&hi2c1, LIS2DW12_Adrr, CTRL1, 1, message, 1, 1000);
	HAL_Delay(3);
	message[0] = 0x20;
	HAL_I2C_Mem_Write(&hi2c1, LIS2DW12_Adrr, CTRL7, 1, message, 1, 1000);
}

void TT_LIS2DW12_Init_For_Angle(void) {
	message[0] = 0x74;
	HAL_I2C_Mem_Write(&hi2c1, LIS2DW12_Adrr, CTRL1, 1, message, 1, 1000);
	message[0] = 0xD4;
	HAL_I2C_Mem_Write(&hi2c1, LIS2DW12_Adrr, CTRL6, 1, message, 1, 1000);
	message[0] = 0x40;
	HAL_I2C_Mem_Write(&hi2c1, LIS2DW12_Adrr, CTRL4_INT1_PAD_CTRL, 1, message, 1,
			1000);
}

void TT_LIS2DW12_Get_Angle(void) {

	HAL_I2C_Mem_Read(&hi2c1, LIS2DW12_Adrr, OUT_X_L, 1, Acce_Data, 6, 1000);
	Raw_Acce_X = (Acce_Data[1] << 8 | Acce_Data[0]);
	Raw_Acce_Y = (Acce_Data[3] << 8 | Acce_Data[2]);
	Raw_Acce_Z = (Acce_Data[5] << 8 | Acce_Data[4]);

	Acce_X = (float) Raw_Acce_X / 8192;
	Acce_Y = (float) Raw_Acce_Y / 8192;
	Acce_Z = (float) Raw_Acce_Z / 8192;

	Angle_Roll = (atan(Acce_Y / sqrt(Acce_X * Acce_X + Acce_Z * Acce_Z)) * 1
			/ (3.142 / 180) + 1);
	Angle_Pitch = (-atan(Acce_X / sqrt(Acce_Y * Acce_Y + Acce_Z * Acce_Z)) * 1
			/ (3.142 / 180) - 0.80);
}

void TT_Tab_dedector(void) {

	HAL_I2C_Mem_Read(&hi2c1, LIS2DW12_Adrr, TAP_SRC, 1, tabb, 1, 1000);
	if (tabb[0] != 0) {
		HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_5);
		HAL_Delay(75);
	}
}

void TT_Free_Fall_Detect(void) {

	HAL_I2C_Mem_Read(&hi2c1, LIS2DW12_Adrr, STATUS_DUP, 1, FALL, 1, 1000);
	if (FALL[0] & (1 << 1)) {

		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, SET);
	}
	/*else{
	 HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, RESET);

	 }*/
}

