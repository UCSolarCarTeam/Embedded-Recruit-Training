#pragma once

#include "main.h"
#include "cmsis_os2.h"

extern osThreadId_t BlinkLED_TaskHandle;
#define TMR1_INTERRUPT_FLAG  (1 << 0)
void BlinkLED_Task(void* argument);