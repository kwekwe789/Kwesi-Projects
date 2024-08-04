#include "interrupt.h"
#include "gpio.h"


void TIM2_IRQHandler(void) //timer 2 interrupt handler
{
	TIM2->SR &=~(1U<<0); //resets the status register
	if(Mode==0) //calls a function based on the mode of the display
	{
		upSeg();
		return;
	}
	if(timer==1)
	{
		downSeg();

	}
	if(Mode==2)
	{
		blink();
	}
}

void TIM3_IRQHandler(void) //timer 3 interrupt handler
{
	TIM3->SR &=~(1U<<0); //resets the status register

	if(Mode==0) //calls a function based on the mode of the display
	{
		upSingSeg();
		return;
	}
	if(timer==1)
	{
		downSingSeg();
		return;
	}
}


void EXTI15_10_IRQHandler(void) //interrupt handler for the gpio pins
{
	if((EXTI->PR & (1U<<13)) !=0 ) //if pc13 is pressed the clock is toggled
	{
		EXTI->PR |= (1U<<13);
		TIM2->CR1 ^= (1U<<0);
		TIM3->CR1 ^= (1U<<0);
	}
}

void EXTI9_5_IRQHandler(void)
{
	if((EXTI->PR & (1U<<8)) !=0 )//an input is received from the first column and that function is called
	{

		EXTI->PR |= (1U<<8);
		column1();
	}
}

void EXTI3_IRQHandler(void)
{
	if((EXTI->PR & (1U<<3)) !=0 )//an input is received from the second column and that function is called
	{
		EXTI->PR |= (1U<<3);
		column2();
	}
}

void EXTI2_IRQHandler(void)
{
	if((EXTI->PR & (1U<<2)) !=0 )//an input is received from the third column and that function is called
	{
		EXTI->PR |= (1U<<2);
		column3();
	}
}

void EXTI0_IRQHandler(void)//an input is received from the fourth column and that function is called
{
	if((EXTI->PR & (1U<<0)) !=0 )
	{
		EXTI->PR |= (1U<<0);
		column4();
	}
}

void column1(void)
{
	gpio_OFF('b',0);  //turns off the power to the last 3 rows
	gpio_OFF('a',1);
	gpio_OFF('a',4);
	if(GPIOB->IDR & (1U<<8)) //checks if the column still receives input
	{
		if(Mode==1) // calls the function to display the the corresponding number on the display
		{
			placeHolder(x,1);
			x++;
		}
		delay(100);
		return;
	}
	gpio_ON('b',0);

	if(GPIOB->IDR & (1U<<8))
	{
		if(Mode==1)
		{
			placeHolder(x,2);
			x++;
		}
		delay(100);
		return;
	}
	gpio_ON('a',4);
	if(GPIOB->IDR & (1U<<8))
	{
		if(Mode==1)
		{
			placeHolder(x,3);
			x++;
		}
		delay(100);
		return;
	}
	gpio_ON('a',1);
	if(GPIOB->IDR & (1U<<8))
	{
		TIM2->CR1 &=~ (1U<<0); //changes the mode of the display to the stopwatch
		TIM3->CR1 &=~ (1U<<0);
		sec1=0;
		sec2=0;
		min1=0;
		min2=0;
		milsec=0;
		Mode=0;
		return;
	}
}

void column2(void)
{

	gpio_OFF('b',0);
	gpio_OFF('a',1);
	gpio_OFF('a',4);
	if(GPIOC->IDR & (1U<<3))
	{
		if(Mode==1)
		{
			placeHolder(x,4);
			x++;
		}
		delay(100);
		return;
	}
	gpio_ON('b',0);

	if(GPIOC->IDR & (1U<<3))
	{
		if(Mode==1)
		{
			placeHolder(x,5);
			x++;
		}
		delay(100);
		return;
	}
	gpio_ON('a',4);
	if(GPIOC->IDR & (1U<<3))
	{
		if(Mode==1)
		{
			placeHolder(x,6);
			x++;
		}
		delay(100);
		return;
	}
	gpio_ON('a',1);
	if(GPIOC->IDR & (1U<<3))
	{
		Mode = 1;
		milsec=0;
		return;
	}
}

void column3(void)
{
	gpio_OFF('b',0);
	gpio_OFF('a',1);
	gpio_OFF('a',4);
	if(GPIOC->IDR & (1U<<2))
	{
		if(Mode==1)
		{
			placeHolder(x,7);
			x++;
		}
		delay(100);
		return;
	}
	gpio_ON('b',0);

	if(GPIOC->IDR & (1U<<2))
	{
		if(Mode==1)
		{
			placeHolder(x,8);
			x++;
		}
		delay(100);
		return;
	}
	gpio_ON('a',4);
	if(GPIOC->IDR & (1U<<2))
	{
		if(Mode==1)
		{
			placeHolder(x,9);
			x++;
		}
		delay(100);
		return;
	}
	gpio_ON('a',1);
	if(GPIOC->IDR & (1U<<2))
	{
		Mode=3;
		return;
	}
}

void column4(void)
{
	gpio_OFF('b',0);
	gpio_OFF('a',1);
	gpio_OFF('a',4);
	if(GPIOC->IDR & (1U<<0))
	{
		if(Mode==1)
		{
			temp1=0;
			temp2=0;
			temp3=0;
			temp4=0;
			x=0;
		}
		delay(100);
		return;
	}
	gpio_ON('b',0);

	if(GPIOC->IDR & (1U<<0))
	{
		if(Mode==1)
		{
			placeHolder(x,0);
			x++;
		}
		delay(100);
	}
	gpio_ON('a',4);
	if(GPIOC->IDR & (1U<<0))
	{
		if(countdownDone==1)
		{
			timer=0; //turns of the blinking mode of the display and resets the values of the timer
			TIM2->CR1 &= ~(1U<<0);
			TIM3->CR1 &= ~(1U<<0);
			gpio_OFF('b',9);
			gpio_OFF('b',7);
			countdownDone=0;
			Mode=1;
			x=0;
			delay(200);
			milsec=0;
			return;
		}
		timer=1;
		TIM2->CR1 ^= (1U<<0);
		TIM3->CR1 ^= (1U<<0);
		delay(100);
		milsec=9;
		return;
	}
	gpio_ON('a',1);
	if(GPIOC->IDR & (1U<<0))
	{
		EXTI->PR |= (1U<<13); //toggles the clock
	    TIM2->CR1 ^= (1U<<0);
		TIM3->CR1 ^= (1U<<0);
		delay(50);
		return;
	}
}


