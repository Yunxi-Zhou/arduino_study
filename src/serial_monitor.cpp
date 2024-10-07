#include <Arduino.h>
#include "serial_monitor.h"

// constant declaration
const int latchPin = 11;
const int clockPin = 9;
const int dataPin = 12;

byte leds = 0;

void update_monitor() {
    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, LSBFIRST, leds);
    digitalWrite(latchPin, HIGH);
}

void set_monitor() {
    Serial.begin(9600);
    pinMode(latchPin, OUTPUT);
    pinMode(dataPin, OUTPUT);
    pinMode(clockPin, OUTPUT);
    update_monitor();
    while (! Serial); // wait until serial is ready
    Serial.println("Enter leds Number 0 - 7 or 'x' to clear");

}

void loop_monitor() {
    if (Serial.available()) {
        char ch = Serial.read();

        if (ch >= '0' && ch <= '7') {
            int le = ch - '0';
            bitSet(leds, le);
            update_monitor();
            Serial.print("Turned on leds ");
            Serial.println(le);
        }

        if (ch == 'x') {
            leds = 0;
            update_monitor();
            Serial.println("Cleared");
        }
    }
}