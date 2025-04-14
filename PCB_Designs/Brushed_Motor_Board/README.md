# Brushed Motor Board 2025 #

## Overview ##

The goal of this project is to create a custom brushed motor driver for my project team that would reduce the 
overall number of boards we needed to drive our brushed motors. Our old brushed motor boards were only capable 
of driving two motors independently, which meant that we would need 6 boards total to drive all 12 of our motors.
This more than doubled the number of other boards in our electronics bay, forcing it to be significantly larger
than it otherwise would have to. I was able to increase the number of independent outputs to 6, while maintaining
the size of the overall board footprint. In addition to its core functionality, I also added ports for communication 
with humidity and CO2 sensors for the astrobiological technology subteam using an I2C bus and a number of GPIOs. 
This was done to further reduce board count and enable easier integration of the off-the-shelf sensors.

<img src="/images/Old_vs_new_BDC.jpg"  width="50%" />
Left - Old Board        

Right - New board

## Design Requirements ##

<ol>
    <li>Board must be able to independently control 6 brushed motors at 1A each</li>
    <li>Must be able to communicate over CANFD</li>
    <li>Must be able to accept a range of voltages (24 to 32V) and output 12V to motors</li>
    <li>Must be able to provide enough current for all 6 motors</li>
    <li>Should be as compact as possible (equal to or less than the original footprint), and easy to mount in any enclosure</li>
    <li>Should be a 2-layer, single-sided assembly to reduce cost</li>
    <li>Power and CAN should have auxiliary connectors to enable daisy chaining</li>
    <li>Must have some way of communicating with the humidity and CO2 sensors for the astrobiological technology team</li>
</ol>

## Design ##

<img src="/images/BDC Board.png"  width="50%" />

This is a complete redesign of the old board. The MCU and CAN transceivers were both changed in order to be 
compatible with CANFD. The motor driver was exchanged for two smaller drivers with more outputs. The layout 
of the buck converter was redone to more efficiently manage grounding on a single plane and reduce its footprint
on the board. 

This design uses 2 DRV8906 H-bridge drivers to control 3 motors per chip. This configuration was chosen due
to a lack of cost-effective 6-output drivers at 2 amps per output (chosen to give each output a safety factor).
The two chips communicate with an STM32G4 microcontroller via a shared SPI bus. This microcontroller was chosen 
for its compatibility with CANFD, and its wide range of ADC-configurable pins. 

Power is provided to the board through a custom buck converter, utilizing the LM25085 to step down to 12V. This
IC was chosen for its low board footprint and relatively simple implementation for a buck converter handling 
this much current. 

Shunt resistors on each output measure the current being drawn on each motor. This can be used for diagnostics and 
current limiting. LEDs on each output also give a visual indicator of which motors are being driven and in which 
direction to ease firmware debugging. A temperature sensor is placed next to the buck converter for monitoring and 
over-temperature protection. Finally, ports to connect three external humidity and CO2 sensors are placed on the board
edge and connected to the MCU via a single I2C bus, 3 PWM channels, and 6 GPIO pins.

<img src="/images/Screenshot 2025-04-02 080753.png"  width="50%" />

The layout is optimized for size as much as possible, while maintaining the two-layer, one-sided assembly. This was
done to keep the board within the footprint of its predecessor and ensure that it would not require other systems on 
the rover to become larger to accommodate the change. Keeping within these requirements did come with some drawbacks, 
the largest being that the main 12V line to the motor outputs has to run on a single trace, which could cause melting 
issues during an unexpected high load. The large number of ICs on this board also forced me to use the second layer 
rather extensively for signal routing, causing there to be many large cuts in the ground plane.

## Testing ## 

On the first version of the board, the footprints for the Schottky diode and MOSFET in the buck converter had incorrect 
pin assignments given to them. This caused a small electrical fire the first time the board was plugged in. This issue
was fixed by desoldering those components and connecting the pins to their corresponding pads using jumper wires. 
The footprints were then fixed in the second version of the board.

After the buck converter was fixed, testing was carried out incrementally as firmware was written. In its current state, the 
board is able to independently and synchronously drive six motors forward, backward, brake, or coast, and switch between 
these states at timed intervals defined by the user. PWM for variable speed control is not yet implemented. It has both 
visual and digital fault reporting, sending a diagnostic message over the CANFD line to enable live debugging without the 
need for additional communication lines. 

During testing for the astrobiological technology team, the board was successfully used to drive an array of peristaltic 
pump motors for soil sample testing. The board was successfully able to control all 6 motors with the millisecond-precise 
timing required to dispense individual droplets in a repeatable manner. 

The current sense and temperature sense capabilities will be tested once firmware to read and report the corresponding ADC
values has been written. In the future, these sensors will allow the user to set custom current limits for different motors,
and set custom temperature limits, increasing the safety features on the board and reducing the risk of burning out small motors.







