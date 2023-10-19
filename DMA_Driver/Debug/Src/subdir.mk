################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/DMA_prog.c \
../Src/GPIO_Program.c \
../Src/NVIC_Program.c \
../Src/RCC_Program.c \
../Src/STK_Program.c \
../Src/main.c \
../Src/syscalls.c \
../Src/sysmem.c 

OBJS += \
./Src/DMA_prog.o \
./Src/GPIO_Program.o \
./Src/NVIC_Program.o \
./Src/RCC_Program.o \
./Src/STK_Program.o \
./Src/main.o \
./Src/syscalls.o \
./Src/sysmem.o 

C_DEPS += \
./Src/DMA_prog.d \
./Src/GPIO_Program.d \
./Src/NVIC_Program.d \
./Src/RCC_Program.d \
./Src/STK_Program.d \
./Src/main.d \
./Src/syscalls.d \
./Src/sysmem.d 


# Each subdirectory must supply rules for building sources it contributes
Src/%.o Src/%.su: ../Src/%.c Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -c -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Src

clean-Src:
	-$(RM) ./Src/DMA_prog.d ./Src/DMA_prog.o ./Src/DMA_prog.su ./Src/GPIO_Program.d ./Src/GPIO_Program.o ./Src/GPIO_Program.su ./Src/NVIC_Program.d ./Src/NVIC_Program.o ./Src/NVIC_Program.su ./Src/RCC_Program.d ./Src/RCC_Program.o ./Src/RCC_Program.su ./Src/STK_Program.d ./Src/STK_Program.o ./Src/STK_Program.su ./Src/main.d ./Src/main.o ./Src/main.su ./Src/syscalls.d ./Src/syscalls.o ./Src/syscalls.su ./Src/sysmem.d ./Src/sysmem.o ./Src/sysmem.su

.PHONY: clean-Src
