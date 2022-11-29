/*
linker file 
*/


MEMORY 
{
	FLASH (RX) : ORIGIN = 0x08000000 , LENGTH = 128K
	SRAM (RWX) : ORIGIN = 0x20000000 , LENGTH = 20k
}

SECTIONS
{
	.text : {
		*(.vectors*)
		*(.text*)
		_E_TEXT = . ;
	}>FLASH
	             		
	.data : {
	_S_DATA = . ;
		*(.data)
		*(.rodata*)
		. = ALIGN(4);
	_E_DATA = . ;

	}>FLASH
						
	.bss : {
	. = ALIGN(4);
	_S_BSS = . ;
	*(.bss)
	_E_BSS = . ;
	. = ALIGN(4);
	. = . + 0x1000 ;
	stack_top = . ;
	}>SRAM		

}