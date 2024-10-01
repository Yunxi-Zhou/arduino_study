#include <Arduino.h>
#include "input_pullup.h"

void set_pullup(){
    //start serial communication
    Serial.begin(9600);
    // set pin 2 as an input and enable the internal pull-up resistor
    pinMode(2, INPUT_PULLUP);
    pinMode(13, OUTPUT);
}

void loop_pullup() {
    //read the push button into variable
    int sensorVal = digitalRead(2);
    //print out the value of the push button
    Serial.println(sensorVal);

    if (sensorVal == HIGH) {
        digitalWrite(13,LOW);
    } else {
        digitalWrite(13,HIGH);
    }
}