#include <Arduino.h>
#include "active_buzzer.h"

int buzzer = 11; //set the pin of the active buzzer

void set_buzzer() {
    pinMode(buzzer, OUTPUT);
    Serial.begin(9600); // initialize the serial port.
}

void loop_buzzer() {
    int sound_duration = 500;
    for (int i = 0; i < 20; i++) {
        // use the if function to gradually shorten the interval of the sound
        if (i < 5) {
            sound_duration = 500;
        } else if (i < 10) {
            sound_duration = 300;
        } else if (i < 20) {
            sound_duration = 100;
        }

        // activate the active buzzer
        digitalWrite(buzzer, HIGH);
        Serial.print("Buzzing at duration: "); 
        Serial.println(sound_duration);
        delay(sound_duration); // wait for sound_duration ms

        // deactivate the active buzzer
        digitalWrite(buzzer, LOW);
        delay(sound_duration); // wait for sound_duration ms
    }

    // activate the active buzzer and continue 5 seconds
    Serial.println("Buzzing continuously for 5 second...");
    digitalWrite(buzzer, HIGH);
    delay(5000); // keep playing sound for 5 seconds
    digitalWrite(buzzer, LOW);
}