/*
 * boot.c
 *
 *  Created on: Sep 24, 2020
 *      Author: embeddedfab
 */

#include "boot.h"



ISR (USART_RXC_vect)
{
	unsigned char oldsrg = SREG,rec_char=0;
	cli();
	 rec_char= UDR;
	 if(rec_char=='s')  uart_received_word_counter=0;
	 uart_received_word[uart_received_word_counter++]=rec_char;
	if(uart_received_word_counter == DEFAULT_WORD_SIZE)
	{
		uart_received_word_counter = 0; //pointer = 0;
	}
	SREG = oldsrg;

	if(strstr((const char *)uart_received_word,(const char *)START_BOOT_WORD) != 0)
	{
		eeprom_write_byte((uint8_t *)BOOT_LOADER_FLAG_ADDRESS,TRUE);

		UART_SEND_string(" \r\n now the device will be restarted to start boot loader \r\n");
		WDT_ON();
       while(1);

	}



}


void WDT_off(void)
{

wdt_reset();
WDTCR |= (1<<4) | (1<<3);
WDTCR = 0x00;

}

void WDT_ON(void)
{

	wdt_reset();
	WDTCR = (1<<WDE)|(1<<WDP0)|(1<<WDP1)|(1<<WDP2);

}

