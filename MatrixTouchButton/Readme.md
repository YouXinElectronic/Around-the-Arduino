# purchase link

[Click to buy]()

# picture display

<img src="https://raw.githubusercontent.com/YouXinElectronic/Around-the-Arduino/main/MatrixTouchButton/image/top.jpg " width="300"><img src="https://raw.githubusercontent.com/YouXinElectronic/Around-the-Arduino/main/MatrixTouchButton/image/buttom.jpg" width="300">

# Introduction
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
TTP229 TonTouch IC is a touch chip designed using capacitive sensing principle. This chip has built-in voltage regulator circuit for
Touch sensor use, stable touch effect can be applied in various applications, human touch panel can pass non-conductive insulation.
Edge material connection, the main application is to replace mechanical switches or buttons, this chip can independently support 8 touch keys or 16 touch keys.
This module is configured as 16-key input mode, IIC output data,
# parameter
| Voltage | 3.3 / 5V |
|--|--|
| Chip model | TTP229 |
| positioning hole | M3 |
| Module weight | 23.20g |
| Interface model | PH2.0-4P |
| communication method | IIC |
| Operating mode | 16 key input |

# Pin description

| pin name | pin function |
|--|--|
| G | power negative, ground |
| V | Power is positive, 5V |
| D | SDO data cable |
| C | SCL clock line |

# Instructions for use
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
after downloading the corresponding program, touch the corresponding area, you can read the corresponding data,

| DHT11 | arduino |
|--|--|
| G | GND |
| V | 5V |
| D | A4 |
| C | A5 |

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
After connecting the line and downloading the program, press the switch, you can see the light will come on.

```cpp

//
// Created by kiryanenko on 14.09.19.
//

//////////////////////////////////////////////////////////////////
// Connections
//
// Uno:   SDA <-> A4 (SDA)
//        SCL <-> A5 (SCL)
//
// Mega:  SDA <-> 20 (SDA)
//        SCL <-> 21 (SCL)
//
// Leo:   SDA <-> 2 (SDA)
//        SCL <-> 3 (SCL)
//
//////////////////////////////////////////////////////////////////


#include <Wire.h>
#include <TTP229.h>

TTP229 ttp229;

void setup()
{
    Wire.begin();
    Serial.begin(9600);
}

void loop()
{
    ttp229.readKeys();

    Serial.print("Key states: ");
    for (int i = 0; i < 16; ++i) {
        if (ttp229.isKeyPress(i)) {
            Serial.print("1 ");
        } else {
            Serial.print("0 ");
        }
    }

    int key = ttp229.getKey();
    Serial.print("Pressed key: ");
    Serial.print(key);

    Serial.print("   ");
    if (ttp229.isKeyDown(0)) {
        Serial.print("Key 0 is down");
    } else if (ttp229.isKeyUp(0)) {
        Serial.print("Key 0 is up");
    }

    Serial.println();
    delay(500);
}


```

# size reference

<img src="https://raw.githubusercontent.com/YouXinElectronic/Around-the-Arduino/main/MatrixTouchButton/image/Dimensions.jpg" width="300">

