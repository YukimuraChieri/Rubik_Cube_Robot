#ifndef __LED_H
#define __LED_H
#include "sys.h"

#define LED PCout(13)		// ����LED
#define LED1 PAout(9)		// ���LED��

////ռ�ձ�
//#define LED_CH2_PWM TIM3->CCR2

void LED_Init(void);		// ����LED�����LED��ʼ������
void TIM2_Int_Init(u16 arr,u16 psc);		// ��ʱ��2�жϳ�ʼ������
void TIM3_Int_Init(u16 arr,u16 psc);		// ��ʱ��3�жϳ�ʼ������
void Soft_PWM_Init(u16 freq, float dutyCycle);	// ���PWM��ʼ������
void SetLight(u16 light);		// �������LED���Ⱥ���

#endif

