#include "4_Potentiometer.h"
#include "stm32f4xx_hal_adc.h"
#include "ADC_Task.h"

#include "1_UART.h"
#include "stm32f4xx_hal_uart.h"


void ADC_Task(void *argument){
    for(;;){
        osDelay(1);
    }
}