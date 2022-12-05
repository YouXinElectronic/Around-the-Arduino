# Fan module

@[TOC](Contents)

### purchase link

[Click to buy]() 

## picture display

![](https://github.com/YouXinElectronic/Around-the-Arduino/blob/main/Fan/image/top.jpg)

### Foreword：

The small fan module is powered by an R300C DC motor, which rotates clockwise to drive the fan blades to blow forward, which can be used to develop some interesting projects. Only turn clockwise. Provide a driver example for Arduino UNO

### parameter

| Item                          | Value       |
|:-----------------------------:|:-----------:|
| Voltage                       | 3.3/5V      |
| Input                         | PWM/digital |
| Temperature measurement range | -20℃ - 80℃  |
| Interface model               | PH2.0-3P    |

### 

## Pin description

| Pin name | Pin Function            |
|:--------:|:-----------------------:|
| G        | power negative, ground  |
| V        | Power Positive, 3.3/5V  |
| S        | PWM input/Digital input |

### Instructions for use

This example can be used to test our fan module, by increasing the duty cycle by 20% every 2 seconds to drive the small fan to rotate, when the duty cycle reaches 100%, reduce the duty cycle by 20% every two seconds until the duty cycle The ratio becomes 0%, and this cycle is repeated. Because it is a fan module, it can only rotate clockwise and cannot rotate counterclockwise. 

UNO (tested myself)

When your Arduino board has insufficient power supply, it is recommended to power the fan module separately.

Before programming, you can plug the PH2.0 cable into the backplane, or connect as shown in the table below.

| ADXL335 | Arduino |
| ------- | ------- |
| G       | GND     |
| V       | 5V      |
| S       | D3      |

In the example,The signal input pin of the fan module is connected to the D3 pin of the Arduino board. You can change the wiring of the signal pin by the following statement

```cpp
#define FANS 3
```

Change the last parameter after this statement to the pin you want to control.

The example uses two while() loops to accumulate and decrement the duty cycle from 0% to 100%, thereby changing the speed of the fan module.

```
while (i < 250)
  {
    i += 50;
    analogWrite(FANS, i);
    delay(2000);
  }
  delay(2000);
  while (i > 0)
  {
    i -= 50;
    analogWrite(FANS, i);
    delay(2000);
  }
```

### Size reference

![](https://github.com/YouXinElectronic/Around-the-Arduino/blob/main/Fan/image/Dimensions.jpg)

More information - 

Version: V1.0
