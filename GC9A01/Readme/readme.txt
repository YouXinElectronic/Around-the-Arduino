接线说明

	LCD端口定义在 lcd_init.h 文件中   用户若需要修改端口，除了需要修改 lcd_init.h 文件中的宏定义外还需修改 lcd_init.c 中函数 void LCD_GPIO_Init(void); 对 GPIO 引脚以及时钟初始化部分
	
	关于数据口没有定义的说法，数据口初始化在lcd_init.c 中函数 void LCD_GPIO_Init(void); 中,并未使用宏定义,而采用直接驱动ODR寄存器的方式驱动,由于没有做或运算因此这种驱动方式会影响到整个PC端口，用户可自行优化
	
	触摸IIC通信引脚定义于 softIIC.h 文件中,中断引脚定义于 CST816.h 文件中

	默认接线如下
	stm32F10x		GC9A01(touch)
	
	3V3				VIN
	GND				GND
	BL				PB7
	RST				PA6
	CS				PB6
	RS				PA7
	WR				PA5
	RD				PA4
	DB0				PC3
	DB1				PC4
	DB2				PC5
	DB3				PC6
	DB4				PC7
	DB5				PC8
	DB6				PC9
	DB7				PC10
	T_RST			---
	T_INT			PB5
	T_SCL			PB0		
	T_SDA			PB1

代码说明

	LCD显示部分代码移植中景园代码, lcd.h 文件中包含 颜色填充 画点/线/矩形/圆形  显示汉字(需要自行取模)  图片等函数,用户可根据自己需要自行调用
	
	显示汉字部分数组在 lcdfont.h 文件中  图片在 image.h 中  用户可自行研究移植
	
	由于触摸芯片资料过少,但通过测试之后仍然编写有  手势判断  ,  触摸判断  ,  初始化检测  ,  触摸事件以及触摸的  X  Y  轴坐标,坐标原点位于显示器左上角,以上功能已经可以实现大部分触摸功能，由于资料过少更多功能需用户自行研究
	
代码功能
	
	以上代码示例仅供测试，并未使用中断检测等功能,向上/下/左/右四个方向滑动屏幕会显示对应方向箭头，长按屏幕正中间会到LOGO主界面







