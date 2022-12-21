/*
 * led.h
 *
 * Created: 09/12/2022 04:35:41 م
 *  Author: MOHAMMAD SAMY
 */ 


#ifndef LED_H_
#define LED_H_

#include "../../MCAL/Dio/dio.h" //dio.h



// define car traffic led port and pins

#define CAR_LED_PORT PORT_A
#define CAR_LED_PIN_Gr PIN0    //for green led
#define CAR_LED_PIN_Ye PIN1    //for yellow led
#define CAR_LED_PIN_Re PIN2     //for red led

// define pedestrian traffic led port and pins
#define PED_LED_PORT PORT_B
#define PED_LED_PIN_Gr PIN0
#define PED_LED_PIN_Ye PIN1
#define PED_LED_PIN_Re PIN2


//led functions
void LED_init(uint8_t ledPort,uint8_t ledPin);  //to initialize led
void LED_on(uint8_t ledPort,uint8_t ledPin);    //to turn on the led
void LED_off(uint8_t ledPort,uint8_t ledPin);    //to turn off the led
void LED_toggle(uint8_t ledPort,uint8_t ledPin);   //to toggle the led



#endif /* LED_H_ */