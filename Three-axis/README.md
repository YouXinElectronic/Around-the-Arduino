# **Three-axis accelerometer**

@[TOC](Contents)

### purchase link

[Click to buy]()

## picture display

<img title="" src="https://github.com/YouXinElectronic/Around-the-Arduino/blob/main/Three-axis/image/top.jpg" alt="" data-align="inline">

### Foreword：

The ADXL335 is a simple 3-axis accelerometer. The current acceleration is represented by outputting the analog quantity, which can be used to identify the posture and motion of the object. The acceleration range of ADXL335 is ±3g.

### Describe：

This example can be used to read the ADXL335's raw analog and acceleration G values. UNO (tested myself)

### parameter

| Item                          | Value       |
|:-----------------------------:|:-----------:|
| Voltage                       | 3.3/5V      |
| Output                        | analog      |
| Temperature measurement range | -55℃ - 125℃ |
| Interface model               | PH2.0-6P    |

### 

## Pin description

| Pin name | Pin Function                                       |
|:--------:|:--------------------------------------------------:|
| G        | power negative, ground                             |
| V        | Power Positive, 3.3/5V                             |
| X        | Acceleration signal output in the X-axis direction |
| Y        | Acceleration signal output in Y-axis direction     |
| Z        | Acceleration signal output in Z-axis direction     |
| T        | self-test pin                                      |

### 

### Instructions for use

This example can be used to read the ADXL335's raw analog and acceleration G values. UNO (tested myself)

Before programming, you can plug the PH2.0 cable into the backplane, or connect as shown in the table below.

| ADXL335 | Arduino |
| ------- | ------- |
| G       | GND     |
| V       | 5V      |
| X       | A0      |
| Y       | A1      |
| Z       | A2      |
| T       |         |

In the example, the acceleration is output as a positive number. Of course, if you need to be accurate to a higher position, you can change the following three statements:

```cpp
Serial.print(xAccel,0);
Serial.print(yAccel,0);
Serial.print(zAccel,0);
```

Change

```cpp
Serial.print();
```

Change the second argument from “0” to the number of decimal places you want to keep \ accurate.

Example default pin definitions are:

 X --> A0

 Y --> A1 

Z --> A2

 You can change the pin definition by changing these three statements, pay attention to the need to connect the analog pin.

```cpp
const int Xpin = A0;
const int Ypin = A1;
const int Zpin = A2;
```

The example reduces noise by averaging multiple samples, which is changed when "sampleSize" is defined at the beginning of the program

```cpp
const int sampleSize=XX
```

The value of can change the number of samples

##### The reference voltage: To use this example, be sure to input 3.3V to the AREF pin of the Arduino board

```cpp
/****************************
parameter:
DataPin -- need to read the analog pin number (corresponding to X, Y, Z axis)
return value:
Average of multiple samples
************************/
int ReadAxis(int DataPin)
```

It is used to obtain the original analog signal output by the three axes of ADXL335, improve the reliability of data by taking the average value of multiple sampling, and return the original analog signal

```
/****************************
parameter:
Value -- the analog value sampled by the X, Y, and Z axes
return value:
acceleration G value
************************/
float Accel(int Value)
```

It is used to convert the analog quantity sampled by the X, Y, and Z axes into acceleration

### Size reference

![](https://github.com/YouXinElectronic/Around-the-Arduino/blob/main/Three-axis/image/Dimensions.jpg)

More information - 

Version: V1.0
