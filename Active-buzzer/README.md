# purchase link

[Click to buy]()

# picture display

<img src="https://raw.githubusercontent.com/YouXinElectronic/Around-the-Arduino/main/Active-buzzer/image/top.jpg" width="300"><img src="https://raw.githubusercontent.com/YouXinElectronic/Around-the-Arduino/main/Active-buzzer/image/bottom.jpg" width="300">

# Introduction
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;The `active buzzer` sounding module is driven by `S8550 PNP` type triode. The `low level` drives the buzzer to sound, and it is suspended or turned off at high level. The on-board `freewheeling diode` provides a discharge current loop for the self-induced electromotive force and plays a protective role.

# parameter
| Voltage | 3.3 / 5V |
|--|--|
| Communication Interface | I/O high and low level drive (low level sound) |
| Interface model | PH2.0-3P |

# Pin description

| pin name | pin function |
|--|--|
| G | power negative, ground |
| V | Power is positive,3.3 / 5V |
| S | I/O level input port |


# Instructions for use
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Before programming, you can plug the PH2.0 cable into the backplane, or connect as shown in the table below.

| buzzer | arduino |
|--|--|
| G | GND |
| V | 5V |
| S | 2 |

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Connect the sensor to the arduino, after programming the code, we will hear the buzzer beep beep-dip-dip-dip, the frequency is once every 1S.

```cpp

/*
  The buzzer sounds in 1s cycle
  Author: YXDZ
  Creation Date: 2022/8/25
  Version: V1.0
  github：https://github.com/YouXinElectronic/Around-the-Arduino
*/

#define Buzzer_Pin 2
#define cycleTimes 1000

void setup() {
  // put your setup code here, to run once:
  pinMode(Buzzer_Pin,OUTPUT);
  digitalWrite(Buzzer_Pin,HIGH);   //No sound when power on
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(Buzzer_Pin,HIGH);   //High level does not sound
  delay(cycleTimes/2);
  digitalWrite(Buzzer_Pin,LOW);   //low level
  delay(cycleTimes/2);
}


```

code snippet

```cpp

#define Buzzer_Pin 2

```

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Obviously, the number 2 is used to modify the use of the buzzer link port. We only need to change 2 to 3 to plug the buzzer into the digital port 3 of Arduino for use

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;We see another code snippet that can be used to modify the frequency of the buzzer sounding in ms

```cpp

#define cycleTimes 1000

```


# size reference

<img src="https://raw.githubusercontent.com/YouXinElectronic/Around-the-Arduino/main/Active-buzzer/image/Dimensions.jpg" width="300">


