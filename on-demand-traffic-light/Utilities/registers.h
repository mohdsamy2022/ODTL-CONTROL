/*
 * registers.h
 *
 * Created: 09/12/2022 04:38:28 م
 *  Author: mohdammad samy
 */ 


#ifndef REGISTERS_H_
#define REGISTERS_H_

#include "types.h"


//define port pins
#define PIN0 0
#define PIN1 1
#define PIN2 2
#define PIN3 3
#define PIN4 4
#define PIN5 5
#define PIN6 6
#define PIN7 7

// define  dio registers (from data sheet)
//portA registers
#define PORTA (*(volatile uint8_t*)(0x3B))  //port register
#define DDRA (*(volatile uint8_t*)(0x3A))   //data direction register
#define PINA (*(volatile uint8_t*)(0x39))   //port input register

//PortB registers
#define PORTB (*(volatile uint8_t*)(0x38))
#define DDRB (*(volatile uint8_t*)(0x37))
#define PINB (*(volatile uint8_t*)(0x36))

//PortC registers
#define PORTC (*(volatile uint8_t*)(0x35))
#define DDRC (*(volatile uint8_t*)(0x34))
#define PINC (*(volatile uint8_t*)(0x33))

//PortD registers
#define PORTD (*(volatile uint8_t*)(0x32))
#define DDRD (*(volatile uint8_t*)(0x31))
#define PIND (*(volatile uint8_t*)(0x30))

//timer registers
#define TCCR0 (*(volatile uint8_t*)(0x53))
#define TCNT0 (*(volatile uint8_t*)(0x52))
#define TIFR (*(volatile uint8_t*)(0x58))
#define TIMSK (*(volatile uint8_t*)(0x59))


//interrupt registers
#define SREG (*(volatile uint8_t*)(0x5F))
#define GICR (*(volatile uint8_t*)(0x5B))
#define MCUCR (*(volatile uint8_t*)(0x55))




#endif /* REGISTERS_H_ */