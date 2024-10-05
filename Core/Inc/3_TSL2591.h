#pragma once

#include <stdint.h>
#include "stm32f4xx_hal.h"

// Device address of peripheral
#define TSL2591_DEVICE_ADDR 0x29

// Enable and configuration registers
// Read/Write
#define ENABLE_REG_ADDR 0x00
#define CONFIG_REG_ADDR 0x01

// Read only dummy registers
#define PID_REG_ADDR 0x11
#define ID_REG_ADDR 0x12
#define STATUS_REG_ADDR 0x13

// Data registers
// Read only
#define C0DATAL_REG_ADDR 0x14
#define C0DATAH_REG_ADDR 0x15
#define C1DATAL_REG_ADDR 0x16
#define C1DATAH_REG_ADDR 0x17

// Mask for commands
#define COMMAND_MASK 0xA0


// External Definitions
extern I2C_HandleTypeDef hi2c3;

// Function Declarations
void tsl2591_Init();
void tsl2591_Read_Byte(uint8_t reg, uint8_t* buf);
void tsl2591_Write_Byte(uint8_t reg, uint8_t value);
void tsl2591_Poll_Data(uint8_t* C0DATA, uint8_t* C1DATA);

