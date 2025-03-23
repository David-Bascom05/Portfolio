# Servo Driver, 2024 #

# Overview #

The goal of this project is to create a custom servo driver that can control a large 
number of servos independently and communicate over CANFD. This was not designed with
a particular project in mind, but more as an adaptable board that I could use in any 
project where I needed to be able to control a servo. I also wanted this board to be 
able to communicate over the same protocol as the mjbots moteus boards, which I have 
used in many of my other projects.

<img src="/images/Servo_Board_V2_3D.png" alt="Frame CAD" width="35%" />

## Design Requirements ##

<ol>
    <li>Board must be able to independently control a large number of servos (at least 10)</li>
    <li>Must be able to communicate over CANFD</li>
    <li>Must be able to accept a range of voltages (12 to 30V) and output the correct level for both the servos and on board components</li>
    <li>Must be able to provide enough current for all servos operating simultanously and thier normal load current</li>
    <li>Should Be compact as possbile, and easy to mount in any enclosure</li>
    <li>Should be a 2 layer, single sided assembly to reduce cost</li>
    <li>Power and CAN should have auxiliary connectors to enable daisy chaining</li>
</ol>

## Design ##

This board is centered around the use of the PCA9685PW LED driver, which is the chip that 
the board uses to generate PWM signals. This chip was chosen both because of the large 
assortment of open-source projects and libraries available, as well as its ability to 
generate up to 16 independent PWM signals.

The microcontroller is an STM32G431CBT6, which was chosen primarily for its compatibility 
with CANFD. I wanted to use an STM32 microcontroller due to their easy-to-use IDE and the 
abundance of resources I could find online, as this was my first design with a 
microcontroller.

The main buck converter is an LM25145RGYR, chosen for its high current capacity and abundance 
of safety features. While far from the easiest converter I could have used, the LM25145RGYR 
allows me to draw up to 20A. For most hobby servos, this is enough to drive every servo at 
nominal load at the same time. Some servo models may draw more than can be continuously provided
to all servos, in which case the LM25145RGYR provides overcurrent protection. This particular 
design is meant to accept a large range of voltages, causing the efficiency to decrease rather 
sharply at low current. To account for this, a Schottky diode is added to the main high current
loop to mitigate the effects of reverse recovery losses.

Current and temperature sensing are also integrated onto the board. While it would have been more 
optimal to place the temperature sensor directly under the buck regulator, it would have added to 
assembly cost by making it a double-sided assembly. Because of this, the temperature sensor is
placed as close as possible to the regulator, but it is safe to assume that the reading is not 
entirely accurate.

<img src="/images/Servo_Board_V2_Layout.png" alt="Frame CAD" width="50%" />

The layout is optimized to reduce board size as much as possible. This was done to enable the board 
to be used in a variety of projects, including those where space is a premium. This does, however, 
come with some drawbacks, mainly the fact that the high current connection running power to the 
servos is done using a single trace. Current overdraw could lead to this trace melting, rendering 
all connectors after the failure useless. A pour or auxiliary traces could have been used to mitigate 
this problem, however it is unlikely that servo motors draw over 20A of current, and the board has 
overcurrent protections in place to prevent this from occurring.

Another downside of this layout is that I would have much preferred to have 4 mounting holes instead 
of 3, however I could not figure out a way to do this without adding substantially to the board's size.

## Testing ##

During testing, the board performed very well. The first version had an issue with the feedback loop 
reference voltage in the layout, where I was accidentally feeding a second input voltage into the voltage
divider. This caused the reference voltage to be incorrect when the input voltage to the board was raised
above 12V, or when currents above 100mA were drawn. Fortunately, this issue was found and I am currently 
working on fixing it in the next revision. This led to the board malfunctioning when more than three servos 
attempt to draw current simultanously, and drop below the required driving voltage. However, all other 
functionality of the board was fully opperational. The protective measures of the board also 
worked well, triggering the overcurrent protection during a short, and preventing unsafe opperation.





