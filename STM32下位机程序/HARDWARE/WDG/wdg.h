/**
  ******************************************************************************
  * @file    wdg.h
  * @author  朱韬亮
  * @version V1.0
  * @date    2020-5-17
  * @brief   此文件提供窗口看门狗功能
  ******************************************************************************
	*/

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __WDG_H
#define __WDG_H

/* Includes ------------------------------------------------------------------*/
#include "sys.h"

void WWDG_Init(u8 tr,u8 wr,u8 fprer);		// WWDG初始化
void WWDG_Set_Counter(u8 val);					// 重设置WWDG计数器的值
void WWDG_Feed(void);										// 喂窗口看门狗
#endif

/********************************END OF FILE**********************************/




























