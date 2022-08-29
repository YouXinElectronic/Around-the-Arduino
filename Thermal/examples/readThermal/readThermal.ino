
const int AD = 2;     // 连接D0的引脚
const int T =  A0;      // 连接T的引脚

void setup() {
  // put your setup code here, to run once:
     Serial.begin(9600);
     pinMode(AD, INPUT_PULLUP);
}

void loop() {
  // put your main code here, to run repeatedly:
      int buttonState = !digitalRead(AD);
      int sensorValue = analogRead(T);
      Serial.print("the D0 is:");
      Serial.print(buttonState);
      Serial.print("  the A0 is:");
      Serial.println(sensorValue);
      delay(1000);
      
      
}
