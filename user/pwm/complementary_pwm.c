/***************************************************************/
#include "complementary_pwm.h"
#include "stm32f10x.h"
/***************************************************************/
static 	TIM_OCInitTypeDef    TIM1_OC1InitStructure,TIM1_OC2InitStructure,TIM1_OC3InitStructure;
static 	TIM_OCInitTypeDef    TIM8_OC1InitStructure,TIM8_OC2InitStructure,TIM8_OC3InitStructure;
/***************************************************************/

void TIM1_Configuration(u16 Prescaler,u16 Period,u8 OC1,u8 OC2,u8 OC3,u8 DeadTime,u8 Open)
{
	GPIO_InitTypeDef        GPIO_InitStructure;
	TIM_TimeBaseInitTypeDef TIM_BaseInitStructure;
    TIM_BDTRInitTypeDef     TIM_BDTRInitStructure;

    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA | RCC_APB2Periph_GPIOB , ENABLE);
	//启动AFIO
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO, ENABLE);
	//启动TIM1
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM1, ENABLE);

	//Step2. GPIO做相应设置，为AF输出
	//PA.8/9口设置为TIM1的OC1输出口
	if(OC1)
	{
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8 ;
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
		GPIO_Init(GPIOA, &GPIO_InitStructure);

		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_13 ;
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
		GPIO_Init(GPIOB, &GPIO_InitStructure);
	}
	if(OC2)
	{
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9 ;
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
		GPIO_Init(GPIOA, &GPIO_InitStructure);

		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_14 ;
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
		GPIO_Init(GPIOB, &GPIO_InitStructure);
	}
	if(OC3)
	{
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10 ;
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
		GPIO_Init(GPIOA, &GPIO_InitStructure);

		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_15 ;
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
		GPIO_Init(GPIOB, &GPIO_InitStructure);
	}

	//TIM1基本计数器设置（设置PWM频率）
    //频率=TIM1_CLK/(ARR+1)
	TIM_BaseInitStructure.TIM_Prescaler = Prescaler-1;				 //预分频	  0 表示不分频
    TIM_BaseInitStructure.TIM_Period = Period-1;				     //设置计数器溢出后的重载初值
    TIM_BaseInitStructure.TIM_ClockDivision = 0;					 //配置时钟分隔值
    TIM_BaseInitStructure.TIM_CounterMode = TIM_CounterMode_Up;		 //计娄方式为顺序计数模式，增大型
    TIM_BaseInitStructure.TIM_RepetitionCounter = 0;				 //循环计数次数值
    TIM_TimeBaseInit(TIM1, &TIM_BaseInitStructure);
    //启用ARR的影子寄存器（直到产生更新事件才更改设置）
    TIM_ARRPreloadConfig(TIM1, ENABLE);

	if(OC1)
	{
    	//TIM1_OC1模块设置（设置1通道占空比）
    	TIM1_OC1InitStructure.TIM_OCMode = TIM_OCMode_PWM1;
    	TIM1_OC1InitStructure.TIM_OutputState = TIM_OutputState_Enable;
    	TIM1_OC1InitStructure.TIM_OutputNState = TIM_OutputNState_Enable;
    	TIM1_OC1InitStructure.TIM_OCPolarity = TIM_OCPolarity_High;
    	TIM1_OC1InitStructure.TIM_OCNPolarity = TIM_OCNPolarity_High;
    	TIM1_OC1InitStructure.TIM_Pulse = 10000;
    	TIM_OC1Init(TIM1, &TIM1_OC1InitStructure);
    	//启用CCR1寄存器的影子寄存器（直到产生更新事件才更改设置）
    	TIM_OC1PreloadConfig(TIM1, TIM_OCPreload_Enable);
	}
	if(OC2)
	{
    	//TIM1_OC2模块设置（设置2通道占空比）
		TIM1_OC2InitStructure.TIM_OCMode = TIM_OCMode_PWM1;
    	TIM1_OC2InitStructure.TIM_OutputState = TIM_OutputState_Enable;
    	TIM1_OC2InitStructure.TIM_OutputNState = TIM_OutputNState_Enable;
		TIM1_OC2InitStructure.TIM_OCPolarity = TIM_OCPolarity_High;
    	TIM1_OC2InitStructure.TIM_OCNPolarity = TIM_OCNPolarity_High;
    	TIM1_OC2InitStructure.TIM_Pulse = 10000;
    	TIM_OC2Init(TIM1, &TIM1_OC2InitStructure);
    	//启用CCR2寄存器的影子寄存器（直到产生更新事件才更改设置）
    	TIM_OC2PreloadConfig(TIM1, TIM_OCPreload_Enable);
	}
	if(OC3)
	{
    	//TIM1_OC3模块设置（设置3通道占空比）
		TIM1_OC3InitStructure.TIM_OCMode = TIM_OCMode_PWM1;
    	TIM1_OC3InitStructure.TIM_OutputState = TIM_OutputState_Enable;
    	TIM1_OC3InitStructure.TIM_OutputNState = TIM_OutputNState_Enable;
		TIM1_OC3InitStructure.TIM_OCPolarity = TIM_OCPolarity_High;
    	TIM1_OC3InitStructure.TIM_OCNPolarity = TIM_OCNPolarity_High;
    	TIM1_OC3InitStructure.TIM_Pulse = 10000;
    	TIM_OC3Init(TIM1, &TIM1_OC3InitStructure);
    	//启用CCR2寄存器的影子寄存器（直到产生更新事件才更改设置）
    	TIM_OC3PreloadConfig(TIM1, TIM_OCPreload_Enable);
	}
	if(Open)
	{
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_12;			
        GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
        GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
        GPIO_Init(GPIOB, &GPIO_InitStructure);
	}
    
    //死区设置
    TIM_BDTRInitStructure.TIM_OSSRState = TIM_OSSRState_Enable;
    TIM_BDTRInitStructure.TIM_OSSIState = TIM_OSSIState_Enable;
    TIM_BDTRInitStructure.TIM_LOCKLevel = TIM_LOCKLevel_OFF;
    TIM_BDTRInitStructure.TIM_DeadTime = DeadTime;  //这里调整死区大小0-0xff
    if(Open)TIM_BDTRInitStructure.TIM_Break = TIM_Break_Enable;
	else 	TIM_BDTRInitStructure.TIM_Break = TIM_Break_Disable;
    if(Open==1)TIM_BDTRInitStructure.TIM_BreakPolarity = TIM_BreakPolarity_Low; //刹车输入低电平有效
	else TIM_BDTRInitStructure.TIM_BreakPolarity = TIM_BreakPolarity_High; //刹车输入高电平有效
    TIM_BDTRInitStructure.TIM_AutomaticOutput = TIM_AutomaticOutput_Enable;
    TIM_BDTRConfig(TIM1, &TIM_BDTRInitStructure);
    
	if(Open)TIM_ITConfig(TIM1,TIM_IT_Break,ENABLE);
    //TIM1开启
    TIM_Cmd(TIM1, ENABLE);
    //TIM1_OC通道输出PWM（一定要加）
    TIM_CtrlPWMOutputs(TIM1, ENABLE);

}
void TIM1_OC1_Pulse(u8 OCPolarity,u8 OCNPolarity,u16 TIM_Pulse)
{
    if(OCPolarity) TIM1_OC1InitStructure.TIM_OCPolarity = TIM_OCPolarity_High;
	else 		   TIM1_OC1InitStructure.TIM_OCPolarity = TIM_OCPolarity_Low;

    if(OCNPolarity)TIM1_OC1InitStructure.TIM_OCNPolarity = TIM_OCNPolarity_High;
	else 		   TIM1_OC1InitStructure.TIM_OCNPolarity = TIM_OCNPolarity_Low;
    TIM1_OC1InitStructure.TIM_Pulse = TIM_Pulse ;

    TIM_OC1Init(TIM1, &TIM1_OC1InitStructure);
    //启用CCR1寄存器的影子寄存器（直到产生更新事件才更改设置）
    TIM_OC1PreloadConfig(TIM1, TIM_OCPreload_Enable);
}
void TIM1_OC2_Pulse(u8 OCPolarity,u8 OCNPolarity,u16 TIM_Pulse)
{
    if(OCPolarity) TIM1_OC2InitStructure.TIM_OCPolarity = TIM_OCPolarity_High;
	else 		   TIM1_OC2InitStructure.TIM_OCPolarity = TIM_OCPolarity_Low;

    if(OCNPolarity)TIM1_OC2InitStructure.TIM_OCNPolarity = TIM_OCNPolarity_High;
	else 		   TIM1_OC2InitStructure.TIM_OCNPolarity = TIM_OCNPolarity_Low;
    TIM1_OC2InitStructure.TIM_Pulse = TIM_Pulse ;

    TIM_OC2Init(TIM1, &TIM1_OC2InitStructure);
    //启用CCR1寄存器的影子寄存器（直到产生更新事件才更改设置）
    TIM_OC2PreloadConfig(TIM1, TIM_OCPreload_Enable);
}
void TIM1_OC3_Pulse(u8 OCPolarity,u8 OCNPolarity,u16 TIM_Pulse)
{
    if(OCPolarity) TIM1_OC3InitStructure.TIM_OCPolarity = TIM_OCPolarity_High;
	else 		   TIM1_OC3InitStructure.TIM_OCPolarity = TIM_OCPolarity_Low;

    if(OCNPolarity)TIM1_OC3InitStructure.TIM_OCNPolarity = TIM_OCNPolarity_High;
	else 		   TIM1_OC3InitStructure.TIM_OCNPolarity = TIM_OCNPolarity_Low;
    TIM1_OC3InitStructure.TIM_Pulse = TIM_Pulse ;

    TIM_OC3Init(TIM1, &TIM1_OC3InitStructure);
    //启用CCR1寄存器的影子寄存器（直到产生更新事件才更改设置）
    TIM_OC3PreloadConfig(TIM1, TIM_OCPreload_Enable);
}
/***************************************************************************/









void TIM8_Configuration(u16 Prescaler,u16 Period,u8 OC1,u8 OC2,u8 OC3,u8 DeadTime,u8 Open)
{
	GPIO_InitTypeDef        GPIO_InitStructure;
	TIM_TimeBaseInitTypeDef TIM_BaseInitStructure;
    TIM_BDTRInitTypeDef     TIM_BDTRInitStructure;

	RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM8 | RCC_APB2Periph_GPIOC, ENABLE);

    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA | RCC_APB2Periph_GPIOB , ENABLE);
	//启动AFIO
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO, ENABLE);

	//Step2. GPIO做相应设置，为AF输出
	if(OC1)
	{
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6 ;
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
		GPIO_Init(GPIOC, &GPIO_InitStructure);

		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_7 ;
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
		GPIO_Init(GPIOA, &GPIO_InitStructure);
	}
	if(OC2)
	{
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_7 ;
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
		GPIO_Init(GPIOC, &GPIO_InitStructure);

		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0 ;
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
		GPIO_Init(GPIOB, &GPIO_InitStructure);
	}
	if(OC3)
	{
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8 ;
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
		GPIO_Init(GPIOC, &GPIO_InitStructure);

		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1 ;
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
		GPIO_Init(GPIOB, &GPIO_InitStructure);
	}

	//TIM8基本计数器设置（设置PWM频率）
    //频率=TIM8_CLK/(ARR+1)
	TIM_BaseInitStructure.TIM_Prescaler = Prescaler-1;				 //预分频	  0 表示不分频
    TIM_BaseInitStructure.TIM_Period = Period-1;				     //设置计数器溢出后的重载初值
    TIM_BaseInitStructure.TIM_ClockDivision = 0;					 //配置时钟分隔值
    TIM_BaseInitStructure.TIM_CounterMode = TIM_CounterMode_Up;		 //计娄方式为顺序计数模式，增大型
    TIM_BaseInitStructure.TIM_RepetitionCounter = 0;				 //循环计数次数值
    TIM_TimeBaseInit(TIM8, &TIM_BaseInitStructure);
    //启用ARR的影子寄存器（直到产生更新事件才更改设置）
    TIM_ARRPreloadConfig(TIM8, ENABLE);

	if(OC1)
	{
    	//TIM8_OC1模块设置（设置1通道占空比）
    	TIM8_OC1InitStructure.TIM_OCMode = TIM_OCMode_PWM1;
    	TIM8_OC1InitStructure.TIM_OutputState = TIM_OutputState_Enable;
    	TIM8_OC1InitStructure.TIM_OutputNState = TIM_OutputNState_Enable;
    	TIM8_OC1InitStructure.TIM_OCPolarity = TIM_OCPolarity_High;
    	TIM8_OC1InitStructure.TIM_OCNPolarity = TIM_OCNPolarity_High;
    	TIM8_OC1InitStructure.TIM_Pulse = 5000;
    	TIM_OC1Init(TIM8, &TIM8_OC1InitStructure);
    	//启用CCR1寄存器的影子寄存器（直到产生更新事件才更改设置）
    	TIM_OC1PreloadConfig(TIM8, TIM_OCPreload_Enable);
	}
	if(OC2)
	{
    	//TIM8_OC2模块设置（设置2通道占空比）
		TIM8_OC2InitStructure.TIM_OCMode = TIM_OCMode_PWM1;
    	TIM8_OC2InitStructure.TIM_OutputState = TIM_OutputState_Enable;
    	TIM8_OC2InitStructure.TIM_OutputNState = TIM_OutputNState_Enable;
		TIM8_OC2InitStructure.TIM_OCPolarity = TIM_OCPolarity_High;
    	TIM8_OC2InitStructure.TIM_OCNPolarity = TIM_OCNPolarity_High;
    	TIM8_OC2InitStructure.TIM_Pulse = 680;
    	TIM_OC2Init(TIM8, &TIM8_OC2InitStructure);
    	//启用CCR2寄存器的影子寄存器（直到产生更新事件才更改设置）
    	TIM_OC2PreloadConfig(TIM8, TIM_OCPreload_Enable);
	}
	if(OC3)
	{
    	//TIM8_OC3模块设置（设置3通道占空比）
		TIM8_OC3InitStructure.TIM_OCMode = TIM_OCMode_PWM1;
    	TIM8_OC3InitStructure.TIM_OutputState = TIM_OutputState_Enable;
    	TIM8_OC3InitStructure.TIM_OutputNState = TIM_OutputNState_Enable;
		TIM8_OC3InitStructure.TIM_OCPolarity = TIM_OCPolarity_High;
    	TIM8_OC3InitStructure.TIM_OCNPolarity = TIM_OCNPolarity_High;
    	TIM8_OC3InitStructure.TIM_Pulse = 1000;
    	TIM_OC3Init(TIM8, &TIM8_OC3InitStructure);
    	//启用CCR2寄存器的影子寄存器（直到产生更新事件才更改设置）
    	TIM_OC3PreloadConfig(TIM8, TIM_OCPreload_Enable);
	}
	if(Open)
	{
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6;			
        GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
        GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
        GPIO_Init(GPIOA, &GPIO_InitStructure);
	}
    
    //死区设置
    TIM_BDTRInitStructure.TIM_OSSRState = TIM_OSSRState_Enable;
    TIM_BDTRInitStructure.TIM_OSSIState = TIM_OSSIState_Enable;
    TIM_BDTRInitStructure.TIM_LOCKLevel = TIM_LOCKLevel_OFF;
    TIM_BDTRInitStructure.TIM_DeadTime = DeadTime;  //这里调整死区大小0-0xff
    if(Open)TIM_BDTRInitStructure.TIM_Break = TIM_Break_Enable;
	else 	TIM_BDTRInitStructure.TIM_Break = TIM_Break_Disable;
    if(Open==1)TIM_BDTRInitStructure.TIM_BreakPolarity = TIM_BreakPolarity_Low; //刹车输入低电平有效
	else TIM_BDTRInitStructure.TIM_BreakPolarity = TIM_BreakPolarity_High; //刹车输入高电平有效
    TIM_BDTRInitStructure.TIM_AutomaticOutput = TIM_AutomaticOutput_Enable;
    TIM_BDTRConfig(TIM8, &TIM_BDTRInitStructure);
    
	if(Open)TIM_ITConfig(TIM8,TIM_IT_Break,ENABLE);
    //TIM8开启
    TIM_Cmd(TIM8, ENABLE);
    //TIM8_OC通道输出PWM（一定要加）
    TIM_CtrlPWMOutputs(TIM8, ENABLE);

}
void TIM8_OC1_Pulse(u8 OCPolarity,u8 OCNPolarity,u16 TIM_Pulse)
{
    if(OCPolarity) TIM8_OC1InitStructure.TIM_OCPolarity = TIM_OCPolarity_High;
	else 		   TIM8_OC1InitStructure.TIM_OCPolarity = TIM_OCPolarity_Low;

    if(OCNPolarity)TIM8_OC1InitStructure.TIM_OCNPolarity = TIM_OCNPolarity_High;
	else 		   TIM8_OC1InitStructure.TIM_OCNPolarity = TIM_OCNPolarity_Low;
    TIM8_OC1InitStructure.TIM_Pulse = TIM_Pulse ;

    TIM_OC1Init(TIM8, &TIM8_OC1InitStructure);
    //启用CCR1寄存器的影子寄存器（直到产生更新事件才更改设置）
    TIM_OC1PreloadConfig(TIM1, TIM_OCPreload_Enable);
}
void TIM8_OC2_Pulse(u8 OCPolarity,u8 OCNPolarity,u16 TIM_Pulse)
{
    if(OCPolarity) TIM8_OC2InitStructure.TIM_OCPolarity = TIM_OCPolarity_High;
	else 		   TIM8_OC2InitStructure.TIM_OCPolarity = TIM_OCPolarity_Low;

    if(OCNPolarity)TIM8_OC2InitStructure.TIM_OCNPolarity = TIM_OCNPolarity_High;
	else 		   TIM8_OC2InitStructure.TIM_OCNPolarity = TIM_OCNPolarity_Low;
    TIM8_OC2InitStructure.TIM_Pulse = TIM_Pulse ;

    TIM_OC2Init(TIM8, &TIM8_OC2InitStructure);
    //启用CCR1寄存器的影子寄存器（直到产生更新事件才更改设置）
    TIM_OC2PreloadConfig(TIM1, TIM_OCPreload_Enable);
}
void TIM8_OC3_Pulse(u8 OCPolarity,u8 OCNPolarity,u16 TIM_Pulse)
{
    if(OCPolarity) TIM8_OC3InitStructure.TIM_OCPolarity = TIM_OCPolarity_High;
	else 		   TIM8_OC3InitStructure.TIM_OCPolarity = TIM_OCPolarity_Low;

    if(OCNPolarity)TIM8_OC3InitStructure.TIM_OCNPolarity = TIM_OCNPolarity_High;
	else 		   TIM8_OC3InitStructure.TIM_OCNPolarity = TIM_OCNPolarity_Low;
    TIM8_OC3InitStructure.TIM_Pulse = TIM_Pulse ;

    TIM_OC3Init(TIM8, &TIM8_OC3InitStructure);
    //启用CCR1寄存器的影子寄存器（直到产生更新事件才更改设置）
    TIM_OC3PreloadConfig(TIM1, TIM_OCPreload_Enable);
}
/***************************************************************************/



