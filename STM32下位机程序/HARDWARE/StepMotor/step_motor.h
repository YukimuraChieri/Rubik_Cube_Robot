#ifndef __STEP_MOTOR_H
#define __STEP_MOTOR_H


#include "sys.h"
#include "delay.h"
#include "pwm.h"
#include "protocol.h"

// ��תһ�����������
#define PulNum	1000

// ��������˿�
#define PUL1 PBout(13)
#define ENA1 PAout(5)
#define DIR1 PAout(4)

#define PUL2 PBout(14)
#define ENA2 PBout(0)
#define DIR2 PAout(7)

#define BRK PBin(12)

extern u8 brkFlag;		// ɲ������״̬

void BRK_Reset_Proc(void);	// ɲ����λ������
void Step_Init(void);				// ���������ʼ������
void Step_Rot_90(u8 dir, char motor);		// ���������ת90�Ⱥ���
void Step_Rot_180(u8 dir, char motor);	// ���������ת180�Ⱥ���
u8 Get_Step_Status(void);		// ��ȡ�������������״̬
u8 Get_Step_Finish(void);		// ��ȡ������������״̬


#endif

