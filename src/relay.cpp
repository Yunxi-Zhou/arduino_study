#include <Arduino.h>
#include "relay.h"

#define ENABLE 5
#define DIRA 3
#define DIRB 4


void set_relay() {
    pinMode(ENABLE, OUTPUT);
    pinMode(DIRA, OUTPUT);
    pinMode(DIRB, OUTPUT);
    Serial.begin(9600);
}

void loop_relay() {
    // relay example
    digitalWrite(ENABLE, HIGH); // enable on
    for (int i = 0; i < 5; i++) {
        Serial.println("spin");
        digitalWrite(DIRA, HIGH); // motor spins
        digitalWrite(DIRB, LOW); 
        delay(2000);
        Serial.println("stop");
        digitalWrite(DIRA, LOW); // motor stops
        digitalWrite(DIRB, HIGH);
        delay(2000);
    }
}