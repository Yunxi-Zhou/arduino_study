#include <Arduino.h>
//#include "hello.h" //first program hello world
//#include "pin_mode.h"
//#include "pin_button.h"
//#include "debounce.h"
#include "input_pullup.h"
// put function declarations here:

void setup() {
  // put your setup code here, to run once:
  //hello();
  //setup_pin();
  //set_led();
  //set_debounce();
  // Serial.begin(9600);
  set_pullup();
}

void loop() {
  // put your main code here, to run repeatedly:
  //loop_pin();
  //close_pin();
  //lightOnOff();
  //fun_debounce();
  // Serial.println("Hello from Arduino!");
  // delay(1000);
  loop_pullup();
}

// put function definitions here: