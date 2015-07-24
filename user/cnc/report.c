/*
  report.c - reporting and messaging methods
  Part of Grbl

  The MIT License (MIT)

  GRBL(tm) - Embedded CNC g-code interpreter and motion-controller
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
/* 
  This file functions as the primary feedback interface for Grbl. Any outgoing data, such 
  as the protocol status messages, feedback messages, and status reports, are stored here.
  For the most part, these functions primarily are called from protocol.c methods. If a 
  different style feedback is desired (i.e. JSON), then a user can change these following 
  methods to accomodate their needs.
*/
#include "stm32f10x.h"
//#include <avr/pgmspace.h>
#include "report.h"
#include "print.h"
#include "settings.h"
#include "nuts_bolts.h"
#include "gcode.h"
#include "coolant_control.h"
#include "usart.h"
#include "delay.h"


// Handles the primary confirmation protocol response for streaming interfaces and human-feedback.
// For every incoming line, this method responds with an 'ok' for a successful command or an 
// 'error:'  to indicate some error event with the line or some critical system error during 
// operation. Errors events can originate from the g-code parser, settings module, or asynchronously
// from a critical error, such as a triggered hard limit. Interface should always monitor for these
// responses.
// NOTE: In silent mode, all error codes are greater than zero.
// TODO: Install silent mode to return only numeric values, primarily for GUIs.
void report_status_message(uint8_t status_code) 
{
  if (status_code == 0) { // STATUS_OK
    printf(("ok\r\n"));
		//printf(("@"));
  } else {
    printf(("error: "));
    switch(status_code) {          
      case STATUS_BAD_NUMBER_FORMAT:
      printf(("Bad number format")); break;
      case STATUS_EXPECTED_COMMAND_LETTER:
      printf(("Expected command letter")); break;
      case STATUS_UNSUPPORTED_STATEMENT:
      printf(("Unsupported statement")); break;
      case STATUS_ARC_RADIUS_ERROR:
      printf(("Invalid radius")); break;
      case STATUS_MODAL_GROUP_VIOLATION:
      printf(("Modal group violation")); break;
      case STATUS_INVALID_STATEMENT:
      printf(("Invalid statement")); break;
      case STATUS_SETTING_DISABLED:
      printf(("Setting disabled")); break;
      case STATUS_SETTING_VALUE_NEG:
      printf(("Value < 0.0")); break;
      case STATUS_SETTING_STEP_PULSE_MIN:
      printf(("Value < 3 usec")); break;
      case STATUS_SETTING_READ_FAIL:
      printf(("EEPROM read fail. Using defaults")); break;
      case STATUS_IDLE_ERROR:
      printf(("Busy or queued")); break;
      case STATUS_ALARM_LOCK:
      printf(("Alarm lock")); break;
      case STATUS_OVERFLOW:
      printf(("Line overflow")); break;
    }
    printf(("\r\n"));
  }
}

// Prints alarm messages.
void report_alarm_message(int8_t alarm_code)
{
  printf(("ALARM: "));
  switch (alarm_code) {
    case ALARM_HARD_LIMIT: 
    printf(("Hard limit")); break;
    case ALARM_ABORT_CYCLE: 
    printf(("Abort during cycle")); break;
  }
  printf((". MPos?\r\n"));
  delay_ms(500); // Force delay to ensure message clears serial write buffer.
}

// Prints feedback messages. This serves as a centralized method to provide additional
// user feedback for things that are not of the status/alarm message protocol. These are
// messages such as setup warnings, switch toggling, and how to exit alarms.
// NOTE: For interfaces, messages are always placed within brackets. And if silent mode
// is installed, the message number codes are less than zero.
// TODO: Install silence feedback messages option in settings
void report_feedback_message(uint8_t message_code)
{
  printf(("["));
  switch(message_code) {
    case MESSAGE_CRITICAL_EVENT:
    printf(("Reset to continue")); break;
    case MESSAGE_ALARM_LOCK:
    printf(("'$H'|'$X' to unlock")); break;
    case MESSAGE_ALARM_UNLOCK:
    printf(("Caution: Unlocked")); break;
    case MESSAGE_ENABLED:
    printf(("Enabled")); break;
    case MESSAGE_DISABLED:
    printf(("Disabled")); break;    
  }
  printf(("]\r\n"));
}


// Welcome message
void report_init_message()
{
  printf(("\r\nGrbl " GRBL_VERSION " ['$' for help]\r\n"));
}

// Grbl help message
void report_grbl_help() {
  printf(("$$ (view Grbl settings)\r\n"
                      "$# (view # parameters)\r\n"
                      "$G (view parser state)\r\n"
                      "$N (view startup blocks)\r\n"
                      "$x=value (save Grbl setting)\r\n"
                      "$Nx=line (save startup block)\r\n"
                      "$C (check gcode mode)\r\n"
                      "$X (kill alarm lock)\r\n"
                      "$H (run homing cycle)\r\n"
                      "~ (cycle start)\r\n"
                      "! (feed hold)\r\n"
                      "? (current status)\r\n"
                      "ctrl-x (reset Grbl)\r\n"));
}

// Grbl global settings print out.
// NOTE: The numbering scheme here must correlate to storing in settings.c
void report_grbl_settings() {
  printf(("$0=")); printFloat(settings.steps_per_mm[X_AXIS]);
  printf((" (x, step/mm)\r\n$1=")); printFloat(settings.steps_per_mm[Y_AXIS]);
  printf((" (y, step/mm)\r\n$2=")); printFloat(settings.steps_per_mm[Z_AXIS]);
  printf((" (z, step/mm)\r\n$3=")); printInteger(settings.pulse_microseconds);
  printf((" (step pulse, usec)\r\n$4=")); printFloat(settings.default_feed_rate);
  printf((" (default feed, mm/min)\r\n$5=")); printFloat(settings.default_seek_rate);
  printf((" (default seek, mm/min)\r\n$6=")); printInteger(settings.invert_mask); 
  printf((" (step port invert mask, int:")); print_uint8_base2(settings.invert_mask);  
  printf((")\r\n$7=")); printInteger(settings.stepper_idle_lock_time);
  printf((" (step idle delay, msec)\r\n$8=")); printFloat(settings.acceleration/(60*60)); // Convert from mm/min^2 for human readability
  printf((" (acceleration, mm/sec^2)\r\n$9=")); printFloat(settings.junction_deviation);
  printf((" (junction deviation, mm)\r\n$10=")); printFloat(settings.mm_per_arc_segment);
  printf((" (arc, mm/segment)\r\n$11=")); printInteger(settings.n_arc_correction);
  printf((" (n-arc correction, int)\r\n$12=")); printInteger(settings.decimal_places);
  printf((" (n-decimals, int)\r\n$13=")); printInteger(bit_istrue(settings.flags,BITFLAG_REPORT_INCHES));
  printf((" (report inches, bool)\r\n$14=")); printInteger(bit_istrue(settings.flags,BITFLAG_AUTO_START));
  printf((" (auto start, bool)\r\n$15=")); printInteger(bit_istrue(settings.flags,BITFLAG_INVERT_ST_ENABLE));
  printf((" (invert step enable, bool)\r\n$16=")); printInteger(bit_istrue(settings.flags,BITFLAG_HARD_LIMIT_ENABLE));
  printf((" (hard limits, bool)\r\n$17=")); printInteger(bit_istrue(settings.flags,BITFLAG_HOMING_ENABLE));
  printf((" (homing cycle, bool)\r\n$18=")); printInteger(settings.homing_dir_mask);
  printf((" (homing dir invert mask, int:")); print_uint8_base2(settings.homing_dir_mask);  
  printf((")\r\n$19=")); printFloat(settings.homing_feed_rate);
  printf((" (homing feed, mm/min)\r\n$20=")); printFloat(settings.homing_seek_rate);
  printf((" (homing seek, mm/min)\r\n$21=")); printInteger(settings.homing_debounce_delay);
  printf((" (homing debounce, msec)\r\n$22=")); printFloat(settings.homing_pulloff);
  printf((" (homing pull-off, mm)\r\n")); 
}


// Prints gcode coordinate offset parameters
void report_gcode_parameters()
{
  float coord_data[N_AXIS];
  uint8_t coord_select, i;
  for (coord_select = 0; coord_select <= SETTING_INDEX_NCOORD; coord_select++) { 
    if (!(settings_read_coord_data(coord_select,coord_data))) { 
      report_status_message(STATUS_SETTING_READ_FAIL); 
      return;
    } 
    printf(("[G"));
    switch (coord_select) {
      case 0: printf(("54:")); break;
      case 1: printf(("55:")); break;
      case 2: printf(("56:")); break;
      case 3: printf(("57:")); break;
      case 4: printf(("58:")); break;
      case 5: printf(("59:")); break;
      case 6: printf(("28:")); break;
      case 7: printf(("30:")); break;
      // case 8: printf(("92:")); break; // G92.2, G92.3 not supported. Hence not stored.  
    }           
    for (i=0; i<N_AXIS; i++) {
      if (bit_istrue(settings.flags,BITFLAG_REPORT_INCHES)) { printFloat(coord_data[i]*INCH_PER_MM); }
      else { printFloat(coord_data[i]); }
      if (i < (N_AXIS-1)) { printf((",")); }
      else { printf(("]\r\n")); }
    } 
  }
  printf(("[G92:")); // Print G92,G92.1 which are not persistent in memory
  for (i=0; i<N_AXIS; i++) {
    if (bit_istrue(settings.flags,BITFLAG_REPORT_INCHES)) { printFloat(gc.coord_offset[i]*INCH_PER_MM); }
    else { printFloat(gc.coord_offset[i]); }
    if (i < (N_AXIS-1)) { printf((",")); }
    else { printf(("]\r\n")); }
  } 
}


// Print current gcode parser mode state
void report_gcode_modes()
{
  switch (gc.motion_mode) {
    case MOTION_MODE_SEEK : printf(("[G0")); break;
    case MOTION_MODE_LINEAR : printf(("[G1")); break;
    case MOTION_MODE_CW_ARC : printf(("[G2")); break;
    case MOTION_MODE_CCW_ARC : printf(("[G3")); break;
    case MOTION_MODE_CANCEL : printf(("[G80")); break;
  }

  printf((" G"));
  printInteger(gc.coord_select+54);
  
  switch (gc.plane_axis_0) {
    case X_AXIS: printf((" G17")); break;
    case Z_AXIS: printf((" G18")); break;
    default: printf((" G19")); 
  }
  
  if (gc.inches_mode) { printf((" G20")); }
  else { printf((" G21")); }
  
  if (gc.absolute_mode) { printf((" G90")); }
  else { printf((" G91")); }
  
  if (gc.inverse_feed_rate_mode) { printf((" G93")); }
  else { printf((" G94")); }
    
  switch (gc.program_flow) {
    case PROGRAM_FLOW_RUNNING : printf((" M0")); break;
    case PROGRAM_FLOW_PAUSED : printf((" M1")); break;
    case PROGRAM_FLOW_COMPLETED : printf((" M2")); break;
  }

  switch (gc.spindle_direction) {
    case 1 : printf((" M3")); break;
    case -1 : printf((" M4")); break;
    case 0 : printf((" M5")); break;
  }
  
  switch (gc.coolant_mode) {
    case COOLANT_DISABLE : printf((" M9")); break;
    case COOLANT_FLOOD_ENABLE : printf((" M8")); break;
    #ifdef ENABLE_M7
      case COOLANT_MIST_ENABLE : printf((" M7")); break;
    #endif
  }
  
  printf((" T"));
  printInteger(gc.tool);
  
  printf((" F"));
  if (gc.inches_mode) { printFloat(gc.feed_rate*INCH_PER_MM); }
  else { printFloat(gc.feed_rate); }

  printf(("]\r\n"));
}

// Prints specified startup line
void report_startup_line(uint8_t n, char *line)
{
  printf(("$N")); printInteger(n);
  printf(("=")); printString(line);
  printf(("\r\n"));
}

 // Prints real-time data. This function grabs a real-time snapshot of the stepper subprogram 
 // and the actual location of the CNC machine. Users may change the following function to their
 // specific needs, but the desired real-time data report must be as short as possible. This is
 // requires as it minimizes the computational overhead and allows grbl to keep running smoothly, 
 // especially during g-code programs with fast, short line segments and high frequency reports (5-20Hz).
void report_realtime_status()
{
  // **Under construction** Bare-bones status report. Provides real-time machine position relative to 
  // the system power on location (0,0,0) and work coordinate position (G54 and G92 applied). Eventually
  // to be added are distance to go on block, processed block id, and feed rate. Also a settings bitmask
  // for a user to select the desired real-time data.
  uint8_t i;
  int32_t current_position[3]; // Copy current state of the system position variable
  memcpy(current_position,sys.position,sizeof(sys.position));
  float print_position[3];
 
  // Report current machine state
  switch (sys.state) {
    case STATE_IDLE: printf(("<Idle")); break;
//    case STATE_INIT: printf(("[Init")); break; // Never observed
    case STATE_QUEUED: printf(("<Queue")); break;
    case STATE_CYCLE: printf(("<Run")); break;
    case STATE_HOLD: printf(("<Hold")); break;
    case STATE_HOMING: printf(("<Home")); break;
    case STATE_ALARM: printf(("<Alarm")); break;
    case STATE_CHECK_MODE: printf(("<Check")); break;
  }
 
  // Report machine position
  printf((",MPos:")); 
  for (i=0; i<= 2; i++) {
    print_position[i] = current_position[i]/settings.steps_per_mm[i];
    if (bit_istrue(settings.flags,BITFLAG_REPORT_INCHES)) { print_position[i] *= INCH_PER_MM; }
    printFloat(print_position[i]);
    printf((","));
  }
  
  // Report work position
  printf(("WPos:")); 
  for (i=0; i<= 2; i++) {
    if (bit_istrue(settings.flags,BITFLAG_REPORT_INCHES)) {
      print_position[i] -= (gc.coord_system[i]+gc.coord_offset[i])*INCH_PER_MM;
    } else {
      print_position[i] -= gc.coord_system[i]+gc.coord_offset[i];
    }
    printFloat(print_position[i]);
    if (i < 2) { printf((",")); }
  }
    
  printf((">\r\n"));
}
