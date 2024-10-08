#include <Arduino.h>
#include <Servo.h>
#include "servo_s.h"

// const declaration
Servo myServo; //  create servo object to control a servo
// 12 servo objects can be created store the servo position

int pos = 0; // variable to store the servo position


void set_servo() {
    Serial.begin(9600); //initialize the serial port
    myServo.attach(9); // attaches the servo on pin 9 to the servo object
    
}

void loop_servo() {
    for (pos = 0; pos <= 180; pos += 1) {
        // in steps of 1 degree
        myServo.write(pos); // tell servo to go to position in variable 'pos'
        delay(15); // waits 15ms for the servo to reach the position
    }

    for (pos = 180; pos >= 0; pos -= 1) {
        myServo.write(pos);
        delay(15);
    }
}

void serial_servo() {
    if (Serial.available() > 0) {
        // read the data from python
        int angle = Serial.parseInt();

        // make sure the angle is between 0 and 180
        if (angle >= 0 && angle <= 180) {
            myServo.write(angle);
            Serial.print("Moving to ");
            Serial.print(angle);
            Serial.println(" degrees");
        }

        while (Serial.available() > 0) {
            Serial.read();
        }
    }
}