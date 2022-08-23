#ifndef _SOFTIIC_H_
#define _SOFTIIC_H_

#define SCL_1   GPIO_SetBits(Pin_group,SCL_Pin)
#define SCL_0   GPIO_ResetBits(Pin_group,SCL_Pin)
											 
#define SDA_1  GPIO_SetBits(Pin_group,SDA_Pin)
#define SDA_0	 GPIO_ResetBits(Pin_group,SDA_Pin)

#define read_SDA  GPIO_ReadInputDataBit(Pin_group,SDA_Pin)
									
/*定义使用引脚*/				 
#define   SCL_Pin    GPIO_Pin_0
#define   SDA_Pin   GPIO_Pin_1

/*定义引脚所在组*/
#define   Pin_group   GPIOB
										 
/*定义使用的时钟*/

#define   Pin_RCC   RCC_APB2Periph_GPIOD




/*初始化配置IIC使用引脚*/
void soft_begin(void);

/*IIC起始函数*/
void soft_IIC_Start(void);

/*IIC终止函数*/
void soft_IIC_Stop(void);

/*从器件响应，返回0为响应，返回1为未响应*/
unsigned char soft_wait_ack(void);

/*输入参数0为应答，1为非应答*/
void soft_ack(unsigned char S_Ack);

/*输入参数0为写操作，1为读操作
返回0为从器件响应数据，返回1为未响应*/
int soft_write_address(unsigned char R_W,unsigned char addr);

/*写入一个字节数据*/
void soft_write_Byte(unsigned char LM75_DATA);

/*读取一个字节数据
输入参数为0时读取完数据进行响应，输入参数为1时读取完数据不进行响应*/
int soft_read_Byte(unsigned char S_Ack);





#endif

