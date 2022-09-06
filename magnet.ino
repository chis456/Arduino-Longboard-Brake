/*
 * Written by: Chris Sim and Tony Chen
 * used guide from Nathan Seidle
 * Components required: Load cell, 
 Example using the SparkFun HX711 breakout board with a scale
 By: Nathan Seidle
 SparkFun Electronics
 Date: November 19th, 2014
 License: This code is public domain but you buy me a beer if you use this and we meet someday (Beerware license).

 This example demonstrates basic scale output. See the calibration sketch to get the calibration_factor for your
 specific load cell setup.

 This example code uses bogde's excellent library: https://github.com/bogde/HX711
 bogde's library is released under a GNU GENERAL PUBLIC LICENSE

 The HX711 does one thing well: read load cells. The breakout board is compatible with any wheat-stone bridge
 based load cell which should allow a user to measure everything from a few grams to tens of tons.
 Arduino pin 2 -> HX711 CLK
 3 -> DAT
 5V -> VCC
 GND -> GND

 The HX711 board can be powered from 2.7V to 5V so the Arduino 5V power should be fine.

*/

#include "HX711.h"

#define calibration_factor -7050.0 //This value is obtained using the SparkFun_HX711_Calibration sketch

#define DOUT  4
#define CLK  5
#define SOLENOID1  12
#define SOLENOID2  11
#define SOLENOID3  10
#define SOLENOID4  9
bool activated = false;

HX711 scale;

void setup() {
  Serial.begin(9600);
  Serial.println("HX711 scale demo");

  scale.begin(DOUT, CLK);
  scale.set_scale(calibration_factor); //This value is obtained by using the SparkFun_HX711_Calibration sketch
  scale.tare(); //Assuming there is no weight on the scale at start up, reset the scale to 0

  Serial.println("Readings:");
  pinMode(12,OUTPUT); // RELAY PIN
  pinMode(11,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(9,OUTPUT);
}

void loop() {
  if(!activated)
  {
    digitalWrite(SOLENOID1, LOW);
  }
  float weight = abs(scale.get_units());
 
  if(weight > 10)
  {
    Serial.print("test1");
    activated = true;
    
  }

  if(activated)
    {
      Serial.print("activated");
      if(weight < 10)
      {
        digitalWrite(SOLENOID1, HIGH);
        digitalWrite(SOLENOID2, LOW);
        digitalWrite(SOLENOID3, LOW);
        digitalWrite(SOLENOID4, LOW);
        /*
        Serial.print("solenoid go in");
        delay(2000);
        digitalWrite(SOLENOID1, HIGH);
        digitalWrite(SOLENOID2, HIGH);
        digitalWrite(SOLENOID3, HIGH);
        digitalWrite(SOLENOID4, HIGH);
        */
        activated = false;
        scale.set_scale(calibration_factor); //This value is obtained by using the SparkFun_HX711_Calibration sketch
        scale.tare(); //Assuming there is no weight on the scale at start up, reset the scale to 0
      }
    }
    
  Serial.print("Reading: ");
  Serial.print(weight, 1); //scale.get_units() returns a float
  Serial.print(" lbs"); //You can change this to kg but you'll need to refactor the calibration_factor
  Serial.println();
//  return weight;
}
