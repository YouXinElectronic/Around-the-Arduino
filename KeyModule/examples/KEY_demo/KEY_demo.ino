/*==================Key开关量读取程序=========================
 * 接线    LED模块     arduino
 *          V           5V
 *          G           GND
 *          S            2
 * 接好线下载完程序可以看到模块一闪一灭
 ======================YXDZ========================*/

int a=2;    //信号引脚定义，可在此更改引脚

void setup() {
  // put your setup code here, to run once:
pinMode(a,INPUT);
Serial.begin(9600);  
}

void loop() {
  // put your main code here, to run repeatedly:
 Serial.println(digitalRead(a)); 
 delay(500);
}
