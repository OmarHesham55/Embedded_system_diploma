#Prepared by ENG.Omar Hesham 
#Learn in depth

PROJNAME=lab_4
CC = arm-none-eabi
CFLAG = -mcpu=cortex-m4
INC = -I .
LINKER =-T linker_script.ld
MAPFILE =-Map=Map_file.map
SRC= $(wildcard *.c)
OBJS= $(SRC:.c=.o)
AS= $(wildcard*.s)
ASOBJ=$(AS:.s=.o)
DEBUG= -g -gdwarf-2

ALL:$(PROJNAME).bin
	@echo "======Build is Done======"

%.o: %.c
	$(CC)-gcc.exe -c $(CFLAG) $(DEBUG) $< -o $@	

$(PROJNAME).elf: $(ASOBJ) $(OBJS)
	$(CC)-ld.exe $(LINKER) $(ASOBJ) $(OBJS) -o $@ $(MAPFILE)
	cp $(PROJNAME).elf $(PROJNAME).axf

$(PROJNAME).bin:$(PROJNAME).elf
	$(CC)-objcopy.exe -O binary $< $@

clear:
	rm *.elf *.bin

clear_all:
	rm *.o *.elf *.bin
