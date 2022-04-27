/*
  Annie Liu
  Created 04/26/2022
  
  Description: This program maps the analog readings from a knitted stretch soft sensor
  to an led's brightness.

  Board: Arduino Uno
*/

int sensor = A0; // goes to soft sensor
int led = 11; // led is connected to pin 11

void setup() {
  pinMode(sensor, INPUT_PULLUP);
  pinMode(led, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int sensorValue = analogRead(sensor); // read sensor value
  Serial.println(sensorValue); // print sensor value
  delay(1); // delay 1 ms
  sensorValue = constrain(sensorValue, 20, 180); // constrain sensor values to 20-180 
  int brightness = map(sensorValue, 20, 180, 0, 255); // map sensor values to brightness range
  analogWrite(led, brightness); // write led to brightness
  delay(1); // delay 1 ms

}
