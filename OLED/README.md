# **OLED display module**

@[TOC](Contents)

### purchase link

[Click to buy]()

### 

## picture display

![](https://github.com/YouXinElectronic/Around-the-Arduino/blob/main/OLED/image/top.jpg)

### Foreword：

OLED (Organic Light-Emitting Diode) display screen has a large viewing angle and low power consumption. Because OLED has self-illumination at the same time, does not need backlight (it will not light up only when it is powered on, it will light up when the driver and wiring are correct), high contrast ratio, thin thickness, wide viewing angle, fast response speed, and can be used for flexible panels. , The use of a wide temperature range, structure and simple process and other excellent characteristics. This module adopts the drive of SSD1306, and realizes the display of characters and images through IIC serial communication.

### Describe：

This example can be used for the text display test of our company's 0.96 inch OLED display module. This example will use the U8g2 open source library, please download it in the add library of the Arduino IDE. UNO (tested myself)

### parameter

| Item                          | Value      |
|:-----------------------------:|:----------:|
| Voltage                       | 3.3/5V     |
| Communication Interface       | IIC        |
| Temperature measurement range | -40℃ - 70℃ |
| Interface model               | PH2.0-4P   |

### 

## Pin description

| Pin name | Pin Function                  |
|:--------:|:-----------------------------:|
| G        | power negative, ground        |
| V        | Power Positive, 3.3/5V        |
| D        | SDL pin of IIC, data transfer |
| C        | SCL pin of IIC, clock         |

### 

### Instructions for use

This example can be used to test our 0.96 inch OLED display module, showing "Clover Publish" and "HELLO WORLD".

 UNO (tested myself)

Before programming, you can plug the PH2.0 cable into the backplane, or connect as shown in the table below.

| OLED display module | Arduino |
| ------------------- | ------- |
| G                   | GND     |
| V                   | 5V      |
| D                   | A4      |
| C                   | A5      |

This example is driven by the hardware IIC interface of the Arduino board, which cannot be changed at will, but you can change the IIC interface by changing the instantiation function of the U8g2 library to the software IIC driving method.

```cpp
U8G2_SSD1306_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0, /* reset=*/ U8X8_PIN_NONE);
```

Just open the example side of a U8g2 library and there will be many instantiation functions to choose from. Copy it directly and replace the above statement. Note that the driver chip is SSD1306.

```cpp
U8G2_SSD1306_128X64_NONAME_F_SW_I2C u8g2(U8G2_R0, /* clock=*/ 16, /* data=*/ 17, /* reset=*/ U8X8_PIN_NONE);
```

Change the printed text

Change the parameters in the function

```cpp
u8g2.print("Clover");
```

For more function analysis, please refer to the description of U8g2 library

### Size reference

![](https://github.com/YouXinElectronic/Around-the-Arduino/blob/main/OLED/image/Dimensions.jpg)

More information - 

Version: V1.0
