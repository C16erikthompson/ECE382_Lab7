ECE382_Lab7
===========
#General Approach
To get my first sensor working, I used the Dr.Coulston's code from his website.  Given that code, I had an idea of how each of the sensors had to be wired and how to code for detecting a change in voltage.  From here, I was able to apply the detetion code to the other two sensors and pins to get the LED to go high when a high enough voltage was presented to its respective sensor.  The wiring was rather simple, connecting Pin 6 to left, Pin 7 to center, and Pin 5 to right, followed by supplying 5 volts to the sensors and connecting them to ground.  This build would not interefere with that of my Lab 6, allowig it to be utilized for the robot maze in Lab 8.

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
