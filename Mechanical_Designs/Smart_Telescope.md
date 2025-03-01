# Smart Telescope Prototype 2024 #

## Overview ##

This is a personal project that I worked on over the summer. Its objective is to replace my 
current telescope mount with a motorized version that is capable of tracking and targeting 
celestial bodies. I also want it to avoid as much of the manual calibration as possible that 
is inherent in many commercially available smart telescope designs. This first design is 
meant to be a functional prototype. It is mechanically as simple as possible, using belt 
drive and very simple 3D prints with internal steel reinforcement. The electronics stack is 
also simple, utilizing a Raspberry Pi for control and an Arduino as a sensor input board. This 
setup allows me to develop and iterate on software that I can test on a working stand. I plan
to make future versions of this that are more mechanically advanced with custom electronics to 
reduce complexity and mounting space.

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
Smart telescopes generally use very short telescopes in order to simplify the mounting setup so that 
the telescope can be mounted above the telescope without any risk of collision. My telescope was much
too long to do this, so the mounting point could not be directly over the first axis of rotation, 
inducing a large moment on the first rotational joint. Additionally, I chose brushless motors to drive
this system, as I already had them, and they met my needs for absolute position control when combined 
with encoder feedback. However, at the low speeds I needed to move at, I was encountering cogging that
led to poor performance.

<img src="/images/Telescope Actuator.png" alt="Frame CAD" width="45%" />

These two issues led me to design a modular belt drive actuator. This allowed me to run my motors faster 
to avoid cogging, while also allowing me to integrate bearings on the output to handle the moment loads
without the load pathing through the motor. This actuator was used for both rotational joints of the mount.
I used linear rods to reinforce the 3D print. This gave the actuators both the strength and rigidity needed
to use these as the main structure of the mount. This meant that all that was required to complete the 
structure of the mount was 3D printed connectors between the actuators and clamps to hold the telescope 
itself.

### Electrical ###

The electrical system for this project was fairly rudimentary. A Raspberry Pi acted as the main computer 
for the system, while an Arduino was used to take input from the large array of sensors I used to calculate 
position, heading, altitude, and location, current time, and level. The Arduino communicated with the Pi 
over serial bus. In order to control the motors, I used two BLDC motor drivers with absolute magnetic encoders. 
These communicated directly with the Pi over an FDCAN bus. I also used auxiliary encoders on the belt output to 
disambiguate the output position during startup. The whole system was powered via a 24V lithium polymer battery.
I plan to later move the Arduino sensors all onto a custom PCB that can also be put on the FDCAN network with
the motor drivers, but this simple setup was used for the viability of the system.


## Testing ##

This mount performed very well for what it was. I was able to successfully control both axes to point at a requested
celestial body without collision with the base of the mount. I also proved that reinforced 3D prints were more than 
enough to hold the weight of the telescope and withstand the loads from moving to a new position. While this was a 
success in that I was able to locate planets, it was hard to get a good image, as the output had some very small 
oscillations that made it hard to focus. This can likely be fixed in the future with better tuning of the controller,
and potentially a higher reduction or stronger motors if controller tuning is not adequate.
















