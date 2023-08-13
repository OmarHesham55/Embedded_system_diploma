################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../HAL_Drivers/7_SEG.c \
../HAL_Drivers/keypad.c \
../HAL_Drivers/lcd.c 

OBJS += \
./HAL_Drivers/7_SEG.o \
./HAL_Drivers/keypad.o \
./HAL_Drivers/lcd.o 

C_DEPS += \
./HAL_Drivers/7_SEG.d \
./HAL_Drivers/keypad.d \
./HAL_Drivers/lcd.d 


# Each subdirectory must supply rules for building sources it contributes
HAL_Drivers/%.o HAL_Drivers/%.su HAL_Drivers/%.cyclo: ../HAL_Drivers/%.c HAL_Drivers/subdir.mk
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I../Inc -I"D:/Coruses/Embedded/Course_keroles/WorkSpace/Drivers/HAL_Drivers/inc" -I"D:/Coruses/Embedded/Course_keroles/WorkSpace/Drivers/STM32F103_C6_Drivers/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-HAL_Drivers

clean-HAL_Drivers:
	-$(RM) ./HAL_Drivers/7_SEG.cyclo ./HAL_Drivers/7_SEG.d ./HAL_Drivers/7_SEG.o ./HAL_Drivers/7_SEG.su ./HAL_Drivers/keypad.cyclo ./HAL_Drivers/keypad.d ./HAL_Drivers/keypad.o ./HAL_Drivers/keypad.su ./HAL_Drivers/lcd.cyclo ./HAL_Drivers/lcd.d ./HAL_Drivers/lcd.o ./HAL_Drivers/lcd.su

.PHONY: clean-HAL_Drivers

