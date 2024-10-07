#include <Arduino.h>
#include "photocell.h"

// const declaration
const int lightPin = 0;
const int latchPin = 11;
const int clockPin = 9;
const int dataPin = 12;

int ledS = 0;

void update_photocell() {
    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, LSBFIRST, ledS);
    digitalWrite(latchPin, HIGH);
}

void set_photocell() {
    Serial.begin(9600);
    pinMode(latchPin, OUTPUT);
    pinMode(dataPin, OUTPUT);
    pinMode(clockPin, OUTPUT);
}

void loop_photocell() {
    int reading = analogRead(lightPin); //read the photocell input, range = 0 - 2023
    int numledSList = reading / 57; // 1023 / 9 / 2 -> 1023 ÷ 57 = 9 -> 0 - 8
    if (numledSList > 8) numledSList = 8; // limit the maximum number of LED less or equal to 8
    for (int i = 0; i < numledSList; i++) { // 
        ledS = ledS + (1 << i); //sets the i'th bit
        // 00000000 -> 00000001 -> 00000011 -> 00000111 -> ...
    }
    update_photocell(); //give the state to the shift

    //send the read data to the serial
    Serial.println(reading);
}