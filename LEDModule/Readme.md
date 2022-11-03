# purchase link

[Click to buy](https://item.taobao.com/item.htm?spm=a1z10.3-c-s.w4002-21223910208.16.46046a4bs0pcQO&id=685727212244)

# picture display

<img src="https://raw.githubusercontent.com/YouXinElectronic/Around-the-Arduino/main/LEDModule/image/top.jpg" width="300"><img src="https://raw.githubusercontent.com/YouXinElectronic/Around-the-Arduino/main/LEDModule/image/bottom.jpg" width="300">

# Introduction
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
The LED module adopts the form of pull-up resistor, the signal pin S input is low-level lighted, and high-level is extinguished.

# parameter
| Voltage | 3.3 / 5V |
|--|--|
| LED lamp diameter | 5mm |
| positioning hole | M3 |
| Module weight | 6.75g |
| Interface model | PH2.0-3P |

# Pin description

| pin name | pin function |
|--|--|
| G | power negative, ground |
| V | Power is positive, 5V |
| s | Signal input control pin |


# Instructions for use
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
Before programming the code, you can directly insert the `PH2.0` cable into the `2` port on the backplane, or connect as follows

| DHT11 | arduino |
|--|--|
| G | GND |
| V | 5V |
| S | 2 |

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
After connecting the line and downloading the program, you can see that the module flashes and turns off.

```cpp

/*
  LED flashing program control
  Author: YXDZ
  Creation Date: 2022/8/25
  Version: V1.0
  github：https://github.com/YouXinElectronic/Around-the-Arduino
*/

int a=2;        //Signal pin definition, you can change the pin here
 
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


```

# size reference

<img src="https://raw.githubusercontent.com/YouXinElectronic/Around-the-Arduino/main/LEDModule/image/Dimensions.jpg" width="300">
