//function definition
#include <Arduino.h>
#include "hello.h"

void hello() {
    Serial.begin(9600);
    Serial.println("Hello, world!!");
}