# Contents

  - [purchase link](#purchase-link)
  - [picture display](#picture-display)
  - [Introduction](#introduction)
  - [parameter](#parameter)
  - [Instructions for use](#instructions-for-use)

## Purchase link
[Click to buy](https://item.taobao.com/item.htm?spm=a1z10.3-c-s.w4002-24126019655.11.73ea11a02GtJkN&id=688241458566)

## Picture display
![在这里插入图片描述](https://img-blog.csdnimg.cn/e03ca773cb5942d1bb25b36023371eab.png#pic_center)

## Introduction
Tilt sensor adopts tilt switch SW-520D, high sensitivity, based on the digital module of the steel ball switch, using the characteristics of the steel ball, through the action of gravity to make the steel ball to roll low, so as to make the switch closed or off. At present, the ball switch is mostly mercury switch, with easy damage, oxidation, leakage, short life, environmental pollution and other drawbacks, ball switch abandon the above shortcomings. More environmentally friendly, safer than using mercury switches. Therefore, it can be used as a unidirectional inclination sensor. Use wide voltage LM393 comparator, signal clean, good waveform, strong driving capacity, more than 15mA.

## Parameter
Operating voltage: 5V

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
After the VCC and GND are connected, the power indicator of the module will be on. Gently place the module horizontally on the table, slowly rotate the module upward, and the switch indicator will light up. Then rotate the module in the opposite direction, and return to the original state. The switch indicator will turn off. This phenomenon shows that changing the sensor Angle can trigger the module, which makes the switch indicator light on. When the module has no tilt or the tilt Angle fails to reach the set threshold, port D outputs high level; when the sensor tilt Angle exceeds the threshold, module D outputs low level; The digital output D of the small board can be directly connected with the single chip microcomputer, through which the high and low level can be detected, thus detecting the change of the Angle of the object; Small board digital output D can directly drive the store relay module, which can form a tilt switch. Analog output A pin is not used, do not need to connect.


