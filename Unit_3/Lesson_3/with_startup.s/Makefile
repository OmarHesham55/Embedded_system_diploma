#Copyright@Omar_Hesham
#build By Eng:Omar Hesham

CC=arm-none-eabi
PROC=-mcpu=cortex-m3
INCS=-I .
LIBS=
PROJ_NAME=lesson2_lab2
SRC = $(wildcard *.c)       
OBJ= $(SRC:.c=.o)
SRC_AS= $(wildcard *.s)
OBJ_AS= $(SRC_AS:.s=.o)	

all: $(PROJ_NAME).bin
	@echo "=====Build is done====="


%.o: %.c
	$(CC)-gcc.exe -c -I . -gdwarf-2 $(PROC) $< -o $@

startup.o: startup.s
	$(CC)-as.exe -gdwarf-2 $(PROC) $< -o $@

$(PROJ_NAME).elf: $(OBJ) $(OBJ_AS)
	$(CC)-ld.exe -T linker_script.ld $(OBJ) $(OBJ_AS) -o $@ -Map=map_file.map

$(PROJ_NAME).bin: $(PROJ_NAME).elf
	$(CC)-objcopy.exe -O binary $< $@	

clear: 
	rm *.elf *.bin

clear_all: 
	rm *.o *.elf *.bin	
	@echo "clean is done"