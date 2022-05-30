// This uses Serial Monitor to display Range Finder distance readings

// Include NewPing Library
#include "NewPing.h"

// Hook up HC-SR04 with Trig to Arduino Pin 9, Echo to Arduino pin 10
#define TRIGGER_PIN 9
#define ECHO_PIN 10

// Maximum distance we want to ping for (in centimeters).
#define MAX_DISTANCE 400  

// NewPing setup of pins and maximum distance.
NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);
float duration, distance;

void setup() 
{
  Serial.begin(9600);
  pinMode(13, OUTPUT);
}

void loop() 
{
  // Send ping, get distance in cm
  distance = sonar.ping_cm();
  
  // Send results to Serial Monitor
  Serial.print("Distance = ");
  
  if (distance >= 400 || distance <= 0) 
  {
    Serial.println("Out of range");
  }
  else 
  {
    if (distance <= 128 ) 
    {
      Serial.print(distance);
      Serial.println(" cm");
      
      Serial.println("Someone is here");
      digitalWrite(13, HIGH);   // turn the LED on (HIGH is the voltage level)
      delay(10);              // wait for a second
      digitalWrite(13, LOW);    // turn the LED off by making the voltage LOW
      delay(10);
    } 
    else
    {
    Serial.print(distance);
    Serial.println(" cm");
    }
    
  }
       
  delay(300);
}
