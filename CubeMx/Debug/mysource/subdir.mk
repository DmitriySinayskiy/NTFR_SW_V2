################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../mysource/measuring.c \
../mysource/touch.c 

OBJS += \
./mysource/measuring.o \
./mysource/touch.o 

C_DEPS += \
./mysource/measuring.d \
./mysource/touch.d 


# Each subdirectory must supply rules for building sources it contributes
mysource/%.o mysource/%.su mysource/%.cyclo: ../mysource/%.c mysource/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F401xC -c -I../Core/Inc -I"C:/Users/user/Documents/GIT_WORKSPACE/NTFR_SW_V2/CubeMx/ST7735_inc" -I"C:/Users/user/Documents/GIT_WORKSPACE/NTFR_SW_V2/CubeMx/w25qxx" -I"C:/Users/user/Documents/GIT_WORKSPACE/NTFR_SW_V2/CubeMx/mysource" -I"C:/Users/user/Documents/GIT_WORKSPACE/NTFR_SW_V2/CubeMx/ST7735_src" -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../USB_DEVICE/App -I../USB_DEVICE/Target -I../Middlewares/ST/STM32_USB_Device_Library/Core/Inc -I../Middlewares/ST/STM32_USB_Device_Library/Class/CDC/Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-mysource

clean-mysource:
	-$(RM) ./mysource/measuring.cyclo ./mysource/measuring.d ./mysource/measuring.o ./mysource/measuring.su ./mysource/touch.cyclo ./mysource/touch.d ./mysource/touch.o ./mysource/touch.su

.PHONY: clean-mysource

