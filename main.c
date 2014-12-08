//-----------------------------------------------------------------
// Name:	Coulston
// File:	lab7.c
// Date:	Fall 2014
// Purp:	Collect analog samples from P1.3 and P1.4
//-----------------------------------------------------------------
#include "msp430g2553.h"
#include "sensorLibrary.h"

void initMSP430();

//----------------------------------------------------------------------
//----------------------------------------------------------------------
int main(void) {

	unsigned short sample[16];									// Just to analyze the values
	unsigned char i = 0;										// index into sample array
	unsigned short left;
	unsigned short center;
	unsigned short right;

	IFG1=0; 													// clear interrupt flag1
	WDTCTL = WDTPW + WDTHOLD;									// disable WDT

	BCSCTL1 = CALBC1_8MHZ;										// 8MHz clock
	DCOCTL = CALDCO_8MHZ;


	while(1) {

		if (getLeft() > 0x0230){
			P1DIR = BIT0;												// Set the red LED as output
			P1OUT |= BIT0;
		}
		else
			P1OUT &= ~BIT0;

		if (getRight() > 0x0230)	{
			P1DIR = BIT6;
			P1OUT |= BIT6;
		}
		else
			P1OUT &= ~BIT6;

	} // end infinite loop

} // end main
