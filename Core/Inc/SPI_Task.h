#pragma once

#include "2_LIS302DL.h"

#include "RTOS_Tasks.h"
#include "cmsis_os2.h"

extern osMutexId_t UART_Mutex;
void SPI_Task(void *argument);