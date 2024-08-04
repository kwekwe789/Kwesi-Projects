#include "stm32f4xx.h"
#include "gpio.h"
#include "sevenseg.h"
#include "init.h"
#include "sevensegFunctions.h"

int main(void)
{
	init(); //Initialization of peripherals including the keypad leds 7 segment and timer
	initLED();
	initIRQ();
	initKey();
	initTimer();

	gpio_ON('b',0); //gives initial power to the C pins of the keypad
	gpio_ON('c',1);
	gpio_ON('a',1);
	gpio_ON('a',4);
	segment(1,0);  	//gives initial value of 0 to 7 segment to display when code is first run
	segment(2,0);
	segment(3,0);
	segment(4,0);

	while(1)
	{
		gpio_ON('b',0); //power is resupplied to C pins of the keypad after returning from interrupt
		gpio_ON('c',1);
		gpio_ON('a',4);
		if(Mode==0) //the different modes of the display are set here, mode changes with a button push
		{
			segment(4,sec1); //mode is for the stopwatch
			segment(3,sec2);
			segment(2,min1);
			segment(1,min2);
			numSing(milsec);

		}
		else if(Mode==1)
		{
			segment(1,temp1);//mode is for the countdown
			segment(2,temp2);
			segment(3,temp3);
			segment(4,temp4);
			numSing(milsec);
		}
		else if(Mode==2)
		{
			segment(1,0); //mode is for blinking of zeros
			segment(2,0);
			segment(3,0);
			segment(4,0);
		}
		else if(Mode==3) //mode for turning off display
		{

		}
	}
}

