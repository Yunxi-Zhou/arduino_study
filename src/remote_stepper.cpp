#include <Arduino.h>
#include "remote_stepper.h"
#include <Stepper.h>
#include <IRremote.h>

#define STEPS 32 // Number of steps per revolution of Internal shaft
int Steps2Take; // 2048 = 1 Revolution
int receiver = 12; // Signal Pin of IR receiver to Arduino Digital Pin 12

//  Declare objects
Stepper small_stepper(STEPS, 8, 10, 9, 11);
IRrecv irrecv(receiver);
uint32_t last_decodedRawData = 0;

void set_remStp() {
    irrecv.enableIRIn();
    Serial.begin(9600);
}

void loop_remStp() {
    if (irrecv.decodedIRData.flags) {
        irrecv.decodedIRData.decodedRawData = last_decodedRawData;
    }
    switch (irrecv.decodedIRData.decodedRawData) {
        case 0xE916FF00:
            small_stepper.setSpeed(500);  // max 500
            Steps2Take = -2048; // Rotate CCW
            small_stepper.step(Steps2Take);
            delay(2000);
            break;

        case 0xF30CFF00:
            small_stepper.setSpeed(500);  // max 500
            Steps2Take = 2048; // Rotate CW
            small_stepper.step(Steps2Take);
            delay(2000);
            break;
    }
    if (Serial.available() > 0) {
        String command = Serial.readStringUntil('\n'); // read the serial input command
        command.trim(); // remove ' ' and '\n' and '$'

        if (command == "CCW") {
            small_stepper.setSpeed(500);  // max 500
            Steps2Take = -2048; // Rotate CCW
            small_stepper.step(Steps2Take);
            delay(2000);
        } else if (command == "CW") {
            small_stepper.setSpeed(500);  // max 500
            Steps2Take = 2048; // Rotate CW
            small_stepper.step(Steps2Take);
            delay(2000);
        }
    }
    // store the last decodedRawData
    last_decodedRawData = irrecv.decodedIRData.decodedRawData;
    irrecv.resume(); // receive the next value
    digitalWrite(8, LOW);
    digitalWrite(9, LOW);
    digitalWrite(10, LOW);
    digitalWrite(11, LOW);
}