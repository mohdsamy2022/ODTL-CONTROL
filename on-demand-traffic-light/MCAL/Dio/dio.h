/*
 * DIO.h
 *
 * Created: 09/12/2022 04:31:26 م
 *  Author: mohammad samy
 */ 


#ifndef DIO_H_
#define DIO_H_

#include "../../Utilities/registers.h"
#include "../../Utilities/bitman.h"  //bit manipolation functions


#define PORT_A 'A'
#define PORT_B 'B'
#define PORT_C 'C'
#define PORT_D 'D'

//define directions
#define IN 0
#define OUT 1

//define values
#define LOW 0
#define HIGH 1


void DIO_init(uint8_t portNumber, uint8_t pinNumber, uint8_t direction);// dio direction initialization function
void DIO_write(uint8_t portNumber, uint8_t pinNumber, uint8_t value);   //write into dio function
void DIO_toggle(uint8_t portNumber, uint8_t pinNumber);                 //toggle dio  function
void DIO_read(uint8_t portNumber, uint8_t pinNumber, uint8_t* value);   //dio read function




#endif /* DIO_H_ */