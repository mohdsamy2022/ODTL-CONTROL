/*
 * timer.c
 *
 * Created: 09/12/2022 04:35:56 م
 *  Author: DELL
 */ 


#include "timer.h"
#include <math.h>
#include "../../Utilities/bitman.h"

void TIMER_init()
{
	TCCR0 = 0x00; //normal mode
}
void TIMER_delay(uint16_t Tdelay)
{
	uint16_t Noverflows;  //define variables
	uint16_t TimerInitial;
	double Tmaxdelay;
	double Ttick;
	uint32_t overFlowcount=0;


	Ttick = 256.0/1000.0;    //ms    Ttick = Presc/FCPU    prescaler=256
	Tmaxdelay= 65.536;      //ms		Tmaxdelay = Ttick * 2^8
	if(Tdelay<Tmaxdelay)
	{
		TimerInitial = (Tmaxdelay-Tdelay)/Ttick;
		Noverflows = 1;    //no overflow case
		
		}
		else if(Tdelay == (int)Tmaxdelay)
		{
		TimerInitial=0;
		Noverflows=1;   //no overflow case
		}
		else
		{
		Noverflows = ceil((double)Tdelay/Tmaxdelay);                 //overflow case
		TimerInitial = (1<<8) - ((double)Tdelay/Ttick)/Noverflows;   //timer initial= 2^8 - ((Tdelay/Ttick)/Noverflows)
		
	}
	TCNT0 = TimerInitial;
	TCCR0 |= (1<<2);     //set 256 prescaler
	while(overFlowcount<Noverflows)
	{
		//busy wait
		while(READ_BIT(TIFR,0)==0);   //TIFR (time interrupt flag register)
		//clear overflow flag
		SET_BIT(TIFR,0);
		
		overFlowcount++;  //increment counter
	}
	//Timer stop
	TCCR0 = 0x00;
}