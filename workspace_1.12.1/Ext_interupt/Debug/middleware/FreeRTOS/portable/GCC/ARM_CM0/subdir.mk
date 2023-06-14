################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../middleware/FreeRTOS/portable/GCC/ARM_CM0/port.c 

OBJS += \
./middleware/FreeRTOS/portable/GCC/ARM_CM0/port.o 

C_DEPS += \
./middleware/FreeRTOS/portable/GCC/ARM_CM0/port.d 


# Each subdirectory must supply rules for building sources it contributes
middleware/FreeRTOS/portable/GCC/ARM_CM0/%.o middleware/FreeRTOS/portable/GCC/ARM_CM0/%.su middleware/FreeRTOS/portable/GCC/ARM_CM0/%.cyclo: ../middleware/FreeRTOS/portable/GCC/ARM_CM0/%.c middleware/FreeRTOS/portable/GCC/ARM_CM0/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0plus -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32G070xx -c -I../Core/Inc -I../Drivers/STM32G0xx_HAL_Driver/Inc -I../Drivers/STM32G0xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32G0xx/Include -I../Drivers/CMSIS/Include -I"/Users/nithish/STM32CubeIDE/workspace_1.12.1/Ext_interupt/middleware/FreeRTOS/portable/GCC/ARM_CM0" -I"/Users/nithish/STM32CubeIDE/workspace_1.12.1/Ext_interupt/middleware/FreeRTOS/portable/MemMang" -I"/Users/nithish/STM32CubeIDE/workspace_1.12.1/Ext_interupt/middleware/FreeRTOS/include" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-middleware-2f-FreeRTOS-2f-portable-2f-GCC-2f-ARM_CM0

clean-middleware-2f-FreeRTOS-2f-portable-2f-GCC-2f-ARM_CM0:
	-$(RM) ./middleware/FreeRTOS/portable/GCC/ARM_CM0/port.cyclo ./middleware/FreeRTOS/portable/GCC/ARM_CM0/port.d ./middleware/FreeRTOS/portable/GCC/ARM_CM0/port.o ./middleware/FreeRTOS/portable/GCC/ARM_CM0/port.su

.PHONY: clean-middleware-2f-FreeRTOS-2f-portable-2f-GCC-2f-ARM_CM0

