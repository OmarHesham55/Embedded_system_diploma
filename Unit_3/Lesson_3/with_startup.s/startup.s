/*
	startup_cortexM3.s
	Eng.Omar Hesham
*/


/* SRAM: 0x20000000 */

.section .vectors
.word 0x20001000	// stack address
.word _reset        // reset address
.word vector_handler // NMI
.word vector_handler // hard_fault_handler
.word vector_handler // MemManage
.word vector_handler // BusFault
.word vector_handler // Usage Fault
.word vector_handler // Reserved
.word vector_handler // Reserved
.word vector_handler // Reserved
.word vector_handler // Reserved
.word vector_handler // SV Call
.word vector_handler //
.word vector_handler //

.section .text
_reset:
	bl main
	b .

.thumb_func
vector_handler:
	b _reset

