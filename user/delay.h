/***************************************************************/
#include "stm32f10x.h"
/***************************************************************/
#ifndef __DELAY_H
#define __DELAY_H 

/***************************************************************/
void delay_Configuration(u8 SYSCLK);							    					  
void delay_ms(u16 nms);
void delay_us(u32 Nus);
void delay_s(u32 Ns);
void RCC_Configuration(void);
void SoftReset(void);
/***************************************************************/


#endif

