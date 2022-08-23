#include "softIIC.h"
#include "pbdata.h"


void soft_SDA_OUT(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Pin=SDA_Pin;
 	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_Out_PP;   //设置IO口为开漏输出模式*/ 
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(Pin_group,  &GPIO_InitStructure);
	SDA_1;
}

void soft_SDA_IN(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Pin=SDA_Pin;
 	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_IPU;   //设置IO口为开漏输出模式*/ 
	GPIO_Init(Pin_group,  &GPIO_InitStructure);
	SDA_1;
}

void soft_begin(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Pin=SCL_Pin|SDA_Pin;
 	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_Out_PP;   
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init( Pin_group,  &GPIO_InitStructure);
	SCL_1;
	SDA_1;
}

void soft_IIC_Start(void)
{
	soft_SDA_OUT();
	delay_us(10);
	SCL_0;
	//延时10us左右
	delay_us(10);
	SDA_1;
	delay_us(10);
	SCL_1;
	delay_us(10);
	SDA_0;
	delay_us(10);
	SCL_0;
}

void soft_IIC_Stop(void)
{
	soft_SDA_OUT();
	delay_us(10);
	SCL_0;
	delay_us(10);
	SDA_0;
	delay_us(10);
	SCL_1;
	delay_us(10);
	SDA_1;
	delay_us(10);
	SCL_0;
}

unsigned char soft_wait_ack(void)
{
	unsigned char state=1;
	soft_SDA_IN();
	delay_us(10);
	SCL_0;
	delay_us(10);
	SDA_1;
	delay_us(10);
	SCL_1;
	delay_us(10);
	state=read_SDA;
	delay_us(10);
	SCL_0;
	return(state);
}

void soft_ack(unsigned char S_Ack)
{
	soft_SDA_OUT();
	delay_us(10);
	SCL_0;
	delay_us(10);
	if(S_Ack==0)
	{
		SDA_0;
	}
	else
	{
		SDA_1;
	}
	delay_us(10);
	SCL_1;
	delay_us(10);
	SCL_0;
}

int soft_write_address(unsigned char R_W,unsigned char addr)
{
	unsigned char write_IIC_address,i;
	soft_SDA_OUT();
	delay_us(10);
	SCL_0;
	delay_us(10);
	if(!R_W)
	{
		write_IIC_address=addr<<1;
	}
	else
	{
		write_IIC_address=(addr<<1)|0x01;
	}
	for(i=0;i<8;i++)
	{
		SCL_0;
		delay_us(10);
		if(write_IIC_address&0x80)
		{
			SDA_1;
		}
		else
		{
			SDA_0;
		}
		delay_us(10);
		SCL_1;
		delay_us(10);
		SCL_0;
		write_IIC_address<<=1;
		delay_us(10);
	}
	return(soft_wait_ack());
}

void soft_write_Byte(unsigned char soft_DATA)
{
	unsigned char i;
	soft_SDA_OUT();
	delay_us(10);
	SCL_0;
	delay_us(10);
	for(i=0;i<8;i++)
	{
		SCL_0;
		delay_us(10);
		if(soft_DATA&0x80)
		{
			SDA_1;
		}
		else
		{
			SDA_0;
		}
		delay_us(10);
		SCL_1;
		delay_us(10);
		soft_DATA<<=1;
	}
	SCL_0;
	delay_us(10);
	
	soft_wait_ack();
}

int soft_read_Byte(unsigned char S_Ack)
{
	int read_data=0x00;
	unsigned char i;
	soft_SDA_IN();
	delay_us(10);
	SCL_0;
	delay_us(10);
	SDA_1;
	delay_us(10);
	for(i=0;i<8;i++)
	{
		SCL_0;
		delay_us(10);
		SCL_1;
		delay_us(10);
		read_data<<=1;
		if(read_SDA)
		{
			read_data=read_data+1;
		}
	}
	SCL_0;
	if(S_Ack==0)
	{
		soft_ack(0);
	}
	else
	{
		soft_ack(1);
	}
	return(read_data);
}


