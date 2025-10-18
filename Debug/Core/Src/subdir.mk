################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/0_BlinkyLED.c \
../Core/Src/1_UART.c \
../Core/Src/2_LIS302DL.c \
../Core/Src/3_TSL2591.c \
../Core/Src/4_Potentiometer.c \
../Core/Src/main.c \
../Core/Src/stm32f4xx_hal_msp.c \
../Core/Src/stm32f4xx_it.c \
../Core/Src/syscalls.c \
../Core/Src/sysmem.c \
../Core/Src/system_stm32f4xx.c 

OBJS += \
./Core/Src/0_BlinkyLED.o \
./Core/Src/1_UART.o \
./Core/Src/2_LIS302DL.o \
./Core/Src/3_TSL2591.o \
./Core/Src/4_Potentiometer.o \
./Core/Src/main.o \
./Core/Src/stm32f4xx_hal_msp.o \
./Core/Src/stm32f4xx_it.o \
./Core/Src/syscalls.o \
./Core/Src/sysmem.o \
./Core/Src/system_stm32f4xx.o 

C_DEPS += \
./Core/Src/0_BlinkyLED.d \
./Core/Src/1_UART.d \
./Core/Src/2_LIS302DL.d \
./Core/Src/3_TSL2591.d \
./Core/Src/4_Potentiometer.d \
./Core/Src/main.d \
./Core/Src/stm32f4xx_hal_msp.d \
./Core/Src/stm32f4xx_it.d \
./Core/Src/syscalls.d \
./Core/Src/sysmem.d \
./Core/Src/system_stm32f4xx.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/%.o Core/Src/%.su Core/Src/%.cyclo: ../Core/Src/%.c Core/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F407xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Src

clean-Core-2f-Src:
	-$(RM) ./Core/Src/0_BlinkyLED.cyclo ./Core/Src/0_BlinkyLED.d ./Core/Src/0_BlinkyLED.o ./Core/Src/0_BlinkyLED.su ./Core/Src/1_UART.cyclo ./Core/Src/1_UART.d ./Core/Src/1_UART.o ./Core/Src/1_UART.su ./Core/Src/2_LIS302DL.cyclo ./Core/Src/2_LIS302DL.d ./Core/Src/2_LIS302DL.o ./Core/Src/2_LIS302DL.su ./Core/Src/3_TSL2591.cyclo ./Core/Src/3_TSL2591.d ./Core/Src/3_TSL2591.o ./Core/Src/3_TSL2591.su ./Core/Src/4_Potentiometer.cyclo ./Core/Src/4_Potentiometer.d ./Core/Src/4_Potentiometer.o ./Core/Src/4_Potentiometer.su ./Core/Src/main.cyclo ./Core/Src/main.d ./Core/Src/main.o ./Core/Src/main.su ./Core/Src/stm32f4xx_hal_msp.cyclo ./Core/Src/stm32f4xx_hal_msp.d ./Core/Src/stm32f4xx_hal_msp.o ./Core/Src/stm32f4xx_hal_msp.su ./Core/Src/stm32f4xx_it.cyclo ./Core/Src/stm32f4xx_it.d ./Core/Src/stm32f4xx_it.o ./Core/Src/stm32f4xx_it.su ./Core/Src/syscalls.cyclo ./Core/Src/syscalls.d ./Core/Src/syscalls.o ./Core/Src/syscalls.su ./Core/Src/sysmem.cyclo ./Core/Src/sysmem.d ./Core/Src/sysmem.o ./Core/Src/sysmem.su ./Core/Src/system_stm32f4xx.cyclo ./Core/Src/system_stm32f4xx.d ./Core/Src/system_stm32f4xx.o ./Core/Src/system_stm32f4xx.su

.PHONY: clean-Core-2f-Src

