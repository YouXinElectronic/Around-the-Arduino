/*
		已编写函数读取CST816手势状态，获取触摸坐标点信息
		并通过读Device ID进行初始化判断是否接入CST816
		作者:JXL
		创建日期:2022/7/13
		版本：V1.0
*/

#ifndef _CST816_H_
#define _CST816_H_

#include "stm32f10x.h"

/*定义使用引脚*/				 
#define   INT_Pin    GPIO_Pin_5

/*定义引脚所在组*/
#define   INT_Pin_group   GPIOB
										 
/*定义使用的时钟*/

#define   INT_Pin_RCC   RCC_APB2Periph_GPIOB

#define CST816Address 0x15
#define chipID 0xB4
#define REG_CHIP_ID 0xA3
#define CST816_DATA 0x01

enum gesture
{
	NONE = 0x00,
	SWIPE_DOWN = 0x01,
	SWIPE_UP = 0x02,
	SWIPE_RIGHT = 0x03,
	SWIPE_LEFT = 0x04,
	LONG_PRESS = 0x0c
};


typedef struct {
  uint8_t gestureID;   // 手势识别数据
  uint8_t points;   // 触摸点位数ID，没有手册,触摸芯片相关内容过少,不知道为什么一直是1
  uint8_t event;   // 触摸的事件（0 = 触摸时，手放上，1 = 触摸结束手离开，2 = 触摸中）
  uint8_t x;   //X轴坐标
  uint8_t y;   //Y轴坐标
}data_struct;

	
/*上电判断CST816是否响应来确定CST816是否接入
CST816接入返回1，未检测到返回0*/
uint8_t init_CST816(void);
/*判断屏幕上是否有触摸，有返回1并获取屏幕触摸数据并存储结构体data_struct声明的对象touch_data中，以供后续调用，没有返回0*/
uint8_t CST816_available(void);
/*
返回手势
	0x00 无手势   0x01 向下滑动   0x02 向上滑动   0x03 向右滑动   0x04 向左滑动   0x0c 长按
*/
uint8_t CST816_Gesture(void);

uint8_t CST816_points(void);

/* 触摸的事件（0 = 触摸时，手放上，1 = 触摸结束手离开，2 = 触摸中） */
uint8_t CST816_event(void);
uint8_t CST816_x(void);
uint8_t CST816_y(void);
	



#endif
