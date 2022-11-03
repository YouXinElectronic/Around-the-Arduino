
# Contents

  - [purchase link](#purchase-link)
  - [picture display](#picture-display)
  - [Introduction](#introduction)
  - [parameter](#parameter)
  - [Pin description](#pin-description)
  - [Instructions for use](#instructions-for-use)
  - [size reference](#size-reference)

## purchase link
[Click to buy](https://item.taobao.com/item.htm?spm=a1z10.3-c-s.w4002-21223910208.29.7d2b6a4bhBGp0x&id=686359658933)

## picture display
<img src="https://raw.githubusercontent.com/YouXinElectronic/Around-the-Arduino/main/Rotary-Encoder/image/top.jpg" width="300"><img src="https://raw.githubusercontent.com/YouXinElectronic/Around-the-Arduino/main/Rotary-Encoder/image/bottom.jpg" width="300">

## Introduction
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;The `rotary encoder` can `count the number of pulses output in the forward direction` and `reverse direction` by rotating it. Determine the rotation direction by detecting the pulse sequence of `A B phase`, and has a `key` function, the default `A B phase` `And the button port both output `high level`, output `low level` after triggering, module A and B phases and buttons have `10K` pull-up resistors and `0.1uf` filter capacitors, which is convenient for users to use MCU without pull-up function. It is used on the software and avoids the user's delay processing at the software level.

## parameter
| Voltage | 3.3 / 5V |
|--|--|
| Communication Interface | I/O high and low level communication |
| Number of pulses | lap 20 |
| Interface model | PH2.0-5P |

## Pin description

| pin name | pin function |
|--|--|
| G | power negative, ground |
| V | Power is positive,3.3 / 5V |
| A | A-phase signal output |
| B | B-phase signal output |
| S | key signal output |


## Instructions for use
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Before programming the code, you can directly insert the `PH2.0` cable into the `2` 、 `3` 、 `4` port on the backplane, or connect as follows

| Rotary encoder | arduino |
|--|--|
| G | GND |
| V | 5V |
| A | 2 |
| B | 3 |
| S | 4 |

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;After connecting the wires, burn the code, open the serial monitor and set the baud rate to `115200`, You will see the `rotary encoder` counts returned as well as the key state in the serial monitor.

```cpp

/*
  Output the current state of the encoder and count
  Author: YXDZ
  Creation Date: 2022/8/25
  Version: V1.0
  github：https://github.com/YouXinElectronic/Around-the-Arduino
*/

#define A_pin 2 //A port connection pins
#define B_pin 3 //B port connection pins
#define key_pin 4 //Button port pins

int EncoderNum =0; 
int A_pin_State; 
int A_pin_BeforeState;
bool bottomState =0; 
bool timeState = 0;

void setup() 
{
  pinMode (A_pin,INPUT); 
  pinMode (B_pin,INPUT); 
  pinMode (key_pin,INPUT);
  Serial.begin (115200); 
  A_pin_BeforeState = digitalRead(A_pin); 
}
void loop() 
{
  bottomState = 1;
  
  A_pin_State = digitalRead(A_pin);
  if (A_pin_State != A_pin_BeforeState)
  {
    if (digitalRead(B_pin) != A_pin_BeforeState)
    {
      EncoderNum++; 
    } 
    else 
    {
      EncoderNum--; 
    }
    
  }
  A_pin_BeforeState = A_pin_State;

  if (digitalRead(key_pin) == LOW)
  {
    bottomState = 0;
  }

  if(millis()%500/5 == 0)
  {
    if(timeState == 0)
    {
      timeState = 1;
      Serial.print("EncoderNum:");
      Serial.print(EncoderNum/2);
      Serial.print("     button state:");
      Serial.println(bottomState);
      }
    }
  else
  {
    timeState = 0;
    }
}


```

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;code snippet

```cpp

#define A_pin 2 //A port connection pins
#define B_pin 3 //B port connection pins
#define key_pin 4 //Button port pins

```

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;This code macro defines the connection ports of the A, B phases and the button pins, which can be modified according to your own needs.

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Among the defined variables, EncoderNum stores the count of the encoder. The count increases clockwise and decreases counterclockwise. BottomState stores the state of the switch button. When the value is 1, the button is not pressed, and when the value is 0, it is the pressed state.

```cpp

int EncoderNum =0; 
int A_pin_State; 
int A_pin_BeforeState;
bool bottomState =0; 
bool timeState = 0;

```

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;In the main function, there are three major parts of the code, which respectively realize the detection of the encoder count, the detection of the button function, and the rough timing output of the serial port. Users can refer to the following code to modify.

```cpp

  A_pin_State = digitalRead(A_pin);
  if (A_pin_State != A_pin_BeforeState)
  {
    if (digitalRead(B_pin) != A_pin_BeforeState)
    {
      EncoderNum++; 
    } 
    else 
    {
      EncoderNum--; 
    }
  }
  A_pin_BeforeState = A_pin_State;

```

```cpp

  if (digitalRead(key_pin) == LOW)
  {
    bottomState = 0;
  }

```

```cpp

  if(millis()%500/5 == 0)
  {
    if(timeState == 0)
    {
      timeState = 1;
      Serial.print("EncoderNum:");
      Serial.print(EncoderNum/2);
      Serial.print("     button state:");
      Serial.println(bottomState);
      }
    }
  else
  {
    timeState = 0;
    }

```

## size reference

<img src="https://raw.githubusercontent.com/YouXinElectronic/Around-the-Arduino/main/Rotary-Encoder/image/Dimensions.jpg" width="300">


