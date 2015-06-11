/***************************************************************/
#include "gpio.h"

/***************************************************************/

void My_GPIO_Init(GPIO_TypeDef* GPIOx,u16 pin,u8 mode)
{
		GPIO_InitTypeDef GPIO_InitStructure;

		if(GPIOx==GPIOA)RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
		else if(GPIOx==GPIOB)RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
		else if(GPIOx==GPIOC)RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);
		else if(GPIOx==GPIOD)RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOD, ENABLE);
		else if(GPIOx==GPIOE)RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOE, ENABLE);
		else if(GPIOx==GPIOF)RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOF, ENABLE);
		else if(GPIOx==GPIOG)RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOG, ENABLE);
	  else {}
			
	  if(mode==1)
	  {
						
				GPIO_InitStructure.GPIO_Pin = pin;		
				GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;			 
				GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;			 
				GPIO_Init(GPIOx, &GPIO_InitStructure);					  
    }
		else if(mode==0) 
		{
			  GPIO_InitStructure.GPIO_Pin = pin;				 
				GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;			 
				GPIO_Init(GPIOx, &GPIO_InitStructure);
    }
}
