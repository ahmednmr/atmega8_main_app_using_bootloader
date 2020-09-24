/*
 * boot.h
 *
 *  Created on: Sep 24, 2020
 *      Author: embeddedfab
 */

#ifndef BOOT_H_
#define BOOT_H_

#include <string.h>
#include<stdio.h>
#include"avr/interrupt.h"
#include <avr/wdt.h>
#include<avr/eeprom.h>
#include"MCAL/UART.h"

#define TRUE 				          1
#define FALSE         				  0
#define DEFAULT_WORD_SIZE             15
#define BOOT_LOADER_FLAG_ADDRESS      245
#define START_BOOT_WORD               "start boot"

volatile unsigned char uart_received_word[DEFAULT_WORD_SIZE];
volatile unsigned char uart_received_word_counter;
void WDT_off(void);
void WDT_ON(void);



#endif /* BOOT_H_ */
