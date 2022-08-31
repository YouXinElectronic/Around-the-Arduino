#include"TTP229.h"

int SCLPin = A5, SDOPin = A4;   //定义 SCL时钟 、SDO数据 端口
unsigned int h = 0, oldh = 0;
TTP229 mTTP229;
char str[128];
void setup()
{
  Serial.begin(9600);   //设置串口波特率为9600
  mTTP229.initTTP229(SCLPin, SDOPin);

}

void loop()
{
  uint16_t keycode = mTTP229.GetKeyCode();
  if (keycode != 0xFFFF) {      //判断按键是否按下
    String key_name = mTTP229.GetKeyMap();
    sprintf(str, "Get ir code: 0x%x key name: %s \n", keycode, (char *)key_name.c_str()); 
    //将按键的值转为字符串
    Serial.println(str);    //打印按键对应的字符
  }
  delay(100);
}
