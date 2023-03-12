#include "protocol.h"
#include <string.h>

CMD_FIFO_t cmd_fifo;		// 定义指令队列变量
RobotState_t robot;			// 定义机器人状态变量
int led_light = 0;			// LED亮度值

// 指令队列初始化函数
void CMD_Init(void)
{
	memset(&cmd_fifo, 0x00, sizeof(cmd_fifo));		// 清空指令队列
}

// 机器人状态初始化函数
void Robot_Init(void)
{
	memset(&robot, 0x00, sizeof(robot));		// 初始化机器人状态
}


// 机器人状态更新
u8 Robot_Update(CMD_Typedef cmd)
{
	switch(cmd)
	{
		case CMD_A0:							// 左臂夹爪松开
			robot.LeftHand = 0;			// 更新左臂夹爪状态
		break;
		
		case CMD_A1:							// 左臂夹爪夹紧
			robot.LeftHand = 1;			// 更新左臂夹爪状态
		break;
		
		case CMD_AH:							// 左臂夹爪半松
			robot.LeftHand = 2;			// 更新左臂夹爪状态
		break;
		
		case CMD_B0:							// 右臂夹爪松开
			robot.RightHand = 0;		// 更新右臂夹爪状态
		break;
		
		case CMD_B1:							// 右臂夹爪夹紧
			robot.RightHand = 1;		// 更新右臂夹爪状态
		break;
		
		case CMD_BH:							// 右臂夹爪半松
			robot.RightHand = 2;		// 更新右臂夹爪状态
		break;
		
		case CMD_A:								// 左臂顺时针旋转90度
			if(robot.RightArm != 0)	// 右臂状态不为0度
				return 1;							// 返回错误值
			else
				robot.LeftArm = (robot.LeftArm + 90)%180;		// 更新左臂角度
		break;
		
		case CMD_A_Inv:						// 左臂逆时针旋转90度
			if(robot.RightArm != 0)	// 右臂状态不为0度
				return 1;							// 返回错误值
			else
				robot.LeftArm = (robot.LeftArm - 90)%180;		// 更新左臂角度
		break;
			
		case CMD_B:								// 右臂顺时针旋转90度
			if(robot.LeftArm != 0)	// 左臂状态不为0度
				return 1;							// 返回错误值
			else
				robot.RightArm = (robot.RightArm + 90)%180;	// 更新右臂角度
		break;
			
		case CMD_B_Inv:						// 右臂逆时针旋转90度
			if(robot.LeftArm != 0)	// 左臂状态不为0度
				return 1;							// 返回错误值
			else
				robot.RightArm = (robot.RightArm + 90)%180;	// 更新右臂角度
		break;
			
		case CMD_A2:							// 左臂顺时针旋转180度
			if(robot.RightArm != 0)	// 右臂状态不为0度
				return 1;							// 返回错误值
			else
				robot.LeftArm = (robot.LeftArm + 180)%180;	// 更新左臂角度
		break;
			
		case 	CMD_A2_Inv:					// 左臂逆时针旋转180度
			if(robot.RightArm != 0)	// 右臂状态不为0度
				return 1;							// 返回错误值
			else
				robot.LeftArm = (robot.LeftArm - 180)%180;	// 更新左臂角度
		break;
		
		case CMD_B2:							// 右臂顺时针旋转180度
			if(robot.LeftArm != 0)	// 左臂状态不为0度
				return 1;							// 返回错误值
			else
				robot.RightArm = (robot.RightArm + 180)%180;	// 更新右臂角度
		break;
			
		case CMD_B2_Inv:					// 右臂逆时针旋转180度
			if(robot.LeftArm != 0)	// 左臂状态不为0度
				return 1;							// 返回错误值
			else
				robot.RightArm = (robot.RightArm - 180)%180;	// 更新右臂角度
		break;
			
		default:;
	}
	
	return 0;		// 更新完成，返回正确值
}


// 获取魔方闭锁状态
u8 Get_CubeLock_State(void)
{
	if(robot.LeftHand == 0 || robot.RightHand == 0)	
		return 0;	// 返回0，魔方当前开锁	
	
	return 1;		// 返回1，魔方当前闭锁
}


// 获取速度模式
u8 Get_SpeedMode(void)
{
	return robot.SpeedMode;
}


// 解析指令
CMD_Typedef Proc_CMD(char* data, u16 len)
{
	char str[7] = {0};
	
	if(len <= 6)
	{
		strncpy(str, data, len);	// 将读取数据复制到字符串str
		
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
			robot.SpeedMode = 0;		// 低速模式
			Set_Servo_Speed(4);			// 设置舵机速度
			return CMD_LS;
		}
		else if(strcmp(str, "HS") == 0)
		{
			robot.SpeedMode = 1;		// 高速模式
			Set_Servo_Speed(3);			// 设置舵机速度
			return CMD_HS;
		}
	}
	
	return CMD_Error;		// 返回错误指令
}


// 写入指令队列
u8 Write_CMD_Fifo(CMD_Typedef cmd)
{
	if(cmd_fifo.length < CMD_BUF_SIZE)
	{
		cmd_fifo.buff[cmd_fifo.tail] = cmd;		// 指令加入指令缓冲区
		cmd_fifo.tail = (cmd_fifo.tail+1)%CMD_BUF_SIZE;		// 尾指针循环加1
		cmd_fifo.length++;		// 缓冲长度加1
		return 1;			// 写入成功，返回1
	}
	else
		return 0;			// 写入失败，返回0
}
	
// 读取指令队列
u8 Read_CMD_Fifo(CMD_Typedef* cmd)
{
	if(cmd_fifo.length > 0)
	{
		*cmd = cmd_fifo.buff[cmd_fifo.head];		// 读出数据
		cmd_fifo.head = (cmd_fifo.head+1)%CMD_BUF_SIZE;		// 首指针循环加1
		cmd_fifo.length--;		// 缓冲长度减1
		return 1;		// 读出成功，返回1
	}
	else
		return 0;		// 读出失败，返回0	
}


// 获取指令队列长度
u16 Get_Fifo_Len(void)
{
	return cmd_fifo.length;		// 返回指令队列长度
}












