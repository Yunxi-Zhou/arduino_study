#include <Arduino.h>
#include "lcd_display.h"
//#include <Wire.h>
#include <LiquidCrystal.h>

/*
 * LCD RS pin to digital pin 7
 * LCD Enable pin to digital pin 8
 * LCD D4 pin to digital pin 9
 * LCD D5 pin to digital pin 10
 * LCD D6 pin to digital pin 11
 * LCD D7 pin to digital pin 12
 * LCD R/W pin to ground
 * LCD VSS pin to ground
 * LCD VCC pin to 5V
 * 10K resistor:
 * ends to +5V and ground
 * wiper to LCD VO pin (pin 3)
*/

// initialization
LiquidCrystal lcd(7, 8, 9, 10, 11, 12);

void set_lcd() {
    // set up the LCD's number of columns and rows:
    lcd.begin(16,2);
    // print a message to the LCD
    lcd.setCursor(0,0);
    lcd.print("[69,88,67,69,80,");

    lcd.setCursor(0,1);
    lcd.print("84,70,79,82,85]");


    Serial.begin(9600);
}

void loop_lcd() {
    // set the cursor to column 0, line 1
    // lcd.setCursor(0, 1);
    // print the number of seconds since reset
    // lcd.print(millis() / 1000);
    
    //send time through serial
    Serial.print("Time: ");
    Serial.println(millis() / 1000);
    
    delay(1000);
}



