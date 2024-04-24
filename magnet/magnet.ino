/*
 * Written by: Chris Sim and Tony Chen

 * used guide from Nathan Seidle

 Using bogde's HX711 Library: https://github.com/bogde/HX711
 bogde's library is released under a GNU GENERAL PUBLIC LICENSE

*/

#include "HX711.h"

#define calibration_factor -7050.0 //This value is obtained using the SparkFun_HX711_Calibration sketch

#define DOUT  4
#define CLK  5
#define RELAY  12
bool activated = false;

HX711 scale;

void setup() {
  Serial.begin(9600);

  scale.begin(DOUT, CLK);
  scale.set_scale(calibration_factor); //This value is obtained by using the SparkFun_HX711_Calibration sketch
  scale.tare(); //Assuming there is no weight on the scale at start up, reset the scale to 0

  Serial.println("Readings:");
  pinMode(12,OUTPUT); // RELAY PIN
}

void loop() 
{
  /*
  System starts with bool activated = false and the the magnet on.

  When the load cell detects a weight larger than 10 pounds (I.e the user steps on and begins using the longboard),
  activated is set to true, and the system waits for the load cell to read a weight smaller than 10 pounds.

  Now, If the load cell detects a weight smaller than 10 pounds (User falls off or otherwise is no longer on the longboard), a signal is sent to the
  relay module, which deactivates the magnet, allowing the mechanical brake to release and bring the longboard to a stop.

  Now the system is set back to the first step, although the User must manually bring the brake back up to the magnet in order to use it again.
  */

  if(!activated)
  {
    digitalWrite(RELAY, LOW);
  }
  float weight = abs(scale.get_units());
 
  if(weight > 10)
  {
    activated = true;
  }

  if(activated)
  {
    Serial.print("activated");
    if(weight < 10)
    {
      digitalWrite(RELAY, HIGH);
      activated = false;
      scale.set_scale(calibration_factor);
      scale.tare();
    }
  }
    
  Serial.print("Reading: ");
  Serial.print(weight, 1);
  Serial.print(" lbs");
  Serial.println();
}
