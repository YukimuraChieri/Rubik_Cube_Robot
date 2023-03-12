#ifndef __SERVO_H
#define __SERVO_H
#include "sys.h"

//ͨ��1��CH1����PBout(6)
//ͨ��2��CH2����PBout(7)

#define CH1 1
#define CH2 2

//ռ�ձ�
#define CH1_PWM_VAL TIM4->CCR1
#define CH2_PWM_VAL TIM4->CCR2

//extern u8 servo_speed;	// ����н��ٶ�

void TIM4_PWM_Init(u16 arr,u16 psc);	// ��ʱ��4PWM�����ʼ��
u16 Angle_to_PWM(u16 angle);					// �Ƕ�ֵת��ΪPWM�Ƚ�ֵ��������180�ȶ�� ��
void Set_Angle(u8 angle, char dir);		// ���ö���Ƕ�
u8 Get_Servo_Status(void);						// ��ȡ���������״̬
u8 Get_Servo_Finish(void);						// ��ȡ��������״̬
void Set_Servo_Speed(u8 speed);				// ���ö���ٶ�

#endif
