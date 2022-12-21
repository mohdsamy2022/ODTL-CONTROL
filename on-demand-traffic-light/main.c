/*
 * on-demand-traffic-light.c
 *
 * Created: 09/12/2022 04:19:39 م
 * Author : DELL
 */ 

//#include <avr/io.h>
 //#include <avr/sfr_defs.h>
#include "Application/application.h"



int main(void)
{
	//Initialize
	APP_init();
	
	//while loop
	while(1)
	{
		APP_start();
	}
}



//testing
/*
int main(void)
{
BUTTON_init(BUTTON_1_PORT,BUTTON_1_PIN);
LED_init(CAR_LED_PORT,CAR_LED_PIN_Gr);
LED_init(CAR_LED_PORT,CAR_LED_PIN_Ye);
LED_init(CAR_LED_PORT,CAR_LED_PIN_Re);
LED_init(PED_LED_PORT,PED_LED_PIN_Gr);
LED_init(PED_LED_PORT,PED_LED_PIN_Ye);
LED_init(PED_LED_PORT,PED_LED_PIN_Re);
TIMER_init();
uint8_t value;
while(1)
{
BUTTON_read(BUTTON_1_PORT,BUTTON_1_PIN,&value);
if(value==HIGH)
{
LED_toggle(CAR_LED_PORT,CAR_LED_PIN_Gr);
LED_toggle(CAR_LED_PORT,CAR_LED_PIN_Ye);
LED_toggle(CAR_LED_PORT,CAR_LED_PIN_Re);
LED_on(PED_LED_PORT,PED_LED_PIN_Gr);
TIMER_delay(500);
LED_off(PED_LED_PORT,PED_LED_PIN_Gr);
TIMER_delay(500);
LED_on(PED_LED_PORT,PED_LED_PIN_Ye);
TIMER_delay(500);
LED_off(PED_LED_PORT,PED_LED_PIN_Ye);
TIMER_delay(500);
LED_on(PED_LED_PORT,PED_LED_PIN_Re);
TIMER_delay(500);
LED_off(PED_LED_PORT,PED_LED_PIN_Re);
TIMER_delay(500);


}
else
{
//LED_on(CAR_LED_PORT,CAR_LED_PIN_Re);
}

}
}

*/