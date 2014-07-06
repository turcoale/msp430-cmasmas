/*
 * CTimer.h
 *
 *  Created on: Apr 28, 2011
 *      Author: mark
 *
 *     Copyright (c) 2011 Engine12, LLC
 *
 *	   www.engine12.com
 */

#ifndef CTIMER_H_
#define CTIMER_H_

#include "msp430_defs.h"

#define CCIE BIT(4)

#define TIMER_A_BASE  (0x0160)

typedef volatile struct ATTR_PACKED_ALIGNED_WORD _MSP430_TIMERA {

		uint16_t TACTL 		;      /*Read/write    0160    */
		uint16_t TACCTL0 	;      /*Read/write    0162    */
		uint16_t TACCTL1 	;      /*Read/write    0164    */
		uint16_t TACCTL2	;      /*Read/write    0166    */
		uint16_t pad[4]     ;	   /* 0168 016A 016C 016E  */
		uint16_t TAR 		;      /*Read/write    0170    */
		uint16_t TACCR0 	;      /*Read/write    0172    */
		uint16_t TACCR1 	;      /*Read/write    0174    */
		uint16_t TACCR2 	;      /*Read/write    0176    */

}  MSP430_TIMERA, *P_MSP430_TIMERA;

#define P_TIMERA_REGS  ((MSP430_TIMERA *)TIMER_A_BASE)

//timerA on the msp430g2231 has two capture blocks

class CTimer_A{

public:

	enum TIMER_MODE{ 	STOP 		= 0x00,
						UP 			= 0x10,
						CONTINUOUS 	= 0x20,
						UP_DOWN 	= 0x30};

	enum TIMER_SOURCE{	TACLK = 0x000,     	//external
						ACLK  = 0x100,     	//sourced from LFXT or VLO (12 KHz)
						SMCLK = 0x200,		//sourced from DCo by default 1.1 MHZ
						INCLK = 0x300};


	CTimer_A(){

		m_nPeriod = 1000;

		SelectClockSource(ACLK);
		SetCountingMode(CONTINUOUS);
	}


	~CTimer_A(){}

	void SelectClockSource(TIMER_SOURCE nSource){P_TIMERA_REGS->TACTL |= (nSource);}
	void SetCountingMode(TIMER_MODE nMode){P_TIMERA_REGS->TACTL |= nMode;}


//	void SetInterrupt(uint16_t nFreq, pfunction_t pfun_ISR){

//		m_pfun_ISR = pfun_ISR;

	void SetInterrupt(uint16_t nFreq){


		m_nPeriod = (32000/nFreq);

		P_TIMERA_REGS->TACCR0 = (m_nPeriod-1);//set the match value

		P_TIMERA_REGS->TACCTL0 = CCIE; //Enable the interrupt for TACCR0 match

	}


private:
	static uint32_t m_nPeriod;

//	static pfunction_t m_pfun_ISR;
	static void ISR (void);

};

uint32_t CTimer_A::m_nPeriod;

interrupt(TIMERA0_VECTOR) CTimer_A::ISR (void){

//	(m_pfun_ISR)();
	P_TIMERA_REGS->TACCR0 += (m_nPeriod-1);
	LED_TOGGLE(LED0 | LED1); //Toggle both LEDs

}


#endif /* CTIMER_H_ */
