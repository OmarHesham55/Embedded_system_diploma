/*
 * main.c
 *
 *  Created on: Sep 27, 2022
 *      Author: omart
 */
#include <string.h>
#include "uart.h"
#include <stdio.h>
unsigned char tx_string[100] = "omar hesham";
int main(){
	printf("Enter a sentence.....");
	printf("\n you entered");
	rx_string(tx_string);
	return 0;
}

