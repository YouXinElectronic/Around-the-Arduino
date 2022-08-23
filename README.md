@[TOC](stm32驱动GC9A01显示)

![在这里插入图片描述](https://img-blog.csdnimg.cn/e397759ee5404bfb9e5ae07570ae610e.png#pic_center =200x)


# 前言

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;不久前我们收到用户反馈问题中，多次反馈各种不同型号的屏幕驱动不起来，从0开始编写代码花费大量时间，也有不少初次学习驱动屏幕代码编写经验过少等问题，为此我们决定以文章的形式发布到CSDN来分享相应的一些经验以及收集整理好的资料，希望可以帮助用户更加简单的学习或快速移植代码进行项目开发。

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;后续我们将陆续分享有关`GC9A01`、`ST7789`、`ST7735`、`ILI9341`等驱动IC的屏幕驱动案例。

# 关于GC9A01
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;市面采用`GC9A01`驱动IC的屏幕不多，基本上为`1.28寸圆形屏`，机缘巧合有接触过的这款驱动IC中两款屏幕，其中一款为并行`8080接口`驱动的触摸屏，目前有编写`stm32f10x`相关的代码，但市面上使用者似乎较少，因此本文以另一款屏幕为主。

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;另一款为串行口驱动的屏幕，不带触摸，长下面这个样子，网上搜集加上自己编写以及移植整理有`stm32f10x`、`stm32f407`、`arduino`、`stc89c516`、`ESP32`等单片机代码

![在这里插入图片描述](https://img-blog.csdnimg.cn/189c52c990f14c2ca30a48287969e7d8.png#pic_center =200x)

![在这里插入图片描述](https://img-blog.csdnimg.cn/e31d26cce9a148b6be2835b8d84d55a5.png#pic_center =200x)
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;综合了解并观察屏幕一下的一些参数之后开始进行驱动。

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;硬件接口使用的 `PH2.0` 和 `FPC0.5` 的两种接口，配了一根`PH2.0转杜邦母头`的线，这里没什么特别要求肯定是使用 `PH2.0` 的接口直接插到`stm32开发板`上。

| GC9A01 | 参数 |
| ---- | ----- |
| 供电电压 | 3.3~5.5V  |
| 驱动IC | GC9A01 |
| 分辨率 | 240x240   |
| 尺寸 | 1.28  |
| 驱动接口 | 4线SPI  |

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;产商在屏幕设计上添加了`3.3V稳压`芯片以及电平转换芯片，使得这款原本3.3V供电的裸屏可以`兼容5V和3.3V`的单片机，这也意味着`arduino`和`51单片机`的用户也可以驱动这款屏幕了，虽然51单片机性能很一般但总比不能驱动的好。

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;最后了解各个引脚功能之后就可以开始进行驱动

| 引脚名称 | 引脚功能 |
| ---- | ----- |
| GND | 电源负，地  |
| VCC | 电源正，3.3 - 5V，需要与通信电平一致 |
| SCL | SPI时钟信号输入端口   |
| SDA | SPI数据输入端口  |
| RES | 复位，低电平使能  |
| DC | 数据/命令选择，低电平命令，高电平数据  |
| CS | 片选，低电平使能  |
| BLK | 背光，悬空使能接地关闭，默认上拉至3.3V  |


# stm32驱动

## 引脚接线
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;代码方面先按照下表接好线烧录程序之后再对代码移植的关键部分进行说明

| stm32f10x | GC9A01 |
| ---- | ----- |
| 3V3 | VIN  |
| GND | GND |
| SCL | PA5  |
| SDA | PA4  |
| RES | PA6 |
| DC | PA7  |
| CS | PB6  |
| BLK | PB7  |

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;`BLK背光`引脚不用可以悬空不接

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;默认的代码烧录进行之后显示上面图片中大大的 `优信电子logo`，先把示例代码驱动起来，如果示例代码驱动不起来先检查一下接线供电方面的问题，不然后面代码改了半天没有用找问题就和我刚驱动的时候一样头皮发麻。

![在这里插入图片描述](https://img-blog.csdnimg.cn/189c52c990f14c2ca30a48287969e7d8.png#pic_center =200x)
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;驱动成功之后用户可以开始移植代码。

## 代码移植

###  &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;文件复制

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;将 `lcd`、`lcd_init`的`C文件`和`h文件`复制到自己的工程里面，这四个文件包含屏幕初始化以及驱动画点划线显示文字图像的代码。
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;另外还有两个文件为`image.h`和`lcdfont.h`，这两个文件分别存储显示图片数组与显示文字数组。

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;复制到自己工程中编译后会报错，因为缺少了`pbdata.h`中的`毫秒级延时函数`，可以把原工程中的ms延时函数复制过来也可以使用自己编写的，名称与下面的相同即可

```c
void delay_ms(u16 a)
```

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;添加好文件到工程里面之后再次编译一般不会报错，如果仍然报错就只能看具体报错信息去修改了

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;和上面的接线不变，编写下面主函数先进行测试

```c
int main(void)
{
	LCD_Init();
	LCD_Fill(0,0,LCD_W,LCD_H,WHITE);   //填充为白色背景色
	while(1)
	{
		LCD_ShowPicture(0,0,LCD_W,LCD_H,YXDZ_logo);   //显示一张图片
	}
}
```

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;需要用户修改的接口一般有一下几个点

###  &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;端口修改
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;`lcdfont.h`文件中包含对使用引脚的宏定义，修改其中的`GPIO`以及`引脚`即可修改使用的端口

```c
//-----------------LCD端口定义---------------- 

#define LCD_SCLK_Clr() GPIO_ResetBits(GPIOA,GPIO_Pin_5)//SCL=SCLK
#define LCD_SCLK_Set() GPIO_SetBits(GPIOA,GPIO_Pin_5)

#define LCD_MOSI_Clr() GPIO_ResetBits(GPIOA,GPIO_Pin_4)//SDA=MOSI
#define LCD_MOSI_Set() GPIO_SetBits(GPIOA,GPIO_Pin_4)

#define LCD_RES_Clr()  GPIO_ResetBits(GPIOA,GPIO_Pin_6)//RES
#define LCD_RES_Set()  GPIO_SetBits(GPIOA,GPIO_Pin_6)

#define LCD_DC_Clr()   GPIO_ResetBits(GPIOA,GPIO_Pin_7)//DC
#define LCD_DC_Set()   GPIO_SetBits(GPIOA,GPIO_Pin_7)
 		     
#define LCD_CS_Clr()   GPIO_ResetBits(GPIOB,GPIO_Pin_6)//CS
#define LCD_CS_Set()   GPIO_SetBits(GPIOB,GPIO_Pin_6)

#define LCD_BLK_Clr()  GPIO_ResetBits(GPIOB,GPIO_Pin_7)//BLK
#define LCD_BLK_Set()  GPIO_SetBits(GPIOB,GPIO_Pin_7)
```

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;但值得注意的是仅仅修改这里的`宏定义`是没办法使用的，在`lcdfont.c`文件中包含着对`GPIO引脚`以及`时钟初始化`的函数需要进行端口的修改

```c
void LCD_GPIO_Init(void)
{
	GPIO_InitTypeDef  GPIO_InitStructure;
 	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA|RCC_APB2Periph_GPIOB, ENABLE);	 //使能端口时钟
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4|GPIO_Pin_5|GPIO_Pin_6|GPIO_Pin_7;	 
 	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 		 //推挽输出
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;//速度50MHz
 	GPIO_Init(GPIOA, &GPIO_InitStructure);
 	GPIO_SetBits(GPIOA,GPIO_Pin_4|GPIO_Pin_5|GPIO_Pin_6|GPIO_Pin_7);
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6|GPIO_Pin_7;
 	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 		 //推挽输出
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;//速度50MHz
 	GPIO_Init(GPIOB, &GPIO_InitStructure);
 	GPIO_SetBits(GPIOB,GPIO_Pin_6|GPIO_Pin_7);
}
```
 &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;修改完这里之后才算是将端口修改完毕

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;在`lcdfont.h`顶部还有两个宏定义可以自行决定是否修改，分别对应这屏幕`显示方向`和`屏幕分辨率`的参数

```c
#define USE_HORIZONTAL 0  //设置横屏或者竖屏显示 0或1为竖屏 2或3为横屏

#define LCD_W 240
#define LCD_H 240
```

###  &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;显示函数

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;在`lcd.h`中包含了屏幕显示内容的函数，以及部分`颜色的色号`主要用于刷新`屏幕背景色`的

```c
void LCD_Fill(u16 xsta,u16 ysta,u16 xend,u16 yend,u16 color);//指定区域填充颜色
void LCD_DrawPoint(u16 x,u16 y,u16 color);//在指定位置画一个点
void LCD_DrawLine(u16 x1,u16 y1,u16 x2,u16 y2,u16 color);//在指定位置画一条线
void LCD_DrawRectangle(u16 x1, u16 y1, u16 x2, u16 y2,u16 color);//在指定位置画一个矩形
void Draw_Circle(u16 x0,u16 y0,u8 r,u16 color);//在指定位置画一个圆

void LCD_ShowChinese(u16 x,u16 y,u8 *s,u16 fc,u16 bc,u8 sizey,u8 mode);//显示汉字串
void LCD_ShowChinese12x12(u16 x,u16 y,u8 *s,u16 fc,u16 bc,u8 sizey,u8 mode);//显示单个12x12汉字
void LCD_ShowChinese16x16(u16 x,u16 y,u8 *s,u16 fc,u16 bc,u8 sizey,u8 mode);//显示单个16x16汉字
void LCD_ShowChinese24x24(u16 x,u16 y,u8 *s,u16 fc,u16 bc,u8 sizey,u8 mode);//显示单个24x24汉字
void LCD_ShowChinese32x32(u16 x,u16 y,u8 *s,u16 fc,u16 bc,u8 sizey,u8 mode);//显示单个32x32汉字

void LCD_ShowChar(u16 x,u16 y,u8 num,u16 fc,u16 bc,u8 sizey,u8 mode);//显示一个字符
void LCD_ShowString(u16 x,u16 y,const u8 *p,u16 fc,u16 bc,u8 sizey,u8 mode);//显示字符串
u32 mypow(u8 m,u8 n);//求幂
void LCD_ShowIntNum(u16 x,u16 y,u16 num,u8 len,u16 fc,u16 bc,u8 sizey);//显示整数变量
void LCD_ShowFloatNum1(u16 x,u16 y,float num,u8 len,u16 fc,u16 bc,u8 sizey);//显示两位小数变量

void LCD_ShowPicture(u16 x,u16 y,u16 length,u16 width,const u8 pic[]);//显示图片


//画笔颜色
#define WHITE         	 0xFFFF
#define BLACK         	 0x0000	  
#define BLUE           	 0x001F  
#define BRED             0XF81F
#define GRED 			       0XFFE0
#define GBLUE			       0X07FF
#define RED           	 0xF800
#define MAGENTA       	 0xF81F
#define GREEN         	 0x07E0
#define CYAN          	 0x7FFF
#define YELLOW        	 0xFFE0
#define BROWN 			     0XBC40 //棕色
#define BRRED 			     0XFC07 //棕红色
#define GRAY  			     0X8430 //灰色
#define DARKBLUE      	 0X01CF	//深蓝色
#define LIGHTBLUE      	 0X7D7C	//浅蓝色  
#define GRAYBLUE       	 0X5458 //灰蓝色
#define LIGHTGREEN     	 0X841F //浅绿色
#define LGRAY 			     0XC618 //浅灰色(PANNEL),窗体背景色
#define LGRAYBLUE        0XA651 //浅灰蓝色(中间层颜色)
#define LBBLUE           0X2B12 //浅棕蓝色(选择条目的反色)
```

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;在使用的时候只需要看后面的`中文注释`去`调用`对应的函数即可，非常方便使用

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;但是如果需要`显示文字`和`图片`的话只是直接调用上面的函数还不够，`汉字数组`存储的`lcdfont.h`文件中只包含了`中英文字母`、`数字`、`符号`以及非常少量的`中文数组`，中文数组存储在以下几个数组中，按照相同的格式自行添加进去即可

###  &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;中文汉字数组

```c
typedef struct 
{
	unsigned char Index[2];	
	unsigned char Msk[24];
}typFNT_GB12; 
const typFNT_GB12 tfont12[]={
"优",0x24,0x01,0x24,0x02,0x22,0x00,0xFA,0x07,0xA3,0x00,0xA2,0x00,0xA2,0x00,0xA2,0x00,
0x92,0x00,0x92,0x04,0x8A,0x04,0x06,0x07,
"信",0x44,0x00,0x84,0x00,0xFA,0x07,0x02,0x00,0xF3,0x03,0x02,0x00,0xF2,0x03,0x02,0x00,
0xF2,0x03,0x12,0x02,0xF2,0x03,0x12,0x02,
"电",0x10,0x00,0x10,0x00,0xFF,0x01,0x11,0x01,0x11,0x01,0xFF,0x01,0x11,0x01,0x11,0x01,
0xFF,0x01,0x11,0x04,0x10,0x04,0xE0,0x07,
"子",0x00,0x00,0xFC,0x01,0x80,0x00,0x40,0x00,0x20,0x00,0x20,0x00,0xFF,0x07,0x20,0x00,
0x20,0x00,0x20,0x00,0x20,0x00,0x38,0x00,
};

typedef struct 
{
	unsigned char Index[2];	
	unsigned char Msk[32];
}typFNT_GB16; 
const typFNT_GB16 tfont16[]={
"优",0x10,0x09,0x10,0x11,0x10,0x11,0x08,0x01,0xE8,0x7F,0x0C,0x05,0x0C,0x05,0x0A,0x05,
0x09,0x05,0x08,0x05,0x88,0x04,0x88,0x44,0x88,0x44,0x48,0x44,0x48,0x78,0x28,0x00,
"信",0x10,0x02,0x10,0x04,0xD0,0x7F,0x08,0x00,0x08,0x00,0x8C,0x3F,0x0C,0x00,0x0A,0x00,
0x89,0x3F,0x08,0x00,0x08,0x00,0x88,0x3F,0x88,0x20,0x88,0x20,0x88,0x3F,0x88,0x20,
"电",0x80,0x00,0x80,0x00,0x80,0x00,0xFC,0x1F,0x84,0x10,0x84,0x10,0x84,0x10,0xFC,0x1F,
0x84,0x10,0x84,0x10,0x84,0x10,0xFC,0x1F,0x84,0x50,0x80,0x40,0x80,0x40,0x00,0x7F,
"子",0x00,0x00,0xFE,0x1F,0x00,0x08,0x00,0x04,0x00,0x02,0x80,0x01,0x80,0x00,0xFF,0x7F,
0x80,0x00,0x80,0x00,0x80,0x00,0x80,0x00,0x80,0x00,0x80,0x00,0xA0,0x00,0x40,0x00,
};
```

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;数组名字里面的`GB12`和`GB16`代表了`12号字体`和`16号字体`的数组，文件中也有`24号`和`32号`


###  &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;图片
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;图片存储在`image.h`文件中，图片文件中的内容比较简单，一个纯数组取模放进去的

```c
const unsigned char YXDZ_logo[115200] = { /*0X10,0X10,0X00,0XF0,0X00,0XF0,0X01,0X1B,*/
0XFF,0XDF,0XFF,0XDF,0XFF,0XDF,0XFF,0XFF,0XFF,0XFF,0XFF,0XDF,0XFF,0XDF,0XFF,0XDF,
...................
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
};
```

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;记得在数组前面加`const`就行


# 其他单片机驱动

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;使用其他单片机编写的代码显示的效果与上面的`STM32`的相同，都是一张图片，空间不够的单片机只是显示了一张小一点的图片。

## 51单片机

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;51单片机程序由stm32的移植过去的，所以是一样的使用，唯一的区别是51单片机空间小显示不了大图片，速度也比较慢

## arduino/ESP32
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;arduino驱动是网上找到的微雪的例程修改的，个人对Arduino使用没有做过多研究，大部分情况调库使用。
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;`ESP32`驱动直接调用的`GFX`的库编写驱动，具体使用方法可以作者的`github`上有，这个库非常的强大，同样的也很复杂，所以咱这水平也只能是去调用一下别人写好的函数使用。

# 总结

后续我们将编写、移植或者收集测试好的一些屏幕代码分享相应的一些LCD、OLED等显示器件的驱动案例，供大家共同学习进步，前行路上，优信与大家同在，欢迎一键三连，感谢各位大佬！








