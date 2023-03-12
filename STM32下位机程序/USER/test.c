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
	u8 usbstatus=0;				// usb״̬����
	CMD_Typedef cmd;			// ָ�����
	u8 pre_brkFlag = 0;		// ��һ�ε�ɲ��״̬
	
	Stm32_Clock_Init(9);		// ϵͳʱ������
	delay_init(72);					// ��ʱ��ʼ��
	LED_Init();							// LED��ʼ��
	
	Step_Init();						// ���������ʼ������
	
	TIM4_PWM_Init(7199,199);	// PWMƵ��=72M/((7199+1)*(199+1))=50Hz
	Soft_PWM_Init(100, 0);		// ���PWM��ʼ��
	
	CMD_Init();				// ָ����г�ʼ��
	Robot_Init();			// ������״̬��ʼ��
	
	delay_ms(100);
	USB_Port_Set(0); 	// USB�ȶϿ�
	delay_ms(700);
	USB_Port_Set(1);	// USB�ٴ�����
 	Set_USBClock();   
 	USB_Interrupts_Config();    
 	USB_Init();				// ��ʼ��USB
	
	// ��ʼ�����ڿ��Ź�
	WWDG_Init(0X7F,0X7F,3);	// ������ֵΪ7f,���ڼĴ���Ϊ7f,��Ƶ��Ϊ8,���ʱ��Ϊ58.254ms
	
	while(1)
	{
		/*********************************************************************USB����״̬����****/
		if(usbstatus != bDeviceState)	// USB����״̬�����˸ı�.
		{
			usbstatus = bDeviceState;		// ��¼�µ�״̬
			if(usbstatus == CONFIGURED)
				LED = 0;	// ��ʾUSB���ӳɹ�
			else
				LED = 1;	// ��ʾUSB���ӶϿ�
		}
		
		
		/*********************************************************************ɲ����λ����****/
		BRK_Reset_Proc();		// ɲ����λ������
		
		if(pre_brkFlag == 0 && brkFlag == 1)
		{
//			usb_printf("ALM_ON\r\n");		// USB���ͼ�ͣ���ذ�����Ϣ
			CMD_Init();									// ��ʼ��ָ�����
			Robot_Init();								// ��ʼ��������״̬
			
			Set_Angle(0, 'A');					// ������λ
			Set_Angle(0, 'B');					// �Ҷ����λ
		}
//		else if(pre_brkFlag == 1 && brkFlag == 0)
//		{
//			usb_printf("ALM_OFF\r\n");	// USB���ͼ�ͣ���ظ�λ��Ϣ
//		}
		
		pre_brkFlag = brkFlag;
		
		
		/*********************************************************************USB���ݽ��մ���****/
		if(USB_USART_RX_STA&0x8000)				// ���յ�USB����
		{
			if(brkFlag == 0)
			{
				len = USB_USART_RX_STA&0x3FFF;	// ��ȡ�˴ν��յ������ݳ���
				
				cmd = Proc_CMD((char*)USB_USART_RX_BUF, len);		// ����ָ��
				
				if(cmd != CMD_Error)				// ָ���޴���
				{
					if(!Write_CMD_Fifo(cmd))	// ����ȡ����д��ִ�ж���
						usb_printf("BUSY\r\n");	// д��ʧ�ܣ�ָ�������������Ӧ��BUSY
				}
				else
					usb_printf("Receive Error\r\n");	// ���ͽ��մ����־
			}
			else
			{
				usb_printf("ALM_ON\r\n");		// USB���ͼ�ͣ���ذ�����Ϣ
			}
			
			USB_USART_RX_STA = 0;		// ��ն�ȡ��־
		}
		
		/*********************************************************************ָ�����ִ�д���****/
		if(Get_Fifo_Len() > 0)		// ���ָ����зǿ�
		{
			// ϵͳ�����Ҽ�ͣ����δ����
			if(Get_Step_Status() == 0 && Get_Servo_Status() == 0 && brkFlag == 0)
			{
				if(Read_CMD_Fifo(&cmd) == 1)	// ��ָ�����ȡ��һ��ָ��
				{
					if(Robot_Update(cmd))				// ������״̬����
					{
						usb_printf("ILLegal Operation\r\n");	// ����״̬�����־
					}
					else												// ״̬������ȷ
					{
						switch(cmd)								// ִ��ָ��
						{
							case CMD_A0:			Set_Angle(0, 'A');		break;	// ���צ�ɿ�
							case CMD_B0:			Set_Angle(0, 'B');		break;	// �Ҽ�צ�ɿ�
							case CMD_AH:			Set_Angle(77, 'A');		break;	// ���צ����
							case CMD_BH:			Set_Angle(73, 'B');		break;	// �Ҽ�צ����
							case CMD_A1:			Set_Angle(87, 'A');		break;	// ���צ�н�
							case CMD_B1:			Set_Angle(83, 'B');		break;	// �Ҽ�צ�н�
							case CMD_A:				Step_Rot_90(0, 'A');	break;	// ����˳ʱ����ת90��
							case CMD_B:				Step_Rot_90(0, 'B');	break;	// �ҵ��˳ʱ����ת90��
							case CMD_A_Inv:		Step_Rot_90(1, 'A');	break;	// ������ʱ����ת90��
							case CMD_B_Inv:		Step_Rot_90(1, 'B');	break;	// �ҵ����ʱ����ת90��
							case CMD_A2:			Step_Rot_180(0, 'A');	break;	// ����˳ʱ����ת180��
							case CMD_B2:			Step_Rot_180(0, 'B');	break;	// �ҵ��˳ʱ����ת180��
							case CMD_A2_Inv:	Step_Rot_180(1, 'A');	break;	// ������ʱ����ת180��
							case CMD_B2_Inv:	Step_Rot_180(1, 'B');	break;	// �ҵ����ʱ����ת180��
							case CMD_LED:			SetLight(led_light);					// LED����������
																usb_printf("Finish\r\n");	break;	// �������Ӧ��
							case CMD_HS:			usb_printf("Finish\r\n");	break;	// �������Ӧ��
							case CMD_LS:			usb_printf("Finish\r\n");	break;	// �������Ӧ��
							default:;
						}
					}
				}
			}
		}
		
		/*********************************************************************ִ����ɴ���****/
		// ��ȡ���״̬
		if(	Get_Step_Finish() || Get_Servo_Finish())
		{
			if(brkFlag == 0)
				usb_printf("Finish\r\n");	// �������Ӧ��
		}
		
		WWDG_Feed();		// ι��
		
		delay_ms(1);		// ��ʱ1ms
	}
}

