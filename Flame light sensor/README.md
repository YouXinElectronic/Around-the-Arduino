# Contents

  - [purchase link](#purchase-link)
  - [picture display](#picture-display)
  - [Introduction](#introduction)
  - [parameter](#parameter)
  - [instructions for use](#instructions-for-use)

## Purchase link
[Click to buy](https://item.taobao.com/item.htm?spm=a1z10.3-c-s.w4002-24126019655.17.5c7711a0ex34WU&id=688240326583)

## Picture display
![在这里插入图片描述](https://img-blog.csdnimg.cn/e68ded9d467d496aacf9f1da40eb5b54.png#pic_center)


## Introduction
The flame sensor uses a special infrared receiving tube to detect the flame by capturing the infrared wavelength in the flame. It can detect the flame or the light source or heat source with the wavelength between 760nm and 1100nm, and the detection Angle is up to 60 degrees. When the infrared wavelength is near 940nm, its sensitivity reaches the limit. Use wide voltage LM393 comparator, signal clean, good waveform, strong driving ability, more than 15mA, with adjustable precision potentiometer to adjust sensitivity.

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
Flame sensor is the most sensitive to flame, and it is also responsive to ordinary light. It is generally used for flame alarm and other purposes. It can also be used for infrared sensing. In addition, it plays a very important role in the fire robot competition or search and rescue robot competition. It can be used as the eyes of the robot to find the fire source or light source football. Combined with the controller and sensor expansion board, it can be used to make fire robot, soccer robot and so on.

When the ambient flame spectrum or light source fails to reach the set threshold, port D will output high level; when the ambient flame spectrum or light source exceeds the set threshold, module D will output low level; Module digital output D can be directly connected with the MCU, through the MCU to detect high and low levels, thus to detect the temperature change of the environment; Small board digital output D can directly drive the store relay module, which can form a flame switch. Analog output A pin is not used, do not need to connect.

After the VCC and GND are connected, the module power indicator will be on. Place the module on the table. In the absence of flame spectrum, if the board switch indicator is on, adjust the blue potentiometer until the switch indicator is off. Then turn on the lighter at the front end of the flame sensor about 30cm, it will be found that the switch indicator light on the board, and then extinguish the lighter, the switch indicator light will be off. This phenomenon shows that the flame spectrum can trigger the module to light the switch indicator.

Note: Although the sensor is designed to sense fire, it's not fire resistant. The working temperature of the flame sensor probe is -25 C ~ 85 C. In the process of use, we must pay attention to the distance between the flame sensor probe and the flame can not be too close, so as not to cause damage. Generally within 1m applicable (test with lighter flame, half a meter can trigger the sensor). Wire correctly! Do not reverse the positive and negative connection, so that the board electronic devices burned.


