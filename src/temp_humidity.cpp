#include <Arduino.h>
#include "temp_humidity.h"
#include <dht_nonblocking.h>
#define DHT_SENSOR_TYPE DHT_TYPE_11

static const int DHT_SENSOR_PIN = 2;
DHT_nonblocking dht_sensor(DHT_SENSOR_PIN, DHT_SENSOR_TYPE);

void set_humidity() {
    Serial.begin(9600);
}

bool measure_env(float *temperature, float *humidity) {
    static unsigned long time_tmp = millis();

    // Measure once every four seconds
    if (millis() - time_tmp > 3000ul) {
        if (dht_sensor.measure(temperature, humidity) == true) {
            time_tmp = millis();
            return(true);
        }
    }
    return(false);
}

void loop_humidity() {
    float temperature;
    float humidity;

    // Measure temperature and humidity.
    // If the functions returns true, then a measurement is available
    if (measure_env(&temperature, &humidity) == true) {
        Serial.print("T = ");
        Serial.print(temperature,1);  // 1 -> tmp = x.x
        Serial.print(" deg. C, H = ");
        Serial.print(humidity, 1);
        Serial.println("%");
    }
}
