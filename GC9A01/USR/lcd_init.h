#ifndef _LCD_INIT_H
#define _LCD_INIT_H

#include "stm32f10x.h"

#define USE_HORIZONTAL 0  //���ú�������������ʾ 0��1Ϊ���� 2��3Ϊ����


#define LCD_W 240
#define LCD_H 240



//-----------------LCD�˿ڶ���---------------- 

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

//D0~D7���ݽӿ� ��������ΪPC3~PC10  �û��޸�������Ҫ�޸� lcd_init.c�ļ��� void LCD_Writ_Bus(u8 dat) ;���������  GPIOC->ODR = dat << 3;  �ö�Ϊ����������Ʋ���


void LCD_GPIO_Init(void);//��ʼ��GPIO
void LCD_Writ_Bus(u8 dat);//ģ��SPIʱ��
void LCD_WR_DATA8(u8 dat);//д��һ���ֽ�
void LCD_WR_DATA(u16 dat);//д�������ֽ�
void LCD_WR_REG(u8 dat);//д��һ��ָ��
void LCD_Address_Set(u16 x1,u16 y1,u16 x2,u16 y2);//�������꺯��
void LCD_Init(void);//LCD��ʼ��

#endif

