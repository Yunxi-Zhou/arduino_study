#include <Arduino.h>
#include "joystick.h"

// Arduino pin numbers
const int SW_pin = 2;  // digital pin connected to switch output
const int X_pin = A0;  // analog pin connected to X output
const int Y_pin = A1;  // analog pin connected to Y output

void set_joy() {
    pinMode(SW_pin, INPUT);
    digitalWrite(SW_pin, HIGH);
    Serial.begin(9600);
}

void loop_joy() {
    Serial.print("Switch:  ");
    Serial.print(digitalRead(SW_pin));
    Serial.print("\n");
    Serial.print("X-axis:  ");
    Serial.print(analogRead(X_pin));
    Serial.print("\n");
    Serial.print("Y-axis:  ");
    Serial.print(analogRead(Y_pin));
    Serial.print("\n\n");
    delay(500);
}