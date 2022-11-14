# Contents

  - [purchase link](#purchase-link)
  - [picture display](#picture-display)
  - [Introduction](#introduction)
  - [parameter](#parameter)
  - [Instructions for use](#instructions-for-use)

## Purchase link
[Click to buy](https://item.taobao.com/item.htm?spm=a1z10.3-c-s.w4002-24126019655.21.377611a0nKaZcz&id=688521907185)

## Picture display
![在这里插入图片描述](https://img-blog.csdnimg.cn/603ff00f27e344f8b22e0386e3374af7.png#pic_center)


## Introduction
Use normally open high sensitivity vibration switch SW-18010P. When the switch is at rest, it is open circuit OFF state. When it is touched by external force and reaches the corresponding seismic force, or when the moving speed reaches the appropriate deviation (deviation) force, the conductive pin will produce instantaneous conduction and present instantaneous ON state; When the external force disappears, the switch returns to the open OFF state. Can be used for all kinds of vibration trigger effect, report theft alarm, intelligent car, electronic building blocks and so on. Use wide voltage LM393 comparator, signal clean, good waveform, strong driving ability, more than 15mA, with adjustable precision potentiometer to adjust sensitivity.




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
When the product does not vibrate, the vibration switch is disconnected, the output end outputs high level, the indicator light is off; When the product vibrates, the vibration switch will be switched on instantaneously, the output end will output low level, and the indicator will light up. The output terminal can be directly connected with the single chip microcomputer, through the single chip microcomputer to detect the high and low level, so as to detect whether there is vibration in the environment, play an alarm role. Analog output A pin is not used, do not need to connect without tube.

After the VCC and GND are connected, the power indicator of the module will be on. The module is gently placed on the table, adjust the blue potentiometer on the board, until the switch indicator light on the board, and then slightly back to the potentiometer, so that the switch indicator light off, and then beat the desktop with the hand, so that the vibration sensor is felt, at this time, the switch indicator light will be on. The vibration stops and the switch indicator goes off. This phenomenon shows that the vibration can trigger the module, which makes the switch indicator light on.

Note: Wire correctly! Do not reverse the positive and negative connection, so that the board electronic devices burned. When the module senses small vibration, the trigger time will be very short, which is not enough to drive the relay. Some people's data shows that they can be directly connected with the relay module, so the practical application effect is not good.


