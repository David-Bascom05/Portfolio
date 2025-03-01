# FDCAN Driver #

## Overview ##
This driver is designed for the Cornell Mars Rover Project Team. Its purpose is to 
establish FDCAN communication between the rover's Nvidia Jetson Orin Nano and the 
custom boards we have designed.

The driver architecture is pretty simple:

A filter is implemented in order to make sure that only the messages intended for 
this board trigger an interrupt. Functions are then set up to transmit and receive 
messages while ensuring reliable data handling. The interrupt handler itself is 
defined and will be written in the main.c file of the board the driver is used to 
run. This ensures compatibility across multiple boards.

An initialization function enables the clock and sets up the GPIO pins and interrupts 
required, configures the appropriate parameters on the fdcan1 channel, and initializes 
that channel. It also initializes the filter and starts the fdcan peripheral and 
interrupt notifications.

## Testing ##

During testing, the driver was successfully able to handle messaging to and from my 
custom servo board and a Jetson Orin Nano. It successfully filtered unwanted messages 
and was able to handle high message frequency without packet loss.
