################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../App/Src/Hardware/hw_GPIO.c \
../App/Src/Hardware/hw_Timer.c \
../App/Src/Hardware/hw_usart.c 

OBJS += \
./App/Src/Hardware/hw_GPIO.o \
./App/Src/Hardware/hw_Timer.o \
./App/Src/Hardware/hw_usart.o 

C_DEPS += \
./App/Src/Hardware/hw_GPIO.d \
./App/Src/Hardware/hw_Timer.d \
./App/Src/Hardware/hw_usart.d 


# Each subdirectory must supply rules for building sources it contributes
App/Src/Hardware/%.o App/Src/Hardware/%.su App/Src/Hardware/%.cyclo: ../App/Src/Hardware/%.c App/Src/Hardware/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F411xE -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/isabe/STM32CubeIDE/workspace_1.9.0/lab-07-11/App/Inc" -I"C:/Users/isabe/STM32CubeIDE/workspace_1.9.0/lab-07-11/App/Inc/hardware" -I"C:/Users/isabe/STM32CubeIDE/workspace_1.9.0/lab-07-11/App/Inc/Peripherals" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-App-2f-Src-2f-Hardware

clean-App-2f-Src-2f-Hardware:
	-$(RM) ./App/Src/Hardware/hw_GPIO.cyclo ./App/Src/Hardware/hw_GPIO.d ./App/Src/Hardware/hw_GPIO.o ./App/Src/Hardware/hw_GPIO.su ./App/Src/Hardware/hw_Timer.cyclo ./App/Src/Hardware/hw_Timer.d ./App/Src/Hardware/hw_Timer.o ./App/Src/Hardware/hw_Timer.su ./App/Src/Hardware/hw_usart.cyclo ./App/Src/Hardware/hw_usart.d ./App/Src/Hardware/hw_usart.o ./App/Src/Hardware/hw_usart.su

.PHONY: clean-App-2f-Src-2f-Hardware

