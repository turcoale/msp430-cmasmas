#include <msp430x21x2.h>


volatile unsigned int i;
unsigned dato;
int main(void)
{
    WDTCTL = WDTPW + WDTHOLD;
    P1DIR |= 0x01;
    dato =26;
    for (;;)
    {
        P1OUT ^= 0x01;
        i = 1000;
        do (i--);
        while (i != 0);
    }
}
