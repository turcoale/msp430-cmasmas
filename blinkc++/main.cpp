/*
 * main.cpp
 *
 *  Created on: Apr 27, 2011
 *      Author: mark
 *
 *      Copyright (c) 2011 Engine12, LLC
 *
 *	   www.engine12.com
 */


#include "CTimer.h"
#include "CWDTimer.h"
#include "CBasicClockModule.h"
#include "msp430_defs.h"
//#include <msp430x20x2.h>



static CTimer_A 			timer_A;
static CWDTimer 			timer_WDT;
static CBasicClockModule	basicClock;

void initGPIO(void) {
  P_PORT1_REGS->DIR |= (LED0 | LED1);//Set LED pins as outputs
  LED_ON(LED0 | LED1); //Turn on both LEDs
}


int main(void) {

  timer_WDT.Stop();// Stop WDT

  initGPIO(); //Setup LEDs

  basicClock.SelectLowFreqClock(CBasicClockModule::VLOCLK);

//  timer_A.SetInterrupt(2, (pfunction_t)&TIMERA0_ISR);
  timer_A.SetInterrupt(2);

  Enable_Interrupts();//Enable global interrupts

  while(1) {
//Loop forever, interrupts take care of the rest
  }
}






