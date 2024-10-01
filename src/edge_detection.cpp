#include <Arduino.h>
#include "globals.h"
#include "edge_detection.h"

const int buttonPin = 2;
const int ledPin = 13;

int buttonPushCounter = 0; //counter for the 
// int buttonState = 0; //current state of the button
// int lastButtonState = 0; //previous state of the button

void set_detection() {
    // initialize the button pin as a input
    pinMode(buttonPin, INPUT);
    // initialize the led pin as a output
    pinMode(ledPin, OUTPUT);
    //initialize serial communication
    Serial.begin(9600);
}

void loop_detection() {
    // read the pushbutton input pin:
    buttonState = digitalRead(buttonPin);

    // compare the buttonState to its previous state
    if (buttonState != lastButtonState) {
        if (buttonState == HIGH) {
            // if the current state is HIGH then the button went from off to on:
            buttonPushCounter++;
            Serial.println("on");
            Serial.print("number of button pushes: ");
            Serial.println(buttonPushCounter);
        } else {
            // if the current state is LOW then the button went from on to off
            Serial.println("off");
        }
        // Delay a little bit to avoid bouncing
        delay(50);
    }
    // save the current state as the last state, for next time through the loop
    lastButtonState = buttonState;

    // turn on the LED every four button pushes by checking the modulo of the
    // button push counter. 
    if (buttonPushCounter % 4 == 0) {
        digitalWrite(ledPin, HIGH);
    } else {
        digitalWrite(ledPin, LOW);
    }
}