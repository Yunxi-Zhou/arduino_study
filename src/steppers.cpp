#include <Arduino.h>
#include "steppers.h"
#include <Stepper.h>

const int stepsPerRevolution = 2048; // change this to fit the number of steps per revolution
const int rolePerMinute = 15; // Adjustable range of 29BYJ-48 stepper is 0-17 rpm

// initialization the stepper library on pins 8 through 11:
Stepper myStepper(stepsPerRevolution, 8, 10, 9, 11);

void set_stepper() {
    myStepper.setSpeed(rolePerMinute);
    // initialize the serial port
    Serial.begin(9600);
}

void loop_stepper() {
    // step one revolution in the other direction
    Serial.println("counterclockwise");
    myStepper.step(-stepsPerRevolution);
    delay(500);
}