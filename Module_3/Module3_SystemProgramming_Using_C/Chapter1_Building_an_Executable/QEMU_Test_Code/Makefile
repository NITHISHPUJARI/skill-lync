all: system.bin

startup.o: startup.c
	arm-none-eabi-gcc -c -g -mcpu=cortex-m3 -mthumb -o startup.o startup.c

main.o: main.c
	arm-none-eabi-gcc -c -g -mcpu=cortex-m3 -mthumb -o main.o main.c

startup.elf: startup.o main.o
	arm-none-eabi-ld -T linker.ld -o startup.elf startup.o main.o

system.bin: startup.elf
	arm-none-eabi-objcopy -O binary startup.elf system.bin

runTcp: system.bin
	qemu-system-arm -M stm32vldiscovery --cpu cortex-m3 -d unimp,guest_errors -kernel system.bin -nographic -serial tcp::7777,server

runSerial: system.bin
	qemu-system-arm -M stm32vldiscovery --cpu cortex-m3 -d unimp,guest_errors -kernel system.bin  -serial stdio


clean:
	rm -f *.o *.elf *.bin

map:
	arm-none-eabi-ld -Map output.map -T linker.ld  -o startup.elf  startup.o main.o 

dump: 
	arm-none-eabi-nm -n startup.o
	arm-none-eabi-objdump -h startup.o
	arm-none-eabi-nm -n main.o
	arm-none-eabi-objdump -h main.o
	# arm-none-eabi-nm -n startup.elf
	# arm-none-eabi-objdump -h startup.elf
	# arm-none-eabi-size startup.elf

