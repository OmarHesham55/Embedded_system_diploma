/*
 * UART.h
 *
 * Created: 3/26/2023 3:24:49 PM
 *  Author: omart
 */ 


#ifndef UART_H_
#define UART_H_

#include <avr/io.h>

void UART_INIT(void);
void UART_Tx(uint8_t data);
uint8_t UART_Rx(void);
void UART_Tx_String(uint8_t* data);
void UART_Rx_String(uint8_t* data);
void UART_Tx_Num(uint32_t num);
uint32_t UART_Rx_Num(void);
void uart_receive_string_until_enter(char *str, uint8_t maxLen);
#endif /* UART_H_ */