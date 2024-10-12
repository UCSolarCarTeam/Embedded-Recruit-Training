#include "2_LIS302DL.h"

#include "main.h"
#include "stm32f4xx_hal_spi.h"
#include "stm32f4xx_hal_gpio.h"


void lis302dl_Read_Register(uint8_t address, uint8_t* buffer) {
	/* TODO: Implement this
	 * Step 1: Write CS pin to low state (GPIO_PIN_RESET)
	 * Step 2: Transmit address of register you wish to write to
	 * Step 3: Read data from specified register
	 * Step 4: Write CS pin to high state (GPIO_PIN_SET)
	 *
	 * Below are all the functions you will require
	 */

	uint8_t command = (address & 0x3F) | 0x80;

	HAL_GPIO_WritePin(GPIOE, GPIO_PIN_3, GPIO_PIN_RESET);
	HAL_SPI_Transmit(&hspi1, &command, 1, HAL_MAX_DELAY);
	HAL_SPI_Receive(&hspi1, buffer, 1, HAL_MAX_DELAY);
	HAL_GPIO_WritePin(GPIOE, GPIO_PIN_3, GPIO_PIN_SET);

}

void lis302dl_Write_Register(uint8_t address, uint8_t value) {
	/* TODO: Implement this
	 * Step 1: Write CS pin to low state (GPIO_PIN_RESET)
	 * Step 2: Transmit address of register you wish to write to
	 * Step 3: Transmit data you wish to write to register
	 * Step 4: Write CS pin to high state (GPIO_PIN_SET)
	 *
	 * Below are all the functions you will require
	 */

	uint8_t command[] = {(address & 0x3F), value};

	HAL_GPIO_WritePin(GPIOE, GPIO_PIN_3, GPIO_PIN_RESET);
	HAL_SPI_Transmit(&hspi1, &command, 2, HAL_MAX_DELAY);
	HAL_GPIO_WritePin(GPIOE, GPIO_PIN_3, GPIO_PIN_SET);

}


/*
 * Initializes peripheral
 */
void lis302dl_Init() {
	// configure Ctrl_Reg1
	lis302dl_Write_Register(Ctrl_Reg1_REG_ADDR, 0x87);

	// configure Ctrl_Reg2
	lis302dl_Write_Register(Ctrl_Reg2_REG_ADDR, 0x00);

	// configure Ctrl_Reg3
	lis302dl_Write_Register(Ctrl_Reg3_REG_ADDR, 0x00);

}

/*
 * displays the leds based on board orientation
 */
void lis302dl_Display_Led(int8_t x, int8_t y) {
	  if (x >= 10) {
		  HAL_GPIO_WritePin(LD5_GPIO_Port, LD5_Pin, GPIO_PIN_SET);
		  HAL_GPIO_WritePin(LD4_GPIO_Port, LD4_Pin, GPIO_PIN_RESET);
	  }
	  else if (x <= -10) {
		  HAL_GPIO_WritePin(LD4_GPIO_Port, LD4_Pin, GPIO_PIN_SET);
		  HAL_GPIO_WritePin(LD5_GPIO_Port, LD5_Pin, GPIO_PIN_RESET);
	  }
	  else {
		  HAL_GPIO_WritePin(LD4_GPIO_Port, LD4_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(LD5_GPIO_Port, LD5_Pin, GPIO_PIN_RESET);
	  }

	  HAL_Delay(50);

	  if (y >= 10) {
		  HAL_GPIO_WritePin(LD3_GPIO_Port, LD3_Pin, GPIO_PIN_SET);
		  HAL_GPIO_WritePin(LD6_GPIO_Port, LD6_Pin, GPIO_PIN_RESET);
	  }
	  else if (y <= -10) {
		  HAL_GPIO_WritePin(LD6_GPIO_Port, LD6_Pin, GPIO_PIN_SET);
		  HAL_GPIO_WritePin(LD3_GPIO_Port, LD3_Pin, GPIO_PIN_RESET);
	  }
	  else {
		  HAL_GPIO_WritePin(LD3_GPIO_Port, LD3_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(LD6_GPIO_Port, LD6_Pin, GPIO_PIN_RESET);
	  }

}

/*
 * Polls data and display's it in led
 */
void lis302dl_Poll_Data(int8_t* x_buf, int8_t* y_buf, int8_t* z_buf) {
	uint8_t raw_x;
	lis302dl_Read_Register(OutX_REG_ADDR, &raw_x);
	*x_buf = (int8_t) raw_x;

	uint8_t raw_y;
	lis302dl_Read_Register(OutY_REG_ADDR, &raw_y);
	*y_buf = (int8_t) raw_y;

	uint8_t raw_z;
	lis302dl_Read_Register(OutZ_REG_ADDR, &raw_z);
	*z_buf = (int8_t) raw_z;

	// LEDs
	lis302dl_Display_Led(*x_buf, *y_buf);

}
