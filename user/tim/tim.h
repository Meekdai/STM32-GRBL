/***************************************************************/
#include "stm32f10x.h"
/***************************************************************/
#ifndef __TIM_H
#define __TIM_H 
/***************************************************************/

void TIM_Configuration(TIM_TypeDef* TIMER,u16 Period,u16 Prescaler,u8 PP); // Prescaler/72M*Period S  7200/72M*10000

#endif


