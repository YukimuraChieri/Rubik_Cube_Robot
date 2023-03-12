#include "protocol.h"
#include <string.h>

CMD_FIFO_t cmd_fifo;		// ����ָ����б���
RobotState_t robot;			// ���������״̬����
int led_light = 0;			// LED����ֵ

// ָ����г�ʼ������
void CMD_Init(void)
{
	memset(&cmd_fifo, 0x00, sizeof(cmd_fifo));		// ���ָ�����
}

// ������״̬��ʼ������
void Robot_Init(void)
{
	memset(&robot, 0x00, sizeof(robot));		// ��ʼ��������״̬
}


// ������״̬����
u8 Robot_Update(CMD_Typedef cmd)
{
	switch(cmd)
	{
		case CMD_A0:							// ��ۼ�צ�ɿ�
			robot.LeftHand = 0;			// ������ۼ�צ״̬
		break;
		
		case CMD_A1:							// ��ۼ�צ�н�
			robot.LeftHand = 1;			// ������ۼ�צ״̬
		break;
		
		case CMD_AH:							// ��ۼ�צ����
			robot.LeftHand = 2;			// ������ۼ�צ״̬
		break;
		
		case CMD_B0:							// �ұۼ�צ�ɿ�
			robot.RightHand = 0;		// �����ұۼ�צ״̬
		break;
		
		case CMD_B1:							// �ұۼ�צ�н�
			robot.RightHand = 1;		// �����ұۼ�צ״̬
		break;
		
		case CMD_BH:							// �ұۼ�צ����
			robot.RightHand = 2;		// �����ұۼ�צ״̬
		break;
		
		case CMD_A:								// ���˳ʱ����ת90��
			if(robot.RightArm != 0)	// �ұ�״̬��Ϊ0��
				return 1;							// ���ش���ֵ
			else
				robot.LeftArm = (robot.LeftArm + 90)%180;		// ������۽Ƕ�
		break;
		
		case CMD_A_Inv:						// �����ʱ����ת90��
			if(robot.RightArm != 0)	// �ұ�״̬��Ϊ0��
				return 1;							// ���ش���ֵ
			else
				robot.LeftArm = (robot.LeftArm - 90)%180;		// ������۽Ƕ�
		break;
			
		case CMD_B:								// �ұ�˳ʱ����ת90��
			if(robot.LeftArm != 0)	// ���״̬��Ϊ0��
				return 1;							// ���ش���ֵ
			else
				robot.RightArm = (robot.RightArm + 90)%180;	// �����ұ۽Ƕ�
		break;
			
		case CMD_B_Inv:						// �ұ���ʱ����ת90��
			if(robot.LeftArm != 0)	// ���״̬��Ϊ0��
				return 1;							// ���ش���ֵ
			else
				robot.RightArm = (robot.RightArm + 90)%180;	// �����ұ۽Ƕ�
		break;
			
		case CMD_A2:							// ���˳ʱ����ת180��
			if(robot.RightArm != 0)	// �ұ�״̬��Ϊ0��
				return 1;							// ���ش���ֵ
			else
				robot.LeftArm = (robot.LeftArm + 180)%180;	// ������۽Ƕ�
		break;
			
		case 	CMD_A2_Inv:					// �����ʱ����ת180��
			if(robot.RightArm != 0)	// �ұ�״̬��Ϊ0��
				return 1;							// ���ش���ֵ
			else
				robot.LeftArm = (robot.LeftArm - 180)%180;	// ������۽Ƕ�
		break;
		
		case CMD_B2:							// �ұ�˳ʱ����ת180��
			if(robot.LeftArm != 0)	// ���״̬��Ϊ0��
				return 1;							// ���ش���ֵ
			else
				robot.RightArm = (robot.RightArm + 180)%180;	// �����ұ۽Ƕ�
		break;
			
		case CMD_B2_Inv:					// �ұ���ʱ����ת180��
			if(robot.LeftArm != 0)	// ���״̬��Ϊ0��
				return 1;							// ���ش���ֵ
			else
				robot.RightArm = (robot.RightArm - 180)%180;	// �����ұ۽Ƕ�
		break;
			
		default:;
	}
	
	return 0;		// ������ɣ�������ȷֵ
}


// ��ȡħ������״̬
u8 Get_CubeLock_State(void)
{
	if(robot.LeftHand == 0 || robot.RightHand == 0)	
		return 0;	// ����0��ħ����ǰ����	
	
	return 1;		// ����1��ħ����ǰ����
}


// ��ȡ�ٶ�ģʽ
u8 Get_SpeedMode(void)
{
	return robot.SpeedMode;
}


// ����ָ��
CMD_Typedef Proc_CMD(char* data, u16 len)
{
	char str[7] = {0};
	
	if(len <= 6)
	{
		strncpy(str, data, len);	// ����ȡ���ݸ��Ƶ��ַ���str
		
		if(strcmp(str, "A0") == 0)
		{
			return CMD_A0;
		}
		else if(strcmp(str, "A1") == 0)
		{
			return CMD_A1;
		}
		else if(strcmp(str, "AH") == 0)
		{
			return CMD_AH;
		}
		else if(strcmp(str, "B0") == 0)
		{
			return CMD_B0;
		}
		else if(strcmp(str, "B1") == 0)
		{
			return CMD_B1;
		}
		else if(strcmp(str, "BH") == 0)
		{
			return CMD_BH;
		}
		else if(strcmp(str, "A+") == 0)
		{
			return CMD_A;
		}
		else if(strcmp(str, "A-") == 0)
		{
			return CMD_A_Inv;
		}
		else if(strcmp(str, "A++") == 0)
		{
			return CMD_A2;
		}
		else if(strcmp(str, "B+") == 0)
		{
			return CMD_B;
		}
		else if(strcmp(str, "B-") == 0)
		{
			return CMD_B_Inv;
		}
		else if(strcmp(str, "B++") == 0)
		{
			return CMD_B2;
		}
		else if(strcmp(str, "A--") == 0)
		{
			return CMD_A2_Inv;
		}
		else if(strcmp(str, "B--") == 0)
		{
			return CMD_B2_Inv;
		}
		else if(strncmp(str, "LED", 3) == 0)
		{
			led_light = atoi(str+3);
			if(led_light > 100)
				led_light = 100;
			else if(led_light < 0)
				led_light = 0;
			
			return CMD_LED;
		}
		else if(strcmp(str, "LS") == 0)
		{
			robot.SpeedMode = 0;		// ����ģʽ
			Set_Servo_Speed(4);			// ���ö���ٶ�
			return CMD_LS;
		}
		else if(strcmp(str, "HS") == 0)
		{
			robot.SpeedMode = 1;		// ����ģʽ
			Set_Servo_Speed(3);			// ���ö���ٶ�
			return CMD_HS;
		}
	}
	
	return CMD_Error;		// ���ش���ָ��
}


// д��ָ�����
u8 Write_CMD_Fifo(CMD_Typedef cmd)
{
	if(cmd_fifo.length < CMD_BUF_SIZE)
	{
		cmd_fifo.buff[cmd_fifo.tail] = cmd;		// ָ�����ָ�����
		cmd_fifo.tail = (cmd_fifo.tail+1)%CMD_BUF_SIZE;		// βָ��ѭ����1
		cmd_fifo.length++;		// ���峤�ȼ�1
		return 1;			// д��ɹ�������1
	}
	else
		return 0;			// д��ʧ�ܣ�����0
}
	
// ��ȡָ�����
u8 Read_CMD_Fifo(CMD_Typedef* cmd)
{
	if(cmd_fifo.length > 0)
	{
		*cmd = cmd_fifo.buff[cmd_fifo.head];		// ��������
		cmd_fifo.head = (cmd_fifo.head+1)%CMD_BUF_SIZE;		// ��ָ��ѭ����1
		cmd_fifo.length--;		// ���峤�ȼ�1
		return 1;		// �����ɹ�������1
	}
	else
		return 0;		// ����ʧ�ܣ�����0	
}


// ��ȡָ����г���
u16 Get_Fifo_Len(void)
{
	return cmd_fifo.length;		// ����ָ����г���
}












