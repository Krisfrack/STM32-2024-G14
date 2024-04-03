################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/AES-128_V10.c \
../Core/Src/Encrypt_V31.c \
../Core/Src/LoRa.c \
../Core/Src/gpio.c \
../Core/Src/main.c \
../Core/Src/rfm95.c \
../Core/Src/sht3x.c \
../Core/Src/spi.c \
../Core/Src/spi45.c \
../Core/Src/stm32l4xx_hal_msp.c \
../Core/Src/stm32l4xx_it.c \
../Core/Src/syscalls.c \
../Core/Src/sysmem.c \
../Core/Src/system_stm32l4xx.c \
../Core/Src/usart.c 

OBJS += \
./Core/Src/AES-128_V10.o \
./Core/Src/Encrypt_V31.o \
./Core/Src/LoRa.o \
./Core/Src/gpio.o \
./Core/Src/main.o \
./Core/Src/rfm95.o \
./Core/Src/sht3x.o \
./Core/Src/spi.o \
./Core/Src/spi45.o \
./Core/Src/stm32l4xx_hal_msp.o \
./Core/Src/stm32l4xx_it.o \
./Core/Src/syscalls.o \
./Core/Src/sysmem.o \
./Core/Src/system_stm32l4xx.o \
./Core/Src/usart.o 

C_DEPS += \
./Core/Src/AES-128_V10.d \
./Core/Src/Encrypt_V31.d \
./Core/Src/LoRa.d \
./Core/Src/gpio.d \
./Core/Src/main.d \
./Core/Src/rfm95.d \
./Core/Src/sht3x.d \
./Core/Src/spi.d \
./Core/Src/spi45.d \
./Core/Src/stm32l4xx_hal_msp.d \
./Core/Src/stm32l4xx_it.d \
./Core/Src/syscalls.d \
./Core/Src/sysmem.d \
./Core/Src/system_stm32l4xx.d \
./Core/Src/usart.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/%.o Core/Src/%.su: ../Core/Src/%.c Core/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32L476xx -c -I../Core/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Src

clean-Core-2f-Src:
	-$(RM) ./Core/Src/AES-128_V10.d ./Core/Src/AES-128_V10.o ./Core/Src/AES-128_V10.su ./Core/Src/Encrypt_V31.d ./Core/Src/Encrypt_V31.o ./Core/Src/Encrypt_V31.su ./Core/Src/LoRa.d ./Core/Src/LoRa.o ./Core/Src/LoRa.su ./Core/Src/gpio.d ./Core/Src/gpio.o ./Core/Src/gpio.su ./Core/Src/main.d ./Core/Src/main.o ./Core/Src/main.su ./Core/Src/rfm95.d ./Core/Src/rfm95.o ./Core/Src/rfm95.su ./Core/Src/sht3x.d ./Core/Src/sht3x.o ./Core/Src/sht3x.su ./Core/Src/spi.d ./Core/Src/spi.o ./Core/Src/spi.su ./Core/Src/spi45.d ./Core/Src/spi45.o ./Core/Src/spi45.su ./Core/Src/stm32l4xx_hal_msp.d ./Core/Src/stm32l4xx_hal_msp.o ./Core/Src/stm32l4xx_hal_msp.su ./Core/Src/stm32l4xx_it.d ./Core/Src/stm32l4xx_it.o ./Core/Src/stm32l4xx_it.su ./Core/Src/syscalls.d ./Core/Src/syscalls.o ./Core/Src/syscalls.su ./Core/Src/sysmem.d ./Core/Src/sysmem.o ./Core/Src/sysmem.su ./Core/Src/system_stm32l4xx.d ./Core/Src/system_stm32l4xx.o ./Core/Src/system_stm32l4xx.su ./Core/Src/usart.d ./Core/Src/usart.o ./Core/Src/usart.su

.PHONY: clean-Core-2f-Src

