#include <Arduino.h>
#include "digital_input.h"

int ledPin = 5;
int buttonAPin = 9;
int buttonBPin = 8;

void set_digital() {
    pinMode(ledPin, OUTPUT);
    pinMode(buttonAPin, INPUT_PULLUP);
    pinMode(buttonBPin, INPUT_PULLUP);

    Serial.begin(9600); // initialize serial communication
}

void loop_digital() {
    // read button state
    int buttonAState = digitalRead(buttonAPin);
    int buttonBState = digitalRead(buttonBPin);

    if (digitalRead(buttonAPin) == LOW) {
        digitalWrite(ledPin, HIGH);
        Serial.println("Button A pressed: LED ON");
    }

    if (digitalRead(buttonBPin) == LOW) {
        digitalWrite(ledPin, LOW);
        Serial.println("Button B pressed: LED OFF");
    }

    // output current button state
    Serial.print("Button A: ");
    Serial.print(buttonAState == LOW ? "Pressed" : "Not Pressed");
    Serial.print(" | Button B: ");
    Serial.println(buttonBState == LOW ? "Pressed" : "Not Pressed");

    delay(200);
}