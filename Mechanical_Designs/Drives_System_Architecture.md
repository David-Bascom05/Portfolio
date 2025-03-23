# Drives System Architecture 2024-2025 #

## Overview ##
The Cornell Mars Rover Drives team is responsible for all basic mechanical functionality of the rover's 
systems. This includes the frame, suspension, wheels, electronics bay, and radio communication tower. 
As the drives lead, I was responsible for designing system archatecture, setting stratagy, ensuring that 
all systems function properly, and handing unexpected deisgn chalenges. After seeing the competition, and 
how notably flat most parts of it were the last two years, I choose to deemphisise climbing and refocus on
speed and agility. Our astrotech subteam also choose to use the arm to collect soil samples this year, which
meant that unlike in the past, the arm would be on for the science mission, and drives would have to loose 
weight in order to accomidate this change.

#### Click to Play Video ####
[![Watch the video](https://img.youtube.com/vi/HoFIuPtQGmM/0.jpg)](https://www.youtube.com/watch?v=HoFIuPtQGmM)

## Design ##

### Wheels ###

My primary focus for this years rover was fixing the issues with the wheel actuators. Last year, we used 
hub motors from hoverboards to drive the wheels. These had three large problems, the first being low speed 
control. There was no way to mount encoders on the wheels with our electrical system, which meant that we
were relying on the hall effects inside the motor to control them. These motors had no reduction at the 
output, which meant that at low velocities the time between hall effect triggers could be quite long, leading 
to inacuracies and incredably poor low speed control. The second issue was the weight. The motors were
massive, each weighing 3.2kg. In total the wheels alone were 26% of our entire weight budget. This caused
us to go overweight at competition by 3kg, incuring a penality. Finally, the motors lacked the torque 
required to go up steap inclines, failing on a slope over 30 degrees.

<img src="/images/Wheel.jpg" width="45%"/>

In order to fix this, I choose to use much smaller external brushless motors and planetary gearboxes. 
With a nominal torque of 2Nm and a 26:1 reduction, I was able to double the nominal torque output from 
last year, while maintaining a high speed of up to 6m/s. Using external motors also allowed me to mount 
absolute magnetic encoders to the motor shaft, eliminating our accuracy issues. I choose to use planetary
gearboxes, as a small amount of backlash was not an issue, and the reduction ratio I was after was most 
commonly available in planetaries. Convineice was also a factor, and the company that made our motors,
Maxon, also offered to provide us with a large discount on the gearboxes they made.

<img src="/images/Wheel actuators.png" width="45%"/>

The specific gearbox I choose, unfortunatly, did not have a high radial load capacity. This meant that 
additional bearings after the output were required in order to transfer the load off the output shaft. 
The output plate was set between two deep-groove ball bearings in order to reduce the moment and thrust 
load on the gearbox in addition to the axial load they would be under. I also took great care in my 
design to make assembly and manufactoring as easy as possible. It requires only 3 unique CNC parts, two 
settups a piece. The rest of the parts are laser cut sheet metal. Special care was taken to ensure that 
every screw is accessable without any disasembly, meanting that an part of the actuator stack can be removed
and replaced without needing to disasemble any other part. 

### Suspension ###

<img src="/images/PXL_20250221_224831193 (1).jpg" width="45%"/>

This year's suspension features a damped 3-bar linkage with swerve drive to independently change the
direction of each wheel. This change increased the overall stiffness of the system by bringing the 
wheels closer to the frame. Reduced control arm lengths also reduced the effective loading on the 
suspension, allowing for a lighter overall design.

<img src="/images/SwerveMoving.gif" width="45%"/>

In previous years, swerve drive suffered from low speed, limiting responsiveness during driving. It 
could take several seconds to turn the wheels 90 degrees, forcing the rover to slow down or stop in 
order to make some maneuvers. This year, I selected smaller faster motors, and changed the reduction
on the output from 100:1 to 50:1, making it 4 times faster, and 0.5kg lighter per actuator. The origional 
design was done using the same motors and gearboxes as the lower arm for interoperabliity. I worked with the 
arm lead to maintain interoperability, and choose an actuator design that would match the torque and 
speed requirements for both swerve and the wrist. The new stack is responsive enough to make sharp maneuvers 
during operation, and can do a complete 180 in less than one second.

### Frame ###

<img src="/images/Drives chassis.jpg" width="45%"/>

We built on our success from the sheet metal frame I had designed the previous year, modifying it to an 
octagonal shape to support the new suspension. It was also made wider, to increase mounting space inside, 
and unneeded support members were removed to reduce weight. 


## Testing ##

<p float="left">
  <img src="/images/CF Link.jpg" width="45%" />
  <img src="/images/sheet metal link.jpg" width="45%" />
</p>

The rover preformed very well during the first assembly, needing only minor modifications. The carbon fiber 
lower control arm seen above lacked ample contact points to ensure that the swerve module would not rotate. 
I worked to remide this issue by replacing the single clevis with two sheet metal plates, increasing the 
torsional stiffness and eliminating the rotation issue. 

<img src="/images/slallum.gif" width="45%"/>

The changes to swerve previously meantioned allowed us to make sharp turns and manuvers without slowing the 
rover down. Formerly, a direction change would involve almost a complete stop.










