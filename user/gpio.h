/***************************************************************/
#include "stm32f10x.h"
/***************************************************************/
#ifndef __GPIO_H
#define __GPIO_H 
/***************************************************************/


void My_GPIO_Init(GPIO_TypeDef* GPIOx,u16 pin,u8 mode);

#define PA0_OUT   My_GPIO_Init(GPIOA,GPIO_Pin_0,1);
#define PA1_OUT   My_GPIO_Init(GPIOA,GPIO_Pin_1,1);
#define PA2_OUT   My_GPIO_Init(GPIOA,GPIO_Pin_2,1);
#define PA3_OUT   My_GPIO_Init(GPIOA,GPIO_Pin_3,1);
#define PA4_OUT   My_GPIO_Init(GPIOA,GPIO_Pin_4,1);
#define PA5_OUT   My_GPIO_Init(GPIOA,GPIO_Pin_5,1);
#define PA6_OUT   My_GPIO_Init(GPIOA,GPIO_Pin_6,1);
#define PA7_OUT   My_GPIO_Init(GPIOA,GPIO_Pin_7,1);
#define PA8_OUT   My_GPIO_Init(GPIOA,GPIO_Pin_8,1);
#define PA9_OUT   My_GPIO_Init(GPIOA,GPIO_Pin_9,1);
#define PA10_OUT  My_GPIO_Init(GPIOA,GPIO_Pin_10,1);
#define PA11_OUT  My_GPIO_Init(GPIOA,GPIO_Pin_11,1);
#define PA12_OUT  My_GPIO_Init(GPIOA,GPIO_Pin_12,1);
#define PA13_OUT  My_GPIO_Init(GPIOA,GPIO_Pin_13,1);
#define PA14_OUT  My_GPIO_Init(GPIOA,GPIO_Pin_14,1);
#define PA15_OUT  My_GPIO_Init(GPIOA,GPIO_Pin_15,1);

#define PB0_OUT   My_GPIO_Init(GPIOB,GPIO_Pin_0,1);
#define PB1_OUT   My_GPIO_Init(GPIOB,GPIO_Pin_1,1);
#define PB2_OUT   My_GPIO_Init(GPIOB,GPIO_Pin_2,1);
#define PB3_OUT   My_GPIO_Init(GPIOB,GPIO_Pin_3,1);
#define PB4_OUT   My_GPIO_Init(GPIOB,GPIO_Pin_4,1);
#define PB5_OUT   My_GPIO_Init(GPIOB,GPIO_Pin_5,1);
#define PB6_OUT   My_GPIO_Init(GPIOB,GPIO_Pin_6,1);
#define PB7_OUT   My_GPIO_Init(GPIOB,GPIO_Pin_7,1);
#define PB8_OUT   My_GPIO_Init(GPIOB,GPIO_Pin_8,1);
#define PB9_OUT   My_GPIO_Init(GPIOB,GPIO_Pin_9,1);
#define PB10_OUT  My_GPIO_Init(GPIOB,GPIO_Pin_10,1);
#define PB11_OUT  My_GPIO_Init(GPIOB,GPIO_Pin_11,1);
#define PB12_OUT  My_GPIO_Init(GPIOB,GPIO_Pin_12,1);
#define PB13_OUT  My_GPIO_Init(GPIOB,GPIO_Pin_13,1);
#define PB14_OUT  My_GPIO_Init(GPIOB,GPIO_Pin_14,1);
#define PB15_OUT  My_GPIO_Init(GPIOB,GPIO_Pin_15,1);

#define PC0_OUT   My_GPIO_Init(GPIOC,GPIO_Pin_0,1);
#define PC1_OUT   My_GPIO_Init(GPIOC,GPIO_Pin_1,1);
#define PC2_OUT   My_GPIO_Init(GPIOC,GPIO_Pin_2,1);
#define PC3_OUT   My_GPIO_Init(GPIOC,GPIO_Pin_3,1);
#define PC4_OUT   My_GPIO_Init(GPIOC,GPIO_Pin_4,1);
#define PC5_OUT   My_GPIO_Init(GPIOC,GPIO_Pin_5,1);
#define PC6_OUT   My_GPIO_Init(GPIOC,GPIO_Pin_6,1);
#define PC7_OUT   My_GPIO_Init(GPIOC,GPIO_Pin_7,1);
#define PC8_OUT   My_GPIO_Init(GPIOC,GPIO_Pin_8,1);
#define PC9_OUT   My_GPIO_Init(GPIOC,GPIO_Pin_9,1);
#define PC10_OUT  My_GPIO_Init(GPIOC,GPIO_Pin_10,1);
#define PC11_OUT  My_GPIO_Init(GPIOC,GPIO_Pin_11,1);
#define PC12_OUT  My_GPIO_Init(GPIOC,GPIO_Pin_12,1);
#define PC13_OUT  My_GPIO_Init(GPIOC,GPIO_Pin_13,1);
#define PC14_OUT  My_GPIO_Init(GPIOC,GPIO_Pin_14,1);
#define PC15_OUT  My_GPIO_Init(GPIOC,GPIO_Pin_15,1);

#define PD0_OUT   My_GPIO_Init(GPIOD,GPIO_Pin_0,1);
#define PD1_OUT   My_GPIO_Init(GPIOD,GPIO_Pin_1,1);
#define PD2_OUT   My_GPIO_Init(GPIOD,GPIO_Pin_2,1);
#define PD3_OUT   My_GPIO_Init(GPIOD,GPIO_Pin_3,1);
#define PD4_OUT   My_GPIO_Init(GPIOD,GPIO_Pin_4,1);
#define PD5_OUT   My_GPIO_Init(GPIOD,GPIO_Pin_5,1);
#define PD6_OUT   My_GPIO_Init(GPIOD,GPIO_Pin_6,1);
#define PD7_OUT   My_GPIO_Init(GPIOD,GPIO_Pin_7,1);
#define PD8_OUT   My_GPIO_Init(GPIOD,GPIO_Pin_8,1);
#define PD9_OUT   My_GPIO_Init(GPIOD,GPIO_Pin_9,1);
#define PD10_OUT  My_GPIO_Init(GPIOD,GPIO_Pin_10,1);
#define PD11_OUT  My_GPIO_Init(GPIOD,GPIO_Pin_11,1);
#define PD12_OUT  My_GPIO_Init(GPIOD,GPIO_Pin_12,1);
#define PD13_OUT  My_GPIO_Init(GPIOD,GPIO_Pin_13,1);
#define PD14_OUT  My_GPIO_Init(GPIOD,GPIO_Pin_14,1);
#define PD15_OUT  My_GPIO_Init(GPIOD,GPIO_Pin_15,1);

#define PE0_OUT   My_GPIO_Init(GPIOE,GPIO_Pin_0,1);
#define PE1_OUT   My_GPIO_Init(GPIOE,GPIO_Pin_1,1);
#define PE2_OUT   My_GPIO_Init(GPIOE,GPIO_Pin_2,1);
#define PE3_OUT   My_GPIO_Init(GPIOE,GPIO_Pin_3,1);
#define PE4_OUT   My_GPIO_Init(GPIOE,GPIO_Pin_4,1);
#define PE5_OUT   My_GPIO_Init(GPIOE,GPIO_Pin_5,1);
#define PE6_OUT   My_GPIO_Init(GPIOE,GPIO_Pin_6,1);
#define PE7_OUT   My_GPIO_Init(GPIOE,GPIO_Pin_7,1);
#define PE8_OUT   My_GPIO_Init(GPIOE,GPIO_Pin_8,1);
#define PE9_OUT   My_GPIO_Init(GPIOE,GPIO_Pin_9,1);
#define PE10_OUT  My_GPIO_Init(GPIOE,GPIO_Pin_10,1);
#define PE11_OUT  My_GPIO_Init(GPIOE,GPIO_Pin_11,1);
#define PE12_OUT  My_GPIO_Init(GPIOE,GPIO_Pin_12,1);
#define PE13_OUT  My_GPIO_Init(GPIOE,GPIO_Pin_13,1);
#define PE14_OUT  My_GPIO_Init(GPIOE,GPIO_Pin_14,1);
#define PE15_OUT  My_GPIO_Init(GPIOE,GPIO_Pin_15,1);

#define PF0_OUT   My_GPIO_Init(GPIOF,GPIO_Pin_0,1);
#define PF1_OUT   My_GPIO_Init(GPIOF,GPIO_Pin_1,1);
#define PF2_OUT   My_GPIO_Init(GPIOF,GPIO_Pin_2,1);
#define PF3_OUT   My_GPIO_Init(GPIOF,GPIO_Pin_3,1);
#define PF4_OUT   My_GPIO_Init(GPIOF,GPIO_Pin_4,1);
#define PF5_OUT   My_GPIO_Init(GPIOF,GPIO_Pin_5,1);
#define PF6_OUT   My_GPIO_Init(GPIOF,GPIO_Pin_6,1);
#define PF7_OUT   My_GPIO_Init(GPIOF,GPIO_Pin_7,1);
#define PF8_OUT   My_GPIO_Init(GPIOF,GPIO_Pin_8,1);
#define PF9_OUT   My_GPIO_Init(GPIOF,GPIO_Pin_9,1);
#define PF10_OUT  My_GPIO_Init(GPIOF,GPIO_Pin_10,1);
#define PF11_OUT  My_GPIO_Init(GPIOF,GPIO_Pin_11,1);
#define PF12_OUT  My_GPIO_Init(GPIOF,GPIO_Pin_12,1);
#define PF13_OUT  My_GPIO_Init(GPIOF,GPIO_Pin_13,1);
#define PF14_OUT  My_GPIO_Init(GPIOF,GPIO_Pin_14,1);
#define PF15_OUT  My_GPIO_Init(GPIOF,GPIO_Pin_15,1);

#define PG0_OUT   My_GPIO_Init(GPIOG,GPIO_Pin_0,1);
#define PG1_OUT   My_GPIO_Init(GPIOG,GPIO_Pin_1,1);
#define PG2_OUT   My_GPIO_Init(GPIOG,GPIO_Pin_2,1);
#define PG3_OUT   My_GPIO_Init(GPIOG,GPIO_Pin_3,1);
#define PG4_OUT   My_GPIO_Init(GPIOG,GPIO_Pin_4,1);
#define PG5_OUT   My_GPIO_Init(GPIOG,GPIO_Pin_5,1);
#define PG6_OUT   My_GPIO_Init(GPIOG,GPIO_Pin_6,1);
#define PG7_OUT   My_GPIO_Init(GPIOG,GPIO_Pin_7,1);
#define PG8_OUT   My_GPIO_Init(GPIOG,GPIO_Pin_8,1);
#define PG9_OUT   My_GPIO_Init(GPIOG,GPIO_Pin_9,1);
#define PG10_OUT  My_GPIO_Init(GPIOG,GPIO_Pin_10,1);
#define PG11_OUT  My_GPIO_Init(GPIOG,GPIO_Pin_11,1);
#define PG12_OUT  My_GPIO_Init(GPIOG,GPIO_Pin_12,1);
#define PG13_OUT  My_GPIO_Init(GPIOG,GPIO_Pin_13,1);
#define PG14_OUT  My_GPIO_Init(GPIOG,GPIO_Pin_14,1);
#define PG15_OUT  My_GPIO_Init(GPIOG,GPIO_Pin_15,1);

#define PA0_In   My_GPIO_Init(GPIOA,GPIO_Pin_0,0);
#define PA1_In   My_GPIO_Init(GPIOA,GPIO_Pin_1,0);
#define PA2_In   My_GPIO_Init(GPIOA,GPIO_Pin_2,0);
#define PA3_In   My_GPIO_Init(GPIOA,GPIO_Pin_3,0);
#define PA4_In   My_GPIO_Init(GPIOA,GPIO_Pin_4,0);
#define PA5_In   My_GPIO_Init(GPIOA,GPIO_Pin_5,0);
#define PA6_In   My_GPIO_Init(GPIOA,GPIO_Pin_6,0);
#define PA7_In   My_GPIO_Init(GPIOA,GPIO_Pin_7,0);
#define PA8_In   My_GPIO_Init(GPIOA,GPIO_Pin_8,0);
#define PA9_In   My_GPIO_Init(GPIOA,GPIO_Pin_9,0);
#define PA10_In  My_GPIO_Init(GPIOA,GPIO_Pin_10,0);
#define PA11_In  My_GPIO_Init(GPIOA,GPIO_Pin_11,0);
#define PA12_In  My_GPIO_Init(GPIOA,GPIO_Pin_12,0);
#define PA13_In  My_GPIO_Init(GPIOA,GPIO_Pin_13,0);
#define PA14_In  My_GPIO_Init(GPIOA,GPIO_Pin_14,0);
#define PA15_In  My_GPIO_Init(GPIOA,GPIO_Pin_15,0);

#define PB0_In   My_GPIO_Init(GPIOB,GPIO_Pin_0,0);
#define PB1_In   My_GPIO_Init(GPIOB,GPIO_Pin_1,0);
#define PB2_In   My_GPIO_Init(GPIOB,GPIO_Pin_2,0);
#define PB3_In   My_GPIO_Init(GPIOB,GPIO_Pin_3,0);
#define PB4_In   My_GPIO_Init(GPIOB,GPIO_Pin_4,0);
#define PB5_In   My_GPIO_Init(GPIOB,GPIO_Pin_5,0);
#define PB6_In   My_GPIO_Init(GPIOB,GPIO_Pin_6,0);
#define PB7_In   My_GPIO_Init(GPIOB,GPIO_Pin_7,0);
#define PB8_In   My_GPIO_Init(GPIOB,GPIO_Pin_8,0);
#define PB9_In   My_GPIO_Init(GPIOB,GPIO_Pin_9,0);
#define PB10_In  My_GPIO_Init(GPIOB,GPIO_Pin_10,0);
#define PB11_In  My_GPIO_Init(GPIOB,GPIO_Pin_11,0);
#define PB12_In  My_GPIO_Init(GPIOB,GPIO_Pin_12,0);
#define PB13_In  My_GPIO_Init(GPIOB,GPIO_Pin_13,0);
#define PB14_In  My_GPIO_Init(GPIOB,GPIO_Pin_14,0);
#define PB15_In  My_GPIO_Init(GPIOB,GPIO_Pin_15,0);

#define PC0_In   My_GPIO_Init(GPIOC,GPIO_Pin_0,0);
#define PC1_In   My_GPIO_Init(GPIOC,GPIO_Pin_1,0);
#define PC2_In   My_GPIO_Init(GPIOC,GPIO_Pin_2,0);
#define PC3_In   My_GPIO_Init(GPIOC,GPIO_Pin_3,0);
#define PC4_In   My_GPIO_Init(GPIOC,GPIO_Pin_4,0);
#define PC5_In   My_GPIO_Init(GPIOC,GPIO_Pin_5,0);
#define PC6_In   My_GPIO_Init(GPIOC,GPIO_Pin_6,0);
#define PC7_In   My_GPIO_Init(GPIOC,GPIO_Pin_7,0);
#define PC8_In   My_GPIO_Init(GPIOC,GPIO_Pin_8,0);
#define PC9_In   My_GPIO_Init(GPIOC,GPIO_Pin_9,0);
#define PC10_In  My_GPIO_Init(GPIOC,GPIO_Pin_10,0);
#define PC11_In  My_GPIO_Init(GPIOC,GPIO_Pin_11,0);
#define PC12_In  My_GPIO_Init(GPIOC,GPIO_Pin_12,0);
#define PC13_In  My_GPIO_Init(GPIOC,GPIO_Pin_13,0);
#define PC14_In  My_GPIO_Init(GPIOC,GPIO_Pin_14,0);
#define PC15_In  My_GPIO_Init(GPIOC,GPIO_Pin_15,0);

#define PD0_In   My_GPIO_Init(GPIOD,GPIO_Pin_0,0);
#define PD1_In   My_GPIO_Init(GPIOD,GPIO_Pin_1,0);
#define PD2_In   My_GPIO_Init(GPIOD,GPIO_Pin_2,0);
#define PD3_In   My_GPIO_Init(GPIOD,GPIO_Pin_3,0);
#define PD4_In   My_GPIO_Init(GPIOD,GPIO_Pin_4,0);
#define PD5_In   My_GPIO_Init(GPIOD,GPIO_Pin_5,0);
#define PD6_In   My_GPIO_Init(GPIOD,GPIO_Pin_6,0);
#define PD7_In   My_GPIO_Init(GPIOD,GPIO_Pin_7,0);
#define PD8_In   My_GPIO_Init(GPIOD,GPIO_Pin_8,0);
#define PD9_In   My_GPIO_Init(GPIOD,GPIO_Pin_9,0);
#define PD10_In  My_GPIO_Init(GPIOD,GPIO_Pin_10,0);
#define PD11_In  My_GPIO_Init(GPIOD,GPIO_Pin_11,0);
#define PD12_In  My_GPIO_Init(GPIOD,GPIO_Pin_12,0);
#define PD13_In  My_GPIO_Init(GPIOD,GPIO_Pin_13,0);
#define PD14_In  My_GPIO_Init(GPIOD,GPIO_Pin_14,0);
#define PD15_In  My_GPIO_Init(GPIOD,GPIO_Pin_15,0);

#define PE0_In   My_GPIO_Init(GPIOE,GPIO_Pin_0,0);
#define PE1_In   My_GPIO_Init(GPIOE,GPIO_Pin_1,0);
#define PE2_In   My_GPIO_Init(GPIOE,GPIO_Pin_2,0);
#define PE3_In   My_GPIO_Init(GPIOE,GPIO_Pin_3,0);
#define PE4_In   My_GPIO_Init(GPIOE,GPIO_Pin_4,0);
#define PE5_In   My_GPIO_Init(GPIOE,GPIO_Pin_5,0);
#define PE6_In   My_GPIO_Init(GPIOE,GPIO_Pin_6,0);
#define PE7_In   My_GPIO_Init(GPIOE,GPIO_Pin_7,0);
#define PE8_In   My_GPIO_Init(GPIOE,GPIO_Pin_8,0);
#define PE9_In   My_GPIO_Init(GPIOE,GPIO_Pin_9,0);
#define PE10_In  My_GPIO_Init(GPIOE,GPIO_Pin_10,0);
#define PE11_In  My_GPIO_Init(GPIOE,GPIO_Pin_11,0);
#define PE12_In  My_GPIO_Init(GPIOE,GPIO_Pin_12,0);
#define PE13_In  My_GPIO_Init(GPIOE,GPIO_Pin_13,0);
#define PE14_In  My_GPIO_Init(GPIOE,GPIO_Pin_14,0);
#define PE15_In  My_GPIO_Init(GPIOE,GPIO_Pin_15,0);

#define PF0_In   My_GPIO_Init(GPIOF,GPIO_Pin_0,0);
#define PF1_In   My_GPIO_Init(GPIOF,GPIO_Pin_1,0);
#define PF2_In   My_GPIO_Init(GPIOF,GPIO_Pin_2,0);
#define PF3_In   My_GPIO_Init(GPIOF,GPIO_Pin_3,0);
#define PF4_In   My_GPIO_Init(GPIOF,GPIO_Pin_4,0);
#define PF5_In   My_GPIO_Init(GPIOF,GPIO_Pin_5,0);
#define PF6_In   My_GPIO_Init(GPIOF,GPIO_Pin_6,0);
#define PF7_In   My_GPIO_Init(GPIOF,GPIO_Pin_7,0);
#define PF8_In   My_GPIO_Init(GPIOF,GPIO_Pin_8,0);
#define PF9_In   My_GPIO_Init(GPIOF,GPIO_Pin_9,0);
#define PF10_In  My_GPIO_Init(GPIOF,GPIO_Pin_10,0);
#define PF11_In  My_GPIO_Init(GPIOF,GPIO_Pin_11,0);
#define PF12_In  My_GPIO_Init(GPIOF,GPIO_Pin_12,0);
#define PF13_In  My_GPIO_Init(GPIOF,GPIO_Pin_13,0);
#define PF14_In  My_GPIO_Init(GPIOF,GPIO_Pin_14,0);
#define PF15_In  My_GPIO_Init(GPIOF,GPIO_Pin_15,0);

#define PG0_In   My_GPIO_Init(GPIOG,GPIO_Pin_0,0);
#define PG1_In   My_GPIO_Init(GPIOG,GPIO_Pin_1,0);
#define PG2_In   My_GPIO_Init(GPIOG,GPIO_Pin_2,0);
#define PG3_In   My_GPIO_Init(GPIOG,GPIO_Pin_3,0);
#define PG4_In   My_GPIO_Init(GPIOG,GPIO_Pin_4,0);
#define PG5_In   My_GPIO_Init(GPIOG,GPIO_Pin_5,0);
#define PG6_In   My_GPIO_Init(GPIOG,GPIO_Pin_6,0);
#define PG7_In   My_GPIO_Init(GPIOG,GPIO_Pin_7,0);
#define PG8_In   My_GPIO_Init(GPIOG,GPIO_Pin_8,0);
#define PG9_In   My_GPIO_Init(GPIOG,GPIO_Pin_9,0);
#define PG10_In  My_GPIO_Init(GPIOG,GPIO_Pin_10,0);
#define PG11_In  My_GPIO_Init(GPIOG,GPIO_Pin_11,0);
#define PG12_In  My_GPIO_Init(GPIOG,GPIO_Pin_12,0);
#define PG13_In  My_GPIO_Init(GPIOG,GPIO_Pin_13,0);
#define PG14_In  My_GPIO_Init(GPIOG,GPIO_Pin_14,0);
#define PG15_In  My_GPIO_Init(GPIOG,GPIO_Pin_15,0);

//快速IO
#define	Set_A0   GPIOA->BSRR=1<<0 ;
#define	Set_A1   GPIOA->BSRR=1<<1 ;
#define	Set_A2   GPIOA->BSRR=1<<2;
#define	Set_A3   GPIOA->BSRR=1<<3;
#define	Set_A4   GPIOA->BSRR=1<<4;
#define	Set_A5   GPIOA->BSRR=1<<5;
#define	Set_A6   GPIOA->BSRR=1<<6;
#define	Set_A7   GPIOA->BSRR=1<<7;
#define	Set_A8   GPIOA->BSRR=1<<8;
#define	Set_A9   GPIOA->BSRR=1<<9 ;
#define	Set_A10  GPIOA->BSRR=1<<10;
#define	Set_A11  GPIOA->BSRR=1<<11;
#define	Set_A12  GPIOA->BSRR=1<<12;
#define	Set_A13  GPIOA->BSRR=1<<13;
#define	Set_A14  GPIOA->BSRR=1<<14;
#define	Set_A15  GPIOA->BSRR=1<<15;
#define	Set_A(n) GPIOA->BSRR=1<<n;
 
#define	Set_B0   GPIOB->BSRR=1<<0 ;
#define	Set_B1   GPIOB->BSRR=1<<1;
#define	Set_B2   GPIOB->BSRR=1<<2;
#define	Set_B3   GPIOB->BSRR=1<<3;
#define	Set_B4   GPIOB->BSRR=1<<4;
#define	Set_B5   GPIOB->BSRR=1<<5;
#define	Set_B6   GPIOB->BSRR=1<<6;
#define	Set_B7   GPIOB->BSRR=1<<7;
#define	Set_B8   GPIOB->BSRR=1<<8;
#define	Set_B9   GPIOB->BSRR=1<<9 ;
#define	Set_B10  GPIOB->BSRR=1<<10;
#define	Set_B11  GPIOB->BSRR=1<<11;
#define	Set_B12  GPIOB->BSRR=1<<12;
#define	Set_B13  GPIOB->BSRR=1<<13;
#define	Set_B14  GPIOB->BSRR=1<<14;
#define	Set_B15  GPIOB->BSRR=1<<15;
#define	Set_B(n) GPIOB->BSRR=1<<n;

 
#define	Set_C0   GPIOC->BSRR=1<<0 ;
#define	Set_C1   GPIOC->BSRR=1<<1;
#define	Set_C2   GPIOC->BSRR=1<<2;
#define	Set_C3   GPIOC->BSRR=1<<3;
#define	Set_C4   GPIOC->BSRR=1<<4;
#define	Set_C5   GPIOC->BSRR=1<<5;
#define	Set_C6   GPIOC->BSRR=1<<6;
#define	Set_C7   GPIOC->BSRR=1<<7;
#define	Set_C8   GPIOC->BSRR=1<<8;
#define	Set_C9   GPIOC->BSRR=1<<9 ;
#define	Set_C10  GPIOC->BSRR=1<<10;
#define	Set_C11  GPIOC->BSRR=1<<11;
#define	Set_C12  GPIOC->BSRR=1<<12;
#define	Set_C13  GPIOC->BSRR=1<<13;
#define	Set_C14  GPIOC->BSRR=1<<14;
#define	Set_C15  GPIOC->BSRR=1<<15;
#define	Set_C(n) GPIOC->BSRR=1<<n;
 
#define	Set_D0   GPIOD->BSRR=1<<0 ;
#define	Set_D1   GPIOD->BSRR=1<<1;
#define	Set_D2   GPIOD->BSRR=1<<2;
#define	Set_D3   GPIOD->BSRR=1<<3;
#define	Set_D4   GPIOD->BSRR=1<<4;
#define	Set_D5   GPIOD->BSRR=1<<5;
#define	Set_D6   GPIOD->BSRR=1<<6;
#define	Set_D7   GPIOD->BSRR=1<<7;
#define	Set_D8   GPIOD->BSRR=1<<8;
#define	Set_D9   GPIOD->BSRR=1<<9 ;
#define	Set_D10  GPIOD->BSRR=1<<10;
#define	Set_D11  GPIOD->BSRR=1<<11;
#define	Set_D12  GPIOD->BSRR=1<<12;
#define	Set_D13  GPIOD->BSRR=1<<13;
#define	Set_D14  GPIOD->BSRR=1<<14;
#define	Set_D15  GPIOD->BSRR=1<<15;
#define	Set_D(n) GPIOD->BSRR=1<<n;
 
#define	Set_E0   GPIOE->BSRR=1<<0 ;
#define	Set_E1   GPIOE->BSRR=1<<1;
#define	Set_E2   GPIOE->BSRR=1<<2;
#define	Set_E3   GPIOE->BSRR=1<<3;
#define	Set_E4   GPIOE->BSRR=1<<4;
#define	Set_E5   GPIOE->BSRR=1<<5;
#define	Set_E6   GPIOE->BSRR=1<<6;
#define	Set_E7   GPIOE->BSRR=1<<7;
#define	Set_E8   GPIOE->BSRR=1<<8;
#define	Set_E9   GPIOE->BSRR=1<<9 ;
#define	Set_E10  GPIOE->BSRR=1<<10;
#define	Set_E11  GPIOE->BSRR=1<<11;
#define	Set_E12  GPIOE->BSRR=1<<12;
#define	Set_E13  GPIOE->BSRR=1<<13;
#define	Set_E14  GPIOE->BSRR=1<<14;
#define	Set_E15  GPIOE->BSRR=1<<15;
#define	Set_E(n) GPIOE->BSRR=1<<n;

#define	Set_F0   GPIOF->BSRR=1<<0 ;
#define	Set_F1   GPIOF->BSRR=1<<1;
#define	Set_F2   GPIOF->BSRR=1<<2;
#define	Set_F3   GPIOF->BSRR=1<<3;
#define	Set_F4   GPIOF->BSRR=1<<4;
#define	Set_F5   GPIOF->BSRR=1<<5;
#define	Set_F6   GPIOF->BSRR=1<<6;
#define	Set_F7   GPIOF->BSRR=1<<7;
#define	Set_F8   GPIOF->BSRR=1<<8;
#define	Set_F9   GPIOF->BSRR=1<<9 ;
#define	Set_F10  GPIOF->BSRR=1<<10;
#define	Set_F11  GPIOF->BSRR=1<<11;
#define	Set_F12  GPIOF->BSRR=1<<12;
#define	Set_F13  GPIOF->BSRR=1<<13;
#define	Set_F14  GPIOF->BSRR=1<<14;
#define	Set_F15  GPIOF->BSRR=1<<15;
#define	Set_F(n) GPIOF->BSRR=1<<n;

#define	Set_G0   GPIOG->BSRR=1<<0 ;
#define	Set_G1   GPIOG->BSRR=1<<1;
#define	Set_G2   GPIOG->BSRR=1<<2;
#define	Set_G3   GPIOG->BSRR=1<<3;
#define	Set_G4   GPIOG->BSRR=1<<4;
#define	Set_G5   GPIOG->BSRR=1<<5;
#define	Set_G6   GPIOG->BSRR=1<<6;
#define	Set_G7   GPIOG->BSRR=1<<7;
#define	Set_G8   GPIOG->BSRR=1<<8;
#define	Set_G9   GPIOG->BSRR=1<<9 ;
#define	Set_G10  GPIOG->BSRR=1<<10;
#define	Set_G11  GPIOG->BSRR=1<<11;
#define	Set_G12  GPIOG->BSRR=1<<12;
#define	Set_G13  GPIOG->BSRR=1<<13;
#define	Set_G14  GPIOG->BSRR=1<<14;
#define	Set_G15  GPIOG->BSRR=1<<15;
#define	Set_G(n) GPIOG->BSRR=1<<n;

//#define Set_GPIO()

#define	Clr_A0   GPIOA->BRR=1<<0; 
#define	Clr_A1   GPIOA->BRR=1<<1;
#define	Clr_A2   GPIOA->BRR=1<<2;
#define	Clr_A3   GPIOA->BRR=1<<3;
#define	Clr_A4   GPIOA->BRR=1<<4;
#define	Clr_A5   GPIOA->BRR=1<<5;
#define	Clr_A6   GPIOA->BRR=1<<6;
#define	Clr_A7   GPIOA->BRR=1<<7;
#define	Clr_A8   GPIOA->BRR=1<<8;
#define	Clr_A9   GPIOA->BRR=1<<9 ;
#define	Clr_A10  GPIOA->BRR=1<<10;
#define	Clr_A11  GPIOA->BRR=1<<11;
#define	Clr_A12  GPIOA->BRR=1<<12;
#define	Clr_A13  GPIOA->BRR=1<<13;
#define	Clr_A14  GPIOA->BRR=1<<14;
#define	Clr_A15  GPIOA->BRR=1<<15;
#define	Clr_A(n) GPIOA->BRR=1<<n;
 
#define	Clr_B0   GPIOB->BRR=1<<0 ;
#define	Clr_B1   GPIOB->BRR=1<<1;
#define	Clr_B2   GPIOB->BRR=1<<2;
#define	Clr_B3   GPIOB->BRR=1<<3;
#define	Clr_B4   GPIOB->BRR=1<<4;
#define	Clr_B5   GPIOB->BRR=1<<5;
#define	Clr_B6   GPIOB->BRR=1<<6;
#define	Clr_B7   GPIOB->BRR=1<<7;
#define	Clr_B8   GPIOB->BRR=1<<8;
#define	Clr_B9   GPIOB->BRR=1<<9 ;
#define	Clr_B10  GPIOB->BRR=1<<10;
#define	Clr_B11  GPIOB->BRR=1<<11;
#define	Clr_B12  GPIOB->BRR=1<<12;
#define	Clr_B13  GPIOB->BRR=1<<13;
#define	Clr_B14  GPIOB->BRR=1<<14;
#define	Clr_B15  GPIOB->BRR=1<<15;
#define	Clr_B(n) GPIOB->BRR=1<<n;

 
#define	Clr_C0   GPIOC->BRR=1<<0 ;
#define	Clr_C1   GPIOC->BRR=1<<1;
#define	Clr_C2   GPIOC->BRR=1<<2;
#define	Clr_C3   GPIOC->BRR=1<<3;
#define	Clr_C4   GPIOC->BRR=1<<4;
#define	Clr_C5   GPIOC->BRR=1<<5;
#define	Clr_C6   GPIOC->BRR=1<<6;
#define	Clr_C7   GPIOC->BRR=1<<7;
#define	Clr_C8   GPIOC->BRR=1<<8;
#define	Clr_C9   GPIOC->BRR=1<<9 ;
#define	Clr_C10  GPIOC->BRR=1<<10;
#define	Clr_C11  GPIOC->BRR=1<<11;
#define	Clr_C12  GPIOC->BRR=1<<12;
#define	Clr_C13  GPIOC->BRR=1<<13;
#define	Clr_C14  GPIOC->BRR=1<<14;
#define	Clr_C15  GPIOC->BRR=1<<15;
#define	Clr_C(n) GPIOC->BRR=1<<n;
 
#define	Clr_D0   GPIOD->BRR=1<<0 ;
#define	Clr_D1   GPIOD->BRR=1<<1;
#define	Clr_D2   GPIOD->BRR=1<<2;
#define	Clr_D3   GPIOD->BRR=1<<3;
#define	Clr_D4   GPIOD->BRR=1<<4;
#define	Clr_D5   GPIOD->BRR=1<<5;
#define	Clr_D6   GPIOD->BRR=1<<6;
#define	Clr_D7   GPIOD->BRR=1<<7;
#define	Clr_D8   GPIOD->BRR=1<<8;
#define	Clr_D9   GPIOD->BRR=1<<9 ;
#define	Clr_D10  GPIOD->BRR=1<<10;
#define	Clr_D11  GPIOD->BRR=1<<11;
#define	Clr_D12  GPIOD->BRR=1<<12;
#define	Clr_D13  GPIOD->BRR=1<<13;
#define	Clr_D14  GPIOD->BRR=1<<14;
#define	Clr_D15  GPIOD->BRR=1<<15;
#define	Clr_D(n) GPIOD->BRR=1<<n;
 
#define	Clr_E0   GPIOE->BRR=1<<0 ;
#define	Clr_E1   GPIOE->BRR=1<<1;
#define	Clr_E2   GPIOE->BRR=1<<2;
#define	Clr_E3   GPIOE->BRR=1<<3;
#define	Clr_E4   GPIOE->BRR=1<<4;
#define	Clr_E5   GPIOE->BRR=1<<5;
#define	Clr_E6   GPIOE->BRR=1<<6;
#define	Clr_E7   GPIOE->BRR=1<<7;
#define	Clr_E8   GPIOE->BRR=1<<8;
#define	Clr_E9   GPIOE->BRR=1<<9 ;
#define	Clr_E10  GPIOE->BRR=1<<10;
#define	Clr_E11  GPIOE->BRR=1<<11;
#define	Clr_E12  GPIOE->BRR=1<<12;
#define	Clr_E13  GPIOE->BRR=1<<13;
#define	Clr_E14  GPIOE->BRR=1<<14;
#define	Clr_E15  GPIOE->BRR=1<<15;
#define	Clr_E(n) GPIOE->BRR=1<<n;

#define	Clr_F0   GPIOF->BRR=1<<0 ;
#define	Clr_F1   GPIOF->BRR=1<<1;
#define	Clr_F2   GPIOF->BRR=1<<2;
#define	Clr_F3   GPIOF->BRR=1<<3;
#define	Clr_F4   GPIOF->BRR=1<<4;
#define	Clr_F5   GPIOF->BRR=1<<5;
#define	Clr_F6   GPIOF->BRR=1<<6;
#define	Clr_F7   GPIOF->BRR=1<<7;
#define	Clr_F8   GPIOF->BRR=1<<8;
#define	Clr_F9   GPIOF->BRR=1<<9 ;
#define	Clr_F10  GPIOF->BRR=1<<10;
#define	Clr_F11  GPIOF->BRR=1<<11;
#define	Clr_F12  GPIOF->BRR=1<<12;
#define	Clr_F13  GPIOF->BRR=1<<13;
#define	Clr_F14  GPIOF->BRR=1<<14;
#define	Clr_F15  GPIOF->BRR=1<<15;
#define	Clr_F(n) GPIOF->BRR=1<<n;

#define	Clr_G0   GPIOG->BRR=1<<0 ;
#define	Clr_G1   GPIOG->BRR=1<<1;
#define	Clr_G2   GPIOG->BRR=1<<2;
#define	Clr_G3   GPIOG->BRR=1<<3;
#define	Clr_G4   GPIOG->BRR=1<<4;
#define	Clr_G5   GPIOG->BRR=1<<5;
#define	Clr_G6   GPIOG->BRR=1<<6;
#define	Clr_G7   GPIOG->BRR=1<<7;
#define	Clr_G8   GPIOG->BRR=1<<8;
#define	Clr_G9   GPIOG->BRR=1<<9 ;
#define	Clr_G10  GPIOG->BRR=1<<10;
#define	Clr_G11  GPIOG->BRR=1<<11;
#define	Clr_G12  GPIOG->BRR=1<<12;
#define	Clr_G13  GPIOG->BRR=1<<13;
#define	Clr_G14  GPIOG->BRR=1<<14;
#define	Clr_G15  GPIOG->BRR=1<<15;
#define	Clr_G(n) GPIOG->BRR=1<<n;

////////////////////////////////////////////
//快速 读IO
#define A0       ((GPIOA->IDR&(1<<0))?1:0)
#define A1       ((GPIOA->IDR&(1<<1))?1:0)
#define A2       ((GPIOA->IDR&(1<<2))?1:0)
#define A3       ((GPIOA->IDR&(1<<3))?1:0)
#define A4       ((GPIOA->IDR&(1<<4))?1:0)
#define A5       ((GPIOA->IDR&(1<<5))?1:0)
#define A6       ((GPIOA->IDR&(1<<6))?1:0)
#define A7       ((GPIOA->IDR&(1<<7))?1:0)
#define A8       ((GPIOA->IDR&(1<<8))?1:0)
#define A9       ((GPIOA->IDR&(1<<9))?1:0)
#define A10      ((GPIOA->IDR&(1<<10))?1:0)
#define A11      ((GPIOA->IDR&(1<<11))?1:0)
#define A12      ((GPIOA->IDR&(1<<12))?1:0)
#define A13      ((GPIOA->IDR&(1<<13))?1:0)
#define A14      ((GPIOA->IDR&(1<<14))?1:0)
#define A15      ((GPIOA->IDR&(1<<15))?1:0)
#define A(n)     ((GPIOA->IDR&(1<<n))?1:0)

#define B0       ((GPIOB->IDR&(1<<0))?1:0)
#define B1       ((GPIOB->IDR&(1<<1))?1:0)
#define B2       ((GPIOB->IDR&(1<<2))?1:0)
#define B3       ((GPIOB->IDR&(1<<3))?1:0)
#define B4       ((GPIOB->IDR&(1<<4))?1:0)
#define B5       ((GPIOB->IDR&(1<<5))?1:0)
#define B6       ((GPIOB->IDR&(1<<6))?1:0)
#define B7       ((GPIOB->IDR&(1<<7))?1:0)
#define B8       ((GPIOB->IDR&(1<<8))?1:0)
#define B9       ((GPIOB->IDR&(1<<9))?1:0)
#define B10      ((GPIOB->IDR&(1<<10))?1:0)
#define B11      ((GPIOB->IDR&(1<<11))?1:0)
#define B12      ((GPIOB->IDR&(1<<12))?1:0)
#define B13      ((GPIOB->IDR&(1<<13))?1:0)
#define B14      ((GPIOB->IDR&(1<<14))?1:0)
#define B15      ((GPIOB->IDR&(1<<15))?1:0)
#define B(n)     ((GPIOB->IDR&(1<<n))?1:0)

#define C0       ((GPIOC->IDR&(1<<0))?1:0)
#define C1       ((GPIOC->IDR&(1<<1))?1:0)
#define C2       ((GPIOC->IDR&(1<<2))?1:0)
#define C3       ((GPIOC->IDR&(1<<3))?1:0)
#define C4       ((GPIOC->IDR&(1<<4))?1:0)
#define C5       ((GPIOC->IDR&(1<<5))?1:0)
#define C6       ((GPIOC->IDR&(1<<6))?1:0)
#define C7       ((GPIOC->IDR&(1<<7))?1:0)
#define C8       ((GPIOC->IDR&(1<<8))?1:0)
#define C9       ((GPIOC->IDR&(1<<9))?1:0)
#define C10      ((GPIOC->IDR&(1<<10))?1:0)
#define C11      ((GPIOC->IDR&(1<<11))?1:0)
#define C12      ((GPIOC->IDR&(1<<12))?1:0)
#define C13      ((GPIOC->IDR&(1<<13))?1:0)
#define C14      ((GPIOC->IDR&(1<<14))?1:0)
#define C15      ((GPIOC->IDR&(1<<15))?1:0)
#define C(n)     ((GPIOC->IDR&(1<<n))?1:0)

#define D0       ((GPIOD->IDR&(1<<0))?1:0)
#define D1       ((GPIOD->IDR&(1<<1))?1:0)
#define D2       ((GPIOD->IDR&(1<<2))?1:0)
#define D3       ((GPIOD->IDR&(1<<3))?1:0)
#define D4       ((GPIOD->IDR&(1<<4))?1:0)
#define D5       ((GPIOD->IDR&(1<<5))?1:0)
#define D6       ((GPIOD->IDR&(1<<6))?1:0)
#define D7       ((GPIOD->IDR&(1<<7))?1:0)
#define D8       ((GPIOD->IDR&(1<<8))?1:0)
#define D9       ((GPIOD->IDR&(1<<9))?1:0)
#define D10      ((GPIOD->IDR&(1<<10))?1:0)
#define D11      ((GPIOD->IDR&(1<<11))?1:0)
#define D12      ((GPIOD->IDR&(1<<12))?1:0)
#define D13      ((GPIOD->IDR&(1<<13))?1:0)
#define D14      ((GPIOD->IDR&(1<<14))?1:0)
#define D15      ((GPIOD->IDR&(1<<15))?1:0)
#define D(n)     ((GPIOD->IDR&(1<<n))?1:0)

#define E0       ((GPIOE->IDR&(1<<0))?1:0)
#define E1       ((GPIOE->IDR&(1<<1))?1:0)
#define E2       ((GPIOE->IDR&(1<<2))?1:0)
#define E3       ((GPIOE->IDR&(1<<3))?1:0)
#define E4       ((GPIOE->IDR&(1<<4))?1:0)
#define E5       ((GPIOE->IDR&(1<<5))?1:0)
#define E6       ((GPIOE->IDR&(1<<6))?1:0)
#define E7       ((GPIOE->IDR&(1<<7))?1:0)
#define E8       ((GPIOE->IDR&(1<<8))?1:0)
#define E9       ((GPIOE->IDR&(1<<9))?1:0)
#define E10      ((GPIOE->IDR&(1<<10))?1:0)
#define E11      ((GPIOE->IDR&(1<<11))?1:0)
#define E12      ((GPIOE->IDR&(1<<12))?1:0)
#define E13      ((GPIOE->IDR&(1<<13))?1:0)
#define E14      ((GPIOE->IDR&(1<<14))?1:0)
#define E15      ((GPIOE->IDR&(1<<15))?1:0)
#define E(n)     ((GPIOE->IDR&(1<<n))?1:0)

#define F0       ((GPIOF->IDR&(1<<0))?1:0)
#define F1       ((GPIOF->IDR&(1<<1))?1:0)
#define F2       ((GPIOF->IDR&(1<<2))?1:0)
#define F3       ((GPIOF->IDR&(1<<3))?1:0)
#define F4       ((GPIOF->IDR&(1<<4))?1:0)
#define F5       ((GPIOF->IDR&(1<<5))?1:0)
#define F6       ((GPIOF->IDR&(1<<6))?1:0)
#define F7       ((GPIOF->IDR&(1<<7))?1:0)
#define F8       ((GPIOF->IDR&(1<<8))?1:0)
#define F9       ((GPIOF->IDR&(1<<9))?1:0)
#define F10      ((GPIOF->IDR&(1<<10))?1:0)
#define F11      ((GPIOF->IDR&(1<<11))?1:0)
#define F12      ((GPIOF->IDR&(1<<12))?1:0)
#define F13      ((GPIOF->IDR&(1<<13))?1:0)
#define F14      ((GPIOF->IDR&(1<<14))?1:0)
#define F15      ((GPIOF->IDR&(1<<15))?1:0)
#define F(n)     ((GPIOF->IDR&(1<<n))?1:0)

#define G0       ((GPIOG->IDR&(1<<0))?1:0)
#define G1       ((GPIOG->IDR&(1<<1))?1:0)
#define G2       ((GPIOG->IDR&(1<<2))?1:0)
#define G3       ((GPIOG->IDR&(1<<3))?1:0)
#define G4       ((GPIOG->IDR&(1<<4))?1:0)
#define G5       ((GPIOG->IDR&(1<<5))?1:0)
#define G6       ((GPIOG->IDR&(1<<6))?1:0)
#define G7       ((GPIOG->IDR&(1<<7))?1:0)
#define G8       ((GPIOG->IDR&(1<<8))?1:0)
#define G9       ((GPIOG->IDR&(1<<9))?1:0)
#define G10      ((GPIOG->IDR&(1<<10))?1:0)
#define G11      ((GPIOG->IDR&(1<<11))?1:0)
#define G12      ((GPIOG->IDR&(1<<12))?1:0)
#define G13      ((GPIOG->IDR&(1<<13))?1:0)
#define G14      ((GPIOG->IDR&(1<<14))?1:0)
#define G15      ((GPIOG->IDR&(1<<15))?1:0)
#define G(n)     ((GPIOG->IDR&(1<<n))?1:0)


//位带操作,实现51类似的GPIO控制功能
//具体实现思想,参考<<CM3权威指南>>第五章(87页~92页).
//IO口操作宏定义
#define BITBAND(addr, bitnum) ((addr & 0xF0000000)+0x2000000+((addr &0xFFFFF)<<5)+(bitnum<<2)) 
#define MEM_ADDR(addr)  *((volatile unsigned long  *)(addr)) 
#define BIT_ADDR(addr, bitnum)   MEM_ADDR(BITBAND(addr, bitnum)) 
//IO口地址映射
#define GPIOA_ODR_Addr    (GPIOA_BASE+12) //0x4001080C 
#define GPIOB_ODR_Addr    (GPIOB_BASE+12) //0x40010C0C 
#define GPIOC_ODR_Addr    (GPIOC_BASE+12) //0x4001100C 
#define GPIOD_ODR_Addr    (GPIOD_BASE+12) //0x4001140C 
#define GPIOE_ODR_Addr    (GPIOE_BASE+12) //0x4001180C 
#define GPIOF_ODR_Addr    (GPIOF_BASE+12) //0x40011A0C    
#define GPIOG_ODR_Addr    (GPIOG_BASE+12) //0x40011E0C    

#define GPIOA_IDR_Addr    (GPIOA_BASE+8) //0x40010808 
#define GPIOB_IDR_Addr    (GPIOB_BASE+8) //0x40010C08 
#define GPIOC_IDR_Addr    (GPIOC_BASE+8) //0x40011008 
#define GPIOD_IDR_Addr    (GPIOD_BASE+8) //0x40011408 
#define GPIOE_IDR_Addr    (GPIOE_BASE+8) //0x40011808 
#define GPIOF_IDR_Addr    (GPIOF_BASE+8) //0x40011A08 
#define GPIOG_IDR_Addr    (GPIOG_BASE+8) //0x40011E08 
 
//IO口操作,只对单一的IO口!
//确保n的值小于16!
#define PAout(n)   BIT_ADDR(GPIOA_ODR_Addr,n)  //输出 
#define PAin(n)    BIT_ADDR(GPIOA_IDR_Addr,n)  //输入 

#define PBout(n)   BIT_ADDR(GPIOB_ODR_Addr,n)  //输出 
#define PBin(n)    BIT_ADDR(GPIOB_IDR_Addr,n)  //输入 

#define PCout(n)   BIT_ADDR(GPIOC_ODR_Addr,n)  //输出 
#define PCin(n)    BIT_ADDR(GPIOC_IDR_Addr,n)  //输入 

#define PDout(n)   BIT_ADDR(GPIOD_ODR_Addr,n)  //输出 
#define PDin(n)    BIT_ADDR(GPIOD_IDR_Addr,n)  //输入 

#define PEout(n)   BIT_ADDR(GPIOE_ODR_Addr,n)  //输出 
#define PEin(n)    BIT_ADDR(GPIOE_IDR_Addr,n)  //输入

#define PFout(n)   BIT_ADDR(GPIOF_ODR_Addr,n)  //输出 
#define PFin(n)    BIT_ADDR(GPIOF_IDR_Addr,n)  //输入

#define PGout(n)   BIT_ADDR(GPIOG_ODR_Addr,n)  //输出 
#define PGin(n)    BIT_ADDR(GPIOG_IDR_Addr,n)  //输入



#endif
