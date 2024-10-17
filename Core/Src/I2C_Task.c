#include "3_TSL2591.h"
#include "stm32f4xx_hal_i2c.h"

#include "1_UART.h"
#include "stm32f4xx_hal.h"
#include <stdint.h>
#include "RTOS_Tasks.h"
#include "cmsis_os2.h"
#include "I2C_Task.h"


void I2C_Task(void *argument){
    for(;;){
        uint8_t C0DATA;
        uint8_t C1DATA;
        tsl2591_Poll_Data(&C0DATA,&C1DATA);

        char formatted_buffer[50];  // Buffer to store the formatted string
        int formatted_length = snprintf(formatted_buffer, sizeof(formatted_buffer),
                                "C0Data: %d, C1Data: %d\r\n", C0DATA, C1DATA);

        osStatus_t mutexAcquireReturnCode = osMutexAcquire(UART_Mutex, HAL_MAX_DELAY);

        if(mutexAcquireReturnCode == osOK){
            UART_Transmit((uint8_t*) formatted_buffer, formatted_length);
            osStatus_t mutexReleaseReturnCode = osMutexRelease(UART_Mutex);
        }

        osDelay(200);
    }
}
