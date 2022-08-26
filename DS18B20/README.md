
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

<img src="https://raw.githubusercontent.com/YouXinElectronic/Around-the-Arduino/main/DS18B20/image/top.jpg" width="300"><img src="https://raw.githubusercontent.com/YouXinElectronic/Around-the-Arduino/main/DS18B20/image/bottom.jpg" width="300">

## Introduction
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;`DS18B20` is a classic single bus digital temperature sensor, its temperature measurement range is `-55 ~ 125 ℃`, and it has a `64-bit` read-only memory to store the serial number of the device, which allows up to 8 DS18B20s to communicate in parallel on a single bus at the same time, saving a lot of money The IO port of the user's MCU and other equipment is used, and the `10K resistor` is pulled up on the board, which is convenient for the user to use on the MCU without the pull-up function.

## parameter
| Voltage | 3.3 / 5V |
|--|--|
| Communication Interface | one-wire |
| Temperature measurement range | -55 ~ +125℃ |
| Temperature measurement error | ±0.5℃ |
| Interface model | PH2.0-3P |

## Pin description

| pin name | pin function |
|--|--|
| G | power negative, ground |
| V | Power is positive,3.3 / 5V |
| D | Single bus data communication port |


## Instructions for use
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Before programming, you can plug the PH2.0 cable into the backplane, or connect as shown in the table below.

| DS18B20 | arduino |
|--|--|
| G | GND |
| V | 5V |
| D | 2 |

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;After connecting the sensor with the arduino, do the code burning, after the code burning is complete, open the serial monitor and set the baud rate to 115200 to view the data, you will see in the serial monitor every 1~ Return the measured temperature data in 2 seconds, the main function code is as follows

```cpp

/*
  Get DS18B20 temperature data
  Author: YXDZ
  Creation Date: 2022/8/25
  Version: V1.0
  github：https://github.com/YouXinElectronic/Around-the-Arduino
*/

#include <DS18B20.h>

DS18B20 ds(2);

void setup() {
  Serial.begin(115200);
}

void loop() {
  ds.doConversion();
  Serial.print("Temperature: ");
  Serial.print(ds.getTempC());
  Serial.println(" C\n");
  delay(1000);
}


```

code snippet

```cpp

DS18B20 ds(2);

```

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;The `2` code in parentheses is the port connected when driving `DS18B20`, users can modify it according to their own needs

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;There are very complete library functions in the library file for you to call. If you need to get the temperature, you only need to call the following two functions to get the temperature value collected by the sensor

```cpp

doConversion()

getTempC()

```

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;The `doConversion()` function is used to start the `DS18B20` temperature conversion. We need to start it every time we need to get the temperature. After starting, we can call the function `getTempC()`, which will return the collected temperature data for our use.


## size reference

<img src="https://raw.githubusercontent.com/YouXinElectronic/Around-the-Arduino/main/DS18B20/image/Dimensions.jpg" width="300">


