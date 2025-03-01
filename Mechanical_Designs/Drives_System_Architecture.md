# Drives System Architecture 2024-2025 #

## Overview ##

The Cornell Mars Rover Drives team is responsible for all basic mechanical functionality of the rover's 
systems. This includes the frame, suspension, wheels, electronics bay, and radio communication tower. 
This year's drives system is designed to forgo the focus on climbing that drives systems traditionally 
emphasize in favor of a faster, more maneuverable system. Additionally, this year we opted to keep the 
arm on for all missions, meaning that drives needed to become lighter so as to not go over the weight 
limit during the science mission.

## Changes from Previous Years ##

### Wheels ###

Brushless Maxon motors and planetary gearboxes replaced the old hub motors driving the wheels. This 
allowed us to keep a relatively high drive speed, while increasing controllability with absolute 
magnetic encoders, and reducing weight by over 1kg per motor. We also transitioned the tires from 
pneumatic to 3D printed TPU. This allowed for a further reduction of weight.

### Suspension ###

This year's suspension features a damped 3-bar linkage with swerve drive to independently change the
direction of each wheel. This change increased the overall stiffness of the system by bringing the 
wheels closer to the frame. Reduced control arm lengths also reduced the effective loading on the 
suspension, allowing for a lighter overall design.

In previous years, swerve drive suffered from low speed, limiting responsiveness during driving. It 
could take several seconds to turn the wheels 90 degrees, forcing the rover to slow down or stop in 
order to make some maneuvers. This year, faster drone motors were selected, and the reduction on the 
output was reduced, making it 4 times faster, and 0.5kg lighter per actuator. The new stack is 
responsive enough to make sharp maneuvers during operation, and can do a complete 180 in less than one 
second.

### Frame ###

We built on our success from the sheet metal frame I had designed the previous year, modifying it to an 
octagonal shape to support the new suspension. It was also made wider, to increase mounting space inside, 
and unneeded support members were removed to reduce weight.


## Testing ##

The rover has performed remarkably well in testing, despite still being in the first stage of its assembly.
The changes to the wheels and swerve have yielded incredible improvements in responsiveness and handling, 
allowing for much more precise maneuvering and better control at all speeds. The new suspension has exceeded 
our expectations, and despite our focus on maneuverability, it has performed better than any other rover to 
date in the climbing tasks.










