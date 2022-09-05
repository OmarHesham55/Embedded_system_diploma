/*
	learn-in-depth:lab2@lesson2
	ENG:Omar Hesham
*/


MEMORY
{
	FLASH (rx)  : ORIGIN = 0x08000000, LENGTH = 128K	
	SRAM  (rwx) : ORIGIN = 0x20000000 , LENGTH = 20K
}

SECTIONS
{
	.text : 
	{
		*(.vectors*)
		*(.text*)
	} > flash
	.data : 
	{
		*(.data)
		*(.rodata)
	} > flash
	.bss : 
	{
		*(.bss)
	} > sram
}