# Contents

  - [purchase link](#purchase-link)
  - [picture display](#picture-display)
  - [Introduction](#introduction)
  - [parameter](#parameter)
  - [instructions for use](#instructions-for-use)

## Purchase link
[Click to buy](https://item.taobao.com/item.htm?spm=a1z10.3-c-s.w4002-24126019655.13.127211a09aQ6xA&id=688239742845)

## Picture display
![在这里插入图片描述](https://img-blog.csdnimg.cn/afc365e3458d48589e0ffcc05fef1d4b.png#pic_center)



## Introduction
Photosensitive diode module is the most sensitive to ambient light intensity, which is generally used to detect the brightness and light intensity of the surrounding environment. In most occasions, it can be used with the photosensitive resistance sensor module. The difference between the two is that the photosensitive diode module has good directivity and can sense the light source in a fixed direction. Use wide voltage LM393 comparator, signal clean, good waveform, strong driving ability, more than 15mA, with adjustable precision potentiometer to adjust sensitivity.

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
Digital quantity D output can directly drive the store relay module, which can form a light control switch. When there is no light or the ambient light brightness does not reach the set threshold, the D end outputs a high level; when the ambient light brightness exceeds the set threshold, the D end outputs a low level. Detection brightness can be adjusted by potentiometer, clockwise potentiometer, detection brightness increase; Counterclockwise potentiometer to detect luminance reduction. Analog A pin is not used, so leave it alone.

After the VCC and GND are connected, the power indicator of the module will be on. Place the module where there is a light source and adjust the blue potentiometer on the board until the switch indicator on the board is on. Then cover the photosensitive diode with your hand and the switch indicator of the module will be off. Take your hand away and the switch indicator will turn on again. This phenomenon shows that the light source can trigger the module, which makes the switch indicator light on.


