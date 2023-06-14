################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../middleware/FreeRTOS/croutine.c \
../middleware/FreeRTOS/event_groups.c \
../middleware/FreeRTOS/list.c \
../middleware/FreeRTOS/queue.c \
../middleware/FreeRTOS/stream_buffer.c \
../middleware/FreeRTOS/tasks.c \
../middleware/FreeRTOS/timers.c 

OBJS += \
./middleware/FreeRTOS/croutine.o \
./middleware/FreeRTOS/event_groups.o \
./middleware/FreeRTOS/list.o \
./middleware/FreeRTOS/queue.o \
./middleware/FreeRTOS/stream_buffer.o \
./middleware/FreeRTOS/tasks.o \
./middleware/FreeRTOS/timers.o 

C_DEPS += \
./middleware/FreeRTOS/croutine.d \
./middleware/FreeRTOS/event_groups.d \
./middleware/FreeRTOS/list.d \
./middleware/FreeRTOS/queue.d \
./middleware/FreeRTOS/stream_buffer.d \
./middleware/FreeRTOS/tasks.d \
./middleware/FreeRTOS/timers.d 


# Each subdirectory must supply rules for building sources it contributes
middleware/FreeRTOS/%.o middleware/FreeRTOS/%.su middleware/FreeRTOS/%.cyclo: ../middleware/FreeRTOS/%.c middleware/FreeRTOS/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0plus -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32G070xx -c -I../Core/Inc -I../Drivers/STM32G0xx_HAL_Driver/Inc -I../Drivers/STM32G0xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32G0xx/Include -I../Drivers/CMSIS/Include -I"/Users/nithish/STM32CubeIDE/workspace_1.12.1/Timer_interrupt/middleware/FreeRTOS/portable/GCC/ARM_CM0" -I"/Users/nithish/STM32CubeIDE/workspace_1.12.1/Timer_interrupt/middleware/FreeRTOS/portable/MemMang" -I"/Users/nithish/STM32CubeIDE/workspace_1.12.1/Timer_interrupt/middleware/FreeRTOS/include" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-middleware-2f-FreeRTOS

clean-middleware-2f-FreeRTOS:
	-$(RM) ./middleware/FreeRTOS/croutine.cyclo ./middleware/FreeRTOS/croutine.d ./middleware/FreeRTOS/croutine.o ./middleware/FreeRTOS/croutine.su ./middleware/FreeRTOS/event_groups.cyclo ./middleware/FreeRTOS/event_groups.d ./middleware/FreeRTOS/event_groups.o ./middleware/FreeRTOS/event_groups.su ./middleware/FreeRTOS/list.cyclo ./middleware/FreeRTOS/list.d ./middleware/FreeRTOS/list.o ./middleware/FreeRTOS/list.su ./middleware/FreeRTOS/queue.cyclo ./middleware/FreeRTOS/queue.d ./middleware/FreeRTOS/queue.o ./middleware/FreeRTOS/queue.su ./middleware/FreeRTOS/stream_buffer.cyclo ./middleware/FreeRTOS/stream_buffer.d ./middleware/FreeRTOS/stream_buffer.o ./middleware/FreeRTOS/stream_buffer.su ./middleware/FreeRTOS/tasks.cyclo ./middleware/FreeRTOS/tasks.d ./middleware/FreeRTOS/tasks.o ./middleware/FreeRTOS/tasks.su ./middleware/FreeRTOS/timers.cyclo ./middleware/FreeRTOS/timers.d ./middleware/FreeRTOS/timers.o ./middleware/FreeRTOS/timers.su

.PHONY: clean-middleware-2f-FreeRTOS

