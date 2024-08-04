################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Inc/gpio.c \
../Inc/init.c \
../Inc/interrupt.c \
../Inc/sevenseg.c \
../Inc/sevensegFunctions.c 

OBJS += \
./Inc/gpio.o \
./Inc/init.o \
./Inc/interrupt.o \
./Inc/sevenseg.o \
./Inc/sevensegFunctions.o 

C_DEPS += \
./Inc/gpio.d \
./Inc/init.d \
./Inc/interrupt.d \
./Inc/sevenseg.d \
./Inc/sevensegFunctions.d 


# Each subdirectory must supply rules for building sources it contributes
Inc/%.o Inc/%.su Inc/%.cyclo: ../Inc/%.c Inc/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DNUCLEO_F411RE -DSTM32 -DSTM32F4 -DSTM32F411RETx -DSTM32F411xE -c -I../Inc -I"C:/ST/STM32CubeIDE_1.15.1/STM32CubeIDE/STM32Cube_FW_F4_V1.28.0/Drivers/CMSIS/Include" -I"C:/ST/STM32CubeIDE_1.15.1/STM32CubeIDE/STM32Cube_FW_F4_V1.28.0/Drivers/CMSIS/Device/ST/STM32F4xx/Include" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Inc

clean-Inc:
	-$(RM) ./Inc/gpio.cyclo ./Inc/gpio.d ./Inc/gpio.o ./Inc/gpio.su ./Inc/init.cyclo ./Inc/init.d ./Inc/init.o ./Inc/init.su ./Inc/interrupt.cyclo ./Inc/interrupt.d ./Inc/interrupt.o ./Inc/interrupt.su ./Inc/sevenseg.cyclo ./Inc/sevenseg.d ./Inc/sevenseg.o ./Inc/sevenseg.su ./Inc/sevensegFunctions.cyclo ./Inc/sevensegFunctions.d ./Inc/sevensegFunctions.o ./Inc/sevensegFunctions.su

.PHONY: clean-Inc

