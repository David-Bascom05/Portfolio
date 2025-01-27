# Servo Driver, 2024 #

# Overview #

The goal of this project is to create a custom servo driver that can controll a large 
number of servos independantly and comunicate over canfd. This was not designed with 
a particular project in mind, but more as an addaptable board that I could use in any 
project where I needed to be able to control a servo. I also wanted this board to be 
able to comunicate over the same protocal as the mjbots moteus boards, which I have 
used in many of my other projects.

<img src="/images/Servo_Board_3D.png" alt="Frame CAD" width="35%" />

## Design Requirements ##

<ol>
    <li>Board must be able to independantly control a large number of servos (at least 10)</li>
    <li>Must be able to comunicate over CANFD</li>
    <li>Must be able to accept a range of volatges (12 to 30V) and output the correct level for both the servos and on board components</li>
    <li>Must be able to provide enough current for all servos opperating simultanously and thier normal load current</li>
    <li>Should Be compact as possbile, and easy to mount in any enclosure</li>
    <li>Should be a 2 layer, single sided assembly to reduce cost</li>
    <li>Power and CAN should have auxilary connectors to enable daisy chaining</li>
</ol>

## Design ##

This board is centered around the use of the PCA9685PW LED driver, which is the chip 
that the board uses to generate PWM signals. This chip was choosen both because of the 
large asortment of open source projects and libraries available, as well as its ability
to generate up to 16 independent PWM signals.

The microcontroller is a STM32G431CBT6, which was chosen primarily for its compatability 
with CANFD. I wanted to use an STM32 microcontroller due to there easy to use IDE and 
the abundence of resources I could find online, as this was my first design with a 
microcontroller. The other components are ones that I was farmiliar with from other 
designs that I had worked on before, and were choosen for ease over optimal functionality.

<img src="/images/Servo_Board_Layout.png" alt="Frame CAD" width="35%" />

The layout is a work in progress, but this was my first attempt at it. Some key aspects 
of the layout are that I wanted all the connectors on one side for easy wiring and 
the possiblity of carrier board integration in the future. I also wanted easy access to 
all the connectors for the servo plug in, again so that wiring is as easy as possible. 
However, I think there is quite a bit of space optimization that can be done, and the 
considerable distance that the CAN RX and TX lines need to travel from the microcontroller
to the CAN tranciever is a definite downside. The buck boost converter used step down the 
voltage to 6V is also a mess on the layout, and probably over designed. The current 
version is able to handle up to 10A of continous current, which for only 16 hobby servos 
is very unlikely to occer. It is probably wiser to reduce the requirments on the converter,
and impliment a current monitoring cuicuit, or modify the overvoltage protection cuircut to 
prvent high currents in addition to the curent short curcuit protection

## Testing ##

As I said before, this board is a work in progress, and I am currently working on a breadboard
prototype. Using a NUCLEO board and an off the shelf breakout for the PCA9685PW, I was sucessfully 
able to drive multiple independant servos simultaniously. In order to start working on CANFD 
implimentation, I designed a custom breakout for my CANFD chip, and I am currently learning how to 
write the firmware to drive it, as well as learning about how to design my own protocol for 
comunicating over CANFD. 





