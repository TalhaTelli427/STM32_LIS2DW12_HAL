
# STM32_LIS2DW12_HAL

Welcome to the STM32 LIS2DW12 accelerometer sensor driver repository! This project focuses on creating a versatile driver for the LIS2DW12 accelerometer sensor using an STM32 microcontroller. The driver includes functionalities for measuring tilt angles, detecting free falls, and generating a signal on a single tap. Let's dive into the details.

## Circuit Image
![WhatsApp Görsel 2023-08-25 saat 22 32 23](https://github.com/TalhaTelli427/STM32_LIS2DW12_HAL/assets/132828233/95cef9f2-5065-4e97-be4b-b62aad254ae8)

## Tilt Angle
![ezgif-4-3217d18aa7](https://github.com/TalhaTelli427/STM32_LIS2DW12_HAL/assets/132828233/fb8d7893-70c9-46a9-b06a-020425b42537)

## One Tap
![ezgif-4-550cefc1d4](https://github.com/TalhaTelli427/STM32_LIS2DW12_HAL/assets/132828233/09368411-1fcc-42fe-9525-65fb60f8636e)

## Free Fall
![ezgif-4-55f8453ef8](https://github.com/TalhaTelli427/STM32_LIS2DW12_HAL/assets/132828233/6817abfd-7520-4300-8518-96115c8754e2)


## Features

- Measures tilt angles using accelerometer data.
- Detects free fall situations using the sensor.
- Generates a signal upon detecting a single tap.

## Initialization and Usage

The driver provides several initialization functions for different functionalities:

- `TT_LIS2DW12_Init_Free_Fall()`: Initializes the sensor for free fall detection.
- `TT_LIS2DW12_Init_Single_TAP()`: Initializes the sensor for single tap detection.
- `TT_LIS2DW12_Init_For_Angle()`: Initializes the sensor for measuring angles.

To utilize the sensor's functionalities:

- `TT_LIS2DW12_Get_Angle()`: Retrieves and calculates tilt angles.
- `TT_Tab_dedector()`: Detects a single tap and toggles a GPIO pin.
- `TT_Free_Fall_Detect()`: Detects free fall situations and triggers a GPIO pin.

