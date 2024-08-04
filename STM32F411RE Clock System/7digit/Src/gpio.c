#include "gpio.h"

int timer=0; //variable declaration
int sec1=0;
int sec2=0;
int min1=0;
int min2=0;
int milsec=0;
int Mode=0;
int temp1=0;
int temp2=0;
int temp3=0;
int temp4=0;
int place=0;
int x=0;
int lock=0;
int countdownDone=0;



void delay(int d) //delay function
{
	for(; d>0;d--)
	{
		for(int i =0;i<3195;i++)
		{

		}
	}
}


void gpio_Output(char port, int pin) //function that configures each gpio port for output depending on the input
{
	int x = pin*2;
	int y= x+1;
	if(port == 'a')
	{
		RCC->AHB1ENR |= (1U<<0); //enables clock access to the port
		GPIOA->MODER |= (1U<<x); //sets the mode in the mode register
		GPIOA->MODER &= ~(1U<<y);
	}
	else if(port=='b')
	{
		RCC->AHB1ENR |= (1U<<1);
		GPIOB->MODER |= (1U<<x);
		GPIOB->MODER &= ~(1U<<y);
	}
	else if(port=='c')
	{
		RCC->AHB1ENR |= (1U<<2);
		GPIOC->MODER |= (1U<<x);
		GPIOC->MODER &= ~(1U<<y);
	}
	else if(port=='d')
	{
		RCC->AHB1ENR |= (1U<<3);
		GPIOD->MODER |= (1U<<x);
		GPIOD->MODER &= ~(1U<<y);
	}
	else if(port=='e')
	{
		RCC->AHB1ENR |= (1U<<4);
		GPIOE->MODER |= (1U<<x);
		GPIOE->MODER &= ~(1U<<y);
	}
	else
	{
		RCC->AHB1ENR |= (1U<<7);
		GPIOH->MODER |= (1U<<x);
		GPIOH->MODER &= ~(1U<<y);
	}

}
void gpio_ON(char port,int pin) //supplies power to the gpio port using bit set reset
{
		if(port == 'a')
		{
			GPIOA->BSRR |=(1U<<pin);
		}
		else if(port=='b')
		{
			GPIOB->BSRR |=(1U<<pin);
		}
		else if(port=='c')
		{
			GPIOC->BSRR |=(1U<<pin);
		}
		else if(port=='d')
		{
			GPIOD->BSRR |=(1U<<pin);
		}
		else if(port=='e')
		{
			GPIOE->BSRR |=(1U<<pin);
		}
		else
		{
			GPIOH->BSRR |=(1U<<pin);
		}
}
void gpio_OFF(char port,int pin) //turns off power to the gpio port using bit set reset
{
	int x = pin;
	pin =pin +16;

	if(port == 'a')
		{
			GPIOA->BSRR &=~(1U<<x);
			GPIOA->BSRR |=(1U<<pin);
		}
		else if(port=='b')
		{
			GPIOB->BSRR &=~(1U<<x);
			GPIOB->BSRR |=(1U<<pin);
		}
		else if(port=='c')
		{
			GPIOC->BSRR &=~(1U<<x);
			GPIOC->BSRR |=(1U<<pin);
		}
		else if(port=='d')
		{
			GPIOD->BSRR &=~(1U<<x);
			GPIOD->BSRR |=(1U<<pin);
		}
		else if(port=='e')
		{
			GPIOE->BSRR &=~(1U<<x);
			GPIOE->BSRR |=(1U<<pin);
		}
		else
		{
			GPIOH->BSRR &=~(1U<<x);
			GPIOH->BSRR |=(1U<<pin);
		}
}
void gpio_Toggle(char port,int pin) //toggles the power to the gpio port using the output data register
{
	if(port == 'a')
		{
			GPIOA->ODR ^= (1U<<pin);
		}
		else if(port=='b')
		{
			GPIOB->ODR ^= (1U<<pin);
		}
		else if(port=='c')
		{
			GPIOC->ODR ^= (1U<<pin);
		}
		else if(port=='d')
		{
			GPIOD->ODR ^= (1U<<pin);
		}
		else if(port=='e')
		{
			GPIOE->ODR ^=(1U<<pin);
		}
		else
		{
			GPIOH->ODR ^=(1U<<pin);
		}
}
void gpio_Blink(char port,int pin,int delay)//toggles power to the pin depending on a user supplied input
{
	if(port == 'a')
		{

			GPIOA->ODR ^= (1U<<pin);//turns on the pin using the output data register
			for(int i=0; i<delay; i++) //delays for a certain period of time
			{


			}
			GPIOA->ODR ^= (1U<<pin); //turns off the pin using the output data register
		}
		else if(port=='b')
		{
			GPIOB->ODR ^= (1U<<pin);
			for(int i=0; i<delay; i++)
			{

			}
			GPIOB->ODR ^= (1U<<pin);
		}
		else if(port=='c')
		{
			GPIOC->ODR ^= (1U<<pin);
			for(int i=0; i<delay; i++)
			{

			}
			GPIOC->ODR ^= (1U<<pin);
		}
		else if(port=='d')
		{
			GPIOD->ODR ^= (1U<<pin);
			for(int i=0; i<delay; i++)
			{

			}
			GPIOD->ODR ^= (1U<<pin);
		}
		else if(port=='e')
		{
			GPIOE->ODR ^=(1U<<pin);
			for(int i=0; i<delay; i++)
			{

			}
			GPIOE->ODR ^= (1U<<pin);
		}
		else
		{
			GPIOH->ODR ^=(1U<<pin);
			for(int i=0; i<delay; i++)
			{

			}
			GPIOH->ODR ^= (1U<<pin);
		}
}
void gpio_Input(char port, int pin) //function that configures each gpio port for input
{
	int x = pin*2;
	int y= x+1;
	if(port == 'a')
	{
		RCC->AHB1ENR |= (1U<<0); //enables clock access to the gpio port
		GPIOA->MODER &= ~(1U<<x); //sets mode for the pin to input
		GPIOA->MODER &= ~(1U<<y);
		GPIOA->PUPDR &= ~(1U<<x); //enables pull up/down resistor
		GPIOA->PUPDR |= (1U<<y);
	}
	else if(port=='b')
	{
		RCC->AHB1ENR |= (1U<<1);
		GPIOB->MODER &= ~(1U<<x);
		GPIOB->MODER &= ~(1U<<y);
		GPIOB->PUPDR &= ~(1U<<x);
		GPIOB->PUPDR |= (1U<<y);

	}
	else if(port=='c')
	{
		RCC->AHB1ENR |= (1U<<2);
		GPIOC->MODER &= ~(1U<<x);
		GPIOC->MODER &= ~(1U<<y);
		GPIOC->PUPDR &= ~(1U<<x);
		GPIOC->PUPDR |= (1U<<y);
	}
	else if(port=='d')
	{
		RCC->AHB1ENR |= (1U<<3);
		GPIOD->MODER &= ~(1U<<x);
		GPIOD->MODER &= ~(1U<<y);
		GPIOD->PUPDR &= ~(1U<<x);
		GPIOD->PUPDR |= (1U<<y);
	}
	else if(port=='e')
	{
		RCC->AHB1ENR |= (1U<<4);
		GPIOE->MODER &= ~(1U<<x);
		GPIOE->MODER &= ~(1U<<y);
		GPIOE->PUPDR &= ~(1U<<x);
		GPIOE->PUPDR |= (1U<<y);
	}
	else
	{
		RCC->AHB1ENR |= (1U<<7);
		GPIOH->MODER &= ~(1U<<x);
		GPIOH->MODER &= ~(1U<<y);
		GPIOH->PUPDR &= ~(1U<<x);
		GPIOH->PUPDR |= (1U<<y);
	}

}

void IRQ_Initial(char port,int pin, char event) //function for configuring gpio port for interrupts functionality
{
	__disable_irq(); //disable global interrupts
	RCC->APB2ENR |= (1U<<14); ////enables system timer
	int cr=pin/4;
	int x=(pin%4)*4;
	int y= x+1;
	int z=y+1;
	if(port == 'a')
		{
			SYSCFG->EXTICR[cr] |= (1U<<0); //enables systic configuration exti control register

		}
		else if(port=='b')
		{
			SYSCFG->EXTICR[cr] |= (1U<<x);

		}
		else if(port=='c')
		{
			SYSCFG->EXTICR[cr] |= (1U<<y);
		}
		else if(port=='d')
		{
			SYSCFG->EXTICR[cr] |= (1U<<x);
			SYSCFG->EXTICR[cr] |= (1U<<y);
		}
		else if(port=='e')
		{
			SYSCFG->EXTICR[cr] |= (1U<<z);
		}
		else
		{
			SYSCFG->EXTICR[cr] |= (1U<<x);
			SYSCFG->EXTICR[cr] |= (1U<<y);
			SYSCFG->EXTICR[cr] |= (1U<<z);
		}

	if(event == 'r')  //enables interrupt for rising or falling edge based on user input
	{
		EXTI->RTSR |= (1U<<pin);
	}
	else
	{
		EXTI->FTSR |= (1U<<pin);
	}
	EXTI->IMR |= (1U<<pin);  //masks the interrupt
	if(pin==0)  //enables the interrupt in the NVIC table
	{
		NVIC_EnableIRQ(EXTI0_IRQn);
	}
	else if(pin==1)
	{
		NVIC_EnableIRQ(EXTI1_IRQn);
	}
	else if(pin==2)
	{
		NVIC_EnableIRQ(EXTI2_IRQn);
	}
	else if(pin==3)
	{
		NVIC_EnableIRQ(EXTI3_IRQn);
	}
	else if(pin==4)
	{
		NVIC_EnableIRQ(EXTI4_IRQn);
	}
	else if(pin<=9)
	{
		NVIC_EnableIRQ(EXTI9_5_IRQn);
	}
	else
	{
		NVIC_EnableIRQ(EXTI15_10_IRQn);
	}

	__enable_irq(); //enables global interrupts
}
