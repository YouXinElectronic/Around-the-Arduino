const int Touch = 3;

void setup() {
  // put your setup code here, to run once:
     pinMode(Touch,INPUT_PULLUP );  
     Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
     int a = !digitalRead(Touch);
     Serial.println(a);
     delay(1000);
}
