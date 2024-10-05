# Embedded Recruit Training

## STM32 Project File System

STM32 projects typically follow a structured file system that separates different components to enhance maintainability and scalability. The key components include:

- **Core**: Contains the startup files, system configurations, and core libraries (e.g., `main.c`, `stm32f4xx_it.c` for interrupt handling, and `syscalls.c`).
  
- **Drivers**: Includes hardware abstraction libraries such as the **HAL** (Hardware Abstraction Layer), **CMSIS** (Cortex Microcontroller Software Interface Standard), and device-specific drivers (e.g., `stm32f4xx_hal_gpio.c` for GPIO handling).

- **Core/Inc**: Header files that define the interfaces for functions used throughout the project (e.g., `main.h`, `stm32f4xx_hal_conf.h`).

- **Core/Src**: Source files for the application code. This includes `main.c` where the user defines the primary application logic, along with other peripheral-specific files.

- **Middlewares**: Optional directory that contains third-party libraries or additional software components like RTOS, file systems, or USB stacks.

## What is HAL?

**HAL (Hardware Abstraction Layer)** is a set of libraries provided by STMicroelectronics to simplify the development process on STM32 microcontrollers. HAL provides a high-level interface for interacting with the MCU's peripherals like GPIO, SPI, UART, and more, allowing developers to write code that is more portable across different STM32 devices.

By using HAL, developers can avoid dealing directly with hardware registers, which speeds up development, improves readability, and reduces the complexity of peripheral configurations.

## What you will do...

You will implement functions found in the `Core/Src` folder starting with task `0_BlinkyLED.c`.

### Task 0: Blinky LED

### Task 1: UART Transmit

### Task 2: Accelerometer SPI Peripheral

### Task 3: Lux Sensor I2C Peripheral

### Task 4: Potentiometer ADC Periheral


