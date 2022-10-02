PROJ = lab3
INCS = -I .
DEBUG = -gdwarf-2
CC = arm-none-eabi
PROC = -mcpu=cortex-m3 -gdwarf-2
SRCS = $(wildcard *.c)
OBJ  = $(SRCS:.c=.o)
ASSEM = $(wildcard *.s)
ASOBJ = $(ASSEM:.s=.o)
LINKER = linker.ld
MAP = -Map=map_file.map

all: $(PROJ).bin
	@echo "============build is done============"

%.o: %.c
	$(CC)-gcc.exe -c  $(INCS) $(PROC) $< -o $@

# startup.o: startup.s
# 	$(CC)-as.exe $(PROC) $< -o $@

$(PROJ).elf: $(OBJ) $(ASOBJ)
	$(CC)-ld.exe -T $(LINKER) $(OBJ) $(ASOBJ) -o $@ $(MAP) 

$(PROJ).bin: $(PROJ).elf
	$(CC)-objcopy.exe -O binary $< $@



clean:
	rm *.o *.bin *.elf