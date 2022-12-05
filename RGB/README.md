# **RGB module**

@[TOC](Contents)

### purchase link

[Click to buy]()

### 

## picture display

![](https://github.com/YouXinElectronic/Around-the-Arduino/blob/main/RGB/image/top.jpg)

### Foreword：

The lamp beads of the RGB lamp module are composed of three common cathode three primary color light-emitting diodes. Through the combination of different proportions of red, green and blue colors, the RGB lamp beads can display 256 cubic colors, which basically covers the world. all colors..

### Describe：

This example is used to test the reliability and functionality of our company's RGB modules 

UNO (tested myself)

### parameter

| Item                          | Value          |
|:-----------------------------:|:--------------:|
| Voltage                       | 3.3/5V         |
| Input                         | analog/digital |
| Temperature measurement range | -20℃ - 100℃    |
| Interface model               | PH2.0-4P       |
| Beam angle                    | 120°           |

### 

## Pin description

| Pin name | Pin Function                        |
|:--------:|:-----------------------------------:|
| GND      | power negative, ground              |
| R        | Red light control, digital/analog   |
| G        | Green light control, digital/analog |
| B        | Blue light control, digital/analog  |

### 

### Instructions for use

In this example, the lighting of a certain color lamp is controlled by generating random numbers within a fixed range, and the control analog quantity of the lamp is changed at the same time, so that the brightness of the color lamp changes, and the function of changing the color of the breathing lamp is realized.

In addition to the breathing light function, this example can also implement the function of a magic light.

UNO (tested myself)

Before programming, you can plug the PH2.0 cable into the backplane, or connect as shown in the table below.

| RGB module | Arduino |
| ---------- | ------- |
| GND        | GND     |
| R          | D3      |
| G          | D5      |
| B          | D6      |

Example default pin definitions are:

 R --> D3

 G --> D5 

 B --> D6

 You can change the pin definition by changing these three statements, note that the PWM function pins need to be connected.

```cpp
#define R 3
#define G 5
#define B 6
```

You can change the light transition speed of the magic color function and breathing light function by changing the delay time in the corresponding function.

Breathing light

```cpp
void breathing()
```

Magic lights

```cpp
void magic(int a, int b, int c)
```

Change the delay function parameters in the above two functions to change the speed of light color transformation

### Size reference

![](https://github.com/YouXinElectronic/Around-the-Arduino/blob/main/RGB/image/Dimensions.jpg)

More information - 

Version: V1.0
