/*
 * interrupts.h
 *
 * Created: 09/12/2022 04:38:53 م
 *  Author: mohammad samy
 */ 


#ifndef INTERRUPTS_H_
#define INTERRUPTS_H_

#include "registers.h"

//Interrupt vectors
#define EXT_INT_0 __vector_1
#define EXT_INT_1 __vector_2


#define sei()  __asm__ __volatile__ ("sei" ::: "memory")  //enable interrupts function
#define cli()  __asm__ __volatile__ ("cli" ::: "memory")  //clear interrupts function

//Rising edge
#define RISING_EDGE_SETUP() MCUCR|= (1<<1) | (1<<0)  //set isc00=1 isc01=1 (interrupt sense >>rising edge)


#define SETUP_INT0() GICR|=(1<<6)  //to enable external interrupt INT0


//ISR macro (interrupt service routine)
#define ISR(INT_VECT) \
void INT_VECT(void) __attribute__ ((signal,used)); \
void INT_VECT(void)



#endif /* INTERRUPTS_H_ */