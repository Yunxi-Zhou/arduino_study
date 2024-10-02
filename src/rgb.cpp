#include <Arduino.h>
#include "rgb.h"
// how to use the tone() command to generate notes
//Define Pins
#define BLUE 3
#define GREEN 5
#define RED 6

void set_rgb() {
    pinMode(RED, OUTPUT);
    pinMode(GREEN, OUTPUT);
    pinMode(BLUE, OUTPUT);
    digitalWrite(RED, HIGH);
    digitalWrite(GREEN, LOW);
    digitalWrite(BLUE, LOW);
}

void loop_rgb() {

}