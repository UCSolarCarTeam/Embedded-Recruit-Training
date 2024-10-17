#include "2_LIS302DL.h"
#include "1_UART.h"

#include "main.h"
#include "stm32f4xx_hal_spi.h"
#include "stm32f4xx_hal_gpio.h"
#include "stm32f4xx_hal_uart.h"
#include <stdio.h>
#include "RTOS_Tasks.h"
#include "cmsis_os2.h"
#include "SPI_Task.h"


void SPI_Task(void *argument){
    for(;;){
        int8_t x,y,z;
        lis302dl_Poll_Data(&x,&y,&z);

        char formatted_buffer[50];  // Buffer to store the formatted string
        int formatted_length = snprintf(formatted_buffer, sizeof(formatted_buffer),
                                "X Data: %d, Y Data: %d, Z Data: %d\r\n", x, y, z);

        osStatus_t mutexAcquireReturnCode = osMutexAcquire(UART_Mutex, HAL_MAX_DELAY);

        if(mutexAcquireReturnCode == osOK){
            UART_Transmit((uint8_t*) formatted_buffer, formatted_length);   
            osStatus_t mutexReleaseReturnCode = osMutexRelease(UART_Mutex);
        }
        osDelay(200);
    }
}
