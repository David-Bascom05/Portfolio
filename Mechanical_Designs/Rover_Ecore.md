# Ecore 2023 #

## Overview ##

This project was done as a part of the Cornell Mars Rover project team. Its objective was to 
simplify the electronics bay of the rover, and make the wire routing for the rover easier to 
manage. To accomplish this, I completely restructured how the ecore itself functioned, 
changing it from basically a box enclosure to a removable power distribution unit, with 
built-in wire routing, and made it fully removable from the frame for easier maintenance. 
Through these changes, I was able to greatly improve cable management, and the ability to 
debug electrical problems on the rover.

Here, you can see the old ecore (Left) compared to the new ecore (Right).

<div style="display: flex; justify-content: space-between;">
  <img src="/images/Old_Ecore.jpg" alt="Old Ecore" style="height: 400px; width: auto;">
  <img src="/images/NewEcore.png" alt="New Ecore" style="height: 400px; width: auto;">
</div>

## Design Requirements ##

<ol>
    <li>Houses all required electrical equipment for rover operation</li>
    <li>Runs wiring to all systems</li>
    <li>Adequate cooling for desert conditions, up to 120 degree heat</li>
    <li>Easily understandable wire routing and management</li>
    <li>Fully removable for maintenance and accessibility</li>
    <li>Plug and play capability for all boards and external systems</li>
    <li>No disassembly required for transport</li>
</ol>


## Design ##

<img src="/images/Ecore_Insides.png" alt="Old Ecore" style="height: 400px; width: auto;">

This design revolves around the use of a false floor to route wires under. This method allowed me to 
drastically reduce clutter from wires, and improve organization. It also provided easy mounting for 
all the connectors to be embedded into the structure of the ecore. This meant that for both boards and 
external systems that plug into the ecore, all wiring was permanent, and any system became plug-and-play,
with no additional integration work required when taking parts on and off the rover. This plug-and-play 
system drastically reduced the time to assemble the rover, which was critically important for exchanging 
systems during testing, hot swapping components that broke, and reassembling the rover at competition.


## Testing ##

Having the Ecore be fully removable was a huge improvement regarding maintenance. It allowed the electrical
team to work on it off the rover, which was both much easier, and allowed the other subteams to work on the 
mechanical aspects of the rover at the same time. This was yet another way in which this design helped save 
us time, which led to us being able to move much more quickly at competition.

We didn't have any issues with the wiring setup, which was a massive improvement in organization from last 
year. However, by mounting connectors on the side, lots of holes were added to the side panel. This meant 
that lots of sand was able to get in, which did become an issue when we got hit by a sand storm during the 
last event of the competition.










