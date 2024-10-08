#include <Arduino.h>
#include "ultrasonic_sensor.h"
#include <SR04.h>
#define TRIG_PIN 12
#define ECHO_PIN 11

// const declarations
SR04 sr04 = SR04(ECHO_PIN, TRIG_PIN);

void set_ultrasonic() {
    Serial.begin(9600);
    delay(1000);
}

void loop_ultrasonic() {
    unsigned int distance = sr04.Distance();
    Serial.println(distance);
    delay(1000);
}