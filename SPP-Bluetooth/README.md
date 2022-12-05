# **SPP Bluetooth Module**

@[TOC](Contents)

### purchase link

[Click to buy]() 

## picture display

![](https://github.com/YouXinElectronic/Around-the-Arduino/blob/main/SPP-Bluetooth/image/top.jpg)

### Foreword：

SPP Bluetooth module is based on Bluetooth 3.0 SPP classic Bluetooth protocol design, can support Windows, Linux, android data transparent transmission, 2.4GHz working frequency band, modulation mode GFSK, the maximum transmission distance can reach 30 meters, AT command configuration, only for Bluetooth slave machine.

### Describe：

This example includes data transparent transmission between the SPP Bluetooth module and the host, bluetooth lights and the transmission of DS18B20 readings to the host via Bluetooth 

UNO (tested myself)

### parameter

| Item                          | Value      |
|:-----------------------------:|:----------:|
| Voltage                       | 3.3/5V     |
| Communication Interface       | UART       |
| Temperature measurement range | -40℃ - 80℃ |
| Interface model               | PH2.0-5P   |

### 

## Pin description

| Pin name | Pin Function             |
|:--------:|:------------------------:|
| V        | Power Positive, 3.3/5V   |
| G        | power negative, ground   |
| T        | UART serial write        |
| R        | UART serial read         |
| S        | connection status output |

### 

### Instructions for use

#### parameter configuration

**Reset**

| Instruction | Response | Parameter |
|:-----------:|:--------:|:---------:|
| AT+RESET    | +OK      | NONE      |

**BLE Bluetooth MAC address**

| Instruction | Response       | Parameter |
|:-----------:|:--------------:|:---------:|
| AT+LADDR    | +LADDR=<Param> | NONE      |

**Disconnect**

| Instruction | Response | Parameter |
|:-----------:|:--------:|:---------:|
| AT+DISC     | +OK      | NONE      |

**Baud rate setting/query**

| Instruction    | Response      | Parameter                                                                                                  |
|:--------------:|:-------------:|:----------------------------------------------------------------------------------------------------------:|
| AT+BAUD<Param> | +OK           | Param : (4 to 9)<br/> 4 : 9600                                                                             |
| 5 : 19200      |               |                                                                                                            |
| 6 : 38400      |               |                                                                                                            |
| 7 : 57600      |               |                                                                                                            |
| 8 : 115200     |               |                                                                                                            |
| 9 : 128000     |               |                                                                                                            |
| AT+BAUD        | +BAUD=<Param> | Param : (4 to 9)<br/>4 : 9600 <br/>5 : 19200 <br/>6 : 38400 <br/>7 : 57600 <br/>8 : 115200 <br/>9 : 128000 |

**SPP Bluetooth pairing password**

| Instruction           | Response     | Parameter                                    |
|:---------------------:|:------------:|:--------------------------------------------:|
| AT+PIN<Param>         | +OK          | Param:4-digit password                       |
| <br/>default PIN：1234 |              |                                              |
| AT+PIN                | +PIN=<Param> | Param:4-digit password <br/>default PIN：1234 |

**Broadcast name setting/query (Bluetooth name)**

| Instruction                                            | Response      | Parameter                                                                   |
|:------------------------------------------------------:|:-------------:|:---------------------------------------------------------------------------:|
| AT+NAME<Param>                                         | +OK           | Param:Broadcast name                                                        |
| <br/>Maximum : 18 bytes<br/>Default : Clover-Bluetooth |               |                                                                             |
| AT+NAME                                                | +NAME=<Param> | Param:Broadcast name <br/>Maximum : 18 bytes<br/>Default : Clover-Bluetooth |

**Serial port status output enable setting/query**

| Instruction     | Response       | Parameter                                                                                       |
|:---------------:|:--------------:|:-----------------------------------------------------------------------------------------------:|
| AT+ENLOG<Param> | OK             | Param: 1 or 0<br/>1: Open the serial port output<br/>0: close serial port output<br/>Default: 1 |
| AT+ENLOG        | +ENLOG=<Param> | Param: 1 or 0<br/>1: Open the serial port output<br/>0: close serial port output<br/>Default: 1 |

#### BlueTooth-DS18B20

This example is used to measure the temperature value with our company's DS18B20 temperature measurement module, and then transmit it to the main device (Android, Windows, Linux) through the SPP Bluetooth module. For the sample analysis of DS18B20, please read the sample description of our company's DS18B20 temperature measurement module

UNO (tested myself)

Before programming, connect the wiring as shown in the table below.

| SPP Bluetooth Module | Arduino | DS18B20 |
|:--------------------:|:-------:|:-------:|
| V                    | 5v      | V       |
| G                    | GND     | G       |
| T                    | D10     |         |
| R                    | D1      |         |
| S                    |         |         |
|                      | D2      | S       |

The wiring of the DS18B20 temperature measurement module can be modified by changing the parameters of the instantiated DS18B20 library:

```cpp
DS18B20 ds(2);
```

Similarly, if you want to modify the serial port wiring connected to the SPP Bluetooth Module, you can change the parameters of the instantiated soft serial port statement.

```cpp
SoftwareSerial MySerial = SoftwareSerial(10, 11);
```

In the example, the measured value of the DS18B20 temperature measurement module is read every second, and then output to Bluetooth for wireless transmission through the soft serial port of the Arduino board. If you need to change the reading frequency, you can change the delay function of the main function.

#### bluetooth-light

In this example, the SPP Bluetooth Module cooperates with our company's LED light module to realize the on and off of the bluetooth control LED light.
The bluetooth host device (Android, Windows, Linux) can send 1 and 0 in hexadecimal format to control the switch of the LED light module connected to the Arduino board, send 1 LED light module to turn on, send 0 LED light module to turn off

Before programming, connect the wiring as shown in the table below.

| SPP Bluetooth Module | Arduino | LED light module |
|:--------------------:|:-------:|:----------------:|
| V                    | 5V      | V                |
| G                    | GND     | G                |
| T                    | D10     |                  |
| R                    | D11     |                  |
| S                    |         |                  |
|                      | D2      | S                |

The SPP bluetooth master device sends 1 to turn on the LED, and sends 0 to turn off the LED. The control value of the LED can be determined by changing the definition of "ON" and OFF.

```
int NO=1;
int OFF=0;
```

#### SPP-transparent-transmission

This example is used for data transparent transmission between SPP Bluetooth Module and SPP Bluetooth master device (Android, Windows, Linux)

Before programming, connect the wiring as shown in the table below.

| SPP Bluetooth Module | Arduino |
|:--------------------:|:-------:|
| V                    | 5V      |
| G                    | GND     |
| T                    | D10     |
| R                    | D11     |
| S                    |         |

### Size reference

![](https://github.com/YouXinElectronic/Around-the-Arduino/blob/main/SPP-Bluetooth/image/Dimensions.jpg)

More information - 

Version: V1.0
