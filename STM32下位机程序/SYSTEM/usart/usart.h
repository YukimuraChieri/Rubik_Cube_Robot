#ifndef __USART_H
#define __USART_H
#include "sys.h"
#include "stdio.h"	 
//////////////////////////////////////////////////////////////////////////////////	 
//������ֻ��ѧϰʹ�ã�δ��������ɣ��������������κ���;
//ALIENTEK STM32������
//����1��ʼ�����ʺ�STM32F10xϵ�У�		   
//����ԭ��@ALIENTEK
//������̳:www.openedv.com
//��������:2010/1/1
//�汾��V1.7
//��Ȩ���У�����ؾ���
//Copyright(C) ������������ӿƼ����޹�˾ 2009-2019
//All rights reserved
//********************************************************************************
//V1.3�޸�˵�� 
//֧����Ӧ��ͬƵ���µĴ��ڲ���������.
//�����˶�printf��֧��
//�����˴��ڽ��������.
//������printf��һ���ַ���ʧ��bug
//V1.4�޸�˵��
//1,�޸Ĵ��ڳ�ʼ��IO��bug
//2,�޸���USART_RX_STA,ʹ�ô����������ֽ���Ϊ2��14�η�
//3,������USART_REC_LEN,���ڶ��崮�����������յ��ֽ���(������2��14�η�)
//4,�޸���EN_USART1_RX��ʹ�ܷ�ʽ
//V1.5�޸�˵��
//1,�����˶�UCOSII��֧��
//V1.6�޸�˵�� 20150109
//uart_init����ȥ���˿���PE�ж�
//V1.7�޸�˵�� 20150322
//�޸�OS_CRITICAL_METHOD���ж�Ϊ��SYSTEM_SUPPORT_OS
////////////////////////////////////////////////////////////////////////////////// 	  
 
#define USART1_REC_LEN  			200  	//�����������ֽ��� 200
#define USART2_REC_LEN  			200  	//�����������ֽ��� 200
#define USART3_REC_LEN  			200  	//�����������ֽ��� 200

#define EN_USART1_RX 			1		//ʹ�ܣ�1��/��ֹ��0������1����
#define EN_USART2_RX 			1		//ʹ�ܣ�1��/��ֹ��0������1����
#define EN_USART3_RX 			1		//ʹ�ܣ�1��/��ֹ��0������1����
	  	
extern u8  USART1_RX_BUF[USART1_REC_LEN]; //���ջ���,���USART_REC_LEN���ֽ�.ĩ�ֽ�Ϊ���з� 
extern u16 USART1_RX_STA;         		//����״̬���	

extern u8  USART2_RX_BUF[USART2_REC_LEN]; //���ջ���,���USART_REC_LEN���ֽ�.ĩ�ֽ�Ϊ���з� 
extern u16 USART2_RX_STA;         		//����״̬���	

extern u8  USART3_RX_BUF[USART3_REC_LEN]; //���ջ���,���USART_REC_LEN���ֽ�.ĩ�ֽ�Ϊ���з� 
extern u16 USART3_RX_STA;         		//����״̬���	

//����봮���жϽ��գ��벻Ҫע�����º궨��
void uart1_init(u32 pclk2,u32 bound);
void uart1_tx_bytes(u8* TxBuffer, u8 Length);
void uart1_rx_bytes(u8* RxBuffer);

void uart2_init(u32 pclk2,u32 bound);
void uart2_tx_bytes(u8* TxBuffer, u8 Length);
void uart2_rx_bytes(u8* RxBuffer);

void uart3_init(u32 pclk2,u32 bound);
void uart3_tx_bytes(u8* TxBuffer, u8 Length);
void uart3_rx_bytes(u8* RxBuffer);

#endif	   
















