# Arduino-Longboard-Brake
Using an Arduino Microcontroller, we created a mechanical brake that activates when the user falls, or otherwise gets off their longboard. This is with the hope that the longboard will come to a stop long before it gets lost, damaged or runs into hazards like the road.

## Components
For this system, we used the following components
- Arduino Uno Rev3
- 4-Relay Digital Module (Although you only need 1 Relay for this to work)
- 50 KG Load Cell
- HX711 Load Cell Amplifier Chip
- An Electric Magnet Door Lock
- A Brake made out of a steel rod and rubber

## How it works
When getting on their longboard, the user will step on, and keep their foot on a small piece of metal attached to the 50 KG Load cell. They can then use their
longboard as they usually would.
In the case where they fall or otherwise leave their longboard in an uncontrolled manner, the load cell will detect this drop in weight, and begin the braking process.
By default, the electromagnet keeping the brake attached to the longboard is on, but the arduino is programmed to tell the magnet to turn off in the absence of a user riding
the longboard. Finally, when the magnet turns off, the mechanical brake drops from the bottom of the longboard and creates friction with the ground, bringing it to a stop.

We used this very helpful guide in setting up the load cell circuitry: https://circuitjournal.com/50kg-load-cells-with-HX711

## Results
Testing on flat cement, we found that the longboard would roll to a stop after travelling about on average 9.4 meters in 21 seconds.
Equipped with the braking system however, the longboard would come to a stop after travelling on average 2.3 meters in 3.4 seconds.



## Some considerations and improvements
Although this system would be nice to have a for a regular skateboard, users are often doing tricks and leaving their skateboards unmanned for seconds at a time, which would make
our system activate when it shouldn't. A possible fix would be to increase the length of time it takes for the arduino to activate the brake after a drop in weight has occured, but this would
reduce the effectiveness of the brake overall.  
We decided that it would be best to designate this brake system for Longboards since they are more often used for commuting rather than use in skateparks.  

Additionally our design is very rudimentary with exposed wiring, and often the moving parts will create noise in the electrical signals. In possible future iterations it would be best
for the system wiring to be built onto a pcb with some sort of casing around it.




