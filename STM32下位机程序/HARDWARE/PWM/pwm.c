#include "pwm.h"

u8 servoRun = 0;		// �������״̬
u8 leftAngle = 0;		// ������ǰ�Ƕ�
u8 rightAngle = 0;	// �Ҷ����ǰ�Ƕ�
u8 setLeft = 0;			// �����趨�Ƕ�
u8 setRight = 0;		// �Ҷ���趨�Ƕ�
u8 servoFinish = 0;	// ������״̬
u8 servo_speed = 4;	// ����н��ٶ�

void TIM4_PWM_Init(u16 arr,u16 psc)
{
	//�˲������ֶ��޸�IO������
	RCC->APB1ENR|=1<<2; 		//TIM4ʱ��ʹ��    
	RCC->APB2ENR|=1<<3;    	//ʹ��PORTBʱ�� 	 
	GPIOB->CRL&=0X00FFFFFF;	//PB6/7���
	GPIOB->CRL|=0XBB000000;	//���ù������

	TIM4->ARR=arr;			//�趨�������Զ���װֵ 
	TIM4->PSC=psc;			//Ԥ��Ƶ����Ƶ��
//	TIM4->DIER|=1<<0;		//��������ж�
	
	TIM4->CCMR1|=7<<4;  	//CH1 PWM2ģʽ		 
	TIM4->CCMR1|=1<<3; 		//CH1 Ԥװ��ʹ��
	TIM4->CCER|=1<<1;   	//OC1 �������
	TIM4->CCER|=1<<0;			//OC1 ���ʹ��	 

	TIM4->CCMR1|=7<<12;		//CH2 PWM2ģʽ		 
	TIM4->CCMR1|=1<<11;		//CH2 Ԥװ��ʹ��	   
	TIM4->CCER|=1<<5;   	//OC2 �������
	TIM4->CCER|=1<<4;			//OC2 ���ʹ��
	
	TIM4->CR1=0x0080;   //ARPEʹ�� 
	TIM4->CR1|=0x01;    //ʹ�ܶ�ʱ��4
	
	CH1_PWM_VAL = Angle_to_PWM(0);	//��ʼ���Ҷ��PWMռ�ձ�
	CH2_PWM_VAL = Angle_to_PWM(0);	//��ʼ������PWMռ�ձ�
	
	MY_NVIC_Init(1,2,TIM4_IRQn,2);		//��ռ1�������ȼ�2����2
}

//�Ƕ�ֵת��ΪPWM�Ƚ�ֵ��������180�ȶ�� ��
u16 Angle_to_PWM(u16 angle)
{
	angle = angle * 4 + 180;
	
	return 7200 - angle;
}


//���ö���ǶȺ���
void Set_Angle(u8 angle, char dir)
{
	switch(dir)
	{
		case 'A':	setLeft = angle;	break;
		case 'B':	setRight = angle;	break;
	}
	
	if(setLeft != leftAngle || setRight != rightAngle)
	{
		TIM4->DIER |= 1<<0;	// ��������ж�
		servoRun = 1;				// �������״̬��1
	}
	else
		servoFinish = 1;				// ������״̬��1
}


// ��ȡ���������״̬
u8 Get_Servo_Status(void)
{
	return servoRun;		// ���ض������״̬
}


// ��ȡ��������״̬
u8 Get_Servo_Finish(void)
{
	u8 temp = servoFinish;
	
	servoFinish = 0;
	
	return temp;		// ���ض�����״̬
}


// ���ö���ٶ�
void Set_Servo_Speed(u8 speed)
{
	servo_speed = speed;
}


// ��ʱ��4�жϷ�����
void TIM4_IRQHandler(void)
{
	if(TIM4->SR&0X0001)	//����ж�
	{
		if(leftAngle < setLeft)	// ����С���趨�Ƕ�
		{
			leftAngle += (setLeft - leftAngle)/servo_speed + 1;
			CH2_PWM_VAL = Angle_to_PWM(leftAngle);
		}
		else if(leftAngle > setLeft)	// ���������趨�Ƕ�
		{
			leftAngle -= (leftAngle - setLeft)/servo_speed + 1;
			CH2_PWM_VAL = Angle_to_PWM(leftAngle);
		}
		
		if(rightAngle < setRight)	// �Ҷ��С���趨�Ƕ�
		{
			rightAngle += (setRight - rightAngle)/servo_speed + 1;
			CH1_PWM_VAL = Angle_to_PWM(rightAngle);
		}
		else if(rightAngle > setRight)	// �Ҷ�������趨�Ƕ�
		{
			rightAngle -= (rightAngle - setRight)/servo_speed + 1;
			CH1_PWM_VAL = Angle_to_PWM(rightAngle);
		}
		
		if(leftAngle == setLeft && rightAngle == setRight)	// ������Ҷ�����ﵽ�趨�Ƕ�
		{
			servoRun = 0;						// �������״̬��0
			servoFinish = 1;				// ������״̬��1
			TIM4->DIER &= ~(1<<0);	// �ر��ж�
		}
		
		TIM4->SR&=~(1<<0);	//����жϱ�־λ
	}
}
