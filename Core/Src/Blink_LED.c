#include "Blink_LED.h"

void BlinkLED_Task(void* argument){
    for(;;){
        osThreadFlagsWait(TMR1_INTERRUPT_FLAG, osFlagsWaitAll, osWaitForever);

        const int numBlinks = 3;
        for (int i = 0; i < numBlinks; ++i) {
            HAL_GPIO_WritePin(GPIOD, GPIO_PIN_13, GPIO_PIN_SET);
            osDelay(250);
            HAL_GPIO_WritePin(GPIOD, GPIO_PIN_13, GPIO_PIN_RESET);
            osDelay(250);
        }

    }
}