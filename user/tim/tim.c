/***************************************************************/
#include "stm32f10x.h"
#include "tim.h"
/***************************************************************/

void TIM_Configuration(TIM_TypeDef* TIMER,u16 Period,u16 Prescaler,u8 PP)
{
	TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
	NVIC_InitTypeDef NVIC_InitStructure;
	
	if(TIMER==TIM1)     RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM1, ENABLE);
	else if(TIMER==TIM2)RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);
	else if(TIMER==TIM3)RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE);
	else if(TIMER==TIM4)RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM4, ENABLE);
	else if(TIMER==TIM5)RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM5, ENABLE);
	else if(TIMER==TIM6)RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM6, ENABLE);
	else if(TIMER==TIM7)RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM7, ENABLE);
	else if(TIMER==TIM8)RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM8, ENABLE);

	TIM_TimeBaseStructure.TIM_Period = Period-1; 	              //这个就是自动装载的计数值，由于计数是从0开始的，计数10000次后为9999
	TIM_TimeBaseStructure.TIM_Prescaler =Prescaler-1;             // 这个就是预分频系数，当由于为0时表示不分频所以要减1  
	TIM_TimeBaseStructure.TIM_ClockDivision = 0; 	              // 使用的采样频率之间的分频比例
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;   //向上计数
	TIM_TimeBaseInit(TIMER, &TIM_TimeBaseStructure);              //初始化定时器

	TIM_ClearITPendingBit(TIMER, TIM_IT_Update);             	  //Clear TIM5 update pending flag[清除TIM5溢出中断标志] 
	TIM_ITConfig(TIMER, TIM_IT_Update, ENABLE);				      //打开溢出中断
	TIM_Cmd(TIMER, ENABLE);                                       //计数器使能，开始工作
	
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_4);
	if(TIMER==TIM2){NVIC_InitStructure.NVIC_IRQChannel = TIM2_IRQn;}
	else if(TIMER==TIM3){NVIC_InitStructure.NVIC_IRQChannel = TIM3_IRQn;}
	else if(TIMER==TIM4){NVIC_InitStructure.NVIC_IRQChannel = TIM4_IRQn;}
	else if(TIMER==TIM5){NVIC_InitStructure.NVIC_IRQChannel = TIM5_IRQn;}
	
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority =PP;	 //主优先级
//	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;			 //从优先级为0
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;				 //使能中断通道
	NVIC_Init(&NVIC_InitStructure);								 //用以上参数初始化10-15号线中断通道
}

