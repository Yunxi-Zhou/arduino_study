/*
debounce an input = checking twice in a short period of time to 
make sure the pushbutton is definitely pressed. Without debouncing,
pressing the button once may cause unpredictable results.
*/
#include <Arduino.h>
#include "debounce.h"

const int buttonPin = 2;
const int ledPin = 5;

int ledState = HIGH;
int buttonState;
int lastButtonState = LOW;

unsigned long lastDebounceTime = 0;
unsigned long debounceDelay = 50;

void set_debounce() {
    pinMode(buttonPin,INPUT);
    pinMode(ledPin, OUTPUT);

    digitalWrite(ledPin, ledState);
}

void fun_debounce() {
    int reading = digitalRead(buttonPin);

    // if the switch changed, due to noise or pressing:
    if (reading != lastButtonState) {
        lastDebounceTime = millis();
    }

    if ((millis() - lastDebounceTime) > debounceDelay) {
        //if the button state has changed
        if (reading != buttonState) {
            buttonState = reading;
            if (buttonState == HIGH) {
                ledState = !ledState;
            }
        }

    }

    //set the LED
    digitalWrite(ledPin, ledState);

    lastButtonState = reading;
}

