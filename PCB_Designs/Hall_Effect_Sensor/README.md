# Hall Effect Sensor 2024 #

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
    <li>Sensor should be accurate to within 0.5 deg on the output</li>
</ol>


## Design ##

The design is based around the DRV5033AJQDBZRQ1 Hall Effect chip. It is a non-latching
hall effect sensor that is low when no magnetic field is detected. Other than that the 
design is very simple: a power and signal LED show the board state, and a JST connector
provides power and connects the signal line from the moteus controller. The connector 
is a bit large for this board, but was chosen to match the connector on the moteus in 
order to simplify wiring. Optional pin headers are also located on the back of the board 
to give test points, or to allow this to be integrated with a different microcontroller.

## Testing ##

#### Click to Play Video ####

[![Hall Effect Testing](/images/Hall_Effect_Thumbnail.png)](https://youtu.be/xiG5vrSRzsc)

To test, I started with the breadboard circuit in the video linked above. In this test, I
was able to find a midpoint between two magnets, and use that midpoint as my zero. This 
method of zeroing is used because the hall effect goes low as soon as it detects a magnetic
field, which means that it triggers just off the edge of the magnet by some unknown amount. 
This could be measured, but it was believed it would be easier to use two magnets, and have
the offset cancel out. This implementation has the added benefit of also acting as a digital 
limit switch, which may be useful for projects where you need to limit the range of motion on
an actuator.

<img src="/images/Hall_Effect_Real_PCB.png" alt="Old Frame CAD" width="45%" style="transform: rotate(180 deg);" />

In the above photo you can see my first two attempts at turning this into a custom board.
In the first iteration (Left) I used a logic inverter circuit to invert the signal coming 
off the hall effect. I quickly realized however, that this extra circuit served no real 
purpose, and I was better off using the extra space for more pin headers to improve board 
debugging and integration with other devices in the future. I implemented these changes in
version 2 (Right), and the changes actually turned out to be very helpful when I needed to
use this with an Arduino.

Each version of this was cycle tested using the rig above, and a python script that I ran 
to run 200, 500, 1000, and eventually 5,000 times. The python script moved the motor to a 
random position, ran the zero logic, and then compared the measured zero against the preset
"correct" zero that was already set. In each scenario, and for every board, I got 
approximately the same results:

<table>
  <thead>
    <tr>
      <th>Version</th>
      <th>Accuracy on the motor</th>
      <th>Accuracy on Output (4:1)</th>
      <th>Expected for 50:1</th>
      <th>Expected for 100:1</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td>Breadboard</td>
      <td>±6.1</td>
      <td>±1.525</td>
      <td>±0.122</td>
      <td>±0.061</td>
    </tr>
    <tr>
      <td>PCB V1</td>
      <td>±5.8</td>
      <td>±1.45</td>
      <td>±0.116</td>
      <td>±0.058</td>
    </tr>
    <tr>
      <td>PCB V2</td>
      <td>±5.8</td>
      <td>±1.45</td>
      <td>±0.116</td>
      <td>±0.058</td>
    </tr>
  </tbody>
</table>

As you can see, on the 4:1 testing rig I used, this sensor was not quite accurate enough for
my intended application. I tried various ways to improve the accuracy, but they did little or
nothing to improve the data. I may have been able to achieve the accuracy I needed with a higher
reduction, but implementing this on the system it was intended for would have been cost prohibitive,
and I ultimately decided that using auxiliary encoders was the more logical solution than continuing
to iterate on this project.

In the future if I was to revisit this project, I would update it with a more precise hall effect,
and move the hall effect itself to the other side of the board to avoid collision issues with the 
connector that came up in testing.





