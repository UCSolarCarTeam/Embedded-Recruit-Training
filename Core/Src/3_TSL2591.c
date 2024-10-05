#include "3_TSL2591.h"
#include "stm32f4xx_hal_i2c.h"



/*
 * Read specified register from Lux Sensor
 */
void tsl2591_Read_Byte(uint8_t address, uint8_t* buffer) {
	/* TODO: Implement this
	 * Use the following function to communicate with the peripheral
	 */

	address = address | 0xA0;

	HAL_I2C_Mem_Read(&hi2c3, (TSL2591_DEVICE_ADDR << 1), address, I2C_MEMADD_SIZE_8BIT, buffer, 1, HAL_MAX_DELAY);

	// HAL_I2C_Mem_Read(hi2c, DevAddress, MemAddress, MemAddSize, pData, Size, Timeout);
	/* uint16_t DevAddress: I2C address of the device.
	 * uint16_t MemAddress: Memory/register address within the device.
	 * uint16_t MemAddSize: Size of the memory address (8-bit or 16-bit).
	 * uint8_t *pData: Pointer to the data buffer that will receive the data.
	 * uint16_t Size: Amount of data to read.
	 * uint32_t Timeout: Timeout duration.
	 */

}


/*
 * Write to specific register in Lux Sensor
 */
void tsl2591_Write_Byte(uint8_t address, uint8_t value) {
	/* TODO: Implement this
	 * Use the following function to communicate with the peripheral
	 */

	address = address | 0xA0;
	uint8_t data = value;

	HAL_I2C_Mem_Write(hi2c, DevAddress, MemAddress, MemAddSize, pData, Size, Timeout);
	/* uint16_t  DevAddress: I2C address of the device.
	 * uint16_t MemAddress: Memory/register address within the device.
	 * uint16_t MemAddSize: Size of the memory address (typically I2C_MEMADD_SIZE_8BIT or I2C_MEMADD_SIZE_16BIT).
	 * uint8_t *pData: Pointer to the data to write.
	 * uint16_tSize: Amount of data to write.
	 * uint32_t Timeout: Timeout duration.
	 */
}


/*
 * Initializes the Lux Sensor with desired configurations
 */
void tsl2591_Init() {
	// Dummy Register that returns 0x50 everytime
	uint8_t id_buffer;
	tsl2591_Read_Byte(ID_REG_ADDR, &id_buffer);

	if (id_buffer == 0x50) {
		uint8_t enable_cfg = 0x03;
		tsl2591_Write_Byte(ENABLE_REG_ADDR, enable_cfg);

		uint8_t control_cfg = 0x10;
		tsl2591_Write_Byte(CONFIG_REG_ADDR, control_cfg);
	}
}

/*
 * Poll the data from the sensor
 */
void tsl2591_Poll_Data(uint8_t* C0DATA, uint8_t* C1DATA){
	uint8_t C0DATAL,C0DATAH;
	uint8_t C1DATAL, C1DATAH;

	tsl2591_Read_Byte(C0DATAL_REG_ADDR, &C0DATAL);
	tsl2591_Read_Byte(C0DATAH_REG_ADDR, &C0DATAH);

	*C0DATA = (C0DATAH << 8) | C0DATAL;

	tsl2591_Read_Byte(C1DATAL_REG_ADDR, &C1DATAL);
	tsl2591_Read_Byte(C1DATAH_REG_ADDR, &C1DATAH);

	*C1DATA = (C1DATAH << 8) | C1DATAL;
}
