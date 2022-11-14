#define DigitalPin  7//定义传感器数字引脚
#define LEDPin A3//定义LED模块引脚

int  DigitalValue = 0 ;//定义数字变量,读取数字值
void setup()
{
  Serial.begin(9600);//设置串口波特率
  pinMode(DigitalPin, INPUT);//设置传感器数字引脚为输入
  pinMode(LEDPin, OUTPUT);//设置LED模块引脚为输出
}
void loop()
{
  DigitalValue = digitalRead(DigitalPin);//读取传感器数字值
  Serial.print("       Digital Data:  ");
  Serial.println(DigitalValue);//打印传感器数字值
  if (DigitalValue == 0) //判断传感器是否检测到，检测到则LED亮 
  digitalWrite(LEDPin, LOW);
  else
  digitalWrite(LEDPin, HIGH);
}


