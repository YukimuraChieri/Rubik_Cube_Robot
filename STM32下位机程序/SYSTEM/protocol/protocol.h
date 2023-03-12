#ifndef __PROTOCOL_H
#define __PROTOCOL_H

#include "sys.h"
#include "pwm.h"
#include <stdlib.h>

// 定义机器人状态
typedef struct
{
	short LeftArm;		// 左臂电机
	short RightArm;		// 右臂电机
	u8 LeftHand;		// 左臂夹爪
	u8 RightHand;		// 右臂夹爪
	u8 SpeedMode;		// 速度模式
}RobotState_t;

// 动作指令枚举类型定义
// A+ B+ A- B- A++ B++ A-- B-- A0 B0 A1 B1
typedef enum
{
	CMD_A0,				// 左夹爪松开
	CMD_AH,				// 左夹爪半松
	CMD_A1,				// 左夹爪夹紧
	CMD_B0,				// 右夹爪松开
	CMD_BH,				// 右夹爪半松
	CMD_B1,				// 右夹爪夹紧
	CMD_A_Inv,		// 左电机逆时针旋转90度
	CMD_A,				// 左电机顺时针旋转90度
	CMD_B_Inv,		// 右电机逆时针旋转90度
	CMD_B,				// 右电机顺时针旋转90度
	CMD_A2,				// 左电机顺时针旋转180度
	CMD_B2,				// 右电机顺时针旋转180度
	CMD_A2_Inv,		// 左电机逆时针旋转180度
	CMD_B2_Inv,		// 右电机逆时针旋转180度
	CMD_LED,			// LED控制指令
	CMD_LS,				// 速度控制指令，低速
	CMD_HS,				// 速度控制指令，高速
	CMD_Error,		// 错误指令
}CMD_Typedef;

extern int led_light;	// LED亮度值

// 指令队列最大长度
#define CMD_BUF_SIZE	8

// 指令队列
typedef struct
{
	u8 head;								// 头指针
	u8 tail;								// 尾指针
	u8 length;							// 缓冲长度
	CMD_Typedef buff[CMD_BUF_SIZE];	// 指令缓冲区
} CMD_FIFO_t;


void CMD_Init(void);		// 指令队列初始化函数
void Robot_Init(void);	// 机器人状态初始化函数
CMD_Typedef Proc_CMD(char* data, u16 len);	// 解析指令
u8 Write_CMD_Fifo(CMD_Typedef cmd);		// 写入指令队列
u8 Read_CMD_Fifo(CMD_Typedef* cmd);		// 读取指令队列
u16 Get_Fifo_Len(void);			// 获取指令队列长度
u8 Robot_Update(CMD_Typedef cmd);		// 机器人状态更新
u8 Get_CubeLock_State(void);		// 获取魔方闭锁状态
u8 Get_SpeedMode(void);			// 获取速度模式


#endif




