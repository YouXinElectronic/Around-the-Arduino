#ifndef _LCD_INIT_H
#define _LCD_INIT_H

#include "stm32f10x.h"

#define USE_HORIZONTAL 0  //设置横屏或者竖屏显示 0或1为竖屏 2或3为横屏


#define LCD_W 240
#define LCD_H 240



//-----------------LCD端口定义---------------- 

#define LCD_SCLK_Clr() GPIO_ResetBits(GPIOA,GPIO_Pin_5)//SCL=WCLK
#define LCD_SCLK_Set() GPIO_SetBits(GPIOA,GPIO_Pin_5)

#define LCD_RCLK_Clr() GPIO_ResetBits(GPIOA,GPIO_Pin_4)//SCL=RCLK
#define LCD_RCLK_Set() GPIO_SetBits(GPIOA,GPIO_Pin_4)

#define LCD_RES_Clr()  GPIO_ResetBits(GPIOA,GPIO_Pin_6)//RES
#define LCD_RES_Set()  GPIO_SetBits(GPIOA,GPIO_Pin_6)

#define LCD_DC_Clr()   GPIO_ResetBits(GPIOA,GPIO_Pin_7)//DC
#define LCD_DC_Set()   GPIO_SetBits(GPIOA,GPIO_Pin_7)
 		     
#define LCD_CS_Clr()   GPIO_ResetBits(GPIOB,GPIO_Pin_6)//CS
#define LCD_CS_Set()   GPIO_SetBits(GPIOB,GPIO_Pin_6)

#define LCD_BLK_Clr()  GPIO_ResetBits(GPIOB,GPIO_Pin_7)//BLK
#define LCD_BLK_Set()  GPIO_SetBits(GPIOB,GPIO_Pin_7)

//D0~D7数据接口 定义引脚为PC3~PC10  用户修改引脚需要修改 lcd_init.c文件中 void LCD_Writ_Bus(u8 dat) ;函数代码段  GPIOC->ODR = dat << 3;  该段为数据输出控制部分


void LCD_GPIO_Init(void);//初始化GPIO
void LCD_Writ_Bus(u8 dat);//模拟SPI时序
void LCD_WR_DATA8(u8 dat);//写入一个字节
void LCD_WR_DATA(u16 dat);//写入两个字节
void LCD_WR_REG(u8 dat);//写入一个指令
void LCD_Address_Set(u16 x1,u16 y1,u16 x2,u16 y2);//设置坐标函数
void LCD_Init(void);//LCD初始化

#endif

