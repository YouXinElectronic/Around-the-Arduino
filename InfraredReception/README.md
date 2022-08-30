
# Contents

  - [purchase link](#purchase-link)
  - [picture display](#picture-display)
  - [Introduction](#introduction)
  - [parameter](#parameter)
  - [Pin description](#pin-description)
  - [Instructions for use](#instructions-for-use)
  - [size reference](#size-reference)

## purchase link
[Click to buy]()

## picture display
<img src="https://raw.githubusercontent.com/YouXinElectronic/Around-the-Arduino/main/InfraredReception/image/top.jpg" width="300"><img src="https://raw.githubusercontent.com/YouXinElectronic/Around-the-Arduino/main/InfraredReception/image/bottom.jpg" width="300">

## Introduction
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;`VS/HX1838` is a classic infrared receiving sensor. The module has a `10K pull-up resistor` onboard, which is convenient for users to use on a microcontroller without pull-up function.

## parameter
| Voltage | 3.3 / 5V |
|--|--|
| Communication Interface | single wire |
| receiving distance | Related to remote control and power supply, non-fixed value |
| Interface model | PH2.0-3P |

## Pin description

| pin name | pin function |
|--|--|
| G | power negative, ground |
| V | Power is positive,3.3 / 5V |
| S | data communication port |

## Instructions for use
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;The written test code realizes the `NEC decoding` function, and the effect is to press the `button 1 (coded value 0x45)`, the light will be on, and the light will be off after pressing the `button 0 (coded value 0x19)`. The code can be modified by itself, it is not complicated.

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Before programming the code, you can directly insert the `PH2.0` cable into the `2` port on the backplane, or connect as follows

| Rotary encoder | arduino |
|--|--|
| G | GND |
| V | 5V |
| S | 2 |

| LED | arduino |
|--|--|
| G | GND |
| V | 5V |
| S | 3 |

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;After connecting the wires, burn the code, open the serial monitor and set the baud rate to `115200`, After you press the `NEC` remote control button, you will see the output button information on the serial monitor,Of course, if you connect the `LED light`, you can control the on and off of the `LED light` by using `button 1` and `button 0`.

```cpp

/*
  Control the LED light on and off through the NEC coded remote controller. Press the key 1 to light up and the key 0 to light up
  Author: YXDZ
  Creation Date: 2022/8/28
  Version: V1.0
  github：https://github.com/YouXinElectronic/Around-the-Arduino

  The program calls the author's Arduino-IRremote library. The official provides a lot of examples. The following code only calls a small part of the function. The library function is very powerful. You can visit the author's github for more information.
  Library author github: https://github.com/Arduino-IRremote
*/
#include <IRremote.hpp>

#define DECODE_NEC
#define IR_RECEIVE_PIN    2

#define LED_PIN 3
#define LED_Bright digitalWrite(LED_PIN,LOW)
#define LED_Extinguish digitalWrite(LED_PIN,HIGH)

void setup() {
    IrReceiver.begin(IR_RECEIVE_PIN, ENABLE_LED_FEEDBACK);
    printActiveIRProtocols(&Serial);
    Serial.begin(115200);

    pinMode(LED_PIN,OUTPUT);
    LED_Extinguish;
}

void loop() {

  if (IrReceiver.decode()) {
    Serial.println();
    IrReceiver.printIRResultShort(&Serial);
    IrReceiver.resume();
    
    if (IrReceiver.decodedIRData.address == 0) {
      if (IrReceiver.decodedIRData.command == 0x45) {
      LED_Bright;
      }
      else if (IrReceiver.decodedIRData.command == 0x19) {
      LED_Extinguish;
      }
    }
  }
}

```

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;For the above code, we call the open source infrared library on the Internet. Its functions are very powerful. We only use a very small part of the functions to complete the above code writing. If you are interested, you can visit the library's github for more information.`（https://github.com/Arduino-IRremote）`

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;The following code segment defines the pins connecting the `LED` to the `infrared receiving module`, and the user can modify them to the required pins.

```cpp

#define DECODE_NEC
#define IR_RECEIVE_PIN    2

#define LED_PIN 3
#define LED_Bright digitalWrite(LED_PIN,LOW)
#define LED_Extinguish digitalWrite(LED_PIN,HIGH)

```

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;If you need to modify the button of the `NEC remote` control to control the `LED` light, you only need to modify the code used to judge the code value in the `loop` function. 0x45 Keys can be changed.

```cpp

if (IrReceiver.decodedIRData.address == 0) {
  if (IrReceiver.decodedIRData.command == 0x45) {
  LED_Bright;
  }
  else if (IrReceiver.decodedIRData.command == 0x19) {
  LED_Extinguish;
  }
}

```

## size reference

<img src="https://raw.githubusercontent.com/YouXinElectronic/Around-the-Arduino/main/InfraredReception/image/Dimensions.jpg" width="300">


