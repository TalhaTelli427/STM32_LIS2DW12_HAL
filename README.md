
# STM32_LIS2DW12_HAL

Welcome to the STM32 LIS2DW12 accelerometer sensor driver repository! This project focuses on creating a versatile driver for the LIS2DW12 accelerometer sensor using an STM32 microcontroller. The driver includes functionalities for measuring tilt angles, detecting free falls, and generating a signal on a single tap. Let's dive into the details.


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

