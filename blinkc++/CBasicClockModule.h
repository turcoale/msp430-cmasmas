/*
 * CBasicClockModule.h
 *
 *  Created on: Apr 28, 2011
 *      Author: mark
 *
 *     Copyright (c) 2011 Engine12, LLC
 *
 *	   www.engine12.com
 */

#ifndef CBASICCLOCKMODULE_H_
#define CBASICCLOCKMODULE_H_
#include "msp430_defs.h"

#define BASIC_CLOCK_BASE  (0x052)

typedef volatile struct ATTR_PACKED_ALIGNED_WORD _MSP430_BASIC_CLOCK {

		uint8_t pad0     		;	   /* 			   052    */
		uint8_t BCSCTL3 		;      /*Read/write    053    */
		uint16_t pad1     		;	   /* 054 055             */
		uint8_t DCOCTL 			;      /*Read/write    056    */
		uint8_t BCSCTL1 		;      /*Read/write    057    */
		uint8_t BCSCTL2			;      /*Read/write    058    */

}  MSP430_BASIC_CLOCK, *P_MSP430_BASIC_CLOCK;

#define P_BASIC_CLOCK_REGS  ((MSP430_BASIC_CLOCK *)BASIC_CLOCK_BASE)


class CBasicClockModule{

public:

	enum LFXT1Sx{ 	_32_KHZ 		= 0,
					RESERVED 	= 1,
					VLOCLK 		= 2,
					DEXTERN 	= 3};

	CBasicClockModule(){}

	~CBasicClockModule(){}

	inline void SelectLowFreqClock(LFXT1Sx nLFXT1Sx){P_BASIC_CLOCK_REGS->BCSCTL3 |= (nLFXT1Sx << 4);}

};


#endif /* CBASICCLOCKMODULE_H_ */
