#ifndef TEMP_HUMIDITY_H
#define TEMP_HUMIDITY_H

void set_humidity();
bool measure_env(float *temperature, float *humidity);
void loop_humidity();

#endif