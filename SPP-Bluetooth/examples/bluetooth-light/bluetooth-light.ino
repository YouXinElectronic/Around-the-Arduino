#include <SoftwareSerial.h>
#define LED 2
int NO=1;
int OFF=0;
int value;
SoftwareSerial MySerial(10, 11);


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  MySerial.begin(9600);
  MySerial.listen();
  digitalWrite(LED,LOW);
}

void loop() {
  // put your main code here, to run repeatedly:

  if (MySerial.available() > 0)
  {
    delay(100);
    value = MySerial.read();
    Serial.print("value:");
    Serial.println(value);
    if (value == NO)
    {
      Serial.println("1");
      digitalWrite(LED, HIGH);
    }
    else if (value == OFF)
    {
      Serial.println("0");
      digitalWrite(LED, LOW);
    }
    value = "";

  }

  //delay(100);
  //      value+=(char)MySerial.read();


}
