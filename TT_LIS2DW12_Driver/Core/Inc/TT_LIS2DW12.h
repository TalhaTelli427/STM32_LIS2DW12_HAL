/*
 * TT_LIS2DW12.h
 *
 *  Created on: 24 Ağu 2023
 *      Author: talha
 */

#ifndef INC_TT_LIS2DW12_H_
#define INC_TT_LIS2DW12_H_
#include "stm32f4xx_hal.h"
#include <math.h>
#include "stdio.h"
#define PI 3.141592654
#define LIS2DW12_Adrr (0x19<<1)
#define CTRL1 0x20
#define CTRL2 0x21
#define CTRL3 0x22
#define CTRL4_INT1_PAD_CTRL 0x23
#define CTRL5_INT2_PAD_CTRL 0x24
#define CTRL6 0x25
#define OUT_T 0x26
#define STATUS 0x27
#define OUT_X_L 0x28
#define OUT_X_H 0x29
#define OUT_Y_L 0x2A
#define OUT_Y_H 0x2B
#define OUT_Z_L 0x2C
#define OUT_Z_H 0x2D
#define FIFO_CTRL 0x2E
#define FIFO_SAMPLES 0x2F
#define TAP_THS_X 0x30
#define TAP_THS_Y 0x31
#define TAP_THS_Z 0x32
#define INT_DUR 0x33
#define WAKE_UP_THS 0x34
#define WAKE_UP_DUR 0x35
#define FREE_FALL 0x36
#define STATUS_DUP 0x37
#define WAKE_UP_SRC 0x38
#define TAP_SRC 0x39
#define SIXD_SRC 0x3A
#define ALL_INT_SRC 0x3Bh
#define X_OFS_USR 0x3Ch
#define Y_OFS_USR 0x3Dh
#define Z_OFS_USR 0x3Eh
#define CTRL7 0x3F
extern I2C_HandleTypeDef hi2c1;

void TT_LIS2DW12_Init_For_Angle(void);
void TT_LIS2DW12_Get_Angle(void);
void TT_LIS2DW12_Init_Single_TAP(void);
void TT_Tab_dedector(void);
void TT_LIS2DW12_Init_Free_Fall(void);
void TT_Free_Fall_Detect(void);

#endif /* INC_TT_LIS2DW12_H_ */
