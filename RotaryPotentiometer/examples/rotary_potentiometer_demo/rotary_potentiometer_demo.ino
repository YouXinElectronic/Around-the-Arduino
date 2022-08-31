/*==================模拟量采集电位器程序=========================
 * 接线    LED模块     arduino
 *          V           5V
 *          G           GND
 *          S            A0
 * 接好线下载完程序可以打开串口监视器看读取到的模拟量（0-1023）
 ======================YXDZ========================*/

int a=A0;        //信号引脚定义，可在此更改引脚

void setup() {
  // put your setup code here, to run once:
pinMode(a,INPUT);
Serial.begin(9600); 
}

void loop() {
  // put your main code here, to run repeatedly:
 Serial.println(analogRead(a));
 delay(500);
}
