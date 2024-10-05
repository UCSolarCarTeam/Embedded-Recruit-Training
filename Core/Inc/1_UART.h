#pragma once

#include "stm32f4xx_hal.h"
#include <stdint.h>

extern UART_HandleTypeDef huart2;

void UART_Transmit(uint8_t* buffer, uint16_t);
