# purchase link

[Click to buy]()

# picture display

<img title="" src="https://raw.githubusercontent.com/YouXinElectronic/Around-the-Arduino/main/ThermalSensor/image/top.jpg" alt="" width="300"><img title="" src="https://raw.githubusercontent.com/YouXinElectronic/Around-the-Arduino/main/ThermalSensor/image/bottom.jpg" alt="" width="300">

# Introduction

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;`Touch` The thermal sensor module, through LM393 and NTC thermistor, can achieve high-precision voltage comparison and better filter output capacitance. The corresponding analog voltage output can be obtained. The corresponding temperature value can be obtained and related control can be obtained by using digital output.

# parameter

| Voltage                       | 3.3 / 5V           |
| ----------------------------- | ------------------ |
| Communication Interface       | High and low level |
| Temperature measurement range | -20 ~ +60℃         |
| Analog voltage output         | 0~5V               |
| Interface model               | PH2.0-4P           |

# Pin description

| pin name | pin function               |
| -------- | -------------------------- |
| G        | power negative, ground     |
| V        | Power is positive,3.3 / 5V |
| D        | Digital level output       |
| A        | Analog voltage output      |

# Instructions for use

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Before programming the code, you can directly insert the `PH2.0` cable into the `2` port on the backplane, or connect as follows

| Thermal | arduino |
| ------- | ------- |
| G       | GND     |
| V       | 5V      |
| A       | A0      |
| D       | 2       |

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;After connecting to the phone, open the monitor, set the special feature <mark>9600</mark>, and you will be able to see the return signal level in the monitor.

```cpp
/*
  Get Thermal data
  Author: YXDZ
  Creation Date: 2022/8/25
  Version: V1.0
  github：https://github.com/YouXinElectronic/Around-the-Arduino
*/

const int AD = 2;     // 连接D0的引脚
const int T =  A0;      // 连接T的引脚

void setup() {
  // put your setup code here, to run once:
     Serial.begin(9600);
     pinMode(AD, INPUT_PULLUP);
}

void loop() {
  // put your main code here, to run repeatedly:
      int buttonState = !digitalRead(AD);
      int sensorValue = analogRead(T);
      Serial.print("the D0 is:");
      Serial.print(buttonState);
      Serial.print("  the A0 is:");
      Serial.println(sensorValue);
      delay(1000);
      
      
}
```

code snippet

```cpp
const int AD = 2;     // 连接D0的引脚
const int T =  A0;      // 连接T的引脚
```

The numbers behind represent the pin interface of the corresponding ardiuno board, which can be modified according to your own board

```cpp
Serial.print("the D0 is:");
Serial.print(buttonState);
Serial.print("  the A0 is:");
Serial.println(sensorValue);This function is to print the detection level parameters of <mark>Touch</mark>
```

# size reference

<img title="" src="https://raw.githubusercontent.com/YouXinElectronic/Around-the-Arduino/main/ThermalSensor/image/Dimensions.jpg" alt="" width="300">
