
/*
problem : 
Toggle GPIOD_12 (PD12) LED at some visible interval

Each of the GPIO pins can be configured by software as output (push-pull or open-drain, with or without pull-up or pull-down), as input (floating, with or without pull-up or pull-down)
GPIO -> OUTPUT[PUSH_pULL | open drain]
// ---configurations---
GPIOx_MODER,
GPIOx_OTYPER, 
GPIOx_OSPEEDR
and GPIOx_PUPDR


GPIOx_IDR  
GPIOx_ODR (write something in the output)

*/



#include "stm32f4xx.h"
#define LED_DELAY  100000
void delay (uint32_t x);
void delay (uint32_t x){
	for (;x>0;x--)
	{
		//__ASM ("NOP"); 
	
	}
	
}
int main(){
	
	RCC->AHB1ENR |= (1<<1);
	
	// GPIOB_15 AS OUTPUT-----
 GPIOB->MODER |= (1<<30);
 GPIOB->MODER &= ~(1<<31);
 //GPIOB->ODR |= (1<<15);
	//-----------------------
	while (1){
		delay (LED_DELAY);
		GPIOB->ODR ^=(1<<15);
	
	}
	
}
