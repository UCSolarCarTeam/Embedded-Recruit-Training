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

[Here is a link to additional resources on getting started with STM32](https://wiki.st.com/stm32mcu/wiki/Microcontroller)

## What you will do...

The goal of this training is to get you comfortable with the STM32 environment.

You will implement functions found in the `Core/Src` folder starting with task `0_BlinkyLED.c`.

### Task 0: Blinky LED

```c
HAL_StatusTypeDef HAL_GPIO_WritePin(GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin, GPIO_PinState PinState);
```
Sets the state of the specified GPIO pin.
- GPIOx: GPIO port.
- GPIO_Pin: GPIO pin number.
- PinState: Desired pin state (GPIO_PIN_SET or GPIO_PIN_RESET).

```c
GPIO_PinState HAL_GPIO_ReadPin(GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin);
```
Sets the state of the specified GPIO pin.
- GPIOx: GPIO port.
- GPIO_Pin: GPIO pin number.
- Returns: The pin state (GPIO_PIN_SET or GPIO_PIN_RESET).


### Task 1: UART Transmit

```c
HAL_StatusTypeDef HAL_UART_Transmit(UART_HandleTypeDef *huart, uint8_t *pData, uint16_t Size, uint32_t Timeout);
```
Sends data through UART in blocking mode.
- huart: UART handle.
- pData: Data buffer.
- Size: Size of the data.
- Timeout: Timeout duration.


```c
HAL_StatusTypeDef HAL_UART_Receive(UART_HandleTypeDef *huart, uint8_t *pData, uint16_t Size, uint32_t Timeout);
```
Receives data through UART in blocking mode.
- huart: UART handle.
- pData: Data buffer.
- Size: Size of the data.
- Timeout: Timeout duration.

### Task 2: Accelerometer SPI Peripheral

```c
HAL_StatusTypeDef HAL_SPI_Transmit(SPI_HandleTypeDef *hspi, uint8_t *pData, uint16_t Size, uint32_t Timeout);
```
Sends data through SPI in blocking mode.
- hspi: SPI handle.
- pData: Data buffer.
- Size: Size of the data.
- Timeout: Timeout duration.

```c
HAL_StatusTypeDef HAL_SPI_Receive(SPI_HandleTypeDef *hspi, uint8_t *pData, uint16_t Size, uint32_t Timeout);
```
Receives data through SPI in blocking mode.
- hspi: SPI handle.
- pData: Data buffer.
- Size: Size of the data.
- Timeout: Timeout duration.

### Task 3: Lux Sensor I2C Peripheral
  
```c
HAL_StatusTypeDef HAL_I2C_Mem_Read(I2C_HandleTypeDef *hi2c, uint16_t DevAddress, uint16_t MemAddress, uint16_t MemAddSize, uint8_t *pData, uint16_t Size, uint32_t Timeout);
```
Reads data from a specific memory address on an I2C device.
- hi2c: I2C handle.
- DevAddress: I2C device address.
- MemAddress: Memory address.
- MemAddSize: Size of the memory address.
- pData: Data buffer.
- Size: Size of the data.
- Timeout: Timeout duration.

```c
HAL_StatusTypeDef HAL_I2C_Mem_Write(I2C_HandleTypeDef *hi2c, uint16_t DevAddress, uint16_t MemAddress, uint16_t MemAddSize, uint8_t *pData, uint16_t Size, uint32_t Timeout);
```
Writes data to a specific memory address on an I2C device.
- hi2c: I2C handle.
- DevAddress: I2C device address.
- MemAddress: Memory address to write to.
- MemAddSize: Size of the memory address.
- pData: Data buffer containing the data to be written.
- Size: Size of the data.
- Timeout: Timeout duration.

#### Note: Extra I2C functions but for general communication with a peripheral without internal registers (Not needed for task)

```c
HAL_StatusTypeDef HAL_I2C_Master_Transmit(I2C_HandleTypeDef *hi2c, uint16_t DevAddress, uint8_t *pData, uint16_t Size, uint32_t Timeout);
```
Sends data to a specific I2C device in master mode.
- hi2c: I2C handle.
- DevAddress: I2C device address.
- pData: Data buffer.
- Size: Size of the data.
- Timeout: Timeout duration.
  
```c
HAL_StatusTypeDef HAL_I2C_Master_Receive(I2C_HandleTypeDef *hi2c, uint16_t DevAddress, uint8_t *pData, uint16_t Size, uint32_t Timeout);
```
Receives data to a specific I2C device in master mode.
- hi2c: I2C handle.
- DevAddress: I2C device address.
- pData: Data buffer.
- Size: Size of the data.
- Timeout: Timeout duration.

### Task 4: Potentiometer ADC Periheral

```c

```
