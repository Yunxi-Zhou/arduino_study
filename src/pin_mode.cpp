#include <Arduino.h>
#include "pin_mode.h"

int delayTime = 1000;

void setup_pin() {
    pinMode(5, OUTPUT); //LED_BUILTIN
}

void loop_pin() {
    digitalWrite(5, HIGH);
    delay(delayTime);
    digitalWrite(5, LOW);
    delay(delayTime);
}