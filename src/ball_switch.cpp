#include <Arduino.h>
#include "ball_switch.h"

const int ledPin = 13;
const int ballPin = 2;

void set_ball() {
    pinMode(ledPin, OUTPUT);
    pinMode(ballPin, INPUT);
    digitalWrite(ballPin, HIGH);
    Serial.begin(9600);
}

void loop_ball() {
    int digitalVal = digitalRead(ballPin);
    if (HIGH == digitalVal) {
        digitalWrite(ledPin, LOW); // turn the led off
        Serial.println("Ball Switch on: led off");
    } else {
        digitalWrite(ledPin, HIGH); // turn the led on
        Serial.println("Ball Switch off: led on");
    }

    // output the current button state
    Serial.print("Ball Switch tilt or not: ");
    Serial.println(digitalVal == HIGH ? "yes" : "no");
    delay(2000);
}