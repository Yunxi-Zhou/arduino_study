#include <Arduino.h>
#include "dc_motor.h"

#define ENABLE 5
#define DIRA 3
#define DIRB 4

int i;

void set_dc() {
    // set pin direction
    pinMode(ENABLE, OUTPUT);
    pinMode(DIRA, OUTPUT);
    pinMode(DIRB, OUTPUT);
    Serial.begin(9600);
}

void loop_dc() {
    // back and forth example
    Serial.println("One way, then reverse");
    digitalWrite(ENABLE, HIGH); //one way
    for (i = 0; i < 5; i++) {
        digitalWrite(DIRA,HIGH); // one way
        digitalWrite(DIRB, LOW);
        delay(500);
        digitalWrite(DIRA, LOW);
        digitalWrite(DIRB, HIGH);
        delay(500);
    }
    digitalWrite(ENABLE, LOW); // disable
    delay(2000);

    // fast slow example
    Serial.println("fast slow example");
    digitalWrite(ENABLE, HIGH); // enable on
    digitalWrite(DIRA, HIGH); // one way
    digitalWrite(DIRB, LOW);
    delay(3000);
    digitalWrite(ENABLE, LOW); // slow stop
    delay(1000);
    digitalWrite(ENABLE, HIGH); // enable on
    digitalWrite(DIRA, LOW); // one way
    digitalWrite(DIRB, HIGH);
    delay(3000);
    digitalWrite(DIRA, LOW); // fast stop
    delay(2000);

    //PWM example, full speed then slow
    Serial.println("PWM full then slow");
    analogWrite(ENABLE, 255); // enable on
    digitalWrite(DIRA, HIGH); // one way
    digitalWrite(DIRB, LOW);
    delay(2000);
    analogWrite(ENABLE, 180); // half speed
    delay(2000);
    analogWrite(ENABLE, 128); // half speed
    delay(2000);
    analogWrite(ENABLE, 50); // half speed
    delay(2000);
    analogWrite(ENABLE, 128); // half speed
    delay(2000);
    analogWrite(ENABLE, 180); // half speed
    delay(2000);
    analogWrite(ENABLE, 255); // half speed
    delay(2000);
    digitalWrite(ENABLE, LOW); // done
    delay(10000);
}