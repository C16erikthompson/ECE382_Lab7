ECE382_Lab7
===========
#General Approach
To get my first sensor working, I used the Dr.Coulston's code from his website.  Given that code, I had an idea of how each of the sensors had to be wired and how to code for detecting a change in voltage.  From here, I was able to apply the detetion code to the other two sensors and pins to get the LED to go high when a high enough voltage was presented to its respective sensor.  The wiring was rather simple, connecting Pin 6 to left, Pin 7 to center, and Pin 5 to right, followed by supplying 5 volts to the sensors and connecting them to ground.  This build would not interefere with that of my Lab 6, allowig it to be utilized for the robot maze in Lab 8.
#Prelab
What would good reference values be?  
A value of 3.5 volts would be a good reference value simply to test to make sure the lights only turn on when the sensors are decently close to a wall.  A more precise voltage to prevent collision, while allowing for utility, will be decided in the A functionality portion of this lab.
Consider how you'll setup the ADC10 subsystem. What are the registers you'll need to use?   
ADC10AE0, ADC10CTLx, ADC10MEM  
Which bits in those registers are important?   
ADC10AE0 : Bits 7 – 0  
ADC10CTLx : Bits 15 – 12, Bits 7 – 5, Bits 4 – 3, Bit 0, Bits 11 – 10  
ADC10MEM: Bits 15 - 0  
What's the initialization sequence you'll need?  
BCSCTL1 = CALBC1_8MHZ;										// 8MHz clock  
	DCOCTL = CALDCO_8MHZ;  

	P1DIR = BIT0;												// Set the red LED as output  
~~~
	while(1) {

		  // Configure P1.4 to be the ADC input
		ADC10CTL0 = 0;											// Turn off ADC subsystem
		ADC10CTL1 = INCH_4 | ADC10DIV_3 ;						// Channel 4, ADC10CLK/4
		ADC10AE0 = BIT4;		 								// Make P1.4 analog input
		ADC10CTL0 = SREF_0 | ADC10SHT_3 | ADC10ON | ENC;		// Vcc & Vss as reference

		ADC10CTL0 |= ADC10SC;									// Start a conversion
		while(ADC10CTL1 & ADC10BUSY);							// Wait for conversion to complete
~~~
Consider the hardware interface. Which ADC10 channels will you use?   
INCH_2,3,4 (A2,A3,A4)  
Which pins correspond to those channels?  
Pins 4,5,6  
Consider the interface you'll create to your sensors. Will you block or use interrupts?   
Block  
Will you convert one sensor at a time or multiple?  
One sensor at a time and set the value of a variable due to the singular use of ADC10MEM  

#Required Functionality

http://vid47.photobucket.com/albums/f189/erik_thompson2/VID_20141208_002036_6051_zps6yvqg3eh.mp4

#B Functionality

The sensorLibrary.c and .h files control allow for conversion of an analog input into a digital output
to beutilized in further programs.  The pins that are utilized for each of the sensors are as follows:

Left = 1.4 (Pin 6)  
Center = 1.5 (Pin 7)  
Right =  1.3 (Pin 5)  

The methods used to obtain the outputs for each censor are as follows:

Left = getLeft()  
Center = getCenter()  
Right =  getRight() 

#A Functionality

Distances measured in inches.  Left and right distances measured from center of respective wheel.  Center measured from furthest point from the center on the front of the robot.

![alt tag](http://i47.photobucket.com/albums/f189/erik_thompson2/Lab7picA_zps4649e9c1.png
 "TO-220 Config").
#Documentation
None
