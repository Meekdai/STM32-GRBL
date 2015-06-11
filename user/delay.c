/***************************************************************/
#include "stm32f10x.h"
#include "delay.h"
/***************************************************************/

static u8  fac_us=0;                                               // us The multiplier delay times 
static u16 fac_ms=0;                                               // ms The multiplier delay times 
/***************************************************************/
void delay_Configuration(u8 SYSCLK)
{
	SysTick->CTRL&=0xfffffffb;                                     // Select the internal clock HCLK/8		
	fac_us=SYSCLK/8;		    						   
	fac_ms=(u16)fac_us*1000;							 
}	
/***************************************************************/
void delay_ms(u16 nms)
{
	u32 temp;		   
	SysTick->LOAD=(u32)nms*fac_ms;                                 // Loading time
	SysTick->VAL =0x00;                                            // Empty the counter
	SysTick->CTRL=0x01 ;                                           // Start from bottom
	do
	{
		temp=SysTick->CTRL;
	}
	while(temp&0x01&&!(temp&(1<<16)));                             // Wait time arrive
	SysTick->CTRL=0x00;                                            // Close the counter
	SysTick->VAL =0X00;                                            // Empty the counter	    
}		
/***************************************************************/
void delay_us(u32 Nus)
{		
	u32 temp;	    	 
	SysTick->LOAD=Nus*fac_us;   		 
	SysTick->VAL=0x00;       
	SysTick->CTRL=0x01 ;       
	do
	{
		temp=SysTick->CTRL;
	}
	while(temp&0x01&&!(temp&(1<<16)));
	SysTick->CTRL=0x00;       
	SysTick->VAL =0X00;       
}
/***************************************************************/
void delay_s(u32 Ns)
{		
	switch (Ns)
	{
		case 10: delay_ms(1000);
		case 9: delay_ms(1000);
		case 8: delay_ms(1000);
		case 7: delay_ms(1000);
		case 6: delay_ms(1000);
		case 5: delay_ms(1000);
		case 4: delay_ms(1000);
		case 3: delay_ms(1000);
		case 2: delay_ms(1000);
		case 1: delay_ms(1000);break;
	}
}


/***************************************************************/
void RCC_Configuration(void)
{
	ErrorStatus HSEStartUpStatus;								//原本是定义在全局变量中
    RCC_DeInit();									    		//时钟控制寄存器全部恢复默认值
    RCC_HSEConfig(RCC_HSE_ON);						        	//外部高速时钟源开启（8M晶振）
    HSEStartUpStatus = RCC_WaitForHSEStartUp();					//等待外部时钟就绪
    if(HSEStartUpStatus == SUCCESS)								//如果时钟启动成功
    {
		RCC_HCLKConfig(RCC_SYSCLK_Div1);						//定义AHB设备时钟为系统时钟1分频
    	RCC_PCLK2Config(RCC_HCLK_Div1);							//定义AHB2设备时钟为HCLK时钟1分频
    	RCC_PCLK1Config(RCC_HCLK_Div2);							//定义AHB1设备时钟为HCLK时钟2分频
		RCC_ADCCLKConfig(RCC_PCLK2_Div6);
    	FLASH_SetLatency(FLASH_Latency_2);					  	//设定内部FLASH的的延时周期为2周期
    	FLASH_PrefetchBufferCmd(FLASH_PrefetchBuffer_Enable);	//使能FLASH预存取缓冲区
    	RCC_PLLConfig(RCC_PLLSource_HSE_Div1, RCC_PLLMul_9);	//配置PLL时钟为外部高速时钟的9倍频，8MHz * 9 = 72 MHz
    	RCC_PLLCmd(ENABLE);										//使能PLL时钟
    	while(RCC_GetFlagStatus(RCC_FLAG_PLLRDY) == RESET){}    //等待PLL时钟设置完成准备就绪
    	RCC_SYSCLKConfig(RCC_SYSCLKSource_PLLCLK);				//使用PLL时钟作为系统时钟源
    	while(RCC_GetSYSCLKSource() != 0x08){}					//返回系统所用时钟源确认为外部高速晶振，8M晶振。
  	} 
// 	//释放JTAG占用的A13 A14 A15 B3 B4	  A14不能拉高 A13不能拉低
// 	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO,ENABLE);
// 	GPIO_PinRemapConfig(GPIO_Remap_SWJ_JTAGDisable , ENABLE);
			 RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA|RCC_APB2Periph_GPIOB|RCC_APB2Periph_GPIOC|RCC_APB2Periph_GPIOD|RCC_APB2Periph_GPIOE , ENABLE); 
   RCC_AHBPeriphClockCmd(RCC_AHBPeriph_FSMC, ENABLE);		//打开FSMC时钟
}
/***************************************************************/
void SoftReset(void) 
{ 
	__set_FAULTMASK(1); 
	NVIC_SystemReset();
}

/***************************************************************/
