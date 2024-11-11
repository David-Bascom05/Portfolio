# Ecore #

## Overview ##

This project was done as a part of the Cornell Mars Rover project team. Its objective was to
simplify the electronics bay of the rover, and make the wire roughting for the rover easier 
to manage. To acomplish this, I completely restuctured how the ecore itself functioned, 
changing it form basically a box encloser to a revoable power distrabution unit, with built 
in wire roghting, and made it fully removable from the frame for easier maintience. Through
these changes, I was able to greatly improve cable managment, and the ability to debug 
electrical problems on the rover.

Here, you can see the old ecore (Left) compaired to the new ecore (Right)

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










