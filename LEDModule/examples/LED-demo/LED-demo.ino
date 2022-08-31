/*==================LED闪烁程序控制=========================
 * 接线    LED模块     arduino
 *          V           5V
 *          G           GND
 *          S            2
 * 接好线下载完程序可以看到模块一闪一灭
 ======================YXDZ========================*/

int a=2;        //信号引脚定义，可在此更改引脚
 
void setup() {
  // put your setup code here, to run once:
pinMode(a,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(a,LOW);
delay(1000);
digitalWrite(a,HIGH);
delay(1000);
}
