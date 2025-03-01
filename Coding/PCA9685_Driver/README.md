# PCA9685 Driver #

## Overview ##

This driver was written for the PCA9685 in order to output a PWM signal capable of driving 
hobby servos to a given position. It was written in C to be run on an STM32G4 microcontroller. 
The driver sets the output frequency and generates a PWM signal based on the range and desired 
position of each servo, meaning it can take in a variety of different servos with different 
output ranges, and drive them all from the same chip. It also has the ability to set home 
positions for each servo.

## Testing ##

During Testing, the driver worked very well, able to set servo positions with an accuracy of 
under 1 degree for all ranges of servos tested (including 5-turn servos). It was able to drive
all 16 output channels of the chip simultaneously, with almost zero latency between the servo 
and controller.
