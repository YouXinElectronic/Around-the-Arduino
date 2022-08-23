#include "pbdata.h"


void delay(u32 nCount)
{
	for(;nCount!=0;nCount--);
}
void delay_ms(u16 a)
{
	u32 temp;
	SysTick->LOAD=9000*a;//���س�ֵ����Ϊ1ms��ʱ��
	SysTick->VAL=0x00;//��յ�ǰֵ�Ĵ�������ռ�����
	SysTick->CTRL=0x01;//ʹ�ܣ�����0ʱ�޶����������ⲿʱ��Դ
	do
	{
		temp=SysTick->CTRL;//��ȡ��ǰ����ʱ��������ֵ
	}while((temp&0x01)&&(!(temp&(1<<16))));//�ȴ�ʱ�䵽����ȴ���־λ��0
	SysTick->CTRL=0x00;//�رռ�����
	SysTick->VAL=0x00;//��ռ�����
}

void delay_us(u32 nCount)//us����ʱ
{
	while(nCount--)
	{
	u32 temp;
	SysTick->LOAD=9;//���س�ֵ����Ϊ1ms��ʱ��
	SysTick->VAL=0x00;//��յ�ǰֵ�Ĵ�������ռ�����
	SysTick->CTRL=0x01;//ʹ�ܣ�����0ʱ�޶����������ⲿʱ��Դ
	do
	{
		temp=SysTick->CTRL;//��ȡ��ǰ����ʱ��������ֵ
	}while((temp&0x01)&&(!(temp&(1<<16))));//�ȴ�ʱ�䵽����ȴ���־λ��0
	SysTick->CTRL=0x00;//�رռ�����
	SysTick->VAL=0x00;//��ռ�����
	}
}

