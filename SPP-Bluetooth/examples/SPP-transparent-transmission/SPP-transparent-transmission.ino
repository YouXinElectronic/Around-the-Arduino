#include<SoftwareSerial.h>
SoftwareSerial MySerial = SoftwareSerial(10, 11);
String Value="";
void setup() {
  Serial.begin(9600); 
  MySerial.begin(9600); 
}
void loop() {
  /**********************
   * Read the data in the serial port buffer 
   * and send it from the soft serial port 
   * to the Bluetooth module
  **********************/
  if (Serial.available() > 0) 
  {
    MySerial.write(Serial.read());
  }
  /*********************
   * Determine whether the Bluetooth module 
   * has sent data to the soft serial port, 
   * read and print it out
  *********************/
  while (MySerial.available() > 0)
  {
    Value = MySerial.readString();
    Serial.println(Value);
  }
}
