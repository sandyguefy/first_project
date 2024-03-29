
/*
problem : 
Detect if user press USER_BUTTON
Toggle GPIOD_12 (PD12) LED at some visible interval

Each of the GPIO pins can be configured by software as output (push-pull or open-drain, with or without pull-up or pull-down), as input (floating, with or without pull-up or pull-down)
GPIO -> OUTPUT[PUSH_pULL | open drain]
// ---configurations---
GPIOx_MODER,
GPIOx_OTYPER, 
GPIOx_OSPEEDR
and GPIOx_PUPDR


GPIOx_IDR  
GPIOx_ODR 
GPIOx_BSRR

GPIOx_AFRH
GPIOx_AFRL*/

#include <stm32f407xx.h>
//#include <stdio.h>

#define LED_DELAY  1000000

void delay (uint32_t x);



int main()
	
	{
	RCC->AHB1ENR |= (1<<3);
	//RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN; //USER BUTTON -> PAO
	
	// GPIO12_12 AS OUTPUT-----
 GPIOD->MODER |= (1<<24);
 GPIOD->MODER &= ~(1<<25);
	
 GPIOD->ODR |= (1<<12);
		
	//-----------------------
	while (1)
		{
		 delay (LED_DELAY);
		GPIOD->ODR ^= (1<<12);
		
		/*if (GPIOA->IDR & (1<<0)){
		GPIOD->ODR ^=(1<<12);	
		delay (LED_DELAY);*/
		}
			
	 
	}
	void delay (uint32_t x){
	
	     for (;x>0;x--)
			
	      {
		      __ASM ("NOP"); 
	
         	}
       }
	
	
