#include <Arduino.h>
#include "digital_input.h"

int ledPin = 5;
int buttonApin = 9;
int buttonBpin = 8;

void set_digital() {
    pinMode(ledPin, OUTPUT);
    pinMode(buttonApin, INPUT_PULLUP);
    pinMode(buttonBpin, INPUT_PULLUP);
}

void loop_digital() {
    if (digitalRead(buttonApin) == LOW) {
        digitalWrite(ledPin, HIGH);
    }
    if (digitalRead(buttonBpin) == LOW) {
        digitalWrite(ledPin, LOW);
    }
}