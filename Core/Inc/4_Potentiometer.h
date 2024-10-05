#pragma once

#include <stdint.h>
#include "stm32f4xx_hal.h"

extern ADC_HandleTypeDef hadc1;

void read_ADC(uint32_t* adc_raw_value, float* adc_percentage);


