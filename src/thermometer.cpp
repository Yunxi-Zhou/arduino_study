#include <LiquidCrystal.h>
#include "thermometer.h"
#include <Arduino.h>

// declaration 
int tempPin = 0;
LiquidCrystal Lcd(7, 8, 9, 10, 11, 12);

void set_thermometer() {
    Lcd.begin(16, 2);
    Serial.begin(9600);
}

void loop_thermometer() {
    int tempReading = analogRead(tempPin);
    double tempK = log(10000.0 * ((1024.0 / tempReading - 1)));
    tempK = 1 / (0.001129148 + (0.000234125 + (0.0000000876741 * tempK * tempK)) * tempK);   // Temp Kelvin
    float tempC = tempK - 273.15;  // Convert Kelvin to C
    float tempF = (tempC * 9.0) / 5.0 + 32.0;  // Convert C to Fahrenheit

    // Display Temperature in C
    Lcd.setCursor(0, 0);
    Lcd.print("Temp       C  ");
    // Display Temperature in F
    // Lcd.print("Temp       F  ");
    Lcd.setCursor(6, 0);
    // in C
    Lcd.print(tempC);
    // in F
    // Lcd.print(tempF);

    //Serial write
    Serial.print("Temp in C: ");
    Serial.print(tempC);
    Serial.print(" | Temp in F: ");
    Serial.println(tempF);

    delay(1000);


}