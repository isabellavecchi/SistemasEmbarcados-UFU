################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../App/Src/Peripherals/led.c \
../App/Src/Peripherals/tim3.c 

OBJS += \
./App/Src/Peripherals/led.o \
./App/Src/Peripherals/tim3.o 

C_DEPS += \
./App/Src/Peripherals/led.d \
./App/Src/Peripherals/tim3.d 


# Each subdirectory must supply rules for building sources it contributes
App/Src/Peripherals/%.o App/Src/Peripherals/%.su App/Src/Peripherals/%.cyclo: ../App/Src/Peripherals/%.c App/Src/Peripherals/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F411xE -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/isabe/STM32CubeIDE/workspace_1.9.0/lab-07-11/App/Inc" -I"C:/Users/isabe/STM32CubeIDE/workspace_1.9.0/lab-07-11/App/Inc/hardware" -I"C:/Users/isabe/STM32CubeIDE/workspace_1.9.0/lab-07-11/App/Inc/Peripherals" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-App-2f-Src-2f-Peripherals

clean-App-2f-Src-2f-Peripherals:
	-$(RM) ./App/Src/Peripherals/led.cyclo ./App/Src/Peripherals/led.d ./App/Src/Peripherals/led.o ./App/Src/Peripherals/led.su ./App/Src/Peripherals/tim3.cyclo ./App/Src/Peripherals/tim3.d ./App/Src/Peripherals/tim3.o ./App/Src/Peripherals/tim3.su

.PHONY: clean-App-2f-Src-2f-Peripherals

