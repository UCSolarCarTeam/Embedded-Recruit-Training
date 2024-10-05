#pragma once
#include "stm32f4xx_hal.h"
#include <stdint.h>

// Register defines
#define Who_Am_I_REG_ADDR 0x0F
/* Dummy Register
 * Default: 0x3B / 0b00111011
 * Type: Read Only
 */

#define Ctrl_Reg1_REG_ADDR 0x20
#define Ctrl_Reg2_REG_ADDR 0x21
#define Ctrl_Reg3_REG_ADDR 0x22
/* Configuration Registers
 * Ctrl_Reg1 default: 0x07
 * Ctrl_Reg2 default: 0x00
 * Ctrl_Reg3 default: 0x00
 * Type: Read/Write
 */

#define Status_Reg_REG_ADDR 0x27
/* Dummy Register
 * Default: 0x00
 * Type: Read Only
 */

#define OutX_REG_ADDR 0x29
#define OutY_REG_ADDR 0x2B
#define OutZ_REG_ADDR 0x2C
/* Output Registers
 * No default (outputs value)
 * Type: Read Only
 */

// External definitions
extern SPI_HandleTypeDef hspi1;

// Function defines
void lis302dl_Init();
void lis302dl_Read_Register(uint8_t address, uint8_t* buffer);
void lis302dl_Write_Register(uint8_t address, uint8_t value);
void lis302dl_Display_Led(int8_t x, int8_t y);
void lis302dl_Poll_Data(int8_t* x_buf, int8_t* y_buf, int8_t* z_buf);
