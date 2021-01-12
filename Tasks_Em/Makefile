CC = arm-none-eabi-gcc
MACH = cortex-m4
CFLAGS = -c -mcpu=$(MACH) -mthumb -std=gnu11 -Wall -O0
LDFLAGS= -nostdlib -T stm32_ls.ld 

all:main.o stm_startuo.o final.elf

main.o:Task.c
	$(CC) $(CFLAGS) Task.c -o main.o
	
stm_startuo.o:stm_startup.c
	$(CC) $(CFLAGS) -o $@ $^

final.elf: main.o stm_startuo.o
	$(CC) $(LDFLAGS) -o $@ $^

clean:
	rm -rf *.o *.elf
	
