/***************************************************************/
#include "stm32f10x.h"
#include "usart.h"
/***************************************************************/
u8 USARTx_MARK=0;
extern u8 USART_RX[60];
extern u8 USART_mark;
extern int USART_control;
/***************************************************************/
void USART1_Configuration(u32 BaudRate)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	USART_InitTypeDef USART_InitStructure;
	NVIC_InitTypeDef NVIC_InitStructure; 
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_4);
	NVIC_InitStructure.NVIC_IRQChannel = USART1_IRQChannel;   //通道设置为串口1中断
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority =0;   //中断占先等级10
//	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;          //中断响应优先级0
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;             //打开中断
	NVIC_Init(&NVIC_InitStructure);                             //初始化
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1|RCC_APB2Periph_GPIOA | RCC_APB2Periph_AFIO, ENABLE);
	/* 配置 USART1 Tx (PA9)*/
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;	 		//复用开漏输出模式
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		//输出最大频率为50MHz
	GPIO_Init(GPIOA, &GPIO_InitStructure);
	/* 配置 USART1 Rx (PA10)*/
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;	//浮空输入模式
	GPIO_Init(GPIOA, &GPIO_InitStructure);
	
	USART_InitStructure.USART_BaudRate            =BaudRate;	  //波特率
	USART_InitStructure.USART_WordLength          = USART_WordLength_8b; //8位数据
	USART_InitStructure.USART_StopBits            = USART_StopBits_1;	 //停止位1位
	USART_InitStructure.USART_Parity              = USART_Parity_No ;	 //无
	USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
	USART_InitStructure.USART_Mode                = USART_Mode_Rx | USART_Mode_Tx;
	USART_Init(USART1, &USART_InitStructure);
	USART_ITConfig(USART1, USART_IT_RXNE, ENABLE);
	USART_Cmd(USART1, ENABLE);
	USARTx_MARK=1;
//	printf("\r\n USART1 Configuration OK\r\n");
}

void USART21_Configuration(u32 BaudRate)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	USART_InitTypeDef USART_InitStructure;
	NVIC_InitTypeDef NVIC_InitStructure; 
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_4);
	NVIC_InitStructure.NVIC_IRQChannel = USART2_IRQChannel ;  //通道设置为串口2中断
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority =11;   //中断占先等级11
//	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;          //中断响应优先级0
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;             //打开中断
	NVIC_Init(&NVIC_InitStructure);                             //初始化
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA |RCC_APB2Periph_GPIOD | RCC_APB2Periph_AFIO, ENABLE);
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART2, ENABLE);

	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;	 		//复用开漏输出模式
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		//输出最大频率为50MHz
	GPIO_Init(GPIOA, &GPIO_InitStructure);
	
	/* 配置 USART2 Rx (PA3)*/
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_3;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;	//浮空输入模式
	GPIO_Init(GPIOA, &GPIO_InitStructure);  
		
	USART_InitStructure.USART_BaudRate            = BaudRate;	  //波特率
	USART_InitStructure.USART_WordLength          = USART_WordLength_8b; //8位数据
	USART_InitStructure.USART_StopBits            = USART_StopBits_1;	 //停止位1位
	USART_InitStructure.USART_Parity              = USART_Parity_No ;	 //无
	USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
	USART_InitStructure.USART_Mode                = USART_Mode_Rx | USART_Mode_Tx;
	USART_Init(USART2, &USART_InitStructure);
	USART_ITConfig(USART2, USART_IT_RXNE, ENABLE);
	USART_Cmd(USART2, ENABLE);
	USARTx_MARK=2;
	printf("\r\n USART21 Configuration OK\r\n");
}
void USART22_Configuration(u32 BaudRate)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	USART_InitTypeDef USART_InitStructure;
	NVIC_InitTypeDef NVIC_InitStructure; 
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_4);
	NVIC_InitStructure.NVIC_IRQChannel = USART2_IRQChannel ;  //通道设置为串口2中断
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority =11;   //中断占先等级11
//	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;          //中断响应优先级0
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;             //打开中断
	NVIC_Init(&NVIC_InitStructure);                             //初始化
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA |RCC_APB2Periph_GPIOD | RCC_APB2Periph_AFIO, ENABLE);
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART2, ENABLE);
	GPIO_PinRemapConfig(GPIO_Remap_USART2, ENABLE);            //决定USART 输出IO
	/* 配置 USART2Tx (PD5) */
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;	 		//复用开漏输出模式
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		//输出最大频率为50MHz
	GPIO_Init(GPIOD, &GPIO_InitStructure);

	/* 配置 USART2 Rx (PD6)*/
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;	//浮空输入模式
	GPIO_Init(GPIOD, &GPIO_InitStructure); 

	
	USART_InitStructure.USART_BaudRate            = BaudRate;	  //波特率
	USART_InitStructure.USART_WordLength          = USART_WordLength_8b; //8位数据
	USART_InitStructure.USART_StopBits            = USART_StopBits_1;	 //停止位1位
	USART_InitStructure.USART_Parity              = USART_Parity_No ;	 //无
	USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
	USART_InitStructure.USART_Mode                = USART_Mode_Rx | USART_Mode_Tx;
	USART_Init(USART2, &USART_InitStructure);
	USART_ITConfig(USART2, USART_IT_RXNE, ENABLE);
	USART_Cmd(USART2, ENABLE);
	USARTx_MARK=2;
	printf("\r\n USART22 Configuration OK\r\n");
}


void USART3_Configuration(u32 BaudRate)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	USART_InitTypeDef USART_InitStructure;
	NVIC_InitTypeDef NVIC_InitStructure; 
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_4);
	NVIC_InitStructure.NVIC_IRQChannel = USART3_IRQChannel ;  //通道设置为串口3中断
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority =12;   //中断占先等级12
//	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 2;          //中断响应优先级0
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;             //打开中断
	NVIC_Init(&NVIC_InitStructure);                             //初始化
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1| RCC_APB2Periph_AFIO|RCC_APB2Periph_GPIOB, ENABLE);
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART3, ENABLE);
	/* 配置 USART3 Tx (PB10) */
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;	 		//复用开漏输出模式
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		//输出最大频率为50MHz
	GPIO_Init(GPIOB, &GPIO_InitStructure);
	
	/* 配置 USART3 Rx (PB11) */
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_11;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;	//浮空输入模式
	GPIO_Init(GPIOB, &GPIO_InitStructure);
	USART_InitStructure.USART_BaudRate            = BaudRate;	  //波特率
	USART_InitStructure.USART_WordLength          = USART_WordLength_8b; //8位数据
	USART_InitStructure.USART_StopBits            = USART_StopBits_1;	 //停止位1位
	USART_InitStructure.USART_Parity              = USART_Parity_No ;	 //无
	USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
	USART_InitStructure.USART_Mode                = USART_Mode_Rx | USART_Mode_Tx;
	USART_Init(USART3, &USART_InitStructure);
	USART_ITConfig(USART3, USART_IT_RXNE, ENABLE);
	USART_Cmd(USART3, ENABLE);
	USARTx_MARK=3;
	printf("\r\n USART3 Configuration OK\r\n");
}

void USART4_Configuration(u32 BaudRate)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	USART_InitTypeDef USART_InitStructure;
	NVIC_InitTypeDef NVIC_InitStructure; 
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_4);
	NVIC_InitStructure.NVIC_IRQChannel = UART4_IRQChannel ;  //通道设置为串口4中断
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority =13;   //中断占先等级13
//	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 2;          //中断响应优先级0
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;             //打开中断
	NVIC_Init(&NVIC_InitStructure);                             //初始化
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_UART4, ENABLE);
	/* 配置 USART4 Tx (PC10) */
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
	GPIO_Init(GPIOC, &GPIO_InitStructure);
	/* 配置 USART4 Rx (PC11) */
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_11;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
	GPIO_Init(GPIOC, &GPIO_InitStructure);
	
	USART_InitStructure.USART_BaudRate = BaudRate;
	USART_InitStructure.USART_WordLength = USART_WordLength_8b;
	USART_InitStructure.USART_StopBits = USART_StopBits_1;
	USART_InitStructure.USART_Parity = USART_Parity_No ;
	USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
	USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;
	USART_Init(UART4, &USART_InitStructure);
	USART_Cmd(UART4, ENABLE);
	USARTx_MARK=4;
	printf("\r\n USART4 Configuration OK\r\n");
}


void USART5_Configuration(u32 BaudRate)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	USART_InitTypeDef USART_InitStructure;
	NVIC_InitTypeDef NVIC_InitStructure; 
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_4);
	NVIC_InitStructure.NVIC_IRQChannel = UART5_IRQChannel ;  //通道设置为串口5中断
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority =14;   //中断占先等级14
//	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 2;          //中断响应优先级0
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;             //打开中断
	NVIC_Init(&NVIC_InitStructure);                             //初始化
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_UART5, ENABLE);
	/* 配置 USART5 Tx (PC12) */
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_12;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
	GPIO_Init(GPIOC, &GPIO_InitStructure);
	/* 配置 USART5 Rx (PC2) */
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
	GPIO_Init(GPIOC, &GPIO_InitStructure);
	
	USART_InitStructure.USART_BaudRate = BaudRate;
	USART_InitStructure.USART_WordLength = USART_WordLength_8b;
	USART_InitStructure.USART_StopBits = USART_StopBits_1;
	USART_InitStructure.USART_Parity = USART_Parity_No ;
	USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
	USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;
	USART_Init(UART5, &USART_InitStructure);
	USART_Cmd(UART5, ENABLE);
	USARTx_MARK=5;
	printf("\r\n USART5 Configuration OK\r\n");
}


/***************************************************************/
int fputc(int ch, FILE *f)						  //串口PRINTF函数配置程序
{
	if(USARTx_MARK==1)
	{
		USART_SendData(USART1, (unsigned char) ch);
		while (!(USART1->SR & USART_FLAG_TXE));		 //等待发送完成
	}
	else if(USARTx_MARK==2)
	{
		USART_SendData(USART2, (unsigned char) ch);
		while (!(USART2->SR & USART_FLAG_TXE));		 //等待发送完成
	}
  else if(USARTx_MARK==3)
	{
		USART_SendData(USART3, (unsigned char) ch);
		while (!(USART3->SR & USART_FLAG_TXE));		 //等待发送完成		
	}
	else if(USARTx_MARK==4)
	{
		USART_SendData(UART4, (unsigned char) ch);
		while (!(UART4->SR & USART_FLAG_TXE));		 //等待发送完成
	}
  else if(USARTx_MARK==5)
	{
		USART_SendData(UART5, (unsigned char) ch);
		while (!(UART5->SR & USART_FLAG_TXE));		 //等待发送完成		
	}
	return (ch);
}

/***************************************************************/

void Get_RX_4bitData(void)
{
			//USART_control=(USART_RX[0]-'0');
		 	USART_control=(USART_RX[0]-'0')*1000+(USART_RX[1]-'0')*100+(USART_RX[2]-'0')*10+(USART_RX[3]-'0');
 			USART_mark=0;
}

