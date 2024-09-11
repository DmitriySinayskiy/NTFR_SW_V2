################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../ST7735_src/fonts.c \
../ST7735_src/images.c \
../ST7735_src/st7735.c 

OBJS += \
./ST7735_src/fonts.o \
./ST7735_src/images.o \
./ST7735_src/st7735.o 

C_DEPS += \
./ST7735_src/fonts.d \
./ST7735_src/images.d \
./ST7735_src/st7735.d 


# Each subdirectory must supply rules for building sources it contributes
ST7735_src/%.o ST7735_src/%.su ST7735_src/%.cyclo: ../ST7735_src/%.c ST7735_src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F401xC -c -I../Core/Inc -I"C:/Users/user/Documents/GIT_WORKSPACE/NTFR_SW_V2/CubeMx/ST7735_inc" -I"C:/Users/user/Documents/GIT_WORKSPACE/NTFR_SW_V2/CubeMx/w25qxx" -I"C:/Users/user/Documents/GIT_WORKSPACE/NTFR_SW_V2/CubeMx/mysource" -I"C:/Users/user/Documents/GIT_WORKSPACE/NTFR_SW_V2/CubeMx/ST7735_src" -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../USB_DEVICE/App -I../USB_DEVICE/Target -I../Middlewares/ST/STM32_USB_Device_Library/Core/Inc -I../Middlewares/ST/STM32_USB_Device_Library/Class/CDC/Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-ST7735_src

clean-ST7735_src:
	-$(RM) ./ST7735_src/fonts.cyclo ./ST7735_src/fonts.d ./ST7735_src/fonts.o ./ST7735_src/fonts.su ./ST7735_src/images.cyclo ./ST7735_src/images.d ./ST7735_src/images.o ./ST7735_src/images.su ./ST7735_src/st7735.cyclo ./ST7735_src/st7735.d ./ST7735_src/st7735.o ./ST7735_src/st7735.su

.PHONY: clean-ST7735_src

