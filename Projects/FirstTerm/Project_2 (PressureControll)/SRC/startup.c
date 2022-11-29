#include <stdint.h>

extern int main(void);
extern uint32_t _S_TEXT;
extern uint32_t _E_TEXT;
extern uint32_t _S_DATA;
extern uint32_t _E_DATA;
extern uint32_t _S_BSS;
extern uint32_t _E_BSS;
extern uint32_t stack_top;

void Default_handler(void);
void reset_handler(void);
void NMI_handler(void) __attribute__((weak, alias ("Default_handler")));;
void H_fault_handler(void) __attribute__((weak, alias ("Default_handler")));;
void MM_fault_handler(void) __attribute__((weak, alias ("Default_handler")));;
void Bus_fault_handler(void) __attribute__((weak, alias ("Default_handler")));;
void Usage_fault_handler(void) __attribute__((weak, alias ("Default_handler")));;
 

uint32_t vectors[] __attribute__((section(".vectors"))) = {
	(uint32_t) &stack_top,
	(uint32_t) &reset_handler,
	(uint32_t) &NMI_handler,
	(uint32_t) &H_fault_handler,
	(uint32_t) &MM_fault_handler,
	(uint32_t) &Bus_fault_handler,
	(uint32_t) &Usage_fault_handler,
};

void Default_handler(void){
	reset_handler();
}

void reset_handler(void){
	//copy data byte by byte from rom to ram
	uint32_t DATA_size = (uint8_t*)&_E_DATA - (uint8_t*)&_S_DATA;
	uint8_t* P_src = (uint8_t*)&_E_TEXT;
	uint8_t* P_dst = (uint8_t*)&_S_DATA;
	for(int i=0; i<DATA_size;i++){
		*((uint8_t*)P_dst++) = *((uint8_t*)P_src++);
	}

	//init bss with zero
	uint32_t bss_size = (uint8_t*)&_E_BSS - (uint8_t*)&_S_BSS;
	P_dst = (uint8_t*)&_S_BSS;
	for(int i=0; i<bss_size; i++){
		*((uint8_t*)P_dst++) = (uint8_t)0;
	}

	//jump to main 
	main();
}
