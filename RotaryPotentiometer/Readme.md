# purchase link

[Click to buy]()

# picture display

<img src="https://raw.githubusercontent.com/YouXinElectronic/Around-the-Arduino/main/RotaryPotentiometer/image/top.jpg" width="300"><img src="https://raw.githubusercontent.com/YouXinElectronic/Around-the-Arduino/main/RotaryPotentiometer/image/bottom.jpg" width="300">

# Introduction
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
Using a 10K potentiometer, when the potentiometer is rotated, the voltage loaded on the common pin of the potentiometer and the pins on both sides will change. 
Use the ADC that comes with the arduino to read the analog quantity,the clockwise analog quantity decreases, and the counterclockwise analog quantity Increase.
# parameter
| Voltage | 5V |
|--|--|
| Potentiometer Model | RV09 |
| positioning hole | M3 |
| Module weight | 12.20g |
| Interface model | PH2.0-3P |

# Pin description

| pin name | pin function |
|--|--|
| G | power negative, ground |
| V | Power is positive, 5V |
| s | Analog output pin |


# Instructions for use
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
Before programming the code, you can directly insert the `PH2.0` cable into the `2` port on the backplane, or connect as follows

| DHT11 | arduino |
|--|--|
| G | GND |
| V | 5V |
| S | A0 |

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
After connecting the line and downloading the program, you can open the serial monitor to see the read analog quantity (0-1023)

```cpp

/*
  Analog acquisition potentiometer program
  Author: YXDZ
  Creation Date: 2022/8/25
  Version: V1.0
  github：https://github.com/YouXinElectronic/Around-the-Arduino
*/

int a=A0;        //Signal pin definition, you can change the pin here
 
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

<img src="https://raw.githubusercontent.com/YouXinElectronic/Around-the-Arduino/main/RotaryPotentiometer/image/Dimensions.jpg " width="300">
