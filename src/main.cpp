#include <Arduino.h>
// #include "hello.h" //first program hello world
// #include "pin_mode.h"
// #include "pin_button.h"
// #include "debounce.h"
// #include "input_pullup.h"
// #include "rgb.h"
// #include "digital_input.h"
// #include "active_buzzer.h"
// #include "ball_switch.h"
// #include "eight_led.h"
// #include "serial_monitor.h"
#include "photocell.h"

// put function declarations here:

void setup() {
  // put your setup code here, to run once:
  // hello();
  // setup_pin();
  // set_led();
  // set_debounce();
  // Serial.begin(9600);
  // set_pullup();
  // set_detection();
  // set_rgb();
  // set_digital();
  // set_buzzer();
  // set_ball();
  // set_chip();
  // set_monitor();
  set_photocell();
}

void loop() {
  // put your main code here, to run repeatedly:
  // loop_pin();
  // close_pin();
  // lightOnOff();
  // fun_debounce();
  // Serial.println("Hello from Arduino!");
  // delay(1000);
  // loop_pullup();
  // loop_detection();
  // loop_rgb();
  // loop_digital();
  // loop_buzzer();
  // loop_ball();
  // loop_chip();
  // loop_monitor();
  loop_photocell();
}

// put function definitions here: