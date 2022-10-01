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
	}>FLASH
	             		/* >VMA AT> LA*/    /* >SRAM AT> FLASH bas hena  */
	.rodata : {
		*(.rodata)
	}>FLASH

	.data : {
		*(.data)
	}>FLASH
						/* >SRAM AT> FLASH===== bas hena me7tagen nekteb fy el startup copy data mn FLASH lyl SRAM   */
	.bss : {
		*(.bss)
	}>SRAM					/* hena kda kda mafeesh bss fy el flas fa run/load at SRAM */
}