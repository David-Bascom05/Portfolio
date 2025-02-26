# Radio Repeater 2025 #

## Overview ##

A radio repeater is a module that recieves a signal and retransmits it on a slightly
different frequency. This is done to extend line of sight radio opperation beond and
behind obsticals. Comersially, this technology is mostly used to transmit signals from
radio towers over large obsticals like mountain ranges. However, the focus of this project
was to miniaturize it and make it deployable off the back of a mobile robot. This would
allow for better comunications with mobile robots from beond line of sight and around 
obsticals such as hills or buildings.

## Design Requirements ##

<ol>
    <li>Must stay within the UNII frequency bands (assuming the use of a 5G radio)</li>
    <li>Radio power must be under 23 dBm/MHz, and may not exceed 36dBm*</li>
    <li>Must be compact enough to mount onto a mobile robot</li>
    <li>Must only power on after deployment so as to avoid interfierence with onboard radio</li>
    <li>Must to reliably deploy in the correct orientation for the antenna</li>
    <li>Must reliably connect as a new node on the radio network</li>
</ol>

## Design ##

