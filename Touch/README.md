# purchase link

[Click to buy]()

# picture display

<img title="" src="https://raw.githubusercontent.com/YouXinElectronic/Around-the-Arduino/main/Touch/image/top.jpg" alt="" width="300"><img title="" src="https://raw.githubusercontent.com/YouXinElectronic/Around-the-Arduino/main/Touch/image/bottom.jpg" alt="" width="300">

# Introduction

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;`Touch` The touch module uses Tongtai's driver ICTTP223E single touch chip, and the output mode is jog type. In use, a high-level output can be achieved by gently touching the copper area of the module with a finger, which is suitable for switch control in the electronic DIY process. section, the module provides Ardiuno development board test routines for reference.

# parameter

| Voltage                       | 3.3 / 5V           |
| ----------------------------- | ------------------ |
| Communication Interface       | High and low level |
| Temperature measurement range | -20 ~ +60℃         |
| Interface model               | PH2.0-3P           |

# Pin description

| pin name | pin function               |
| -------- | -------------------------- |
| G        | power negative, ground     |
| V        | Power is positive,3.3 / 5V |
| S        | High and low level output  |

# Instructions for use

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Before programming the code, you can directly insert the `PH2.0` cable into the `2` port on the backplane, or connect as follows

| Touch | arduino |
| ----- | ------- |
| G     | GND     |
| V     | 5V      |
| S     | 3       |

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;After connecting to the phone, open the monitor, set the special feature <mark>9600</mark>, and you will be able to see the return signal level in the monitor.

```cpp
/*
  Get Touch data
  Author: YXDZ
  Creation Date: 2022/8/25
  Version: V1.0
  github：https://github.com/YouXinElectronic/Around-the-Arduino
*/

const int Touch = 3;

void setup() {
  // put your setup code here, to run once:
     pinMode(Touch,INPUT_PULLUP );  
     Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
     int a = !digitalRead(Touch);
     Serial.println(a);
     delay(1000);
}
```

code snippet

```cpp
const int Touch = 3;
```

The numbers behind represent the pin interface of the corresponding ardiuno board, which can be modified according to your own board

```cpp
 Serial.println(a);
```

This function is to print the detection level parameters of <mark>Touch</mark>

# size reference

<img title="" src="https://raw.githubusercontent.com/YouXinElectronic/Around-the-Arduino/main/Touch/image/Dimensions.jpg" alt="" width="300">
