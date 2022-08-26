/*
  The buzzer sounds in 1s cycle
  Author: YXDZ
  Creation Date: 2022/8/25
  Version: V1.0
  github：https://github.com/YouXinElectronic/Around-the-Arduino
*/

#define Buzzer_Pin 2
#define cycleTimes 1000

void setup() {
  // put your setup code here, to run once:
  pinMode(Buzzer_Pin,OUTPUT);
  digitalWrite(Buzzer_Pin,HIGH);   //No sound when power on
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(Buzzer_Pin,HIGH);   //High level does not sound
  delay(cycleTimes/2);
  digitalWrite(Buzzer_Pin,LOW);   //low level
  delay(cycleTimes/2);
}
