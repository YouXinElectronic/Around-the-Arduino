/*
  Get DHT11 temperature and humidity data
  Author: YXDZ
  Creation Date: 2022/8/25
  Version: V1.0
  github：https://github.com/YouXinElectronic/Around-the-Arduino
*/

#include <DHT11.h>
DHT11 DHT(2);

void setup(){
  Serial.begin(115200);
}

void loop(){
  DHT.readDht11();
  Serial.print("temp:");
  Serial.print(DHT.getTemperature());
  Serial.print("  humi:");
  Serial.println(DHT.getHumidity());
  delay(1000);
}
