/*
  Annie Liu
  Created 04/26/2022
  
  Description: This program treats a knitted soft sensor as a button
  to turn an led on and off.

  Board: Arduino Uno
*/

int sensor = A0; // goes to soft sensor
int sensVal = 0; // a variable to store previous sensor values
int led = 11; // led is connected to pin 11
boolean touch = false; // a variable to keep track of whether the button has been touched
boolean ledON = false; // a variable to keep track of the led's state

void setup() {
  pinMode(sensor, INPUT_PULLUP);
  pinMode(led, OUTPUT);
  digitalWrite(led, LOW); // led off
  Serial.begin(9600);
}

void loop() {
  int currsensorValue = analogRead(sensor); // read sensor value
  Serial.println(currsensorValue); // print sensor value
  delay(1); // delay 1 ms

  if (currsensorValue > 400 && sensVal < 380) { // in the analog readings, i found that a value above 400 could indicate a touch, the values rest below 380 when not touched
    touch = true;
  } else {
    touch = false;
  }

  if (touch && ledON == false) { // if the button was touched and the led is off
    digitalWrite(led, HIGH); // turn led on
    ledON = true;
  } else if (touch && ledON == true) { // if the button was touched and the led is on
    digitalWrite(led, LOW); // turn the led off
    ledON = false;
  }

  sensVal = currsensorValue; // store sensor value for next loop

}
