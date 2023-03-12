#include "led.h"


// ����LED��ʼ������
void LED_Init(void)
{
	RCC->APB2ENR|=1<<2;		//ʹ��PORTAʱ��
	RCC->APB2ENR|=1<<4;		//ʹ��PORTCʱ��
	
	GPIOA->CRH&=0XFFFFFF0F; 
	GPIOA->CRH|=0X00000030;//PA.9 �������
	
	GPIOC->CRH&=0XFF0FFFFF; 
	GPIOC->CRH|=0X00300000;//PC.13 �������   	 
	GPIOC->ODR|=1<<13;     //PC.13 �����
}

//ͨ�ö�ʱ��2�жϳ�ʼ��
//����ʱ��ѡ��ΪAPB1��2������APB1Ϊ36M
//arr���Զ���װֵ��
//psc��ʱ��Ԥ��Ƶ��
//����ʹ�õ��Ƕ�ʱ��2!
void TIM2_Int_Init(u16 arr,u16 psc)
{
	RCC->APB1ENR|=1<<0;	//TIM2ʱ��ʹ��    
 	TIM2->ARR=arr;  		//�趨�������Զ���װֵ
	TIM2->PSC=psc;  		//Ԥ��Ƶ��7200,�õ�10Khz�ļ���ʱ��		  
	TIM2->DIER|=1<<0;   //��������ж�
	TIM2->SR&=~(1<<0);	//����жϱ�־λ
  MY_NVIC_Init(3,3,TIM2_IRQn,2);	//��ռ3�������ȼ�3����2									 
}


//ͨ�ö�ʱ��3�жϳ�ʼ��
//����ʱ��ѡ��ΪAPB1��2������APB1Ϊ36M
//arr���Զ���װֵ��
//psc��ʱ��Ԥ��Ƶ��
//����ʹ�õ��Ƕ�ʱ��3!
void TIM3_Int_Init(u16 arr,u16 psc)
{
	RCC->APB1ENR|=1<<1;	//TIM3ʱ��ʹ��    
 	TIM3->ARR=arr;  		//�趨�������Զ���װֵ
	TIM3->PSC=psc;  		//Ԥ��Ƶ��7200,�õ�10Khz�ļ���ʱ��		  
	TIM3->DIER|=1<<0;   //��������ж�	 
//	TIM3->CR1|=0x01;    //ʹ�ܶ�ʱ��3	
	TIM3->SR&=~(1<<0);	//����жϱ�־λ
  MY_NVIC_Init(3,3,TIM3_IRQn,2);//��ռ3�������ȼ�3����2									 
}

//��ʱ��2�жϷ������	 
void TIM2_IRQHandler(void)
{ 		    		  			    
	if(TIM2->SR&0X0001)//����ж�
	{
		LED1 = 0;
		TIM2->CR1&=0xFE;	// �رն�ʱ��2
	}				   
	TIM2->SR&=~(1<<0);//����жϱ�־λ	
}

//��ʱ��3�жϷ������	 
void TIM3_IRQHandler(void)
{ 		    		  			    
	if(TIM3->SR&0X0001)//����ж�
	{
		LED1 = 1;
		TIM2->CR1|=0x01;    //ʹ�ܶ�ʱ��2
	}				   
	TIM3->SR&=~(1<<0);//����жϱ�־λ	
}


void Soft_PWM_Init(u16 freq, float dutyCycle)
{
	u16 arr1, arr2;
		
	arr1 = 10000/freq-1;
	arr2 = arr1*dutyCycle;
	
	if(arr2 >= arr1)	arr2 = arr1-1;
	if(arr2 == 0) 		arr2 = 1;
	
	TIM3_Int_Init(arr1, 7199);	//10Khz�ļ���Ƶ��
	TIM2_Int_Init(arr2, 7199);	//10Khz�ļ���Ƶ��
}

// ����LED���Ⱥ���
void SetLight(u16 dc)
{
	u16 arr1, arr2;
	
	while(TIM2->CR1&0x01);    //�ȴ���ʱ��2�ر�
	
	TIM3->CR1&=0xFE;	//�رն�ʱ��3
	TIM2->SR&=~(1<<0);	//����жϱ�־λ
	TIM3->SR&=~(1<<0);	//����жϱ�־λ
	
	if(dc > 0)
	{
		arr1 = TIM3->ARR;
		arr2 = arr1*((float)dc/100);
		
		if(arr2 >= arr1)	arr2 = arr1-1;
		if(arr2 == 0) 		arr2 = 1;
		
		TIM2->ARR = arr2;  		//�趨�������Զ���װֵ
		
		TIM3->CR1|=0x01;	//������ʱ��3
	}
}


