/*
  stepper.h - stepper motor driver: executes motion plans of planner.c using the stepper motors
  Part of Grbl

  The MIT License (MIT)

  GRBL(tm) - Embedded CNC g-code interpreter and motion-controller
  Copyright (c) 2009-2011 Simen Svale Skogsrud
  Copyright (c) 2011 Sungeun K. Jeon

  Permission is hereby granted, free of charge, to any person obtaining a copy
  of this software and associated documentation files (the "Software"), to deal
  in the Software without restriction, including without limitation the rights
  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
  copies of the Software, and to permit persons to whom the Software is
  furnished to do so, subject to the following conditions:

  The above copyright notice and this permission notice shall be included in
  all copies or substantial portions of the Software.

  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
  THE SOFTWARE.
*/

#ifndef stepper_h
#define stepper_h 

//#include <avr/io.h>
#include "stm32f10x.h"
#include "gpio.h"
// Initialize and setup the stepper motor subsystem
void st_init(void);
void Motors_Set_GPIO(void);
void MotorsEnable(char motors);
// Enable steppers, but cycle does not start unless called by motion control or runtime command.
void st_wake_up(void);

// Immediately disables steppers
void st_go_idle(void);

// Reset the stepper subsystem variables       
void st_reset(void);
             
// Notify the stepper subsystem to start executing the g-code program in buffer.
void st_cycle_start(void);

// Reinitializes the buffer after a feed hold for a resume.
void st_cycle_reinitialize(void); 

// Initiates a feed hold of the running program
void st_feed_hold(void);


//#define MOTOR1_ENABLE 	Clr_E9
//#define MOTOR1_DISABLE 	Set_E9
//#define MOTOR2_ENABLE 	Clr_E15
//#define MOTOR2_DISABLE 	Set_E15
//#define MOTOR3_ENABLE 	Clr_E9
//#define MOTOR3_DISABLE 	Set_E9

//#define MOTOR1_LEFT			Clr_E7
//#define MOTOR1_RIGHT		Set_E7
//#define MOTOR2_LEFT			Clr_E13
//#define MOTOR2_RIGHT		Set_E13
//#define MOTOR3_UP				Clr_E1
//#define MOTOR3_DOWN			Set_E1

//#define	MOTOR1					GPIOB
//#define MOTOR1_PIN			(1 << 1)
//#define	MOTOR2					GPIOE
//#define MOTOR2_PIN			(1 << 11)
//#define	MOTOR3					GPIOE
//#define MOTOR3_PIN			(1 << 2)



#define PIN1_PIN				(1 << 1)
#define PIN1_PORT				GPIOA
#define PIN2_PIN				(1 << 2)
#define PIN2_PORT				GPIOA
#define PIN3_PIN				(1 << 0)
#define PIN3_PORT				GPIOA
#define PIN4_PIN				(1 << 4)
#define PIN4_PORT				GPIOA
#define PIN5_PIN				(1 << 5)
#define PIN5_PORT				GPIOA
#define PIN6_PIN				(1 << 3)
#define PIN6_PORT				GPIOA
#define PIN7_PIN				(1 << 9)
#define PIN7_PORT				GPIOD
#define PIN8_PIN				(1 << 11)
#define PIN8_PORT				GPIOD
#define PIN9_PIN				(1 << 13)
#define PIN9_PORT				GPIOD
#define PIN10_PIN				(1 << 1)
#define PIN10_PORT			GPIOD
#define PIN11_PIN				(1 << 3)
#define PIN11_PORT			GPIOD
#define PIN12_PIN				(1 << 5)
#define PIN12_PORT			GPIOD
#define PIN14_PIN				(1 << 14)
#define PIN14_PORT			GPIOD
#define PIN15_PIN				(1 << 12)
#define PIN15_PORT			GPIOD
#define PIN16_PIN				(1 << 10)
#define PIN16_PORT			GPIOD
#define PIN17_PIN				(1 << 8)
#define PIN17_PORT			GPIOD
#define PIN18_PIN				(1 << 10)
#define PIN18_PORT			GPIOB
#define PIN19_PIN				(1 << 14)
#define PIN19_PORT			GPIOE
#define PIN20_PIN				(1 << 12)
#define PIN20_PORT			GPIOE
#define PIN21_PIN				(1 << 10)
#define PIN21_PORT			GPIOE
#define PIN22_PIN				(1 << 8)
#define PIN22_PORT			GPIOE
#define PIN23_PIN				(1 << 2)
#define PIN23_PORT			GPIOB
#define PIN24_PIN				(1 << 2)
#define PIN24_PORT			GPIOA
#define PIN25_PIN				(1 << 0)
#define PIN25_PORT			GPIOA


#define MOTOR1_ENABLE 	PIN3_PORT->BSRR = PIN3_PIN
#define MOTOR1_DISABLE 	PIN3_PORT->BRR  = PIN3_PIN
#define MOTOR2_ENABLE 	PIN6_PORT->BSRR = PIN6_PIN
#define MOTOR2_DISABLE 	PIN6_PORT->BRR  = PIN6_PIN
#define MOTOR3_ENABLE 	PIN9_PORT->BSRR = PIN9_PIN
#define MOTOR3_DISABLE 	PIN9_PORT->BRR  = PIN9_PIN

#define MOTOR1_LEFT			PIN2_PORT->BSRR = PIN2_PIN
#define MOTOR1_RIGHT		PIN2_PORT->BRR  = PIN2_PIN
#define MOTOR2_LEFT			PIN5_PORT->BSRR = PIN5_PIN
#define MOTOR2_RIGHT		PIN5_PORT->BRR  = PIN5_PIN
#define MOTOR3_UP				PIN8_PORT->BRR  = PIN8_PIN
#define MOTOR3_DOWN			PIN8_PORT->BSRR = PIN8_PIN

#define	MOTOR1					PIN1_PORT
#define MOTOR1_PIN			PIN1_PIN
#define	MOTOR2					PIN4_PORT
#define MOTOR2_PIN			PIN4_PIN
#define	MOTOR3					PIN7_PORT
#define MOTOR3_PIN			PIN7_PIN




#endif
