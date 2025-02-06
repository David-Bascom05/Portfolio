# FDCAN Driver #

## Overview ##
This driver is designed for the Cornell Mars Rover Project Team. Its purpose is to establish 
FDCAN comunication between the rover's Nividia Jetson Orin Nano and the custom boards we have 
designed. 

The driver archatecture is pretty simple: 

A filter is implimented in order to make sure that only the meesages intended for this board 
trigger an interupt. Functions are then set up to transmit and recieve messaages while ensuring
reliable data handling. The interupt hadler itself is defined, and will be writen in the main.c 
file of the board the driver is used to run. This ensures compatability accross multiple boards

An initialization function enables the clock and sets up the GPIO pins and interputs required,
configures the appropriate parameters on the fdcan1 channel and initalizes that channel. It also
initializes the filter and starts the fdcan periferal and interupt notifications.

## Testing ##

During testing, the driver was successfully able to haddle messaging to and from my custom servo 
board and a jetson orin nano. It sucessfully filtered unwanted messages and was able to handle 
hgh message frequency without packet loss.
