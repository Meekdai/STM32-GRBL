/*
  spindle_control.c - spindle control methods
  Part of Grbl

  The MIT License (MIT)

  GRBL(tm) - Embedded CNC g-code interpreter and motion-controller
  Copyright (c) 2009-2011 Simen Svale Skogsrud
  Copyright (c) 2012 Sungeun K. Jeon

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
#include "stm32f10x.h"
#include "settings.h"
#include "spindle_control.h"
#include "planner.h"
#include "gpio.h"

static uint8_t current_direction;

void spindle_init()
{
  current_direction = 0;
  SPINDLE_ENABLE_DDR |= (1<<SPINDLE_ENABLE_BIT);
  SPINDLE_DIRECTION_DDR |= (1<<SPINDLE_DIRECTION_BIT);  
	PA7_OUT
	spindle_stop();
}

void spindle_stop()
{
	Clr_A7
  SPINDLE_ENABLE_PORT &= ~(1<<SPINDLE_ENABLE_BIT);
}

void spindle_run(int8_t direction) //, uint16_t rpm) 
{
	
	NVIC_EnableIRQ (TIM2_IRQn);  
	NVIC_SetPriority(TIM2_IRQn, 1);
	
  if (direction != current_direction) {
    plan_synchronize();
    if (direction) {
      if(direction > 0) {  //开激光 M3
				Set_A7
        SPINDLE_DIRECTION_PORT &= ~(1<<SPINDLE_DIRECTION_BIT);
      } else {//开弱光 M4
        SPINDLE_DIRECTION_PORT |= 1<<SPINDLE_DIRECTION_BIT;
      }
      SPINDLE_ENABLE_PORT |= 1<<SPINDLE_ENABLE_BIT;
    } else {
      spindle_stop();   //关掉激光    
    }
    current_direction = direction;
  }
}
