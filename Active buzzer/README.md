# purchase link

[Click to buy]()

# picture display

<img src="https://raw.githubusercontent.com/YouXinElectronic/Around-the-Arduino/main/DHT11/image/top.jpg" width="300"><img src="https://raw.githubusercontent.com/YouXinElectronic/Around-the-Arduino/main/DHT11/image/bottom.jpg" width="300">

# Introduction
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;`DHT11` is a temperature and humidity composite sensor with calibrated digital signal output. It applies dedicated digital module acquisition technology and temperature and humidity sensing technology to ensure the product has reliable stability. The module communicates with MCU and other devices through a single bus, only one line is needed, the module has a built-in pull-up `4.7K resistor`, and the user does not need an external pull-up, which is convenient for users to use on a microcontroller without pull-up function.

# parameter
| Voltage | 3.3 / 5V |
|--|--|
| Communication Interface | one-wire |
| Temperature measurement range | -20 ~ +60℃ |
| Temperature measurement error | ±2℃ |
| Humidity measurement range | 20% ~ 95%RH（0 – 50℃） |
| Interface model | PH2.0-3P |

# Pin description

| pin name | pin function |
|--|--|
| G | power negative, ground |
| V | Power is positive,3.3 / 5V |
| D | Single bus data communication port |


# Instructions for use
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Before programming the code, you can directly insert the `PH2.0` cable into the `2` port on the backplane, or connect as follows

| DHT11 | arduino |
|--|--|
| G | GND |
| V | 5V |
| D | 2 |

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;After connecting the wires, burn the code, open the serial monitor and set the baud rate to `115200`, and you will see the temperature and humidity data returned one after another in the serial monitor.

```cpp

/*
  Get DHT11 temperature and humidity data
  Author: YXDZ
  Creation Date: 2022/8/25
  Version: V1.0
  github：https://github.com/YouXinElectronic/Around-the-Arduino
*/

#include <DHT11.h>
DHT11 DHT(2);

void setup(){
  Serial.begin(115200);
}

void loop(){
  DHT.readDht11();
  Serial.print("temp:");
  Serial.print(DHT.getTemperature());
  Serial.print("  humi:");
  Serial.println(DHT.getHumidity());
  delay(1000);
}


```

code snippet

```cpp

DHT11 DHT(2);

```

The `2` code in parentheses is the port connected when driving `DHT11`, users can modify it according to their own needs

Before taking out the `DHT11` data, you need to use the `readDht11()` function to read the `DHT11` once. After obtaining the `DHT11`, you can use the following functions to obtain the temperature and humidity data respectively.

```cpp

getTemperature()

getHumidity()

```

The code is very simple to use, you only need to call the `DHT11` library we have written to use the above functions to quickly drive the `DHT11`.

# size reference

<img src="https://raw.githubusercontent.com/YouXinElectronic/Around-the-Arduino/main/DHT11/image/Dimensions.jpg" width="300">


