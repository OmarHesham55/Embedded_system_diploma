/*
linker file 
*/


MEMORY
{
	FLASH (RX) : ORIGIN = 0x08000000 , LENGTH = 128K
	SRAM (RWX) : ORIGIN = 0x20000000 , LENGTH = 20K
}

SECTIONS
{
	.text : {
		*(.vectors*)
		*(.text*)
		*(.rodata)
		_E_TEXT = . ;
	}>FLASH
	             		
	.data : {
	_S_DATA = . ;
		*(.data)
	_E_DATA = . ;
	}>FLASH
						/* >SRAM AT> FLASH===== bas hena me7tagen nekteb fy el startup copy data mn FLASH lyl SRAM   */
	.bss : {
	_S_BSS = . ;
		*(.bss)
	. = ALIGN(4);
	_E_BSS = . ;
	. = ALIGN(4);
	. = . + 0x1000 ;
	_stack_top = . ;
	}>SRAM					/* hena kda kda mafeesh bss fy el flas fa run/load at SRAM */
}