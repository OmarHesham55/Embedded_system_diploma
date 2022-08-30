#include "uart.h"
unsigned char string_buffer[100] = "Learn_in_depth:Omar Hesham";

void main(void){
	uart_send_string(string_buffer);
}