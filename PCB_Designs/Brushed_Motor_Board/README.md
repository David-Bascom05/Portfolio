# Brushed Motor Board 2025 #

## Overview ##

The goal of this project is to create a custom brushed motor driver for my project team that would reduce the 
overall number of boards we needed to drive our brushed motors. Our old brushed motor boards were only capable 
of driving two motors independantly, which meant that we would need 6 boards total to drive all 12 of our motors.
This more than doubled the amount of other boards in our electronics bay, forcing it to be significantly larger
than it otherwise would have to. I was able to increase the number of independant outputs to 6, while maintaining
the size of the overall board footprint. In addition to its core functionality, I also added ports for comunication 
with humidity and CO2 sensors for the astrobiological technology subteam using an I2C bus and a number of GPIOs. 
This was done to future reduce board count and enable easier integration of the off the shelf sensors.

<img src="/images/Old_vs_new_BDC.jpg"  width="50%" />
Left - Old Board        

Right - New board

## Design Requirements ##

<ol>
    <li>Board must be able to independently control 6 brushless at 1A each</li>
    <li>Must be able to communicate over CANFD</li>
    <li>Must be able to accept a range of voltages (24 to 32V) and output 12V to motors</li>
    <li>Must be able to provide enough current for all 6 motors</li>
    <li>Should be as compact as possible (equal to or less than the origional footprint), and easy to mount in any enclosure</li>
    <li>Should be a 2 layer, single sided assembly to reduce cost</li>
    <li>Power and CAN should have auxiliary connectors to enable daisy chaining</li>
    <li>Must have some way of comunicating with the humidity and CO2 sensors for the astrobiological technology team</li>
</ol>

## Design ##















