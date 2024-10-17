#pragma once

#include "RTOS_Tasks.h"
#include "cmsis_os2.h"

extern osMutexId_t UART_Mutex;
void I2C_Task(void *argument);