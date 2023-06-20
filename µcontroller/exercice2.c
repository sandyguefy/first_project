#include <stm32f407xx.h>
#include <stdint.h>



#define LED_DELAY  1000000

void delay (uint32_t x);
void delay (uint32_t x){
	
	     for (;x>0;x--)
			
	      {
		      __ASM ("NOP"); 
	
         	}
       }
	



int main(void)
	
	{
	RCC->AHB1ENR |= (1<<3);
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN; //USER BUTTON -> PAO
	
	// GPIO12_12 AS OUTPUT-----
 //GPIOD->MODER |= (1<<24);
 //GPIOD->MODER &=  ~(1<<25);
GPIOD->MODER &= ~(GPIO_MODER_MODER12_Msk); // Efface les bits de configuration existants
GPIOD->MODER |= GPIO_MODER_MODER12_0;  // Configure GPIOD12 en mode sortie

	
 GPIOD->ODR |= (1<<12);

		
	//-----------------------
    while (1)
		{
		
		if (GPIOA->IDR & (1<<0))
			{
		
        
				
		delay (LED_DELAY);
		GPIOD->ODR 	^=(1<<12);	
				
			}
			
			
		
		}
		
			

	 
	}
