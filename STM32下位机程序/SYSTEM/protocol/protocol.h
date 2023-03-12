#ifndef __PROTOCOL_H
#define __PROTOCOL_H

#include "sys.h"
#include "pwm.h"
#include <stdlib.h>

// ���������״̬
typedef struct
{
	short LeftArm;		// ��۵��
	short RightArm;		// �ұ۵��
	u8 LeftHand;		// ��ۼ�צ
	u8 RightHand;		// �ұۼ�צ
	u8 SpeedMode;		// �ٶ�ģʽ
}RobotState_t;

// ����ָ��ö�����Ͷ���
// A+ B+ A- B- A++ B++ A-- B-- A0 B0 A1 B1
typedef enum
{
	CMD_A0,				// ���צ�ɿ�
	CMD_AH,				// ���צ����
	CMD_A1,				// ���צ�н�
	CMD_B0,				// �Ҽ�צ�ɿ�
	CMD_BH,				// �Ҽ�צ����
	CMD_B1,				// �Ҽ�צ�н�
	CMD_A_Inv,		// ������ʱ����ת90��
	CMD_A,				// ����˳ʱ����ת90��
	CMD_B_Inv,		// �ҵ����ʱ����ת90��
	CMD_B,				// �ҵ��˳ʱ����ת90��
	CMD_A2,				// ����˳ʱ����ת180��
	CMD_B2,				// �ҵ��˳ʱ����ת180��
	CMD_A2_Inv,		// ������ʱ����ת180��
	CMD_B2_Inv,		// �ҵ����ʱ����ת180��
	CMD_LED,			// LED����ָ��
	CMD_LS,				// �ٶȿ���ָ�����
	CMD_HS,				// �ٶȿ���ָ�����
	CMD_Error,		// ����ָ��
}CMD_Typedef;

extern int led_light;	// LED����ֵ

// ָ�������󳤶�
#define CMD_BUF_SIZE	8

// ָ�����
typedef struct
{
	u8 head;								// ͷָ��
	u8 tail;								// βָ��
	u8 length;							// ���峤��
	CMD_Typedef buff[CMD_BUF_SIZE];	// ָ�����
} CMD_FIFO_t;


void CMD_Init(void);		// ָ����г�ʼ������
void Robot_Init(void);	// ������״̬��ʼ������
CMD_Typedef Proc_CMD(char* data, u16 len);	// ����ָ��
u8 Write_CMD_Fifo(CMD_Typedef cmd);		// д��ָ�����
u8 Read_CMD_Fifo(CMD_Typedef* cmd);		// ��ȡָ�����
u16 Get_Fifo_Len(void);			// ��ȡָ����г���
u8 Robot_Update(CMD_Typedef cmd);		// ������״̬����
u8 Get_CubeLock_State(void);		// ��ȡħ������״̬
u8 Get_SpeedMode(void);			// ��ȡ�ٶ�ģʽ


#endif




