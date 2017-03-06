//*****************************************************************************
//  Blink LED Example
//
//  Description: Toggles P1.0 by xor'ing P1.0 inside of a software loop. 
//               This example demonstrates the ease of starting a MSP430 
//               project that interacts with the outside via GPIO pins.
//
//                   MSP430
//             -----------------
//         /|\|              XIN|-
//          | |                 |
//          --|RST          XOUT|-
//            |                 |
//            |             P1.0|-->LED
//
//  Texas Instruments Inc.
//*****************************************************************************
/* This software controls a PWM modulated signal on pin P1.0 (red LED), P1.1, and P1.2
 * The signal is asserted active high on P1.0 (red LED)
 * The signal is asserted active low  pm P1.1
 * The signal is asserted active high on P1.2
 * The signal "off time" is about 60 seconds
 * The signal "on time" is about 2 seconds
 * Signal off time is indicated by 1Hz blinking green LED on pin P1.6
 * Signal on time is indicated by solid on red LED on pin P1.0
 */

#define time_off 60			     // Mouse shaker is off for 60 seconds
#define time_on 2                // Mouse shaker is on for 2 seconds
#define time_on_half 1           // Mouse shaker is off for 1 seconds

#define cycles_1sec 1000000      // Cycles for 1 second delay

/*
 * ======== Standard MSP430 includes ========
 */
#include <msp430.h>

/*
 * ======== Grace related includes ========
 */
#include <ti/mcu/msp430/Grace.h>

/*
 *  ======== main ========
 */
int main(void)
{
    int a;
	Grace_init();                   	/* Run Grace-generated initialization */
	//WDTCTL = WDTPW + WDTCNTCL;      // Clear watch dog
    // Stop watchdog timer
	  WDTCTL = WDTPW + WDTHOLD;                 // Stop WDT
	// Check if WDT+ caused the prior reset condition
   if (IFG1 & WDTIFG) {
        // WDT+ initiated the prior reset condition
        IFG1 &= ~WDTIFG; // Software clear WDTIFG
    }

	P1OUT &= ~BIT0;              	       /* Turn off red LED on P1.0 */
	P1OUT |= BIT1;                  	   /* Turn on P1.1 */
	P1OUT &= ~BIT2;              	       /* Turn off  P1.2 */

    while (1) {

    	for ( a = 0; a < time_off; a++ ) {
        //WDTCTL = WDTPW + WDTCNTCL;       // Clear watch dog
        P1OUT ^= BIT6;              	   /* Toggle green LED on P1.6 */
        __delay_cycles(cycles_1sec);       /* Wait ~1s at DCO clock of ~1MHz */
    	}

    	P1OUT &= ~BIT6;              	   /* Turn off green LED on P1.6 */

    	// Shake the mouse #1:

    	P1OUT |= BIT0;               	   /* Turn on red LED on P1.0 */
    	P1OUT &= ~BIT1;              	   /* Turn off  P1.1 */
    	P1OUT |= BIT2;                     /* Turn on P1.2 */

    	for ( a = 0; a < time_on; a++ ) {
        //WDTCTL = WDTPW + WDTCNTCL;        // Clear watch dog
        __delay_cycles(cycles_1sec);        /* Wait ~1s at DCO clock of ~1MHz */
    	}

    	// No Shake:

    	P1OUT &= ~BIT0;              	    /* Turn off red LED on P1.0 */
    	P1OUT |= BIT1;                  	/* Turn on P1.1 */
    	P1OUT &= ~BIT2;              	    /* Turn off  P1.2 */

    	for ( a = 0; a < time_on_half; a++ ) {
        //WDTCTL = WDTPW + WDTCNTCL;        // Clear watch dog
        __delay_cycles(cycles_1sec);        /* Wait ~1s at DCO clock of ~1MHz */
    	}

    	// Shake the mouse #2:

    	P1OUT |= BIT0;               	   /* Turn on red LED on P1.0 */
    	P1OUT &= ~BIT1;              	   /* Turn off  P1.1 */
    	P1OUT |= BIT2;                     /* Turn on P1.2 */

    	for ( a = 0; a < time_on; a++ ) {
        //WDTCTL = WDTPW + WDTCNTCL;        // Clear watch dog
        __delay_cycles(cycles_1sec);        /* Wait ~1s at DCO clock of ~1MHz */
    	}

    	// No Shake:

    	P1OUT &= ~BIT0;              	    /* Turn off red LED on P1.0 */
    	P1OUT |= BIT1;                  	/* Turn on P1.1 */
    	P1OUT &= ~BIT2;              	    /* Turn off  P1.2 */

    	for ( a = 0; a < time_on_half; a++ ) {
        //WDTCTL = WDTPW + WDTCNTCL;        // Clear watch dog
        __delay_cycles(cycles_1sec);        /* Wait ~1s at DCO clock of ~1MHz */
    	}

    	// Shake the mouse #3:

    	P1OUT |= BIT0;               	   /* Turn on red LED on P1.0 */
    	P1OUT &= ~BIT1;              	   /* Turn off  P1.1 */
    	P1OUT |= BIT2;                     /* Turn on P1.2 */

    	for ( a = 0; a < time_on; a++ ) {
        //WDTCTL = WDTPW + WDTCNTCL;        // Clear watch dog
        __delay_cycles(cycles_1sec);        /* Wait ~1s at DCO clock of ~1MHz */
    	}

    	// No Shake:

    	P1OUT &= ~BIT0;              	    /* Turn off red LED on P1.0 */
    	P1OUT |= BIT1;                  	/* Turn on P1.1 */
    	P1OUT &= ~BIT2;              	    /* Turn off  P1.2 */


    }
}
