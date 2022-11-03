# purchase link

[Click to buy](https://item.taobao.com/item.htm?spm=a1z10.3-c-s.w4002-21223910208.45.7dd86a4bVj6BFg&id=688276581200)

# picture display

<img title="" src="https://raw.githubusercontent.com/YouXinElectronic/Around-the-Arduino/main/HC-SR04/image/top.jpg" alt="" width="300"><img title="" src="https://raw.githubusercontent.com/YouXinElectronic/Around-the-Arduino/main/HC-SR04/image/bottom.jpg" alt="" width="300">

# Introduction

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;`HCSR04` The ultrasonic ranging module uses the CS100A ultrasonic ranging chip, and the industrial-grade ranging chip replaces the HC-SR04 chip. It uses a high-precision crystal oscillator, and the ranging is more stable. It can work with a wide voltage at a working voltage of 3-5.5V. Provide Arduino development board related process information.

# parameter

| Voltage                       | 3.3 / 5V           |
| ----------------------------- | ------------------ |
| Communication Interface       | High and low level |
| Temperature measurement range | -20 ~ +60℃         |
| Ranging resolution            | ±1cm               |
| Ranging range                 | 0.2M-4M            |
| Interface model               | PH2.0-4P           |

# Pin description

| pin name | pin function               |
| -------- | -------------------------- |
| G        | power negative, ground     |
| V        | Power is positive,3.3 / 5V |
| T        | Receiving end              |
| E        | Control terminal           |

# Instructions for use

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Before programming the code, you can directly insert the `PH2.0` cable into the `2` port on the backplane, or connect as follows

| HCSR04 | arduino |
| ----- | ------- |
| G     | GND     |
| V     | 5V      |
| E     | 4       |
| T     | 3       |

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;After connecting the line, burn the code, open the serial monitor, set the baud rate to <mark>9600</mark>, and you will see the distance data returned one after another in the serial monitor.

```cpp
/*
  Get HCSR04 range  data
  Author: YXDZ
  Creation Date: 2022/8/25
  Version: V1.0
  github：https://github.com/YouXinElectronic/Around-the-Arduino
*/

const int Trig = 3;                                           // 设定SR04连接的Arduino引脚
const int Echo = 4; 
double distance,timer;
void setup() 
{   
        Serial.begin(9600);                                    // 初始化串口通信及连接SR04的引脚
        pinMode(Trig, OUTPUT); 
  
        pinMode(Echo, INPUT);                                  //要检测引脚上输入的脉冲宽度，需要先设置为输入状态
    Serial.println("The distance is :");
} 
void loop() 
{ 
    
        digitalWrite(Trig, LOW);                                 
        delayMicroseconds(2);                                   
        digitalWrite(Trig, HIGH);                               
        delayMicroseconds(10);                                  //产生一个10us的高脉冲去触发SR04
        digitalWrite(Trig, LOW);                                
        
        timer = pulseIn(Echo, HIGH);                              // 检测脉冲宽度，注意返回值是微秒us
        distance = timer /58 ;                                  //计算出距离,输出的距离的单位是厘米cm
 
        Serial.print(distance);                                //把得到的距离值通过串口通信返回给电脑，通过串口监视器显示出来
        Serial.println("cm"); 
        delay(1000); 
}
```

code snippet

```cpp
const int Trig = 3;
const int Echo = 4; 
```

The numbers behind represent the pin interface of the corresponding ardiuno board, which can be modified according to your own board

```cpp
 Serial.print(distance); 
 Serial.println("cm"); 
```

This function is to print the detection distance parameter of <mark>HCSR04</mark>

# size reference

<img title="" src="https://raw.githubusercontent.com/YouXinElectronic/Around-the-Arduino/main/HC-SR04/image/Dimensions.jpg" alt="" width="300">
