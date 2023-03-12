/**
  ******************************************************************************
  * @file    wdg.c
  * @author  �����
  * @version V1.0
  * @date    2020-5-17
  * @brief   ���ļ��ṩ���ڿ��Ź�����
  ******************************************************************************
	*/

/* Includes ------------------------------------------------------------------*/
#include "wdg.h"	  

//����WWDG������������ֵ,Ĭ��Ϊ���.
u8 WWDG_CNT=0x7f;
//�������Ź�����ֵ 
u8 count = 0;


/**
  * @brief :��ʼ�����ڿ��Ź�
	* @param :tr   :T[6:0],������ֵ 
						wr   :W[6:0],����ֵ 
						fprer:��Ƶϵ����WDGTB��,�����2λ��Ч 
  * @note  :Fwwdg=PCLK1/(4096*2^fprer).
  * @retval:��
  */
void WWDG_Init(u8 tr,u8 wr,u8 fprer) 
{    
	RCC->APB1ENR|=1<<11; 		//ʹ��wwdgʱ�� 
	WWDG_CNT=tr&WWDG_CNT;   //��ʼ��WWDG_CNT.     
	WWDG->CFR|=fprer<<7;    //PCLK1/4096�ٳ�2^fprer 
	WWDG->CFR&=0XFF80;      
	WWDG->CFR|=wr;     			//�趨����ֵ      
	WWDG->CR|=WWDG_CNT; 		//�趨������ֵ 
	WWDG->CR|=1<<7;  				//�������Ź�      
	MY_NVIC_Init(0,0,WWDG_IRQn,2);//��ռ0�������ȼ�0����2     
	WWDG->SR=0X00; 					//�����ǰ�����жϱ�־λ 
	WWDG->CFR|=1<<9;        //ʹ����ǰ�����ж� 
} 


/**
  * @brief :������WWDG��������ֵ 
	* @param :val:����ֵ
  * @note  :��
  * @retval:��
  */
void WWDG_Set_Counter(u8 val) 
{ 
	WWDG->CR =(val&0x7F);//������7λ������ 
} 


/**
  * @brief :ι���ڿ��Ź�
  * @param :��
  * @note  :��
  * @retval:��
  */
void WWDG_Feed(void)
{
	count=0;
	WWDG_Set_Counter(0x7f);				   
}


/**
  * @brief :���ڿ��Ź��жϷ�����
  * @param :��
  * @note  :��
  * @retval:��
  */
void WWDG_IRQHandler(void) 
{
	if(count<3)
	{
		WWDG_Set_Counter(WWDG_CNT);//���贰�ڿ��Ź���ֵ!
		WWDG->SR=0X00;//�����ǰ�����жϱ�־λ 
		count++;
	}
	else
	{
//		Write_State(&handle);		//д�븴λǰ״̬
	}
}

/********************************END OF FILE**********************************/





