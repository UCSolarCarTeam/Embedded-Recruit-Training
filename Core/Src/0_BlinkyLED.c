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
while(1){
	HAL_GPIO_TogglePin(GPIOD,GPIO_PIN_13);
	HAL_GPIO_WritePin(GPIOD, GPIO_PIN_13, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOD, GPIO_PIN_13, GPIO_PIN_SET);

	// Delay in milliseconds
	HAL_Delay(200);
	HAL_GPIO_WritePin(GPIOD, GPIO_PIN_13, GPIO_PIN_RESET);
	HAL_GPIO_TogglePin(GPIOD, GPIO_PIN_12);
	HAL_GPIO_WritePin(GPIOD, GPIO_PIN_12, GPIO_PIN_SET);

	// Delay in milliseconds
	HAL_Delay(200);

	HAL_GPIO_TogglePin(GPIOD, GPIO_PIN_14);
	HAL_GPIO_WritePin(GPIOD, GPIO_PIN_13, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOD, GPIO_PIN_14, GPIO_PIN_SET);

	// Delay in milliseconds
	HAL_Delay(200);

	HAL_GPIO_TogglePin(GPIOD, GPIO_PIN_15);
	HAL_GPIO_WritePin(GPIOD, GPIO_PIN_13, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOD, GPIO_PIN_15, GPIO_PIN_SET);

	// Delay in milliseconds
	HAL_Delay(200);

}
