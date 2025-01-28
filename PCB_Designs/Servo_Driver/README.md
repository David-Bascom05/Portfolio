# Servo Driver, 2024 #

# Overview #

The goal of this project is to create a custom servo driver that can controll a large 
number of servos independantly and comunicate over canfd. This was not designed with 
a particular project in mind, but more as an addaptable board that I could use in any 
project where I needed to be able to control a servo. I also wanted this board to be 
able to comunicate over the same protocal as the mjbots moteus boards, which I have 
used in many of my other projects.

<img src="/images/Servo_Board_V2_3D.png" alt="Frame CAD" width="35%" />

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
microcontroller. 

The main buck converter is a LM25145RGYR, choosen for is high current capacity and 
abundence of safety features. While far from the easiest converter I could have used, 
the LM25145RGYR allows me to draw up to 20A. For most hobby servos, this is enough to 
drive every servo at nominal load at the same time. Some servo models may draw more than 
can  be continously provided to all servos, in which case the LM25145RGYR provides 
overcurrent protection. This particuar design is meant to accept a large range of 
voltages, causing the effiency to decrease rather sharply at low current. To account for 
this, a shottcky diode is added to the main high current loop to midigate the effects of 
reverse recovery losses.

Current and temputure sensing are also integrated onto the board. While it would have been
more optimal to place the temputure sensor directly under the buck regulator, it would 
have added to assembly cost by making it a double sided assembly. Becasue of this, the 
tempurture senor is placed as close as possible to the regulator, but it is safe to assume
that the reading is not entirely accurate.

<img src="/images/Servo_Board_V2_Layout.png" alt="Frame CAD" width="50%" />

The layout is optimized reduce board size as much as possbile. This was done to enable 
the board to be used in a variaty of projects, including those where space is a premium.
This does however come with some drawbacks, mainly the fact that the high current connection 
running power to the servos is done using a single trace. Current overdraw could lead to this
trace melting, rendering all connortors after the failure useless. A pour or auilary traces
could have been used to midigate this problem, however it is unlikely that servo motors draw 
over 20A of current, and the board has overcurent protections in place to prevent this from
occering. 

Another downside of this layout is that I would have much prefered to have 4 mounting holes 
instead of 3, however I could not figure out a way to do this without adding substantually 
to the boards size.

## Firmware ##

The firmware for this board was writen using C on the STM32CubeIDE. I wrote a custom CANFD
protocal, from which the board recives and sends signals to the main controller. The first 
4 bits of the payload is reserved to identify which servo is being requested to move. The 
next two bits specify the command type, position, velocity, or dyagnostic. Velocity mode 
has yet to be implimented on the PCA9685PW driver, but the option to add that capability 
remains. The next 12 bits are reserved for position control (if the message is a position 
command type), which allows increadably high accuracy, even for servos with a large range 
of motors. If the message is a dignostic type, those bits indicate settup information that 
the board needs in order to opperate. The next bit is a binary of if a responce is requested, 
and the next 4 bits are reserved for fault handling.

A custom driver was writen for the PCA9685PW chip that allows for position control. When a 
servo object is initialized in software, it sends a diagnostic message to the board containing
the range of the servo, which is stored in a struct. When a position message is sent, the 
possition is added to the struct, and the stuct is passed into a function that generates a PWM 
signal corresponding to a fraction of the servos opperational range. This implimentation allows 
the controller to account for different ranges of motion on every servo while reducing the amount 
of data that needs to be sent via CAN. This also allows position data to be stored on the 
microcontroller to be queried later if needed.

## Software ##

The software to control this board is writen in python. Each servo is initialized as an object
of the servo class (taking a CANID and ServoID), which sends a dyagnositc message to the board 
encoded with the servo's operational range as stated above. The set_pos() meathod takes in the 
desigered position and if a respoence is requested. When a responce is requested, the struct in 
the firmware is passed back in the same format as the sent message. That responce is broken down 
and saved in a responce object, which can be printed or have its attributes accessed to be used 
elseware.

## Testing ##

During testing, the board performed very well. The first version had an inproperly sized 
inductor on the buck converter. This caused ripple voltage on the 6V output, but this was 
later corrected. The board was successfully able to drive all 16 servos simultanously with 
a high positional accuracy and low latency. The protetective meansures of the board also 
worked well, triggering the overcurrent protection before the 20A maximum of the board was
reached. 





