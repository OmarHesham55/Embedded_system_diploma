################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../STM32F103_C6_Drivers/STM32F103_C6_EXTI_Driver.c \
../STM32F103_C6_Drivers/STM32F103_C6_GPIO_Driver.c \
../STM32F103_C6_Drivers/STM32F103_C6_RCC_Driver.c \
../STM32F103_C6_Drivers/STM32F103_C6_SPI_Driver.c \
../STM32F103_C6_Drivers/STM32F103_C6_UART_Driver.c 

OBJS += \
./STM32F103_C6_Drivers/STM32F103_C6_EXTI_Driver.o \
./STM32F103_C6_Drivers/STM32F103_C6_GPIO_Driver.o \
./STM32F103_C6_Drivers/STM32F103_C6_RCC_Driver.o \
./STM32F103_C6_Drivers/STM32F103_C6_SPI_Driver.o \
./STM32F103_C6_Drivers/STM32F103_C6_UART_Driver.o 

C_DEPS += \
./STM32F103_C6_Drivers/STM32F103_C6_EXTI_Driver.d \
./STM32F103_C6_Drivers/STM32F103_C6_GPIO_Driver.d \
./STM32F103_C6_Drivers/STM32F103_C6_RCC_Driver.d \
./STM32F103_C6_Drivers/STM32F103_C6_SPI_Driver.d \
./STM32F103_C6_Drivers/STM32F103_C6_UART_Driver.d 


# Each subdirectory must supply rules for building sources it contributes
STM32F103_C6_Drivers/%.o STM32F103_C6_Drivers/%.su STM32F103_C6_Drivers/%.cyclo: ../STM32F103_C6_Drivers/%.c STM32F103_C6_Drivers/subdir.mk
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I../Inc -I"D:/Coruses/Embedded/Course_keroles/WorkSpace/Drivers/HAL_Drivers/inc" -I"D:/Coruses/Embedded/Course_keroles/WorkSpace/Drivers/STM32F103_C6_Drivers/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-STM32F103_C6_Drivers

clean-STM32F103_C6_Drivers:
	-$(RM) ./STM32F103_C6_Drivers/STM32F103_C6_EXTI_Driver.cyclo ./STM32F103_C6_Drivers/STM32F103_C6_EXTI_Driver.d ./STM32F103_C6_Drivers/STM32F103_C6_EXTI_Driver.o ./STM32F103_C6_Drivers/STM32F103_C6_EXTI_Driver.su ./STM32F103_C6_Drivers/STM32F103_C6_GPIO_Driver.cyclo ./STM32F103_C6_Drivers/STM32F103_C6_GPIO_Driver.d ./STM32F103_C6_Drivers/STM32F103_C6_GPIO_Driver.o ./STM32F103_C6_Drivers/STM32F103_C6_GPIO_Driver.su ./STM32F103_C6_Drivers/STM32F103_C6_RCC_Driver.cyclo ./STM32F103_C6_Drivers/STM32F103_C6_RCC_Driver.d ./STM32F103_C6_Drivers/STM32F103_C6_RCC_Driver.o ./STM32F103_C6_Drivers/STM32F103_C6_RCC_Driver.su ./STM32F103_C6_Drivers/STM32F103_C6_SPI_Driver.cyclo ./STM32F103_C6_Drivers/STM32F103_C6_SPI_Driver.d ./STM32F103_C6_Drivers/STM32F103_C6_SPI_Driver.o ./STM32F103_C6_Drivers/STM32F103_C6_SPI_Driver.su ./STM32F103_C6_Drivers/STM32F103_C6_UART_Driver.cyclo ./STM32F103_C6_Drivers/STM32F103_C6_UART_Driver.d ./STM32F103_C6_Drivers/STM32F103_C6_UART_Driver.o ./STM32F103_C6_Drivers/STM32F103_C6_UART_Driver.su

.PHONY: clean-STM32F103_C6_Drivers

