#ifndef __STEP_MOTOR_H
#define __STEP_MOTOR_H


#include "sys.h"
#include "delay.h"
#include "pwm.h"
#include "protocol.h"

// 旋转一周输出脉冲数
#define PulNum	1000

// 脉冲输出端口
#define PUL1 PBout(13)
#define ENA1 PAout(5)
#define DIR1 PAout(4)

#define PUL2 PBout(14)
#define ENA2 PBout(0)
#define DIR2 PAout(7)

#define BRK PBin(12)

extern u8 brkFlag;		// 刹车输入状态

void BRK_Reset_Proc(void);	// 刹车复位处理函数
void Step_Init(void);				// 步进电机初始化函数
void Step_Rot_90(u8 dir, char motor);		// 步进电机旋转90度函数
void Step_Rot_180(u8 dir, char motor);	// 步进电机旋转180度函数
u8 Get_Step_Status(void);		// 获取步进电机的运行状态
u8 Get_Step_Finish(void);		// 获取步进电机的完成状态


#endif

