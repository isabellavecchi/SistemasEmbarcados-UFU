################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../App/Src/Middleware/tim.c 

OBJS += \
./App/Src/Middleware/tim.o 

C_DEPS += \
./App/Src/Middleware/tim.d 


# Each subdirectory must supply rules for building sources it contributes
App/Src/Middleware/%.o App/Src/Middleware/%.su App/Src/Middleware/%.cyclo: ../App/Src/Middleware/%.c App/Src/Middleware/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F411xE -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/isabe/STM32CubeIDE/workspace_1.9.0/lab-07-11/App/Inc" -I"C:/Users/isabe/STM32CubeIDE/workspace_1.9.0/lab-07-11/App/Inc/hardware" -I"C:/Users/isabe/STM32CubeIDE/workspace_1.9.0/lab-07-11/App/Inc/Peripherals" -I"C:/Users/isabe/STM32CubeIDE/workspace_1.9.0/lab-07-11/App/Inc/Middleware" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-App-2f-Src-2f-Middleware

clean-App-2f-Src-2f-Middleware:
	-$(RM) ./App/Src/Middleware/tim.cyclo ./App/Src/Middleware/tim.d ./App/Src/Middleware/tim.o ./App/Src/Middleware/tim.su

.PHONY: clean-App-2f-Src-2f-Middleware

