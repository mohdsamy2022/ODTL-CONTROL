/*
 * led.c
 *
 * Created: 09/12/2022 04:35:26 م
 *  Author: mohammad samy
 */ 

#include "led.h"



void LED_init(uint8_t ledPort,uint8_t ledPin)
{
	DIO_init(ledPort,ledPin,OUT);      //led is output device
}
void LED_on(uint8_t ledPort,uint8_t ledPin)
{
	DIO_write(ledPort,ledPin,HIGH);  //high to turn on the led
}
void LED_off(uint8_t ledPort,uint8_t ledPin)
{
	DIO_write(ledPort,ledPin,LOW);     //low to turn the led off
}
void LED_toggle(uint8_t ledPort,uint8_t ledPin)
{
	DIO_toggle(ledPort,ledPin);        //to toggle the led
}