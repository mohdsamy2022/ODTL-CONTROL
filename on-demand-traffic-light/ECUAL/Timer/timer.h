/*
 * timer.h
 *
 * Created: 09/12/2022 04:36:08 م
 *  Author: mohammad samy
 */ 


#ifndef TIMER_H_
#define TIMER_H_

#include "../../Utilities/registers.h"


void TIMER_init();//initialize Timer0
void TIMER_delay(uint16_t Tdelay);      //delay with 256 prescalar




#endif /* TIMER_H_ */