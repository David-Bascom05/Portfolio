# FDCAN Driver 2025 #

## Overview ##
This driver is designed for the Cornell Mars Rover Project Team. Its purpose is to 
establish FDCAN communication between the rover's Nvidia Jetson Orin Nano and the 
custom boards we have designed.

The driver architecture is pretty simple:

An initialization function sets the frame format, enables bitrate switching and 
autoretransmition, and setsthe baud rate. Other FDCAN settings are disabled. It also
calls the functions initialize the CAN periferal, the filter, notifications, and 
starts the can bus.

A filter is implemented in order to make sure that only the messages intended for 
this board trigger an interrupt. This sets the boards ID. For my implimentation, 
only one CAN ID is allowed per board, as opposed to one per motor or one per 
periferal. This is done to reduce bus conjestion, as multiple commands to the 
same board can be sent over the same message to different periferals or motors.
This could be changed if a future board needs more IDs, however this is unlikely
for our aplication. 

A transmission and recieve functions are set up in order to handle outgoing and 
incoming messages, respectively. The transmit function pauses incoming notifications
in order to avoid the transmition being interupted. It constructs a message header,
and passes both the header and message data to the buffer before resuming notifications.

The recieve function itself is even simpler, pausing notifications, sorting the header 
and data from an incoming message, and then calling the interupt handler before resuming 
notifications. The interupt handler is unpopulated but declaired. This is done to allow
for this same driver to be used in every CMR board, and the impimentation of the handler
will varry. 


## Testing ##

During testing, the driver was successfully able to handle messaging to and from my 
custom servo board and BDC Board and a Jetson Orin Nano. It successfully filtered 
unwanted messages and was able to handle high message frequency without packet loss.
