#include "1_UART.h"
#include "stm32f4xx_hal_uart.h"

void UART_Transmit(uint8_t* buffer, uint16_t buffer_size) {
	/* TODO: Implement this
	 *
	 * Use the provided function to transmit data over the UART line
	 */

	HAL_UART_Transmit(&huart2, buffer, buffer_size, HAL_MAX_DELAY);
}
