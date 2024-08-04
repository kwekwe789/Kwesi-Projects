/*
 * sevensegFunctions.c
 *
 *  Created on: Aug 4, 2024
 *      Author: kwkye
 */

#include "sevensegFunctions.h"


void segment(int digit, int number) //controls what is displayed on all four digits of the display
{
	gpio_ON('a',0);
	gpio_ON('a',5);
	gpio_ON('b',6);
	gpio_ON('a',8);

	if(digit == 1) //if the user input digit 1 of the display a pulse is sent to the pin that controls it as well as the pins that display the number inputted
	{
		gpio_OFF('a',5);
		num(number);
		gpio_ON('a',5);
	}
	else if(digit ==2)
	{
		gpio_OFF('b',6);
		num(number);
		dec();
		gpio_ON('b',6);
	}
	else if(digit ==3)
	{
		gpio_OFF('a',0);
		num(number);
		gpio_ON('a',0);
	}
	else
	{
		gpio_OFF('a',8);
		num(number);
		dec();
		gpio_ON('a',8);
	}
}


void num(int number) //calls a display function depending on the number that is inputted
{
	if(number==0)
	{
		seg0();
	}
	else if (number==1)
	{
		seg1();
	}
	else if (number==2)
	{
		seg2();
	}
	else if (number==3)
	{
		seg3();
	}
	else if (number==4)
	{
		seg4();
	}
	else if (number==5)
	{
		seg5();
	}
	else if (number==6)
	{
		seg6();
	}
	else if (number==7)
	{
		seg7();
	}
	else if (number==8)
	{
		seg8();
	}
	else if (number==9)
	{
		seg9();
	}
	else if (number==10)
	{
		segA();
	}
	else if (number==11)
	{
		segB();
	}
	else if (number==12)
	{
		segC();
	}
	else
	{
		segD();
	}
}

void numSing(int number)
{
	if(number==0)
	{
		singseg0();
	}
	else if (number==1)
	{
		singseg1();
	}
	else if (number==2)
	{
		singseg2();
	}
	else if (number==3)
	{
		singseg3();
	}
	else if (number==4)
	{
		singseg4();
	}
	else if (number==5)
	{
		singseg5();
	}
	else if (number==6)
	{
		singseg6();
	}
	else if (number==7)
	{
		singseg7();
	}
	else if (number==8)
	{
		singseg8();
	}
	else
	{
		singseg9();
	}
}

void upSeg(void) //function to count up on the display
{
	sec1++;
	if(sec1==10)
	{
		if(sec2==5)
		{
			sec1=0;
			sec2=0;
			min1++;
			if(min1==10)
			{
				min2++;
				min1=0;
			}
		}
		else
		{
			sec1=0;
			sec2++;
		}
	}
}

void upSingSeg(void)
{
	milsec++;
	if(milsec==10)
	{
		milsec=0;
	}

}

void downSeg(void) //function to count down on the display
{

	if(temp4==0&&temp3==0&&temp2==0&&temp1==0) //if all values of the timer are 0 go to the blink mode
	{
		Mode=2;
		countdownDone=1;
		timer=0;
		return;
	}

	temp4--; //every second this value is decremented
	if(x==4) //controls how the countdown works based on the timer of it
	{
		if(temp4==-1)
		{
			temp3--;
			temp4=9;
			if(temp3==-1)
			{
				temp2--;
				temp3=5;
				if(temp2==-1)
				{
					temp1--;
					temp2=9;
				}
			}
		}
	}
	else if(x==3)
	{
		if(temp4==-1)
		{
			temp3--;
			temp4=9;
			if(temp3==-1)
			{
				temp2--;
				temp3=5;
			}
		}
	}
	else if(x==2)
	{
		if(temp4==-1)
		{
			temp3--;
			temp4=9;
		}
	}
	else
	{
		if(temp4==0)
		{
			Mode=2;
			countdownDone=1;
			timer=0;
		}
	}

}

void downSingSeg(void)
{
	milsec--;
	if(milsec==-1)
	{
		milsec=9;
	}
}

void placeHolder(int x,int y) //when a number is inputted to the counted it shifts the numbers all ready there to the left 1
{
	if (x==0)
	{
		temp4=y;
	}
	else if(x==1)
	{
		temp3=temp4;
		temp4=y;
	}
	else if(x==2)
	{
		temp2=temp3;
		temp3=temp4;
		temp4=y;
	}
	else if(x==3)
	{
		temp1=temp2;
		temp2=temp3;
		temp3=temp4;
		temp4=y;
	}
	else
	{

	}
}


void blink(void) //blinks the display when the countdown reaches 0
{
	segment(1,20);
	segment(2,20);
	segment(3,20);
	segment(4,20);
	gpio_ON('h',1);
	gpio_OFF('b',7);
	gpio_OFF('b',12);
	gpio_OFF('b',2);
	gpio_OFF('b',14);
	gpio_OFF('b',13);
	gpio_OFF('c',4);
	gpio_OFF('b',1);
	delay(250);
	gpio_ON('b',7);
	gpio_OFF('h',1);
	gpio_ON('b',1);
	gpio_ON('b',12);
	gpio_ON('b',2);
	gpio_ON('b',14);
	gpio_ON('b',13);
	gpio_ON('c',4);
}
