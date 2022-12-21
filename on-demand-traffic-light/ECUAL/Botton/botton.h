/*
 * botton.h
 *
 * Created: 09/12/2022 04:34:35 م
 *  Author: mohammad samy
 */ 


#ifndef BOTTON_H_
#define BOTTON_H_

#include "../../MCAL/Dio/dio.h"

//define button port and pins
#define BUTTON_1_PORT PORT_D
#define BUTTON_1_PIN PIN2


//initialize button function
void BUTTON_init(uint8_t buttonPort,uint8_t buttonPin);

// read button function
void BUTTON_read(uint8_t buttonPort,uint8_t buttonPin,uint8_t *value);

void BUTTON_write(uint8_t buttonPort,uint8_t buttonPin,uint8_t value);

#endif /* BOTTON_H_ */