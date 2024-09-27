#include <Arduino.h>
#include "pin_button.h"


void set_led() {
    pinMode(5,OUTPUT);
    pinMode(2, INPUT);
}

void lightOnOff() {
    int butt = digitalRead(2);
    
    if (butt == HIGH){
        digitalWrite(5,HIGH);
        delay(1000);
    } else {
        digitalWrite(5,LOW);
        delay(1000);
    }
}