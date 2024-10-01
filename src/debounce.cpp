/*
debounce an input = checking twice in a short period of time to 
make sure the pushbutton is definitely pressed. Without debouncing,
pressing the button once may cause unpredictable results.
*/
#include <Arduino.h>
#include "globals.h"
#include "debounce.h"

const int buttonPin = 2;
const int ledPin = 13;

int ledState = HIGH;
int buttonState = 0;
int lastButtonState = 0;

unsigned long lastDebounceTime = 0;
unsigned long debounceDelay = 50;

void set_debounce() {
    pinMode(buttonPin,INPUT);
    pinMode(ledPin, OUTPUT);

    digitalWrite(ledPin, ledState);
}

void fun_debounce() {
    int reading = digitalRead(buttonPin);

    // if the switch changed, due to noise or pressing:
    if (reading != lastButtonState) {
        //reset the debouncing timer
        lastDebounceTime = millis();
    }
    //如果时间超过过去抖动延迟，认为按钮状态已经稳定
    if ((millis() - lastDebounceTime) > debounceDelay) {
        //if the button state has changed
        if (reading != buttonState) {
            buttonState = reading;
            
            //只有在按钮按下HIGH的时候，才切换LED状态
            if (buttonState == HIGH) {
                ledState = !ledState;
            }
        }

    }
    //保存这次按钮状态
    lastButtonState = reading;
    //设置LED状态
    digitalWrite(ledPin, ledState);
}

