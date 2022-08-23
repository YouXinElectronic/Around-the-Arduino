#include "CST816.h"
#include "softIIC.h"

data_struct touch_data;

uint8_t init_CST816(void)
{
	uint8_t GET_CHIP_ID;
	
	GPIO_InitTypeDef  GPIO_InitStructure;
 	RCC_APB2PeriphClockCmd(INT_Pin_RCC, ENABLE);	 //使能端口时钟
	GPIO_InitStructure.GPIO_Pin = INT_Pin;	 
 	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU; 		 //上拉
 	GPIO_Init(INT_Pin_group, &GPIO_InitStructure);
 	GPIO_SetBits(INT_Pin_group,INT_Pin);
	
	soft_begin();
	soft_IIC_Start();
	soft_write_address(0,CST816Address);
	soft_write_Byte(REG_CHIP_ID);
	soft_IIC_Start();
  soft_write_address(1,CST816Address);
	soft_read_Byte(0);
  soft_read_Byte(0);
  soft_read_Byte(0);
  soft_read_Byte(0);
  GET_CHIP_ID = soft_read_Byte(1);
	soft_IIC_Stop();
	return GET_CHIP_ID == chipID;
}

uint8_t CST816_available(void)
{
	
	uint8_t touch_state = GPIO_ReadInputDataBit(INT_Pin_group,INT_Pin);
	if(touch_state == 0)
	{
		soft_IIC_Start();
		soft_write_address(0,CST816Address);
		soft_write_Byte(CST816_DATA);
		soft_IIC_Start();
		soft_write_address(1,CST816Address);
		touch_data.gestureID = soft_read_Byte(0);
		touch_data.points = soft_read_Byte(0);
		touch_data.event = soft_read_Byte(0);
		touch_data.x = soft_read_Byte(0);
		soft_read_Byte(0);
		touch_data.y = soft_read_Byte(1);
		soft_IIC_Stop();
	}
	return touch_state;
}


uint8_t CST816_Gesture(void)
{
	return touch_data.gestureID;
}

uint8_t CST816_points(void)
{
	return touch_data.points;
}

/* 触摸的事件（0 = 触摸时，手放上，1 = 触摸结束手离开，2 = 触摸中） */
uint8_t CST816_event(void)
{
	return touch_data.event/0x40;
}


uint8_t CST816_x(void)
{
	return (0xFF-touch_data.x);
}
uint8_t CST816_y(void)
{
	return touch_data.y;
}

