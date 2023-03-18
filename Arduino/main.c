
/*
problem : write Logic High /Low to the GPIO

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

int main(){
	
	RCC->AHB1ENR |= (1<<3);
	
	// GPIOD_12 AS OUTPUT-----
 GPIOD->MODER |= (1<<24);
 GPIOD->MODER &= ~(1<<25);
 GPIOD->ODR |= (1<<12);
	//-----------------------
	
}
