/*
 * init.c
 *
 *  Created on: Jul 30, 2024
 *      Author: kwkye
 */

#include "init.h"

void initIRQ(void)
{
	IRQ_Initial('b',8,'r'); //initializes the pin for IRQ functionality and to trigger on the rising edge
	IRQ_Initial('c',3,'r');
	IRQ_Initial('c',2,'r');
	IRQ_Initial('c',0,'r');
	IRQ_Initial('c',13,'f');

	GPIOB->PUPDR &= ~(1U<<16);
	GPIOB->PUPDR |= (1U<<17);
	GPIOC->PUPDR &= ~(1U<<6);
	GPIOC->PUPDR |= (1U<<7);
	GPIOC->PUPDR &= ~(1U<<4);
	GPIOC->PUPDR |= (1U<<5);
	GPIOC->PUPDR &= ~(1U<<0);
	GPIOC->PUPDR |= (1U<<1);
}
void initKey(void) //initializes the keypad
{
	gpio_Output('c',1);
	gpio_Output('b',0);
	gpio_Output('a',1);
	gpio_Output('a',4);
}
void initLED(void) //initializes the LED
{
	gpio_Output('h',1);
	gpio_Output('b',7);
}
void initTimer(void) //Initializes the general purpose timers 1 hz and 10 hz
{
	RCC->APB1ENR |= (1U<<0); //enables clock access to timer 2
	RCC->APB1ENR |= (1U<<1); //enables clock access to timer 3
	TIM2->PSC = 1600 -1; //sets the prescaler to 1600
	TIM2->ARR = 10000-1; //set the auto reload to 10000
	TIM2->CNT = 0;
	TIM2->DIER |= (1U<<0);
	NVIC_EnableIRQ(TIM2_IRQn); //enables the timer for interrupts
	TIM3->PSC = 1600 -1;
	TIM3->ARR = 1000-1;
	TIM3->CNT = 0;
	TIM3->DIER |= (1U<<0);
	NVIC_EnableIRQ(TIM3_IRQn);

}
