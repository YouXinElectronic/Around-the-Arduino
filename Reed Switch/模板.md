# Contents

  - [purchase link](#purchase-link)
  - [picture display](#picture-display)
  - [Introduction](#introduction)
  - [parameter](#parameter)
  - [Instructions for use](#instructions-for-use)

## Purchase link
[Click to buy](https://item.taobao.com/item.htm?spm=a1z10.3-c-s.w4002-21223910208.27.2cf56a4bPUfGwX&id=688551418973)

## Picture display
![在这里插入图片描述](https://img-blog.csdnimg.cn/911da92881a64614856754dc83f0f089.png#pic_center)

## Introduction
The reed switch is short for dry tongue spring pipe, is a kind of passive electronic switch element with contacts, has the advantages of simple structure, small volume and easy control, its shell is generally a sealed glass tube, the tube is equipped with two iron elastic reed plate, but also filled with a metal rhodium inert gas. Normally, two reeds in the glass tube made of special materials are separated. When a magnetic substance is close to the glass tube, under the action of the magnetic field line of force, the two reeds in the tube will be magnetized and attract and contact each other, and the reeds will be sucked together, so that the circuit connected by the junction is connected. When the external force disappears, the two reeds are separated due to their elasticity, and the line is broken. Therefore, as a circuit switch device controlled by magnetic field signal, reed tube can be used as a sensor for counting, limiting and so on (mainly used in the production of door magnet and window magnet in the security system), but also widely used in a variety of communication equipment. In practice, permanent magnets are usually used to control whether the two pieces of metal are connected or not, so it is also called "magnetron". In the program control switch, copier, washing machine, refrigerator, camera, disinfection cupboard, door magnet, window magnet, electromagnetic relay, electronic weighing instrument, level meter, gas meter, water meter and so on have been very good application.

The wide voltage LM393 comparator can directly output high and low levels with clean signal, good waveform and strong driving capacity of more than 15mA by comparing the value transmitted by the reed tube element with the value of potentiometer.



## Parameter
Operating voltage: 5V

Module interface: PH2.0-2P (with PH2.0 to Dupont female head wire)

Reed switch type: MKA-07101

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
When VCC and GND are connected, the module power indicator light will be on, and the reed tube needs to be used together with the magnet. When a certain magnetic force is sensed, it will be in the on-on state, the module will output low level, while when there is no magnetic force, it will be disconnected and output high level. The induction distance between the reed tube and the magnet is within the sensitivity range. The output end of module D can be directly connected to the I/O port of the single chip microcomputer, through which the single chip microcomputer can detect the trigger state of the spring pipe; The output end of module D is connected with the IN end of relay to form a high-power reed pipe switch to directly control the high voltage. Analog output A pin is not used, do not need to connect.


