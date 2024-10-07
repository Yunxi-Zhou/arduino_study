#include <Arduino.h>
#include "eight_led.h"

// const declaration
const int tDelay = 100;  //delay time
const int latchPin = 11;  // set up on chip
const int clockPin = 9;  // store temporary
const int dataPin = 12;  // output to the serial

byte led = 0;

void update_chip() {
    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, LSBFIRST, led); 
    //LSBFIRST: least significant bit first 最低有效位 -> B10101010
    digitalWrite(latchPin, HIGH);
}

void set_chip() {
    pinMode(latchPin, OUTPUT);
    pinMode(dataPin, OUTPUT);
    pinMode(clockPin, OUTPUT);
    Serial.begin(9600);
    Serial.println("Connected to Arduino");
}

void loop_chip() {
    // led = 0;
    // update_chip();
    // delay(tDelay);
    // for (int i = 0; i < 8; i++) {
    //     bitSet(led, i);
    //     update_chip();
    //     delay(tDelay);
    // }

    // check if the data is available on Serial port
    if (Serial.available() > 0) {
        //read the incoming byte
        led = Serial.read(); // read one byte from serial
        update_chip(); // update the chip with the new data
        Serial.print("LED state updated: ");
        Serial.println(led, BIN); // print current LED state in binary format
    }

}