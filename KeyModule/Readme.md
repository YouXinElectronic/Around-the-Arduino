# purchase link

[Click to buy](https://item.taobao.com/item.htm?spm=a1z10.3-c-s.w4002-21223910208.42.42e36a4b5mwRKl&id=685729512438)

# picture display

<img src="https://raw.githubusercontent.com/YouXinElectronic/Around-the-Arduino/main/KeyModule/image/top.jpg " width="300"><img src="https://raw.githubusercontent.com/YouXinElectronic/Around-the-Arduino/main/KeyModule/image/bottom.jpg" width="300">

# Introduction
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
Through the proposed switch circuit designed by switches, resistors and led lights, the power light is on after power-on, after the switch is pressed, another light is on, and the signal pin S outputs a high level at the same time

# parameter
| Voltage | 3.3 / 5V |
|--|--|
| Switch model | 12 * 12mm |
| positioning hole | M3 |
| Module weight | 9.05g |
| Interface model | PH2.0-3P |

# Pin description

| pin name | pin function |
|--|--|
| G | power negative, ground |
| V | Power is positive, 5V |
| s | Signal output pin |


# Instructions for use
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
Before programming the code, you can directly insert the `PH2.0` cable into the `2` port on the backplane, or connect as follows

| DHT11 | arduino |
|--|--|
| G | GND |
| V | 5V |
| S | 2 |

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
After connecting the line and downloading the program, press the switch, you can see the light will come on.

```cpp

/*
  Key switch reading program
  Author: YXDZ
  Creation Date: 2022/8/25
  Version: V1.0
  github：https://github.com/YouXinElectronic/Around-the-Arduino
*/

int a=2;        //Signal pin definition, you can change the pin here
 
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


```

# size reference

<img src="https://raw.githubusercontent.com/YouXinElectronic/Around-the-Arduino/main/KeyModule/image/Dimensions.jpg" width="300">
