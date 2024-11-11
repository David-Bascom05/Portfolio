# Hall Effect Sensor #

## Overview ##

<img src="/images/Hall_Effect_3D.png" alt="Old Frame CAD" width="45%" />

This board was designed as a way of homing robotic actuators. The idea is that
one of these can be mounted on the output of an actuator that does not know its
starting position. It can then go though a homing sequence, and when a magnet 
passes over the sensor, it can detect that, and send the change of state back 
to the driver. 

## Design Requirements ##

<ol>
    <li>Board must be able to output a signal to a <a href="https://mjbots.com/products/moteus-c1">moteus-c1 BLDC controller</a></li>
    <li>Board must be able to mount on the output side of a Laifual LSN-14 Harmonic Gearbox</li>
    <li>The board should not require any additional power or wiring than what can be provided from the moteus board</li>
    <li>Must be able to detect when a magnet is present, and send a signal to the moteus</li>
    <li>Once the magnet is no longer present, the board should return to the off state</li>
    <li>Should be easy to integrate with other controllers if there is ever a desire to use this with a different microcontroller</li>
    <li>Sensor should be as small as possible</li>
    <li>Sensor should be able to detect a magnet up to 2mm away</li>
    <li>Sensor should be accurate to within 0.1 deg on the output</li>
</ol>


## Design ##

The design is based around the DRV5033AJQDBZRQ1 Hall Effect chip. It is a non-latching 
hall effect sesnor that is low when no magnetic field is detected. Other than that the 
design is very simple: a power and signal LED show the board state, and a JST connector
provides power and connects the signal line from the moteus controller. the connector is
a bit large for this board, but was chosen to match the contector on the moteus in order 
to simplify wiring. Optional pin headers are also located on the back of the board to 
give test points, or to allow this to be integrated with a different microcontroller. 

## Testing ##

[![Hall Effect Testing](path/to/your-image.png)](https://youtu.be/xiG5vrSRzsc)

To test, I started with the breadboard circuit in the video linked above. In this test,
I was able to find a midpoint between two magnets, and use that midpoint as my zero. 
This meathod of zeroing is used because the hall effect goes low as soon as it detects 
a magnectic field, which means that it triggers just off the edge of the magnet by some 
unknown amount. This could be measured, but it beleived it would be easier to use two 
magnets, and have the offset cancel out. This implimentation has the added benifit of 
also acting as a digital limit switch, which may be useful for projects where you need 
to limit the range of motion on an acuator. 

<img src="/images/Hall_Effect_Real_Board.png" alt="Old Frame CAD" width="45%" style="transform: rotate(180deg);" />

I also used the same testing rig on both the breadboard sensor and the PCB, seen in the 
image above.



