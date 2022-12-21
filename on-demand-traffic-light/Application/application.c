/*
 * application.c
 *
 * Created: 09/12/2022 05:12:23 م
 *  Author: DELL
 */ 
#include "../Utilities/bitman.h"
#include "application.h"
//define carled variable  (0 = green /1 = yellow / 2 = red)
uint8_t carLED=0; 
uint8_t prevcarLED=1;   
//define normal mode variable (1=normal mode /0= pedestrian mode)
uint8_t normalmode = 1; 
void APP_init(void)
{
	
	//initialize car led ports and pins
	LED_init(CAR_LED_PORT,CAR_LED_PIN_Gr);
	LED_init(CAR_LED_PORT,CAR_LED_PIN_Ye);
	LED_init(CAR_LED_PORT,CAR_LED_PIN_Re);
	
	//initialize pedestrian led ports and pins
	LED_init(PED_LED_PORT,PED_LED_PIN_Gr);
	LED_init(PED_LED_PORT,PED_LED_PIN_Ye);
	LED_init(PED_LED_PORT,PED_LED_PIN_Re);
	
	//Button initialization
	BUTTON_init(BUTTON_1_PORT,BUTTON_1_PIN);
    /*int pressed=0,pressed_CL=0,pressed_RL=0;
	while(1)
	{
		if(CLEAR_BIT(PIND,PIN2))
		{
			if(pressed==0)
			{
				
			}
		}
	}
	*/
	//Timer initialization
	TIMER_init();
	
	
	sei();                     //enable global interrupts
	RISING_EDGE_SETUP();     //rising edge sense
	

	//normalmode=0;
	//SETUP_INT0();            //enable external interrupts INT0
}
void APP_start(void)
{
		#define BIT_IS_CLEAR(byte, bit) (!(byte & (1 << bit)))
		#define BIT_IS_SET(byte, bit) (byte & (1 << bit))
		#define button_debounce 20 //ms
		uint16_t timer = 0;
		while(BIT_IS_SET(PIND, PIN2))
		{ // button hold down
			timer++; // count how long button is pressed
			TIMER_delay(1);
		}
		if(timer > button_debounce)
		{                        // software debouncing button
			if(timer < 500)
			{                       //unsigned long
				//single click
				//DIO_write(PIND,PIN2,HIGH);
				SETUP_INT0();
				//LED_on(PED_LED_PORT,PED_LED_PIN_Gr);
				timer=0;
			}
			else
			{
				//button hold
				//DIO_write(PIND,PIN2,LOW);
				//timer=0;
			}

		}
	//if normal mode or  car green led or yellow is on
	uint8_t i;
	if(normalmode || carLED==0 || carLED==1)  //green=0 yellow=1
	{
		if(!normalmode)
		{
			carLED=1;
		}
		//set Pedestrian LEDs
		LED_off(PED_LED_PORT,PED_LED_PIN_Gr);
		LED_off(PED_LED_PORT,PED_LED_PIN_Ye);
		//LED_off(PED_LED_PORT,PED_LED_PIN_Re);  //ped red led remain on
		
		switch(carLED)
		{
			
			case 0: //green led
			LED_on(CAR_LED_PORT,CAR_LED_PIN_Gr);
			LED_off(CAR_LED_PORT,CAR_LED_PIN_Ye);
			LED_off(CAR_LED_PORT,CAR_LED_PIN_Re);
			
			for(i=0;i<50;i++)
			{
				TIMER_delay(60);
				if(!normalmode)break;         //check  ISR 
			}
			carLED=1;
			prevcarLED=0;
			break;
			
			case 1:  //yellow led
			
			if(!normalmode)
			{                    //blink yellow in car & pedestrian
				if(prevcarLED!=2)
				{
					LED_on(PED_LED_PORT,PED_LED_PIN_Re);
					
					for(i=0;i<5;i++){
						LED_on(CAR_LED_PORT,CAR_LED_PIN_Ye);  //blinking every second
						LED_on(PED_LED_PORT,PED_LED_PIN_Ye);
						TIMER_delay(400);
						LED_off(CAR_LED_PORT,CAR_LED_PIN_Ye);
						LED_off(PED_LED_PORT,PED_LED_PIN_Ye);
						TIMER_delay(200);
						LED_on(CAR_LED_PORT,CAR_LED_PIN_Ye);
						LED_on(PED_LED_PORT,PED_LED_PIN_Ye);
						TIMER_delay(400);
					}
				}
				prevcarLED=1;
				carLED=2;
				LED_on(CAR_LED_PORT,CAR_LED_PIN_Re);
				}else{
				//blink car yellow led
				for(i=0;i<5;i++){
					LED_on(CAR_LED_PORT,CAR_LED_PIN_Ye);
					TIMER_delay(400);
					LED_off(CAR_LED_PORT,CAR_LED_PIN_Ye);
					TIMER_delay(200);
					LED_on(CAR_LED_PORT,CAR_LED_PIN_Ye);
					TIMER_delay(400);
					if(!normalmode)
					{                //check  ISR 
						prevcarLED=1;
						break;
					}
				}
			}
			LED_off(CAR_LED_PORT,CAR_LED_PIN_Ye);
			LED_off(PED_LED_PORT,PED_LED_PIN_Ye);
			
			if(prevcarLED==0)
			{
				carLED=2;
				prevcarLED=1;
				}
				else if(prevcarLED==2)
				{
				carLED=0;
				prevcarLED=1;
			}
			break;
			//Case RED LED
			case 2:
			LED_off(CAR_LED_PORT,CAR_LED_PIN_Gr);
			LED_off(CAR_LED_PORT,CAR_LED_PIN_Ye);
			LED_on(CAR_LED_PORT,CAR_LED_PIN_Re);
			for(i=0;i<50;i++)
			{
				TIMER_delay(60);
				if(!normalmode)break;
			}
			prevcarLED=2;
			carLED=1;
			break;
			default:
			carLED=2;
			prevcarLED=1;
			break;
		}
		
		}
		else
		{
		//Configure PED LEDs
		LED_on(PED_LED_PORT,PED_LED_PIN_Gr);
		LED_off(PED_LED_PORT,PED_LED_PIN_Ye);
		LED_off(PED_LED_PORT,PED_LED_PIN_Re);
		
		//Configure CAR LEDs
		LED_off(CAR_LED_PORT,CAR_LED_PIN_Gr);
		LED_off(CAR_LED_PORT,CAR_LED_PIN_Ye);
		LED_on(CAR_LED_PORT,CAR_LED_PIN_Re);
		TIMER_delay(5000);                      //5 sec delay
		
		//make sure car red light is off
		LED_off(CAR_LED_PORT,CAR_LED_PIN_Re);
		
		//blink both yellow while ped green is on
		for(i=0;i<5;i++){
			LED_on(CAR_LED_PORT,CAR_LED_PIN_Ye);
			LED_on(PED_LED_PORT,PED_LED_PIN_Ye);
			TIMER_delay(400);
			LED_off(CAR_LED_PORT,CAR_LED_PIN_Ye);
			LED_off(PED_LED_PORT,PED_LED_PIN_Ye);
			TIMER_delay(200);
			LED_on(CAR_LED_PORT,CAR_LED_PIN_Ye);
			LED_on(PED_LED_PORT,PED_LED_PIN_Ye);
			TIMER_delay(400);
		}
		//Turn off yellow LEDs
		LED_off(CAR_LED_PORT,CAR_LED_PIN_Ye);
		LED_off(PED_LED_PORT,PED_LED_PIN_Ye);
		//turn on PED red LED
		LED_on(PED_LED_PORT,PED_LED_PIN_Re);
		//reset normalmode
		normalmode=1;
		//Configure carLED variables
		carLED=0;
		prevcarLED=1;
	}
	
}

/*ISR(EXT_INT_0)
{
LED_on(PED_LED_PORT,PED_LED_PIN_Gr);
LED_on(PED_LED_PORT,PED_LED_PIN_Ye);
LED_on(PED_LED_PORT,PED_LED_PIN_Re);	
}*/

//#define BIT_IS_CLEAR(byte, bit) (!(byte & (1 << bit)))
//#define BIT_IS_SET(byte, bit) (byte & (1 << bit))
//#define button_debounce 10 //ms
ISR(EXT_INT_0)
{
	
	normalmode=0;
	/*if(normalmode)
	{
		uint16_t timer = 0;
		while(BIT_IS_SET(PIND, PIN2))
		{ // button hold down
			timer++; // count how long button is pressed
			TIMER_delay(1);
		}
		if(timer > button_debounce)
		{                        // software debouncing button
			if(timer < 1000UL)
			{                       //unsigned long
				//single click
				normalmode=0;
				//LED_on(PED_LED_PORT,PED_LED_PIN_Gr);
				//timer=0;
			}
			else
			{
				//button hold
				normalmode=1;
				//timer=0;
			}

		}
		//normalmode=0;
	}*/
	
		  }





	  