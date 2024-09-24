################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../mysource/button.c \
../mysource/main_menu.c \
../mysource/measuring.c \
../mysource/page_select.c \
../mysource/product_selection.c \
../mysource/product_struct.c \
../mysource/touch.c 

OBJS += \
./mysource/button.o \
./mysource/main_menu.o \
./mysource/measuring.o \
./mysource/page_select.o \
./mysource/product_selection.o \
./mysource/product_struct.o \
./mysource/touch.o 

C_DEPS += \
./mysource/button.d \
./mysource/main_menu.d \
./mysource/measuring.d \
./mysource/page_select.d \
./mysource/product_selection.d \
./mysource/product_struct.d \
./mysource/touch.d 


# Each subdirectory must supply rules for building sources it contributes
mysource/%.o mysource/%.su mysource/%.cyclo: ../mysource/%.c mysource/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F401xC -c -I../Core/Inc -I"C:/Users/user/Documents/GIT_WORKSPACE/NTFR_SW_V2/CubeMx/ST7735_inc" -I"C:/Users/user/Documents/GIT_WORKSPACE/NTFR_SW_V2/CubeMx/w25qxx" -I"C:/Users/user/Documents/GIT_WORKSPACE/NTFR_SW_V2/CubeMx/mysource" -I"C:/Users/user/Documents/GIT_WORKSPACE/NTFR_SW_V2/CubeMx/ST7735_src" -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../USB_DEVICE/App -I../USB_DEVICE/Target -I../Middlewares/ST/STM32_USB_Device_Library/Core/Inc -I../Middlewares/ST/STM32_USB_Device_Library/Class/CDC/Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-mysource

clean-mysource:
	-$(RM) ./mysource/button.cyclo ./mysource/button.d ./mysource/button.o ./mysource/button.su ./mysource/main_menu.cyclo ./mysource/main_menu.d ./mysource/main_menu.o ./mysource/main_menu.su ./mysource/measuring.cyclo ./mysource/measuring.d ./mysource/measuring.o ./mysource/measuring.su ./mysource/page_select.cyclo ./mysource/page_select.d ./mysource/page_select.o ./mysource/page_select.su ./mysource/product_selection.cyclo ./mysource/product_selection.d ./mysource/product_selection.o ./mysource/product_selection.su ./mysource/product_struct.cyclo ./mysource/product_struct.d ./mysource/product_struct.o ./mysource/product_struct.su ./mysource/touch.cyclo ./mysource/touch.d ./mysource/touch.o ./mysource/touch.su

.PHONY: clean-mysource

