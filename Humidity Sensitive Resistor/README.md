# Contents

  - [purchase link](#purchase-link)
  - [picture display](#picture-display)
  - [Introduction](#introduction)
  - [parameter](#parameter)
  - [instructions for use](#instructions-for-use)

## Purchase link
[Click to buy](https://item.taobao.com/item.htm?spm=a1z10.3-c-s.w4002-24126019655.17.1e1711a0pts6k8&id=687196847761)

## Picture display
![在这里插入图片描述](https://img-blog.csdnimg.cn/d71c2509ef1545f29b94b58b17f07617.png#pic_center)

## Introduction
Humidity sensor module adopts high quality HR202 humidity sensitive resistor, which is very sensitive to environmental humidity, generally used to detect the ambient humidity; The sensor is equipped with M3 fixed mounting hole, easy to adjust direction and fix, wide voltage LM393 comparator, clean signal, good waveform, strong driving ability, more than 15mA, with adjustable precision potentiometer to adjust sensitivity.

## Parameter
Operating voltage: 5V

Model: HR202 Operating temperature: 0~60℃

Working humidity: below 95%RH (non-condensation) Detection accuracy: ≤±5%RH

Wet hysteresis: ≤2%RH  Stability: ≤1%RH/ year

Module interface: PH2.0-2P (with PH2.0 to Dupont female head wire)

Module size: 35 * 23 * 7.2mm (length, width and height)

Mounting hole size: 3mm

| pin name | pin function |
|--|--|
| G | power negative, ground |
| V | Power is positive, 5V |
| D | Digital output pin |
| A | Analog output pin |

![在这里插入图片描述](https://img-blog.csdnimg.cn/ded5aaf1af7148d4ad22cafd908856eb.png#pic_center)

## Instructions for use
When VCC and GND are connected, the module power indicator light will be on, and the threshold value of humidity detection (i.e. the control humidity value) can be changed by adjusting the potentiometer. If the ambient humidity needs to be controlled as 60%, the module will adjust the corresponding ambient humidity to its green light, and D will output the low level. If it is lower than the set humidity value, it will output the high level and the green light will not be on. Module digital output D can be directly connected with the MCU, through the MCU to detect the high and low levels, thus to detect the change of environmental humidity; Small board digital output D can directly drive the store relay module, which can form a humidity switch.

