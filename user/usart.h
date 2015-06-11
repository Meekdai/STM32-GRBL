/*
USART1 Tx (PA9)
USART1 Rx (PA10)
USART2 Tx (PA2)(PD5)  第二脚不能接收
USART2 Rx (PA3)(PD6)
USART3 Tx (PB10)
USART3 Rx (PB11)
UART4 Tx (PC10)       以下接收暂时没用过
UART4 Rx (PC11)
UART5 Tx (PC12)
UART5 Rx (PC2)
*/
/***************************************************************/
#include "stm32f10x.h"
#include "stdio.h"
/***************************************************************/
#ifndef __USART_H
#define __USART_H
/***************************************************************/
#define USART1_IRQChannel            ((u8)0x25)  /* USART1 global Interrupt */
#define USART2_IRQChannel            ((u8)0x26)  /* USART2 global Interrupt */
#define USART3_IRQChannel            ((u8)0x27)  /* USART3 global Interrupt */
#define UART4_IRQChannel            ((u8)0x34)  /* USART4 global Interrupt */
#define UART5_IRQChannel            ((u8)0x35)  /* USART5 global Interrupt */
/***************************************************************/

int fputc(int ch, FILE *f); 
void USART1_Configuration(u32 BaudRate);
void USART21_Configuration(u32 BaudRate);
void USART22_Configuration(u32 BaudRate);
void USART3_Configuration(u32 BaudRate);
void USART4_Configuration(u32 BaudRate);
void USART5_Configuration(u32 BaudRate);
void Get_RX_4bitData(void);

 #endif
