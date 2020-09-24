/*
 * main.c
 *
 *  Created on: Oct 31, 2019
 *      Author: embeddedfab
 */


/*
 *
 *      This Code used to move motor for both direction with delay
 *      to check the circuit without trigger
 *      for ATMEGA8
 *       29/7/2020
 *
 * in this release we changed to internal reference 1.1
 * after we added to resistors 4.7k and 10k as a voltage divider
 *so the input voltage will be multiply 0.319
 *
 */





#include"boot.h"
#include"MCAL/UART.h"
#include"util/delay.h"



int main()
{


	WDT_off();
	init_UART() ;
	sei();
	UART_SEND_string("\r\n start main prog");




	while(1)
	{

		UART_SEND_string("\r\n hello from main prog");
		_delay_ms(1000);

	}
	return 0;
}


