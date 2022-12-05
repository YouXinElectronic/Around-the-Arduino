#include<SoftwareSerial.h>
#include <DS18B20.h>
DS18B20 ds(2);
SoftwareSerial MySerial = SoftwareSerial(10, 11);
String T = "Temperature:";
String Line = "\r\n";
String s = ""; //Store the data returned by the analog serial port
void setup() {
  Serial.begin(9600); //Serial monitor baud rate
  MySerial.begin(9600); //Baud rate of soft serial port
}

void loop() {
  ds.doConversion();
  s=ds.getTempC();
  Serial.print(s);
  MySerial.print(T);
  MySerial.print(s);
  MySerial.print("C");
  MySerial.print(Line);
  delay(1000);
  
}
