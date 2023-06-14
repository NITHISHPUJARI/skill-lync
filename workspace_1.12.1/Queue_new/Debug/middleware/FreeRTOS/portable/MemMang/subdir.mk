################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../middleware/FreeRTOS/portable/MemMang/heap_4.c 

OBJS += \
./middleware/FreeRTOS/portable/MemMang/heap_4.o 

C_DEPS += \
./middleware/FreeRTOS/portable/MemMang/heap_4.d 


# Each subdirectory must supply rules for building sources it contributes
middleware/FreeRTOS/portable/MemMang/%.o middleware/FreeRTOS/portable/MemMang/%.su middleware/FreeRTOS/portable/MemMang/%.cyclo: ../middleware/FreeRTOS/portable/MemMang/%.c middleware/FreeRTOS/portable/MemMang/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0plus -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32G070xx -c -I../Core/Inc -I../Drivers/STM32G0xx_HAL_Driver/Inc -I../Drivers/STM32G0xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32G0xx/Include -I../Drivers/CMSIS/Include -I"/Users/nithish/STM32CubeIDE/workspace_1.12.1/Queue_new/middleware/FreeRTOS/portable/GCC/ARM_CM0" -I"/Users/nithish/STM32CubeIDE/workspace_1.12.1/Queue_new/middleware/FreeRTOS/portable/MemMang" -I"/Users/nithish/STM32CubeIDE/workspace_1.12.1/Queue_new/middleware/FreeRTOS/include" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-middleware-2f-FreeRTOS-2f-portable-2f-MemMang

clean-middleware-2f-FreeRTOS-2f-portable-2f-MemMang:
	-$(RM) ./middleware/FreeRTOS/portable/MemMang/heap_4.cyclo ./middleware/FreeRTOS/portable/MemMang/heap_4.d ./middleware/FreeRTOS/portable/MemMang/heap_4.o ./middleware/FreeRTOS/portable/MemMang/heap_4.su

.PHONY: clean-middleware-2f-FreeRTOS-2f-portable-2f-MemMang

