################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../mysource/touch.c 

OBJS += \
./mysource/touch.o 

C_DEPS += \
./mysource/touch.d 


# Each subdirectory must supply rules for building sources it contributes
mysource/%.o mysource/%.su mysource/%.cyclo: ../mysource/%.c mysource/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F401xC -c -I../Core/Inc -I"C:/Users/user/Documents/GIT_WORKSPACE/NTFR_SW_V2/Graphics_downloader/ST7735_inc" -I"C:/Users/user/Documents/GIT_WORKSPACE/NTFR_SW_V2/Graphics_downloader/w25qxx" -I"C:/Users/user/Documents/GIT_WORKSPACE/NTFR_SW_V2/Graphics_downloader/mysource" -I"C:/Users/user/Documents/GIT_WORKSPACE/NTFR_SW_V2/Graphics_downloader/ST7735_src" -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-mysource

clean-mysource:
	-$(RM) ./mysource/touch.cyclo ./mysource/touch.d ./mysource/touch.o ./mysource/touch.su

.PHONY: clean-mysource

