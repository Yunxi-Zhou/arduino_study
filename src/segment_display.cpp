#include <Arduino.h>
#include "segment_display.h"

byte seg_digit[10] = { B11111100,  // = 0
                              B01100000,  // = 1
                              B11011010,  // = 2
                              B11110010,  // = 3
                              B01100110,  // = 4
                              B10110110,  // = 5
                              B10111110,  // = 6
                              B11100000,  // = 7
                              B11111110,  // = 8
                              B11100110   // = 9
                             };

// connect to the ST_CP of 74HC595 (pin3 latch pin)
int latchPin = 3;
// connect to the SH_CP of 74HC595 (pin4, clock pin)
int clockPin = 4;
// connect to the DS of 74HC595 (pin2)
int dataPin = 2;

void set_segment() {
    pinMode(latchPin, OUTPUT);
    pinMode(clockPin, OUTPUT);
    pinMode(dataPin, OUTPUT);
    Serial.begin(9600);
}

void seg_write(byte digit) {
    //set the latchPin to low potential, before sending data
    digitalWrite(latchPin, LOW);

    // the original data (bit pattern)
    shiftOut(dataPin, clockPin, LSBFIRST, seg_digit[digit]);

    // set the latchPin to high potential, after sending data
    digitalWrite(latchPin, HIGH);

    Serial.print("Displayed Digit: ");
    Serial.println(digit);

}

void loop_segment() {
    // count from 9 to 0
    for (byte digit = 10; digit > 0; --digit) {
        delay(1000);
        seg_write(digit - 1);
    }

    delay(3000);
    
}