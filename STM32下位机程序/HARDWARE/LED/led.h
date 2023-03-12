#ifndef __LED_H
#define __LED_H
#include "sys.h"

#define LED PCout(13)		// 板载LED
#define LED1 PAout(9)		// 外接LED灯

////占空比
//#define LED_CH2_PWM TIM3->CCR2

void LED_Init(void);		// 板载LED和外接LED初始化函数
void TIM2_Int_Init(u16 arr,u16 psc);		// 定时器2中断初始化函数
void TIM3_Int_Init(u16 arr,u16 psc);		// 定时器3中断初始化函数
void Soft_PWM_Init(u16 freq, float dutyCycle);	// 软件PWM初始化函数
void SetLight(u16 light);		// 设置外接LED亮度函数

#endif

