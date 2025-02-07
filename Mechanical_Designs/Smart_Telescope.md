# Smart Telescope Prototype 2024 #

## Overview ##

This is a personal project that I worked on over the summer. Its objective is to replace 
my current telescope mount with a motorized version that is capable of tracking and 
targeting celectial bodies. I also want it to avoid as much of the manual calibration as
possible that is inharent in many comersially available smart telescope designs. This 
first design is meant to be a functional prototype. It is mechanically as simple as possible,
using belt drive and very simple 3D prints with internal steel reinforcment. The electronics 
stack is also simple, utilizing a raspberry pi for control and an arduino as a senor input 
board. This settup allows me to develope and iterate on software that I can test on a working 
stand. I plan to make future versions of this that are more mechanically advanced with custom
electronics to reduce complexity and mounting space.

<img src="/images/9jg4ao.gif" alt="Frame CAD" width="45%" />

## Design Requirements ##

<ol>
    <li>Must be able to withstand the loads of a 15 lb telescope moving at 5 deg per second</li>
    <li>The system must be able to move to see any point in the sky</li>
    <li>System must be as positionally accurate as possibe</li>
        <ul>
            <li>Actuators should have near zero backlash</li>
            <li>Actuators should have position feedback</li>
            <li>The system should be as mechanically stiff as possible</li>
        </ul>
    <li>The system must be able to detect its precise position on earth, current heading, and altitude</li>
    <li>The system must be able to make real time astronomical calculations</li>
    <li>All custom parts must be 3D printable</li>
</ol>

## Design ##

### Mechanical ###




















