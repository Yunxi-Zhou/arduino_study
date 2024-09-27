#include <Arduino.h>
#include "pin_mode.h"

int delayTime = 1000;

void setup_pin() {
    pinMode(13, OUTPUT); //LED_BUILTIN
}

void loop_pin() {
    digitalWrite(13, HIGH);
    delay(delayTime);
    digitalWrite(13, LOW);
    delay(delayTime);
}