# Radio Repeater 2025 #

## Overview ##

A radio repeater is a module that receives a signal and retransmits it on a slightly different 
frequency. This is done to extend line of sight radio operation beyond and behind obstacles. 
Commercially, this technology is mostly used to transmit signals from radio towers over large
obstacles like mountain ranges. However, the focus of this project was to miniaturize it and 
make it deployable off the back of a mobile robot. This would allow for better communications 
with mobile robots from beyond line of sight and around obstacles such as hills or buildings.

<img src="/images/Repeater Module.jpg" width="45%"/>

## Design Requirements ##

<ol>
    <li>Must stay within the UNII frequency bands (assuming the use of a 5G radio)</li>
    <li>Radio power must be under 23 dBm/MHz, and may not exceed 36dBm*</li>
    <li>Must be compact enough to mount onto a mobile robot</li>
    <li>Must only power on after deployment so as to avoid interference with onboard radio</li>
    <li>Must to reliably deploy in the correct orientation for the antenna</li>
    <li>Must reliably connect as a new node on the radio network</li>
</ol>

## Design ##

The design is a fairly simple one: a sheet metal enclosure is designed with an outer shape and 
center of gravity to bias it to fall in one direction. This is done to eliminate the complexity
needed to lower it to the ground, and instead simply drop it off the back of the robot. A
mounting platform holds the repeater to the robot, and during deployment, a servo releases the
device, allowing it to fall down a set of guide rails that assure correct orientation as freefall
begins. While attached to the rover, a magnetic connector feeds power to the coil of a normally 
closed relay. During freefall, this connector is pulled apart, and the relay is opened, allowing
the repeater to power on. Once on the ground, the repeater falls into its proper orientation, 
and connects to the network.

## Testing ##

<img src="/images/9lwepf.gif" width="45%"/>

During testing, all of these systems worked with over 95% reliability. The power-on system worked 
for 100% of trials that were conducted, as well as linking to the network. The repeater itself 
very rarely fell in an incorrect orientation, however even when the orientation was off it was 
still able to connect to the network with a weaker connection. Deploying a repeater did create a 
throughput loss of about 50%, which does limit the viability of chaining several of these together 
to traverse around more complex obstacles.









