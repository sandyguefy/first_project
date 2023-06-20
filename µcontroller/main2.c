#include "stm32f407xx.h"
#define LED_DELAY  1000000
void delay (uint32_t x);

int main()
	{
	RCC->AHB1ENR |= (1<<3);
	//RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN; //USER BUTTON -> PAO
	
	// GPIO12_12 AS OUTPUT-----
 GPIOD->MODER |= (1<<24);
 GPIOD->MODER &= ~(1<<25);
 GPIOD->ODR &= (1<<12);
	//-----------------------
	while (1)
		{
		 delay (LED_DELAY);
		GPIOD->ODR ^= (1<<12);
		
		/*if (GPIOA->IDR & (1<<0)){
		GPIOD->ODR ^=(1<<12);	
		delay (LED_DELAY);*/
		}
		void delay (volatile uint32_t x){
	
	      for (;x>0;x--)
			
	        {
		      __ASM ("NOP"); 
	
         	}
       }
	
	}
	
