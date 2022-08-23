#ifndef _SOFTIIC_H_
#define _SOFTIIC_H_

#define SCL_1   GPIO_SetBits(Pin_group,SCL_Pin)
#define SCL_0   GPIO_ResetBits(Pin_group,SCL_Pin)
											 
#define SDA_1  GPIO_SetBits(Pin_group,SDA_Pin)
#define SDA_0	 GPIO_ResetBits(Pin_group,SDA_Pin)

#define read_SDA  GPIO_ReadInputDataBit(Pin_group,SDA_Pin)
									
/*����ʹ������*/				 
#define   SCL_Pin    GPIO_Pin_0
#define   SDA_Pin   GPIO_Pin_1

/*��������������*/
#define   Pin_group   GPIOB
										 
/*����ʹ�õ�ʱ��*/

#define   Pin_RCC   RCC_APB2Periph_GPIOD




/*��ʼ������IICʹ������*/
void soft_begin(void);

/*IIC��ʼ����*/
void soft_IIC_Start(void);

/*IIC��ֹ����*/
void soft_IIC_Stop(void);

/*��������Ӧ������0Ϊ��Ӧ������1Ϊδ��Ӧ*/
unsigned char soft_wait_ack(void);

/*�������0ΪӦ��1Ϊ��Ӧ��*/
void soft_ack(unsigned char S_Ack);

/*�������0Ϊд������1Ϊ������
����0Ϊ��������Ӧ���ݣ�����1Ϊδ��Ӧ*/
int soft_write_address(unsigned char R_W,unsigned char addr);

/*д��һ���ֽ�����*/
void soft_write_Byte(unsigned char LM75_DATA);

/*��ȡһ���ֽ�����
�������Ϊ0ʱ��ȡ�����ݽ�����Ӧ���������Ϊ1ʱ��ȡ�����ݲ�������Ӧ*/
int soft_read_Byte(unsigned char S_Ack);





#endif

