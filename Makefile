CC=arm-none-eabi-gcc
MACH=cortex-m4
CFLAGS= -c -mcpu=$(MACH) -mthumb -std=gnu11 -O0

all:stm32_startup.o main.o

clean:
	rm -rf *.o *.elf

stm32_startup.o:stm32_startup.c
	$(CC) $(CFLAGS) $^ -o $@

main.o:main.c
	$(CC) $(CFLAGS) $^ -o $@

