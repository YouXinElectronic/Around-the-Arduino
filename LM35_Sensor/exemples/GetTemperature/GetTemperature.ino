#include <LM35.h>

LM35 sensor(0);

void setup() {
  Serial.begin(9600);
}

void loop() {
  Serial.println(sensor.getTemp()); // Temp in celcius
}
