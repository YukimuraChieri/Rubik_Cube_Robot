/**
  ******************************************************************************
  * @file    wdg.c
  * @author  朱韬亮
  * @version V1.0
  * @date    2020-5-17
  * @brief   此文件提供窗口看门狗功能
  ******************************************************************************
	*/

/* Includes ------------------------------------------------------------------*/
#include "wdg.h"	  

//保存WWDG计数器的设置值,默认为最大.
u8 WWDG_CNT=0x7f;
//触发看门狗计数值 
u8 count = 0;


/**
  * @brief :初始化窗口看门狗
	* @param :tr   :T[6:0],计数器值 
						wr   :W[6:0],窗口值 
						fprer:分频系数（WDGTB）,仅最低2位有效 
  * @note  :Fwwdg=PCLK1/(4096*2^fprer).
  * @retval:无
  */
void WWDG_Init(u8 tr,u8 wr,u8 fprer) 
{    
	RCC->APB1ENR|=1<<11; 		//使能wwdg时钟 
	WWDG_CNT=tr&WWDG_CNT;   //初始化WWDG_CNT.     
	WWDG->CFR|=fprer<<7;    //PCLK1/4096再除2^fprer 
	WWDG->CFR&=0XFF80;      
	WWDG->CFR|=wr;     			//设定窗口值      
	WWDG->CR|=WWDG_CNT; 		//设定计数器值 
	WWDG->CR|=1<<7;  				//开启看门狗      
	MY_NVIC_Init(0,0,WWDG_IRQn,2);//抢占0，子优先级0，组2     
	WWDG->SR=0X00; 					//清除提前唤醒中断标志位 
	WWDG->CFR|=1<<9;        //使能提前唤醒中断 
} 


/**
  * @brief :重设置WWDG计数器的值 
	* @param :val:重设值
  * @note  :无
  * @retval:无
  */
void WWDG_Set_Counter(u8 val) 
{ 
	WWDG->CR =(val&0x7F);//重设置7位计数器 
} 


/**
  * @brief :喂窗口看门狗
  * @param :无
  * @note  :无
  * @retval:无
  */
void WWDG_Feed(void)
{
	count=0;
	WWDG_Set_Counter(0x7f);				   
}


/**
  * @brief :窗口看门狗中断服务函数
  * @param :无
  * @note  :无
  * @retval:无
  */
void WWDG_IRQHandler(void) 
{
	if(count<3)
	{
		WWDG_Set_Counter(WWDG_CNT);//重设窗口看门狗的值!
		WWDG->SR=0X00;//清除提前唤醒中断标志位 
		count++;
	}
	else
	{
//		Write_State(&handle);		//写入复位前状态
	}
}

/********************************END OF FILE**********************************/





