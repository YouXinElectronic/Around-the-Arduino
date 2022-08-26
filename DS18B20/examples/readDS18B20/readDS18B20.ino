/*
  Get DS18B20 temperature data
  Author: YXDZ
  Creation Date: 2022/8/25
  Version: V1.0
  github：https://github.com/YouXinElectronic/Around-the-Arduino
*/

#include <DS18B20.h>

DS18B20 ds(2);

void setup() {
  Serial.begin(115200);
}

void loop() {
  ds.doConversion();
  Serial.print("Temperature: ");
  Serial.print(ds.getTempC());
  Serial.println(" C\n");
  delay(1000);
}
