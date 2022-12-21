/*
 * botton.c
 *
 * Created: 09/12/2022 04:34:22 م
 *  Author: mohdammad samy
 */ 

#include "botton.h"

//botton initialization
void BUTTON_init(uint8_t buttonPort,uint8_t buttonPin)
{
	DIO_init(buttonPort,buttonPin,IN);   //botton is input device
}

// button read
void BUTTON_read(uint8_t buttonPort,uint8_t buttonPin,uint8_t *value)
{
	DIO_read(buttonPort,buttonPin,value);

}


