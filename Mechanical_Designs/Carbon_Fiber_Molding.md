# Carbon Fiber Molding 2023 #

## Overview ##

This project was done as a part of the Cornell Mars Rover project team. Its objective was to 
create a replacement for CNC Aluminum parts out of carbon fiber. I developed a way of molding 
solid carbon fiber parts in complex geometries using 3D printed molds. 

<img src="/images/CF_Suspension_Part.jpg" alt="Frame CAD" width="35%" />

## Molding Procces ##

The process I used is called compression molding. During the molding process, chopped carbon 
is placed in the mold, and covered in epoxy resin. This is repeated over and over, until the 
carbon/epoxy mixture is equal to the mass of the desired part (as given by the CAD).

<img src="/images/Carbon_in_Mold.jpg" alt="Frame CAD" width="35%" />

This mixture is usually much larger in volume than the part, so it must then be compressed. 
The top of the mold is pressed down into the mold over a period of around 30 min, to allow 
time for the excess epoxy in the mixture to escape. 

<img src="/images/Mold_in_Vise.jpg" alt="Frame CAD" width="35%" />

## Mold Design ##

As you can see from the images above, and the parts that were made from them, molds could be 
used to create incredibly complex geometry, with relatively little effort. The molds I 
designed were 3D printed out of PETG. This was due to 3D printing being a very easy way to 
make the complex geometry needed in manufacturing these, and PETG was chosen for its lack 
of adhesion to the epoxy I was using. The biggest drawback to using 3D printing was that 
it was very weak, and would often break during the demolding process. This meant that molds
were usually one time use. This was not a huge detriment however, as molds are very easy to 
print. This did make demolding the part the most difficult part of the process, so designing 
molds for part removal was key. Large draft angles on parts that slid past each other was
critical to limit friction between walls of the mold and the part. I also discovered that 3 
piece molds were much easier to take apart than 2 piece molds, as the parts no longer had to 
slide pasteach other, but could be pulled apart. 3 piece molds also allowed more gaps for 
excess epoxy to escape, which was an added benefit.

## Testing ##

To test the yield strength of the forged parts, I made 3 dog bone samples and ran a tensile 
test on each one. The first test was done without the use of an extensometer, so no strain 
data was collected in order to calculate Young's modulus.

<table style="width:100%; border-collapse: collapse;">
  <tr>
    <th style="border: 1px solid #ddd; padding: 8px;">Sample</th>
    <th style="border: 1px solid #ddd; padding: 8px;">Yield Stress (psi)</th>
    <th style="border: 1px solid #ddd; padding: 8px;">Ultimate Stress (psi)</th>
    <th style="border: 1px solid #ddd; padding: 8px;">Youngs Modulus (psi)</th>
  </tr>
  <tr>
    <td style="border: 1px solid #ddd; padding: 8px;">1</td>
    <td style="border: 1px solid #ddd; padding: 8px;">12,072.31</td>
    <td style="border: 1px solid #ddd; padding: 8px;">12,072.31</td>
    <td style="border: 1px solid #ddd; padding: 8px;">No data</td>
  </tr>
  <tr>
    <td style="border: 1px solid #ddd; padding: 8px;">2</td>
    <td style="border: 1px solid #ddd; padding: 8px;">15,632.85</td>
    <td style="border: 1px solid #ddd; padding: 8px;">15,632.85</td>
    <td style="border: 1px solid #ddd; padding: 8px;">5.33 × 10<sup>6</sup></td>
  </tr>
  <tr>
    <td style="border: 1px solid #ddd; padding: 8px;">3</td>
    <td style="border: 1px solid #ddd; padding: 8px;">14,784.78</td>
    <td style="border: 1px solid #ddd; padding: 8px;">14,784.78</td>
    <td style="border: 1px solid #ddd; padding: 8px;">6.76 × 10<sup>6</sup></td>
  </tr>
</table>

As you can see, the yield stress and ultimate stress are basically the same from the 
measurements we were able to take. The material is incredibly brittle; however, it does 
have a decently high yield point (just under half the yield stress of Aluminum at its 
best performance). However, there was also a relatively high variance in this data. The 
first dog bone, which failed substantially before the rest, had a very visible void along 
the fracture line, which I believe is why it failed at such a low value. I also believe 
that smaller voids were probably present in samples 2 and 3 as well, but not quite as 
obvious. This is 1) because of the substantial difference between the failure stresses 
of each part, and 2) because both fell short of the expected yield point.

From this testing, we decided that the process was not yet reliable enough to use on the 
rover without a way to eliminate voids in the parts during the molding process. While it 
did meet the minimum strength requirements we needed in these tests, the possibility that
a large void could substantially weaken the part was too much of a risk. 

From this testing, we decided that the process was not yet reliable enough to use on the rover 
without a way to eliminate viods in the parts during the molding process. While it did meet the 
minimum strength requirements we needed in these tests, the posibility that a large void could 
substantually weaken the part was too much of a risk.


