/***************************************************************/
//2013.8.27  Copyright@ rhyme呆瓜云
/***************************************************************/
#include "stm32f10x.h"
#include "stdio.h"
#include "gpio.h"
#include "usart.h"
#include "delay.h"
#include "tim.h"
#include "eeprom.h"
#include "pwm.h"

#include "config.h"
#include "planner.h"
#include "nuts_bolts.h"
#include "stepper.h"
#include "spindle_control.h"
#include "coolant_control.h"
#include "motion_control.h"
#include "gcode.h"
#include "protocol.h"
#include "limits.h"
#include "report.h"
#include "settings.h"
#include "serial.h"

/***************************************************************/
u8 USART_RX[60]={""};
u8 USART_mark=0;
u8 Press_mark=0;
int USART_control=0;
int USART_data=0;
u16 USART_RX_STA;       //接收状态标记	

uint16_t ee;//EEPROM变量
u8 mo=1;
/***************************************************************/


int main(void)
{
	RCC_Configuration();
	delay_Configuration(72);
	USART1_Configuration(9600);
	PB9_OUT
	Set_B9
	
//	PB8_OUT
//	Set_B8
//	delay_ms(200);
//	Clr_B8
//	delay_ms(200);
//	Set_B8
//	delay_ms(300);
//	Clr_B8
	
//	PA7_OUT
//	Clr_A7
//	
//	PA6_OUT
//	Clr_A6
	
	
	
	Motors_Set_GPIO();//电机IO口定义
	
//	FLASH_Unlock();
//	EE_Init();
	settings_reset(true);//GRBL重置所有参数
	//读取EEPROM 设定FEED和SEEK
//	if(!EE_ReadVariable(32,&ee))
//	{
//		settings.default_feed_rate = ee;
//		settings.default_seek_rate = ee;
//	}
	TIM_Configuration(TIM2,1001,1,1);
	st_init(); //步进电机初始化，用这两个中断，通过 “布雷森汉姆直线算法”同时控制三个步进输出。
	
	memset(&sys, 0, sizeof(sys));  //清数组
	
	sys.abort = true;   // 设置abort 标志着初始化完成
  sys.state = STATE_INIT;  // 设置一个警示标志来指示未知的初始位置
	
//	TIM3_PWM_Configuration(20,3600,1,1,0,0);
//	PA6_OUT
//	Set_A6
//	PA7_OUT
//	Clr_A7
	while(1)
	{
		
		  if (sys.abort) {
      // Reset system.
      serial_reset_read_buffer(); // Clear serial read buffer
      plan_init(); // Clear block buffer and planner variables
      gc_init(); // Set g-code parser to default state
      protocol_init(); // Clear incoming line data and execute startup lines
      spindle_init();
      coolant_init();
      limits_init();
      st_reset(); // Clear stepper subsystem variables.

      // Sync cleared gcode and planner positions to current system position, which is only
      // cleared upon startup, not a reset/abort. 
      sys_sync_current_position();

      // Reset system variables.
      sys.abort = false;
      sys.execute = 0;
      if (bit_istrue(settings.flags,BITFLAG_AUTO_START)) { sys.auto_start = true; }
      
      // Check for power-up and set system alarm if homing is enabled to force homing cycle
      // by setting Grbl's alarm state. Alarm locks out all g-code commands, including the
      // startup scripts, but allows access to settings and internal commands. Only a homing
      // cycle '$H' or kill alarm locks '$X' will disable the alarm.
      // NOTE: The startup script will run after successful completion of the homing cycle, but
      // not after disabling the alarm locks. Prevents motion startup blocks from crashing into
      // things uncontrollably. Very bad.
      #ifdef HOMING_INIT_LOCK
        if (sys.state == STATE_INIT && bit_istrue(settings.flags,BITFLAG_HOMING_ENABLE)) { sys.state = STATE_ALARM; }
      #endif
      
      // Check for and report alarm state after a reset, error, or an initial power up.
      if (sys.state == STATE_ALARM) {
        report_feedback_message(MESSAGE_ALARM_LOCK); 
      } else {
        // All systems go. Set system to ready and execute startup script.
        sys.state = STATE_IDLE;
        protocol_execute_startup(); 
      }
    }	
			

		
    protocol_execute_runtime();
    protocol_process(); // ... process the serial protocol
    if(mo==0) {MotorsEnable(0x00);mo=10;}
		
//		delay_ms(500);
//		Set_B12
//		delay_ms(500);
//		Clr_B12
//		printf(" This is the STM32 Demo !!! \r\n");
	}
	
}
/***************************************************************/

