#include "0_BlinkyLED.h"

#include "main.h"
#include "stm32f4xx_hal_gpio.h"

void blinky_LED() {
	/* TODO: Implement this
	 *
	 * Use the following functions set/reset LEDs
	 *
	 * LD3 (Orange LED): PD13
	 * LD4 (Green LED): PD12
	 * LD5 (Red LED): PD14
	 * LD6 (Blue LED): PD15
	 *
	 * PinState: GPIO_PIN_RESET/GPIO_PIN_SET
	 */

	HAL_GPIO_TogglePin(GPIOx, GPIO_Pin);
	HAL_GPIO_WritePin(GPIOx, GPIO_Pin, PinState);

	// Delay in milliseconds
	HAL_Delay(Delay);
}
