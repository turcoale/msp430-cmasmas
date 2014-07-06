/*
 * msp430_defs.h
 *
 *  Created on: Apr 28, 2011
 *      Author: mark
 *
 *     Copyright (c) 2011 Engine12, LLC
 *
 *	   www.engine12.com
 */

#ifndef MSP430_DEFS_H_
#define MSP430_DEFS_H_

#include <sys/inttypes.h>

//extern "C" void*		_swap_(void volatile *const pValue, void const *const pNewValue);

#define WORD_SIZE 	2  /*size of a word in bytes    */
#define ATTR_PACKED_ALIGNED_WORD  __attribute__ ((__packed__,__aligned__(WORD_SIZE)))

//#define _irq_ void __attribute__((interrupt (NOVECTOR)))
//#define _irq_ inline void
#define interrupt(x) void __attribute__((interrupt (x)))


#define BIT(a)  (1<<a)

/* Enable/Disable interrupts */
#define Enable_Interrupts()   __asm__ __volatile__("eint"::)
#define Disable_Interrupts()  __asm__ __volatile__("dint"::)


// Function pointer type
//typedef void (*pfunction_t)(void);


/*
#define IRQ_BASE  (0xFFE0)

//#define InterruptVectors        (*(volatile pfunction_t *)(IRQ_BASE))

#define reset_vector  0
#define zero_vector   0
#define wakeup_vector 0

#define INTERRUPT_VECTOR_SLOTS      16

volatile pfunction_t  InterruptVectors[INTERRUPT_VECTOR_SLOTS] __attribute__ ((section(".vectors")))={
    zero_vector,
    zero_vector,
    zero_vector,
    zero_vector,
    zero_vector,
    zero_vector,
    wakeup_vector,
    zero_vector,
    zero_vector,
    zero_vector,
    zero_vector,
    zero_vector,
    zero_vector,
    zero_vector,
    zero_vector,
    reset_vector
};


inline void installVector(
        uint16_t vectorNumber,
        pfunction_t interruptServiceRoutine)
{
     InterruptVectors[vectorNumber] = interruptServiceRoutine;

}

*/

/************************************************************
* Interrupt Vectors (offset from 0xFFE0)
************************************************************/

#define PORT1_VECTOR        (2  * 2) /* 0xFFE4 Port 1 */
#define PORT2_VECTOR        (3  * 2) /* 0xFFE6 Port 2 */
#define USI_VECTOR          (4  * 2) /* 0xFFE8 USI */
#define ADC10_VECTOR        (5  * 2) /* 0xFFEA ADC10 */
#define TIMERA1_VECTOR      (8  * 2) /* 0xFFF0 Timer A CC1, TA */
#define TIMERA0_VECTOR      (9  * 2) /* 0xFFF2 Timer A CC0 */
#define WDT_VECTOR          (10 * 2) /* 0xFFF4 Watchdog Timer */
#define NMI_VECTOR          (14 * 2) /* 0xFFFC Non-maskable */
#define RESET_VECTOR        (15 * 2) /* 0xFFFE Reset [Highest Priority] */



#define PORT1_BASE  (0x0020)
#define PORT2_BASE  (0x0028)

typedef volatile struct ATTR_PACKED_ALIGNED_WORD _MSP430_PORT_IRQ {

		uint8_t IN 		;      /*Read          0x0    */
		uint8_t OUT 	;      /*Read/write    0x1    */
		uint8_t DIR 	;      /*Read/write    0x2    */
		uint8_t IFG		;      /*Read/write    0x3    */
		uint8_t IES     ;	   /*Read/write    0x4    */
		uint8_t IE 		;      /*Read/write    0x5    */
		uint8_t SEL 	;      /*Read/write    0x6    */
		uint8_t REN 	;      /*Read/write    0x7    */

	//	uint8_t SEL2 	;      /*Read/write    041    */

}  MSP430_PORT_IRQ, *P_MSP430_PORT_IRQ;


#define P_PORT1_REGS  ((MSP430_PORT_IRQ *)PORT1_BASE)
#define P_PORT2_REGS  ((MSP430_PORT_IRQ *)PORT2_BASE)


#define LED0 BIT(0)
#define LED1 BIT(6)

inline void LED_ON(uint16_t x)		{	P_PORT1_REGS->OUT |=  x ;}
inline void LED_OFF(uint16_t x)		{	P_PORT1_REGS->OUT &= ~(x) ;}
inline void LED_TOGGLE(uint16_t x)	{	P_PORT1_REGS->OUT ^=  (x) ;}




#endif /* MSP430_DEFS_H_ */
