#include <Arduino.h>
//#include "hello.h" //first program hello world
//#include "pin_mode.h"
#include "pin_button.h"

int buttonState = 0;

// put function declarations here:

void setup() {
  // put your setup code here, to run once:
  //hello();
  //setup_pin();
  set_led();
  
  
}

void loop() {
  // put your main code here, to run repeatedly:
  //loop_pin();
  //close_pin();
  lightOnOff();
  

}

// put function definitions here: