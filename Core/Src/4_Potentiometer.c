#include "4_Potentiometer.h"
#include "stm32f4xx_hal_adc.h"

void read_ADC(uint32_t* adc_raw_value, float* adc_percentage) {

		HAL_ADC_Start(&hadc1);
		HAL_ADC_PollForConversion(&hadc1, HAL_MAX_DELAY);
		uint32_t raw = HAL_ADC_GetValue(&hadc1);
		if (adc_raw_value) *adc_raw_value = raw;
		if (adc_percentage) *adc_percentage = (raw / 4095.0f) * 100.0f;
		HAL_ADC_Stop(&hadc1);

	/* TODO: Implement this
	 * Step 1: Start ADC
	 * Step 2: Poll the ADC till conversion is complete
	 * Step 3: Retrieve raw data, assign to pointer)
	 * Step 4: Calculate percentage, (ADC uses 12-bit conversion)
	 * Step 5: Stop ADC
	 */

	// Useful functions
//	HAL_ADC_Start(hadc);
//	HAL_ADC_PollForConversion(hadc, Timeout);
//	HAL_ADC_GetValue(hadc);
//	HAL_ADC_Stop(hadc);

	HAL_Delay(100);
}
