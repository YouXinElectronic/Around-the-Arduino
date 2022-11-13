# purchase link

[Click to buy](https://item.taobao.com/item.htm?spm=a1z10.3-c-s.w4002-21223910208.51.3d406a4bdqYccY&id=688637175048)

# picture display

<img src="https://raw.githubusercontent.com/YouXinElectronic/Around-the-Arduino/main/PhotosensitiveSensor/image/LSR3。png " width="300">

# Introduction
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
Use 5516 photoresistor, divide the voltage with a 10K resistor, output analog quantity; 
compare with a 10k potentiometer to output digital quantity through LM393. When the light becomes dark, the resistance becomes larger, 
the analog output of port A becomes larger, the digital output of port D is high level 1, the indicator light is off, 
and the sensitivity can be adjusted by adjusting the potentiometer and the signal pin S outputs a high level at the same time

# parameter
| Voltage | 3.3 / 5V |
|--|--|
| Photoresistor Model | 5516 |
| positioning hole | M3 |
| Module weight | 7.8g |
| Interface model | PH2.0-3P |

# Pin description

| pin name | pin function |
|--|--|
| G | power negative, ground |
| V | Power is positive, 5V |
| D | Digital output pin |
| A | Analog output pin |


# Instructions for use
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
Before programming the code, you can directly insert the `PH2.0` cable into the `2` port on the backplane, or connect as follows

| DHT11 | arduino |
|--|--|
| G | GND |
| V | 5V |
| D | 2 |
| A | A0 |

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
After downloading the program, adjust the potentiometer, you can see that the digital D port outputs a low level when the indicator light is on

```cpp

/*
  light sensor program
  Author: YXDZ
  Creation Date: 2022/8/25
  Version: V1.0
  github：https://github.com/YouXinElectronic/Around-the-Arduino
*/

int a=2,b=A0;        //Signal pin definition, you can change the pin here
 
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

```

# size reference

<img src="https://raw.githubusercontent.com/YouXinElectronic/Around-the-Arduino/main/PhotosensitiveSensor/image/Dimensions.png" width="300">
