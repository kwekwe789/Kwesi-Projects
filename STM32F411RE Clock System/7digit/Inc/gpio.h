
#include "stm32f4xx.h"




void gpio_Output(char port, int pin);
void gpio_Input(char port, int pin);
void gpio_ON(char port,int pin);
void gpio_Toggle(char port,int pin);
void gpio_OFF(char port,int pin);
void IRQ_Initial(char port,int pin, char event);
void gpio_Blink(char port,int pin,int delay);
void delay(int d);

extern int timer;
extern int sec1;
extern int sec2;
extern int min1;
extern int min2;
extern int milsec;
extern int Mode;
extern int temp1;
extern int temp2;
extern int temp3;
extern int temp4;
extern int place;
extern int x;
extern int lock;
extern int countdownDone;

