/*
占空比从0开始没2秒增加20%驱动小风扇
当占空比到达100%后
每两秒减20%直到占空比减到零
*/


#define FANS 3
void setup() {
  // put your setup code here, to run once:
  pinMode (FANS, OUTPUT);
  Serial.begin(9600);
  Serial.println("fans test begin!!!");
  analogWrite(FANS, 0);
}

void loop() {
  // put your main code here, to run repeatedly:
  int i = 0;
  while (i < 250)
  {
    i += 50;
    analogWrite(FANS, i);
    delay(2000);
  }
  delay(2000);
  while (i > 0)
  {
    i -= 50;
    analogWrite(FANS, i);
    delay(2000);
  }



}
