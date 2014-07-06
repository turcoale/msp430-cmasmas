/*
 * CWDTimer.h
 *
 *  Created on: Apr 28, 2011
 *      Author: mark
 *
 *     Copyright (c) 2011 Engine12, LLC
 *
 *	   www.engine12.com
 */

#ifndef CWDTIMER_H_
#define CWDTIMER_H_

#include "msp430_defs.h"

#define WDTCTL_BASE		(0x0120)    /* Watchdog Timer Control */
#define WDTPW           (0x5A00)    /* WDT password - always write to the upper byte*/

/* The bit names have been prefixed with "WDT" */
#define WDTIS0              BIT(0)
#define WDTIS1              BIT(1)
#define WDTSSEL             BIT(2)
#define WDTCNTCL            BIT(3)
#define WDTTMSEL            BIT(4)
#define WDTNMI              BIT(5)
#define WDTNMIES            BIT(6)
#define WDTHOLD             BIT(7)


typedef volatile struct ATTR_PACKED_ALIGNED_WORD _MSP430_WATCHDOG_TMR {

	//Any write operation to WDTCTL must be a word operation with 05Ah (WDTPW) in the upper byte:
		uint16_t WDTCTL 		;      /*          0x0    */


}  MSP430_WATCHDOG_TMR, *P_MSP430_WATCHDOG_TMR;

#define P_WATCHDOG_TMR_REGS  ((MSP430_WATCHDOG_TMR *)WDTCTL_BASE)

class CWDTimer{

public:

	CWDTimer(){}
	~CWDTimer(){}

	inline void Stop(){ P_WATCHDOG_TMR_REGS->WDTCTL = WDTPW | WDTHOLD;}
};

#endif /* CWDTIMER_H_ */
