#ifndef __SERVO_H
#define __SERVO_H
#include "sys.h"

//通道1（CH1）：PBout(6)
//通道2（CH2）：PBout(7)

#define CH1 1
#define CH2 2

//占空比
#define CH1_PWM_VAL TIM4->CCR1
#define CH2_PWM_VAL TIM4->CCR2

//extern u8 servo_speed;	// 舵机夹紧速度

void TIM4_PWM_Init(u16 arr,u16 psc);	// 定时器4PWM输出初始化
u16 Angle_to_PWM(u16 angle);					// 角度值转换为PWM比较值（适用于180度舵机 ）
void Set_Angle(u8 angle, char dir);		// 设置舵机角度
u8 Get_Servo_Status(void);						// 获取舵机的运行状态
u8 Get_Servo_Finish(void);						// 获取舵机的完成状态
void Set_Servo_Speed(u8 speed);				// 设置舵机速度

#endif
