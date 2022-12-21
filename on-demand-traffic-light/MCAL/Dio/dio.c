/*
 * DIO.c
 *
 * Created: 09/12/2022 04:31:04 م
 *  Author: mohammad samy
 */ 

#include "dio.h"

//define dio initialization function for ports A ,B ,C AND D

void DIO_init(uint8_t portNumber, uint8_t pinNumber, uint8_t direction)
{
	switch(portNumber)
	{
		case PORT_A:
			if(direction == IN){
				CLEAR_BIT(DDRA,pinNumber);
			}else if (direction == OUT){
				SET_BIT(DDRA,pinNumber);
			}
			else{}
			break;
		case PORT_B:
			if(direction == IN){
				CLEAR_BIT(DDRB,pinNumber);
			}else if (direction == OUT){
				SET_BIT(DDRB,pinNumber);
			}
			else{}
			break;
		case PORT_C:
			if(direction == IN){
				CLEAR_BIT(DDRC,pinNumber);
			}else if (direction == OUT){
				SET_BIT(DDRC,pinNumber);
			}
			else{}
			break;
		case PORT_D:
			if(direction == IN){
				CLEAR_BIT(DDRD,pinNumber);
			}else if (direction == OUT){
				SET_BIT(DDRD,pinNumber);
			}
			else{}
			break;
	}
}

//define DIO WRITE functions for port A ,B,C,D
void DIO_write(uint8_t portNumber, uint8_t pinNumber, uint8_t value)
{
	switch(portNumber){
		case PORT_A:
			if(value == LOW)
			{
				CLEAR_BIT(PORTA,pinNumber);
			}
			else if (value == HIGH)
			{
				SET_BIT(PORTA,pinNumber);
			}
			else{}
		break;
		case PORT_B:
			if(value == LOW)
			{
				CLEAR_BIT(PORTB,pinNumber);  //WRITE 0
			}
			else if (value == HIGH)
			{
				SET_BIT(PORTB,pinNumber);  //WRITE 1
			}
			else{	}
		break;
		case PORT_C:
			if(value == LOW)
			{
				CLEAR_BIT(PORTC,pinNumber);
			}
			else if (value == HIGH)
			{
				SET_BIT(PORTC,pinNumber);
			}
			else{}
		break;
		case PORT_D:
			if(value == LOW)
			{
				CLEAR_BIT(PORTD,pinNumber);
			}
			else if (value == HIGH)
			{
				SET_BIT(PORTD,pinNumber);
			}
			else{}
		break;
	}
}

//define DIO TOGGLE functions for port A ,B,C,D
void DIO_toggle(uint8_t portNumber, uint8_t pinNumber)
{
	switch(portNumber)
	{
		case PORT_A: TOGGLE_BIT(PORTA,pinNumber);    //TOGGLE BIT FOR BIT MANiPoLATION
		break;
		case PORT_B: TOGGLE_BIT(PORTB,pinNumber);
		break;
		case PORT_C: TOGGLE_BIT(PORTC,pinNumber);
		break;
		case PORT_D: TOGGLE_BIT(PORTD,pinNumber);
		break;
	}
}

//DEFINE DIO READ FUNCTION
void DIO_read(uint8_t portNumber, uint8_t pinNumber, uint8_t* value)
{
	switch(portNumber){
		case PORT_A:
			*value = READ_BIT(PINA,pinNumber);   //high & low values
		break;
		case PORT_B:
			*value = READ_BIT(PINB,pinNumber);
		break;
		case PORT_C:
			*value = READ_BIT(PINC,pinNumber);
		break;
		case PORT_D:
			*value = READ_BIT(PIND,pinNumber);
		break;
	}
}