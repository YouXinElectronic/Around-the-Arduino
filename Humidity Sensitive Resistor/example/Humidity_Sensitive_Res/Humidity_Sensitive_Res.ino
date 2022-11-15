#define HumidityDigitalPin  7//定义湿度传感器数字引脚
#define HumidityAnalogPin   A0//定义湿度传感器模拟引脚
#define LEDPin A3//定义LED模块引脚


int  HumidityAnalogValue = 0 ;//定义数字变量,读取湿度模拟值
int  HumidityDigitalValue = 0 ;//定义数字变量,读取湿度数字值
void setup()
{
  Serial.begin(9600);//设置串口波特率
  pinMode(HumidityDigitalPin, INPUT);//设置湿度传感器数字引脚为输入
  pinMode(HumidityAnalogPin, INPUT);//设置湿度传感器模拟引脚为输入
  pinMode(LEDPin, OUTPUT);//设置LED模块引脚为输出
}
void loop()
{
  HumidityAnalogValue = analogRead(HumidityAnalogPin);//读取湿度传感器模拟值
  HumidityDigitalValue = digitalRead(HumidityDigitalPin);//读取湿度传感器数字值
  Serial.print("HumidityAnalog Data:  ");
  Serial.print(HumidityAnalogValue);//打印湿度传感器模拟值
  Serial.print("       HumidityDigital Data:  ");
  Serial.println(HumidityDigitalValue);//打印湿度传感器数字值
  if (HumidityDigitalValue == 0) //判断湿度传感器是否检测到所调阀值  检测到则LED亮 
  digitalWrite(LEDPin, LOW);
  else
  digitalWrite(LEDPin, HIGH);
}




