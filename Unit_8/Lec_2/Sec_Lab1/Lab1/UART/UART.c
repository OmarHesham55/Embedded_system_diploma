/*
 * UART.c
 *
 * Created: 3/26/2023 3:24:38 PM
 *  Author: omart
 */ 


#include "UART.h"

void UART_INIT(void)
 {
 	/*Set the baud rate:0d51*/
 	UBRRL = 0x33;
 	
 	/*Set frame format::
 		**to use UCSRC register set the URSEL:1
 	*/
 	
 	//1- Odd Parity bit 
	UCSRC |= (0b11<<4);
	
 	//2-Stop bit
	UCSRC &= ~(1<<3);
 	
 	//3-Data frame
 	UCSRC |= (1<<7) | (1<<1) | (1<<2);
	 
 	/*Enable Rx/Tx*/
 	UCSRB |= (1<<4) | (1<<3);	
 }
 
 void UART_Tx(unsigned char data)
 {
 	while(!(UCSRA & (1<<5)));
 	UDR = data;
 }
 uint8_t UART_Rx(void)
 {
 	while(!(UCSRA &(1<<7)));
 	return(UDR);
 }
 
 
 void UART_Tx_String(uint8_t* data)
 {
	 uint8_t j=0;
	 while(data[j]){
	 UART_Tx(*data);
	 data++;
	 }
 }
 
 void UART_Rx_String(uint8_t* data)
 {
	 *data = UART_Rx();
	 while (*data && *data != '\r')
	 {
		 data++;
		 *data = UART_Rx();
	 }
	 *data = 0;
 }
 
 void UART_Tx_Num(uint32_t num)
 {
	uint32_t n = num;
	char intString[10]; // String buffer

	// Convert integer to string
	snprintf(intString, sizeof(intString), "%d", n);

	// Send the string via UART
	UART_Tx_String(intString);


// 	uint8_t* P = &num;
// 	UART_Tx(P[0]);
// 	UART_Tx(P[1]);
// 	UART_Tx(P[2]);
// 	UART_Tx(P[3]);
 }
 
 uint32_t UART_Rx_Num(void)
 {
	 uint32_t num;
	 uint8_t* Pntr = &num;
	 
	 Pntr[0] = UART_Rx();
	 Pntr[1] = UART_Rx();
	 Pntr[2] = UART_Rx();
	 Pntr[3] = UART_Rx();
	 return num;
 }
 
void uart_receive_string_until_enter(char *str, uint8_t maxLen) {
	uint8_t i = 0;
	char receivedChar;

	do {
		receivedChar = UART_Rx();
		str[i++] = receivedChar;
	} while (receivedChar != '\r' && i < maxLen - 1);

	str[i - 1] = '\0'; // Null-terminate the string
}