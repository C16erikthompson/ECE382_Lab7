/*
 * sensorLibrary.c
 *
 *  Created on: Dec 4, 2014
 *      Author: C16Erik.Thompson
 */

#include "sensorLibrary.h"
#include "msp430g2553.h"


short getLeft(){
	ADC10CTL0 = 0;											// Turn off ADC subsystem
	ADC10CTL1 = INCH_4 | ADC10DIV_3 ;						// Channel 4, ADC10CLK/4
	ADC10AE0 = BIT4;		 								// Make P1.4 analog input
	ADC10CTL0 = SREF_0 | ADC10SHT_3 | ADC10ON | ENC;		// Vcc & Vss as reference

	ADC10CTL0 |= ADC10SC;									// Start a conversion
	while(ADC10CTL1 & ADC10BUSY);							// Wait for conversion to complete
	return ADC10MEM;
}

short getCenter(){
	ADC10CTL0 = 0;											// Turn off ADC subsystem
	ADC10CTL1 = INCH_2 | ADC10DIV_3 ;						// Channel 4, ADC10CLK/4
	ADC10AE0 = BIT2;		 								// Make P1.4 analog input
	ADC10CTL0 = SREF_0 | ADC10SHT_3 | ADC10ON | ENC;		// Vcc & Vss as reference

	ADC10CTL0 |= ADC10SC;									// Start a conversion
	while(ADC10CTL1 & ADC10BUSY);							// Wait for conversion to complete
	return ADC10MEM;
}

short getRight(){
	ADC10CTL0 = 0;											// Turn off ADC subsystem
	ADC10CTL1 = INCH_3 | ADC10DIV_3 ;						// Channel 4, ADC10CLK/4
	ADC10AE0 = BIT3;		 								// Make P1.4 analog input
	ADC10CTL0 = SREF_0 | ADC10SHT_3 | ADC10ON | ENC;		// Vcc & Vss as reference

	ADC10CTL0 |= ADC10SC;									// Start a conversion
	while(ADC10CTL1 & ADC10BUSY);							// Wait for conversion to complete
	return ADC10MEM;
}
