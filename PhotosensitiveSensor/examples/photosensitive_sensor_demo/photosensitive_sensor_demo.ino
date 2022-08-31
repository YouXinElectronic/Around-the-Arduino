/*==================光敏传感器程序=========================
 * 接线    LED模块     arduino
 *          V           5V
 *          G           GND
 *          D            2
 *          A            A0
 * 正常调节电位器至刚好两个灯亮，这时候用手遮住光敏传感器，可以看到有一个灯熄灭
 ======================YXDZ========================*/

int a=2,b=A0;    //信号引脚定义，可在此更改引脚

void setup() {
  // put your setup code here, to run once:
pinMode(a,INPUT);
pinMode(b,INPUT);
Serial.begin(9600);  
}

void loop() {
  // put your main code here, to run repeatedly:
 Serial.println(digitalRead(a)); 
  delay(500);
 Serial.println(analogRead(b)); 
 delay(500);
}
