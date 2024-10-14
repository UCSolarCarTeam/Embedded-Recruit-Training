#include "4_Potentiometer.h"
#include "stm32f4xx_hal_adc.h"
#include "ADC_Task.h"

#include "1_UART.h"
#include "stm32f4xx_hal_uart.h"

void ADC_Task(void *argument) {
    for (;;) {
        
        uint32_t adc_raw_value = 0;
        float adc_percentage = 0;

        // Assuming read_ADC fills the two variables with the ADC values
        read_ADC(&adc_raw_value, &adc_percentage);

        char formatted_buffer[50];  // Buffer to store the formatted string
        int formatted_length = snprintf(formatted_buffer, sizeof(formatted_buffer),
                                "ADC Raw Val: %lu \r\n",
                                (unsigned long)adc_raw_value); //Percentage formatting is L just ignoring for now
        

        UART_Transmit((uint8_t*)formatted_buffer, formatted_length);

        // Delay for 200 ms
        osDelay(200);
    }
}
