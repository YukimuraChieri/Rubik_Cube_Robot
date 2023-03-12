#include "sys.h"
//#include "usart.h"		
#include "delay.h"
#include "step_motor.h"
#include "usb_lib.h"
#include "hw_config.h"
#include "usb_pwr.h"
#include "led.h"
#include "pwm.h"
#include "protocol.h"
#include "wdg.h"


//Main Body
int main(void)
{
	u16 len;
	u8 usbstatus=0;				// usb状态变量
	CMD_Typedef cmd;			// 指令变量
	u8 pre_brkFlag = 0;		// 上一次的刹车状态
	
	Stm32_Clock_Init(9);		// 系统时钟设置
	delay_init(72);					// 延时初始化
	LED_Init();							// LED初始化
	
	Step_Init();						// 步进电机初始化函数
	
	TIM4_PWM_Init(7199,199);	// PWM频率=72M/((7199+1)*(199+1))=50Hz
	Soft_PWM_Init(100, 0);		// 软件PWM初始化
	
	CMD_Init();				// 指令队列初始化
	Robot_Init();			// 机器人状态初始化
	
	delay_ms(100);
	USB_Port_Set(0); 	// USB先断开
	delay_ms(700);
	USB_Port_Set(1);	// USB再次连接
 	Set_USBClock();   
 	USB_Interrupts_Config();    
 	USB_Init();				// 初始化USB
	
	// 初始化窗口看门狗
	WWDG_Init(0X7F,0X7F,3);	// 计数器值为7f,窗口寄存器为7f,分频数为8,溢出时间为58.254ms
	
	while(1)
	{
		/*********************************************************************USB连接状态处理****/
		if(usbstatus != bDeviceState)	// USB连接状态发生了改变.
		{
			usbstatus = bDeviceState;		// 记录新的状态
			if(usbstatus == CONFIGURED)
				LED = 0;	// 提示USB连接成功
			else
				LED = 1;	// 提示USB连接断开
		}
		
		
		/*********************************************************************刹车复位处理****/
		BRK_Reset_Proc();		// 刹车复位处理函数
		
		if(pre_brkFlag == 0 && brkFlag == 1)
		{
//			usb_printf("ALM_ON\r\n");		// USB发送急停开关按下信息
			CMD_Init();									// 初始化指令队列
			Robot_Init();								// 初始化机器人状态
			
			Set_Angle(0, 'A');					// 左舵机复位
			Set_Angle(0, 'B');					// 右舵机复位
		}
//		else if(pre_brkFlag == 1 && brkFlag == 0)
//		{
//			usb_printf("ALM_OFF\r\n");	// USB发送急停开关复位信息
//		}
		
		pre_brkFlag = brkFlag;
		
		
		/*********************************************************************USB数据接收处理****/
		if(USB_USART_RX_STA&0x8000)				// 接收到USB数据
		{
			if(brkFlag == 0)
			{
				len = USB_USART_RX_STA&0x3FFF;	// 获取此次接收到的数据长度
				
				cmd = Proc_CMD((char*)USB_USART_RX_BUF, len);		// 解析指令
				
				if(cmd != CMD_Error)				// 指令无错误
				{
					if(!Write_CMD_Fifo(cmd))	// 将读取数据写入执行队列
						usb_printf("BUSY\r\n");	// 写入失败（指令队列已满），应答BUSY
				}
				else
					usb_printf("Receive Error\r\n");	// 发送接收错误标志
			}
			else
			{
				usb_printf("ALM_ON\r\n");		// USB发送急停开关按下信息
			}
			
			USB_USART_RX_STA = 0;		// 清空读取标志
		}
		
		/*********************************************************************指令队列执行处理****/
		if(Get_Fifo_Len() > 0)		// 如果指令队列非空
		{
			// 系统空闲且急停开关未按下
			if(Get_Step_Status() == 0 && Get_Servo_Status() == 0 && brkFlag == 0)
			{
				if(Read_CMD_Fifo(&cmd) == 1)	// 从指令队列取出一条指令
				{
					if(Robot_Update(cmd))				// 机器人状态更新
					{
						usb_printf("ILLegal Operation\r\n");	// 发送状态错误标志
					}
					else												// 状态更新正确
					{
						switch(cmd)								// 执行指令
						{
							case CMD_A0:			Set_Angle(0, 'A');		break;	// 左夹爪松开
							case CMD_B0:			Set_Angle(0, 'B');		break;	// 右夹爪松开
							case CMD_AH:			Set_Angle(77, 'A');		break;	// 左夹爪半松
							case CMD_BH:			Set_Angle(73, 'B');		break;	// 右夹爪半松
							case CMD_A1:			Set_Angle(87, 'A');		break;	// 左夹爪夹紧
							case CMD_B1:			Set_Angle(83, 'B');		break;	// 右夹爪夹紧
							case CMD_A:				Step_Rot_90(0, 'A');	break;	// 左电机顺时针旋转90度
							case CMD_B:				Step_Rot_90(0, 'B');	break;	// 右电机顺时针旋转90度
							case CMD_A_Inv:		Step_Rot_90(1, 'A');	break;	// 左电机逆时针旋转90度
							case CMD_B_Inv:		Step_Rot_90(1, 'B');	break;	// 右电机逆时针旋转90度
							case CMD_A2:			Step_Rot_180(0, 'A');	break;	// 左电机顺时针旋转180度
							case CMD_B2:			Step_Rot_180(0, 'B');	break;	// 右电机顺时针旋转180度
							case CMD_A2_Inv:	Step_Rot_180(1, 'A');	break;	// 左电机逆时针旋转180度
							case CMD_B2_Inv:	Step_Rot_180(1, 'B');	break;	// 右电机逆时针旋转180度
							case CMD_LED:			SetLight(led_light);					// LED灯亮度设置
																usb_printf("Finish\r\n");	break;	// 发送完成应答
							case CMD_HS:			usb_printf("Finish\r\n");	break;	// 发送完成应答
							case CMD_LS:			usb_printf("Finish\r\n");	break;	// 发送完成应答
							default:;
						}
					}
				}
			}
		}
		
		/*********************************************************************执行完成处理****/
		// 获取完成状态
		if(	Get_Step_Finish() || Get_Servo_Finish())
		{
			if(brkFlag == 0)
				usb_printf("Finish\r\n");	// 发送完成应答
		}
		
		WWDG_Feed();		// 喂狗
		
		delay_ms(1);		// 延时1ms
	}
}

