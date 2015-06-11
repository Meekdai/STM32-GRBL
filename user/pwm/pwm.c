/***************************************************************/
#include "PWM.h"
#include "stm32f10x.h"
/***************************************************************/
//			  输出占空比计算公式：TIM_Pulse/(TIM_Period)
/***************************************************************/

static GPIO_InitTypeDef GPIO_InitStructure;


static TIM_TimeBaseInitTypeDef  TIM1_TimeBaseStructure,TIM2_TimeBaseStructure,TIM3_TimeBaseStructure,TIM4_TimeBaseStructure,TIM5_TimeBaseStructure,TIM8_TimeBaseStructure;
static TIM_OCInitTypeDef  TIM1_OCInitStructure,TIM2_OCInitStructure,TIM3_OCInitStructure,TIM4_OCInitStructure,TIM5_OCInitStructure,TIM8_OCInitStructure;
//static TIM_BDTRInitTypeDef TIM8_BDTRInitStructure;

/*******************************************************************************
*					TIM1的函数
*******************************************************************************/
void TIM1_PWM_Configuration(u16 Prescaler,u16 Period,u8 OC1 ,u8 OC2 ,u8 OC3 ,u8 OC4)							   // PA8    PA9    PA10    PA11
{

	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA , ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO, ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM1, ENABLE);

    if(OC1==1)
    {
	    /* GPIOC Configuration: TIM1 Channel 1 Output */
        GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8;			 
        GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;	      
        GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;	 
        GPIO_Init(GPIOA, &GPIO_InitStructure);
    }
	if(OC2==1)
    {
	    /* GPIOC Configuration: TIM1 Channel 2 Output */
        GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9;			  
        GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;	      
        GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;	  
        GPIO_Init(GPIOA, &GPIO_InitStructure);
    }
	if(OC3==1)
    {
	    /* GPIOC Configuration: TIM1 Channel 3 Output */
        GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10;			  
        GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;	      
        GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;	  
        GPIO_Init(GPIOA, &GPIO_InitStructure);
    }
	if(OC4==1)
    {
	    /* GPIOC Configuration: TIM1 Channel 4 Output */
        GPIO_InitStructure.GPIO_Pin = GPIO_Pin_11;			 
        GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;	     
        GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;	 
        GPIO_Init(GPIOA, &GPIO_InitStructure);
    }


    TIM_DeInit(TIM1);												 //复位定时器8所有寄存器

    /* Time Base configuration */
    TIM1_TimeBaseStructure.TIM_Prescaler = Prescaler-1;				 //预分频数为0,不分频
    TIM1_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;	 //计娄方式为顺序计数模式，增大型
    TIM1_TimeBaseStructure.TIM_Period = Period-1;					 //设置计数器溢出后的重载初值
    TIM1_TimeBaseStructure.TIM_ClockDivision =  0x00;				 //配置时钟分隔值
    TIM1_TimeBaseStructure.TIM_RepetitionCounter = 0x0;			     //循环计数次数值

    TIM_TimeBaseInit(TIM1,&TIM1_TimeBaseStructure);				     //用以上参数初始化定时器时间基础模块
  
    /* Channel 1 Configuration in PWM mode */
    TIM1_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1; 			     //输出方式为PWM模式1
 
    TIM1_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;   //使能输出比较状态
    TIM1_OCInitStructure.TIM_OutputNState = TIM_OutputNState_Enable; //使能定时器互补输出               
    TIM1_OCInitStructure.TIM_Pulse = 20000; 						 //设置脉宽
    TIM1_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;   	 //输出比较极性为高
    TIM1_OCInitStructure.TIM_OCIdleState = TIM_OCIdleState_Set;	     //打开空闲状态选择关闭
  
    /* 初始化TM1通道1*/
    if(OC1==1)TIM_OC1Init(TIM1,&TIM8_OCInitStructure); 		         //用以上参数初始化TIM8的通道1
	if(OC2==1)TIM_OC2Init(TIM1,&TIM8_OCInitStructure); 		         //用以上参数初始化TIM8的通道2
	if(OC3==1)TIM_OC3Init(TIM1,&TIM8_OCInitStructure); 		         //用以上参数初始化TIM8的通道3
	if(OC4==1)TIM_OC4Init(TIM1,&TIM8_OCInitStructure); 		         //用以上参数初始化TIM8的通道4
 
    /* TIM1 counter enable */
    TIM_Cmd(TIM1,ENABLE);							   				 //使能定时器8

    /* Main Output Enable */
    TIM_CtrlPWMOutputs(TIM1,ENABLE);				   				 //使能定时器8的PWM输出	 频率

}  

void TIM1_Change_Period(u16 NoteSet)
{
     TIM1_TimeBaseStructure.TIM_Period = NoteSet ;
	 TIM_TimeBaseInit(TIM1,&TIM1_TimeBaseStructure);
}
/*******************************控制各个通道的脉宽*****************************************************/
void Change_TIM1_OC1_Pulse(u16 Pulse)
{
     TIM1_OCInitStructure.TIM_Pulse = Pulse;
	 TIM_OC1Init(TIM1,&TIM1_OCInitStructure);
}
void Change_TIM1_OC2_Pulse(u16 Pulse)
{
     TIM1_OCInitStructure.TIM_Pulse = Pulse;
	 TIM_OC2Init(TIM1,&TIM1_OCInitStructure);
}
void Change_TIM1_OC3_Pulse(u16 Pulse)
{
     TIM1_OCInitStructure.TIM_Pulse = Pulse;
	 TIM_OC3Init(TIM1,&TIM1_OCInitStructure);
}
void Change_TIM1_OC4_Pulse(u16 Pulse)
{
     TIM1_OCInitStructure.TIM_Pulse = Pulse;
	 TIM_OC4Init(TIM1,&TIM1_OCInitStructure);
}
/*********************************各通道极性控制*****************************************************/
void Change_TIM1_OC1_Polarity(u8 i)
{
     if(i==1)TIM1_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;
	 else 	 TIM1_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_Low;
	 TIM_OC1Init(TIM1,&TIM1_OCInitStructure);
}
void Change_TIM1_OC2_Polarity(u8 i)
{
     if(i==1)TIM1_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;
	 else 	 TIM1_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_Low;
	 TIM_OC2Init(TIM1,&TIM1_OCInitStructure);
}
void Change_TIM1_OC3_Polarity(u8 i)
{
     if(i==1)TIM1_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;
	 else 	 TIM1_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_Low;
	 TIM_OC3Init(TIM1,&TIM1_OCInitStructure);
}
void Change_TIM1_OC4_Polarity(u8 i)
{
     if(i==1)TIM1_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;
	 else 	 TIM1_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_Low;
	 TIM_OC4Init(TIM1,&TIM1_OCInitStructure);
}

/*******************************************************************************
*					TIM2的函数
*******************************************************************************/
void TIM2_PWM_Configuration(u16 Prescaler,u16 Period,u8 OC1 ,u8 OC2 ,u8 OC3 ,u8 OC4)							   // PA0    PA1    PA2    PA3
{  
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);

    if(OC1==1)
    {
	    /* GPIOA Configuration: TIM2 Channel 1 Output */
        GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0;			
        GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;	    
        GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;	  
        GPIO_Init(GPIOA, &GPIO_InitStructure);
    }
	if(OC2==1)
    {
	    /* GPIOA Configuration: TIM2 Channel 2 Output */
        GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1;			  
        GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;	     
        GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;	  
        GPIO_Init(GPIOA, &GPIO_InitStructure);
    }
	if(OC3==1)
    {
	    /* GPIOA Configuration: TIM2 Channel 3 Output */
        GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2;			  
        GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;	     
        GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;	 
        GPIO_Init(GPIOA, &GPIO_InitStructure);
    }
	if(OC4==1)
    {
	    /* GPIOA Configuration: TIM2 Channel 4 Output */
        GPIO_InitStructure.GPIO_Pin = GPIO_Pin_3;			  
        GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;	     
        GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;	 
        GPIO_Init(GPIOA, &GPIO_InitStructure);
    }


    TIM_DeInit(TIM2);												 //复位定时器8所有寄存器

    /* Time Base configuration */
    TIM2_TimeBaseStructure.TIM_Prescaler = Prescaler-1;				 //预分频数为0,不分频
    TIM2_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;	 //计娄方式为顺序计数模式，增大型
    TIM2_TimeBaseStructure.TIM_Period = Period-1;					 //设置计数器溢出后的重载初值
    TIM2_TimeBaseStructure.TIM_ClockDivision =  0x00;				 //配置时钟分隔值
    TIM2_TimeBaseStructure.TIM_RepetitionCounter = 0x0;			     //循环计数次数值

    TIM_TimeBaseInit(TIM2,&TIM2_TimeBaseStructure);				     //用以上参数初始化定时器时间基础模块
  
    /* Channel 1 Configuration in PWM mode */
    TIM2_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1; 			     //输出方式为PWM模式1
 
    TIM2_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;   //使能输出比较状态
    TIM2_OCInitStructure.TIM_OutputNState = TIM_OutputNState_Enable; //使能定时器互补输出               
    TIM2_OCInitStructure.TIM_Pulse = 20000; 						 //设置脉宽
    TIM2_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;   	 //输出比较极性为高
    TIM2_OCInitStructure.TIM_OCIdleState = TIM_OCIdleState_Set;	     //打开空闲状态选择关闭
  
    /* 初始化TM5通道1*/
    if(OC1==1)TIM_OC1Init(TIM2,&TIM2_OCInitStructure); 		         //用以上参数初始化TIM2的通道1
	if(OC2==1)TIM_OC2Init(TIM2,&TIM2_OCInitStructure); 		         //用以上参数初始化TIM2的通道2
	if(OC3==1)TIM_OC3Init(TIM2,&TIM2_OCInitStructure); 		         //用以上参数初始化TIM2的通道3
	if(OC4==1)TIM_OC4Init(TIM2,&TIM2_OCInitStructure); 		         //用以上参数初始化TIM2的通道4
 
    /* TIM5 counter enable */
    TIM_Cmd(TIM2,ENABLE);							   				 //使能定时器2

    /* Main Output Enable */
    TIM_CtrlPWMOutputs(TIM2,ENABLE);				   				 //使能定时器2的PWM输出	 频率

}  

void TIM2_Change_Period(u16 NoteSet)
{
     TIM2_TimeBaseStructure.TIM_Period = NoteSet ;
	 TIM_TimeBaseInit(TIM2,&TIM2_TimeBaseStructure);
}
/*******************************控制各个通道的脉宽*****************************************************/
void Change_TIM2_OC1_Pulse(u16 Pulse)
{
     TIM2_OCInitStructure.TIM_Pulse = Pulse;
	 TIM_OC1Init(TIM2,&TIM2_OCInitStructure);
}
void Change_TIM2_OC2_Pulse(u16 Pulse)
{
     TIM2_OCInitStructure.TIM_Pulse = Pulse;
	 TIM_OC2Init(TIM2,&TIM2_OCInitStructure);
}
void Change_TIM2_OC3_Pulse(u16 Pulse)
{
     TIM2_OCInitStructure.TIM_Pulse = Pulse;
	 TIM_OC3Init(TIM2,&TIM2_OCInitStructure);
}
void Change_TIM2_OC4_Pulse(u16 Pulse)
{
     TIM2_OCInitStructure.TIM_Pulse = Pulse;
	 TIM_OC4Init(TIM2,&TIM2_OCInitStructure);
}
/*********************************各通道极性控制*****************************************************/
void Change_TIM2_OC1_Polarity(u8 i)
{
     if(i==1)TIM2_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;
	 else 	 TIM2_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_Low;
	 TIM_OC1Init(TIM2,&TIM2_OCInitStructure);
}
void Change_TIM2_OC2_Polarity(u8 i)
{
     if(i==1)TIM2_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;
	 else 	 TIM2_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_Low;
	 TIM_OC2Init(TIM2,&TIM2_OCInitStructure);
}
void Change_TIM2_OC3_Polarity(u8 i)
{
     if(i==1)TIM2_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;
	 else 	 TIM2_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_Low;
	 TIM_OC3Init(TIM2,&TIM2_OCInitStructure);
}
void Change_TIM2_OC4_Polarity(u8 i)
{
     if(i==1)TIM2_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;
	 else 	 TIM2_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_Low;
	 TIM_OC4Init(TIM2,&TIM2_OCInitStructure);
}

/*******************************************************************************
*					TIM3的函数
*******************************************************************************/
void TIM3_PWM_Configuration(u16 Prescaler,u16 Period,u8 OC1 ,u8 OC2 ,u8 OC3 ,u8 OC4)							   // PA6    PA7    PB0    PB1
{  
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA | RCC_APB2Periph_GPIOB, ENABLE);

    if(OC1==1)
    {
	    /* GPIOA Configuration: TIM3 Channel 1 Output */
        GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6;			
        GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;	    
        GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;	  
        GPIO_Init(GPIOA, &GPIO_InitStructure);
    }
	if(OC2==1)
    {
	    /* GPIOA Configuration: TIM3 Channel 2 Output */
        GPIO_InitStructure.GPIO_Pin = GPIO_Pin_7;			  
        GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;	     
        GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;	  
        GPIO_Init(GPIOA, &GPIO_InitStructure);
    }
	if(OC3==1)
    {
	    /* GPIOB Configuration: TIM3 Channel 3 Output */
        GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0;			  
        GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;	     
        GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;	 
        GPIO_Init(GPIOB, &GPIO_InitStructure);
    }
	if(OC4==1)
    {
	    /* GPIOB Configuration: TIM3 Channel 4 Output */
        GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1;			  
        GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;	     
        GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;	 
        GPIO_Init(GPIOB, &GPIO_InitStructure);
    }


    TIM_DeInit(TIM3);												 //复位定时器8所有寄存器

    /* Time Base configuration */
    TIM3_TimeBaseStructure.TIM_Prescaler = Prescaler-1;				 //预分频数为0,不分频
    TIM3_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;	 //计娄方式为顺序计数模式，增大型
    TIM3_TimeBaseStructure.TIM_Period =Period-1;					 //设置计数器溢出后的重载初值
    TIM3_TimeBaseStructure.TIM_ClockDivision =  0x00;				 //配置时钟分隔值
    TIM3_TimeBaseStructure.TIM_RepetitionCounter = 0x0;			     //循环计数次数值

    TIM_TimeBaseInit(TIM3,&TIM3_TimeBaseStructure);				     //用以上参数初始化定时器时间基础模块
  
    /* Channel 1 Configuration in PWM mode */
    TIM3_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1; 			     //输出方式为PWM模式1
 
    TIM3_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;   //使能输出比较状态
    TIM3_OCInitStructure.TIM_OutputNState = TIM_OutputNState_Enable; //使能定时器互补输出               
    TIM3_OCInitStructure.TIM_Pulse = 3500; 						 //设置脉宽
    TIM3_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;   	 //输出比较极性为高
    TIM3_OCInitStructure.TIM_OCIdleState = TIM_OCIdleState_Set;	     //打开空闲状态选择关闭
  
    /* 初始化TM3通道1*/
    if(OC1==1)TIM_OC1Init(TIM3,&TIM3_OCInitStructure); 		         //用以上参数初始化TIM3的通道1
	if(OC2==1)TIM_OC2Init(TIM3,&TIM3_OCInitStructure); 		         //用以上参数初始化TIM3的通道2
	if(OC3==1)TIM_OC3Init(TIM3,&TIM3_OCInitStructure); 		         //用以上参数初始化TIM3的通道3
	if(OC4==1)TIM_OC4Init(TIM3,&TIM3_OCInitStructure); 		         //用以上参数初始化TIM3的通道4
 
    /* TIM3 counter enable */
    TIM_Cmd(TIM3,ENABLE);							     			 //使能定时器8

    /* Main Output Enable */
    TIM_CtrlPWMOutputs(TIM3,ENABLE);				   				 //使能定时器8的PWM输出	 频率

}  

void TIM3_Change_Period(u16 NoteSet)
{
     TIM3_TimeBaseStructure.TIM_Period = NoteSet ;
	 TIM_TimeBaseInit(TIM3,&TIM3_TimeBaseStructure);
}
/*******************************控制各个通道的脉宽*****************************************************/
void Change_TIM3_OC1_Pulse(u16 Pulse)
{
     TIM3_OCInitStructure.TIM_Pulse = Pulse;
	 TIM_OC1Init(TIM3,&TIM3_OCInitStructure);
}
void Change_TIM3_OC2_Pulse(u16 Pulse)
{
     TIM3_OCInitStructure.TIM_Pulse = Pulse;
	 TIM_OC2Init(TIM3,&TIM3_OCInitStructure);
}
void Change_TIM3_OC3_Pulse(u16 Pulse)
{
     TIM3_OCInitStructure.TIM_Pulse = Pulse;
	 TIM_OC3Init(TIM3,&TIM3_OCInitStructure);
}
void Change_TIM3_OC4_Pulse(u16 Pulse)
{
     TIM3_OCInitStructure.TIM_Pulse = Pulse;
	 TIM_OC4Init(TIM3,&TIM3_OCInitStructure);
}
/*********************************各通道极性控制*****************************************************/
void Change_TIM3_OC1_Polarity(u8 i)
{
     if(i==1)TIM3_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;
	 else 	 TIM3_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_Low;
	 TIM_OC1Init(TIM3,&TIM3_OCInitStructure);
}
void Change_TIM3_OC2_Polarity(u8 i)
{
     if(i==1)TIM3_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;
	 else 	 TIM3_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_Low;
	 TIM_OC2Init(TIM3,&TIM3_OCInitStructure);
}
void Change_TIM3_OC3_Polarity(u8 i)
{
     if(i==1)TIM3_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;
	 else 	 TIM3_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_Low;
	 TIM_OC3Init(TIM3,&TIM3_OCInitStructure);
}
void Change_TIM3_OC4_Polarity(u8 i)
{
     if(i==1)TIM3_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;
	 else 	 TIM3_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_Low;
	 TIM_OC4Init(TIM3,&TIM3_OCInitStructure);
}


/*******************************************************************************
*					TIM4的函数
*******************************************************************************/
void TIM4_PWM_Configuration(u16 Prescaler,u16 Period,u8 OC1 ,u8 OC2 ,u8 OC3 ,u8 OC4)							   // PB6    PB7    PB8    PB9
{  
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM4, ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);

    if(OC1==1)
    {
	    /* GPIOB Configuration: TIM3 Channel 1 Output */
        GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6;			
        GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;	    
        GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;	  
        GPIO_Init(GPIOB, &GPIO_InitStructure);
    }
	if(OC2==1)
    {
	    /* GPIOB Configuration: TIM3 Channel 2 Output */
        GPIO_InitStructure.GPIO_Pin = GPIO_Pin_7;			  
        GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;	     
        GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;	  
        GPIO_Init(GPIOB, &GPIO_InitStructure);
    }
	if(OC3==1)
    {
	    /* GPIOB Configuration: TIM3 Channel 3 Output */
        GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8;			  
        GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;	     
        GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;	 
        GPIO_Init(GPIOB, &GPIO_InitStructure);
    }
	if(OC4==1)
    {
	    /* GPIOB Configuration: TIM3 Channel 4 Output */
        GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9;			  
        GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;	     
        GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;	 
        GPIO_Init(GPIOB, &GPIO_InitStructure);
    }


    TIM_DeInit(TIM4);												 //复位定时器8所有寄存器

    /* Time Base configuration */
    TIM4_TimeBaseStructure.TIM_Prescaler =Prescaler-1;				 //预分频数为0,不分频
    TIM4_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;	 //计娄方式为顺序计数模式，增大型
    TIM4_TimeBaseStructure.TIM_Period = Period-1;					 //设置计数器溢出后的重载初值
    TIM4_TimeBaseStructure.TIM_ClockDivision =  0x00;				 //配置时钟分隔值
    TIM4_TimeBaseStructure.TIM_RepetitionCounter = 0x0;			     //循环计数次数值

    TIM_TimeBaseInit(TIM4,&TIM4_TimeBaseStructure);				     //用以上参数初始化定时器时间基础模块
  
    /* Channel 1 Configuration in PWM mode */
    TIM4_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1; 			     //输出方式为PWM模式1
 
    TIM4_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;   //使能输出比较状态
    TIM4_OCInitStructure.TIM_OutputNState = TIM_OutputNState_Enable; //使能定时器互补输出               
    TIM4_OCInitStructure.TIM_Pulse = 20000; 						 //设置脉宽
    TIM4_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;   	 //输出比较极性为高
    TIM4_OCInitStructure.TIM_OCIdleState = TIM_OCIdleState_Set;	     //打开空闲状态选择关闭
  
    /* 初始化TM4通道1*/
    if(OC1==1)TIM_OC1Init(TIM4,&TIM4_OCInitStructure); 		         //用以上参数初始化TIM3的通道1
	if(OC2==1)TIM_OC2Init(TIM4,&TIM4_OCInitStructure); 		         //用以上参数初始化TIM3的通道2
	if(OC3==1)TIM_OC3Init(TIM4,&TIM4_OCInitStructure); 		         //用以上参数初始化TIM3的通道3
	if(OC4==1)TIM_OC4Init(TIM4,&TIM4_OCInitStructure); 		         //用以上参数初始化TIM3的通道4
 
    /* TIM4 counter enable */
    TIM_Cmd(TIM4,ENABLE);							   				 //使能定时器8

    /* Main Output Enable */
    TIM_CtrlPWMOutputs(TIM4,ENABLE);				   				 //使能定时器8的PWM输出	 频率

}  

void TIM4_Change_Period(u16 NoteSet)
{
     TIM4_TimeBaseStructure.TIM_Period = NoteSet ;
	 TIM_TimeBaseInit(TIM4,&TIM4_TimeBaseStructure);
}
/*******************************控制各个通道的脉宽*****************************************************/
void Change_TIM4_OC1_Pulse(u16 Pulse)
{
     TIM4_OCInitStructure.TIM_Pulse = Pulse;
	 TIM_OC1Init(TIM4,&TIM4_OCInitStructure);
}
void Change_TIM4_OC2_Pulse(u16 Pulse)
{
     TIM4_OCInitStructure.TIM_Pulse = Pulse;
	 TIM_OC2Init(TIM4,&TIM4_OCInitStructure);
}
void Change_TIM4_OC3_Pulse(u16 Pulse)
{
     TIM4_OCInitStructure.TIM_Pulse = Pulse;
	 TIM_OC3Init(TIM4,&TIM4_OCInitStructure);
}
void Change_TIM4_OC4_Pulse(u16 Pulse)
{
     TIM4_OCInitStructure.TIM_Pulse = Pulse;
	 TIM_OC4Init(TIM4,&TIM4_OCInitStructure);
}
/*********************************各通道极性控制*****************************************************/
void Change_TIM4_OC1_Polarity(u8 i)
{
     if(i==1)TIM4_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;
	 else 	 TIM4_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_Low;
	 TIM_OC1Init(TIM4,&TIM4_OCInitStructure);
}
void Change_TIM4_OC2_Polarity(u8 i)
{
     if(i==1)TIM4_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;
	 else 	 TIM4_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_Low;
	 TIM_OC2Init(TIM4,&TIM4_OCInitStructure);
}
void Change_TIM4_OC3_Polarity(u8 i)
{
     if(i==1)TIM4_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;
	 else 	 TIM4_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_Low;
	 TIM_OC3Init(TIM4,&TIM4_OCInitStructure);
}
void Change_TIM4_OC4_Polarity(u8 i)
{
     if(i==1)TIM4_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;
	 else 	 TIM4_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_Low;
	 TIM_OC4Init(TIM4,&TIM4_OCInitStructure);
}





/*******************************************************************************
*					TIM5的函数
*******************************************************************************/
void TIM5_PWM_Configuration(u16 Prescaler,u16 Period,u8 OC1 ,u8 OC2 ,u8 OC3 ,u8 OC4)							   // PA0    PA1    PA2    PA3
{  
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM5, ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);

    if(OC1==1)
    {
	    /* GPIOA Configuration: TIM5 Channel 1 Output */
        GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0;			
        GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;	    
        GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;	  
        GPIO_Init(GPIOA, &GPIO_InitStructure);
    }
	if(OC2==1)
    {
	    /* GPIOA Configuration: TIM5 Channel 2 Output */
        GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1;			  
        GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;	     
        GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;	  
        GPIO_Init(GPIOA, &GPIO_InitStructure);
    }
	if(OC3==1)
    {
	    /* GPIOA Configuration: TIM5 Channel 3 Output */
        GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2;			  
        GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;	     
        GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;	 
        GPIO_Init(GPIOA, &GPIO_InitStructure);
    }
	if(OC4==1)
    {
	    /* GPIOA Configuration: TIM5 Channel 4 Output */
        GPIO_InitStructure.GPIO_Pin = GPIO_Pin_3;			  
        GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;	     
        GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;	 
        GPIO_Init(GPIOA, &GPIO_InitStructure);
    }


    TIM_DeInit(TIM5);												 //复位定时器8所有寄存器

    /* Time Base configuration */
    TIM5_TimeBaseStructure.TIM_Prescaler = Prescaler-1;				 //预分频数为0,不分频
    TIM5_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;	 //计娄方式为顺序计数模式，增大型
    TIM5_TimeBaseStructure.TIM_Period = Period-1;					 //设置计数器溢出后的重载初值
    TIM5_TimeBaseStructure.TIM_ClockDivision =  0x00;				 //配置时钟分隔值
    TIM5_TimeBaseStructure.TIM_RepetitionCounter = 0x0;			     //循环计数次数值

    TIM_TimeBaseInit(TIM5,&TIM5_TimeBaseStructure);				     //用以上参数初始化定时器时间基础模块
  
    /* Channel 1 Configuration in PWM mode */
    TIM5_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1; 			     //输出方式为PWM模式1
 
    TIM5_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;   //使能输出比较状态
    TIM5_OCInitStructure.TIM_OutputNState = TIM_OutputNState_Enable; //使能定时器互补输出               
    TIM5_OCInitStructure.TIM_Pulse = 20000; 						 //设置脉宽
    TIM5_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;   	 //输出比较极性为高
    TIM5_OCInitStructure.TIM_OCIdleState = TIM_OCIdleState_Set;	     //打开空闲状态选择关闭
  
    /* 初始化TM5通道1*/
    if(OC1==1)TIM_OC1Init(TIM5,&TIM5_OCInitStructure); 		         //用以上参数初始化TIM3的通道1
	if(OC2==1)TIM_OC2Init(TIM5,&TIM5_OCInitStructure); 		         //用以上参数初始化TIM3的通道2
	if(OC3==1)TIM_OC3Init(TIM5,&TIM5_OCInitStructure); 		         //用以上参数初始化TIM3的通道3
	if(OC4==1)TIM_OC4Init(TIM5,&TIM5_OCInitStructure); 		         //用以上参数初始化TIM3的通道4
 
    /* TIM5 counter enable */
    TIM_Cmd(TIM5,ENABLE);							   				 //使能定时器8

    /* Main Output Enable */
    TIM_CtrlPWMOutputs(TIM5,ENABLE);				  				 //使能定时器8的PWM输出	 频率

}  

void TIM5_Change_Period(u16 NoteSet)
{
     TIM5_TimeBaseStructure.TIM_Period = NoteSet ;
	 TIM_TimeBaseInit(TIM5,&TIM5_TimeBaseStructure);
}
/*******************************控制各个通道的脉宽*****************************************************/
void Change_TIM5_OC1_Pulse(u16 Pulse)
{
     TIM5_OCInitStructure.TIM_Pulse = Pulse;
	 TIM_OC1Init(TIM5,&TIM5_OCInitStructure);
}
void Change_TIM5_OC2_Pulse(u16 Pulse)
{
     TIM5_OCInitStructure.TIM_Pulse = Pulse;
	 TIM_OC2Init(TIM5,&TIM5_OCInitStructure);
}
void Change_TIM5_OC3_Pulse(u16 Pulse)
{
     TIM5_OCInitStructure.TIM_Pulse = Pulse;
	 TIM_OC3Init(TIM5,&TIM5_OCInitStructure);
}
void Change_TIM5_OC4_Pulse(u16 Pulse)
{
     TIM5_OCInitStructure.TIM_Pulse = Pulse;
	 TIM_OC4Init(TIM5,&TIM5_OCInitStructure);
}
/*********************************各通道极性控制*****************************************************/
void Change_TIM5_OC1_Polarity(u8 i)
{
     if(i==1)TIM5_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;
	 else 	 TIM5_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_Low;
	 TIM_OC1Init(TIM5,&TIM5_OCInitStructure);
}
void Change_TIM5_OC2_Polarity(u8 i)
{
     if(i==1)TIM5_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;
	 else 	 TIM5_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_Low;
	 TIM_OC2Init(TIM5,&TIM5_OCInitStructure);
}
void Change_TIM5_OC3_Polarity(u8 i)
{
     if(i==1)TIM5_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;
	 else 	 TIM5_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_Low;
	 TIM_OC3Init(TIM5,&TIM5_OCInitStructure);
}
void Change_TIM5_OC4_Polarity(u8 i)
{
     if(i==1)TIM5_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;
	 else 	 TIM5_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_Low;
	 TIM_OC4Init(TIM5,&TIM5_OCInitStructure);
}
/*******************************************************************************
*					TIM8的函数
*******************************************************************************/
void TIM8_PWM_Configuration(u16 Prescaler,u16 Period,u8 OC1 ,u8 OC2 ,u8 OC3 ,u8 OC4)							   // PC6    PC7    PC8    PC9
{  

	RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM8 | RCC_APB2Periph_GPIOC, ENABLE);

    if(OC1==1)
    {
	    /* GPIOC Configuration: TIM8 Channel 1 Output */
        GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6;			  
        GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;	     
        GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;	  
        GPIO_Init(GPIOC, &GPIO_InitStructure);
    }
	if(OC2==1)
    {
	    /* GPIOC Configuration: TIM8 Channel 2 Output */
        GPIO_InitStructure.GPIO_Pin = GPIO_Pin_7;			 
        GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;	      
        GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;	 
        GPIO_Init(GPIOC, &GPIO_InitStructure);
    }
	if(OC3==1)
    {
	    /* GPIOC Configuration: TIM8 Channel 3 Output */
        GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8;			  
        GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;	      
        GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;	  
        GPIO_Init(GPIOC, &GPIO_InitStructure);
    }
	if(OC4==1)
    {
	    /* GPIOC Configuration: TIM8 Channel 4 Output */
        GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9;			  
        GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;	      
        GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;	 
        GPIO_Init(GPIOC, &GPIO_InitStructure);
    }


    TIM_DeInit(TIM8);												 //复位定时器8所有寄存器

    /* Time Base configuration */
    TIM8_TimeBaseStructure.TIM_Prescaler = Prescaler-1;				 //预分频数为0,不分频
    TIM8_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;	 //计娄方式为顺序计数模式，增大型
    TIM8_TimeBaseStructure.TIM_Period = Period-1;					 //设置计数器溢出后的重载初值
    TIM8_TimeBaseStructure.TIM_ClockDivision =  0x00;				 //配置时钟分隔值
    TIM8_TimeBaseStructure.TIM_RepetitionCounter = 0x0;			     //循环计数次数值

    TIM_TimeBaseInit(TIM8,&TIM8_TimeBaseStructure);				     //用以上参数初始化定时器时间基础模块
  
    /* Channel 1 Configuration in PWM mode */
    TIM8_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1; 			     //输出方式为PWM模式1
 
    TIM8_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;   //使能输出比较状态
    TIM8_OCInitStructure.TIM_OutputNState = TIM_OutputNState_Enable; //使能定时器互补输出               
    TIM8_OCInitStructure.TIM_Pulse = 20000; 						 //设置脉宽
    TIM8_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;   	 //输出比较极性为高
    TIM8_OCInitStructure.TIM_OCIdleState = TIM_OCIdleState_Set;	     //打开空闲状态选择关闭
  
    /* 初始化TM8通道1*/
    if(OC1==1)TIM_OC1Init(TIM8,&TIM8_OCInitStructure); 		         //用以上参数初始化TIM8的通道1
	if(OC2==1)TIM_OC2Init(TIM8,&TIM8_OCInitStructure); 		         //用以上参数初始化TIM8的通道2
	if(OC3==1)TIM_OC3Init(TIM8,&TIM8_OCInitStructure); 		         //用以上参数初始化TIM8的通道3
	if(OC4==1)TIM_OC4Init(TIM8,&TIM8_OCInitStructure); 		         //用以上参数初始化TIM8的通道4
 
    /* TIM8 counter enable */
    TIM_Cmd(TIM8,ENABLE);							   				 //使能定时器8

    /* Main Output Enable */
    TIM_CtrlPWMOutputs(TIM8,ENABLE);				   				 //使能定时器8的PWM输出	 频率

}  

void TIM8_Change_Period(u16 NoteSet)
{
     TIM8_TimeBaseStructure.TIM_Period = NoteSet ;
	 TIM_TimeBaseInit(TIM8,&TIM8_TimeBaseStructure);
}
/*******************************控制各个通道的脉宽*****************************************************/
void Change_TIM8_OC1_Pulse(u16 Pulse)
{
     TIM8_OCInitStructure.TIM_Pulse = Pulse;
	 TIM_OC1Init(TIM8,&TIM8_OCInitStructure);
}
void Change_TIM8_OC2_Pulse(u16 Pulse)
{
     TIM8_OCInitStructure.TIM_Pulse = Pulse;
	 TIM_OC2Init(TIM8,&TIM8_OCInitStructure);
}
void Change_TIM8_OC3_Pulse(u16 Pulse)
{
     TIM8_OCInitStructure.TIM_Pulse = Pulse;
	 TIM_OC3Init(TIM8,&TIM8_OCInitStructure);
}
void Change_TIM8_OC4_Pulse(u16 Pulse)
{
     TIM8_OCInitStructure.TIM_Pulse = Pulse;
	 TIM_OC4Init(TIM8,&TIM8_OCInitStructure);
}
/*********************************各通道极性控制*****************************************************/
void Change_TIM8_OC1_Polarity(u8 i)
{
     if(i==1)TIM8_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;
	 else 	 TIM8_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_Low;
	 TIM_OC1Init(TIM8,&TIM8_OCInitStructure);
}
void Change_TIM8_OC2_Polarity(u8 i)
{
     if(i==1)TIM8_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;
	 else 	 TIM8_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_Low;
	 TIM_OC2Init(TIM8,&TIM8_OCInitStructure);
}
void Change_TIM8_OC3_Polarity(u8 i)
{
     if(i==1)TIM8_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;
	 else 	 TIM8_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_Low;
	 TIM_OC3Init(TIM8,&TIM8_OCInitStructure);
}
void Change_TIM8_OC4_Polarity(u8 i)
{
     if(i==1)TIM8_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;
	 else 	 TIM8_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_Low;
	 TIM_OC4Init(TIM8,&TIM8_OCInitStructure);
}
