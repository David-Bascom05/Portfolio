# Servo Driver V1.0 #

# Overview #

The goal of this project is to create a custom servo driver that can controll a large 
number of servos independantly and comunicate over canfd. This was not designed with 
a particular project in mind, but more as an addaptable board that I could use in any 
project where I needed to be able to control a servo. 

<img src="/images/Servo_Board_3D.png" alt="Frame CAD" width="35%" />

## Design Requirements ##

<ol>
    <li>Board must be able to independantly control a large number of servos (at least 10)</li>
    <li>Must be able to comunicate over CANFD</li>
    <li>Must be able to accept a range of volatges (10 to 30V) and output the correct level for both the servos and on board components</li>
    <li>Must be able to provide enough current for all servos opperating simultanously and thier normal load current</li>
    <li>Should Be compact as possbile, and easy to mount in any enclosure</li>
    <li>Should be a 2 layer, single sided assembly to reduce cost</li>
    <li>Power and CAN should have auxilary connectors to enable daisy chaining</li>
</ol>
