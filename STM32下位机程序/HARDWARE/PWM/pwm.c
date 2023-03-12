#include "pwm.h"

u8 servoRun = 0;		// 舵机运行状态
u8 leftAngle = 0;		// 左舵机当前角度
u8 rightAngle = 0;	// 右舵机当前角度
u8 setLeft = 0;			// 左舵机设定角度
u8 setRight = 0;		// 右舵机设定角度
u8 servoFinish = 0;	// 舵机完成状态
u8 servo_speed = 4;	// 舵机夹紧速度

void TIM4_PWM_Init(u16 arr,u16 psc)
{
	//此部分需手动修改IO口设置
	RCC->APB1ENR|=1<<2; 		//TIM4时钟使能    
	RCC->APB2ENR|=1<<3;    	//使能PORTB时钟 	 
	GPIOB->CRL&=0X00FFFFFF;	//PB6/7输出
	GPIOB->CRL|=0XBB000000;	//复用功能输出

	TIM4->ARR=arr;			//设定计数器自动重装值 
	TIM4->PSC=psc;			//预分频器分频数
//	TIM4->DIER|=1<<0;		//允许更新中断
	
	TIM4->CCMR1|=7<<4;  	//CH1 PWM2模式		 
	TIM4->CCMR1|=1<<3; 		//CH1 预装载使能
	TIM4->CCER|=1<<1;   	//OC1 输出反相
	TIM4->CCER|=1<<0;			//OC1 输出使能	 

	TIM4->CCMR1|=7<<12;		//CH2 PWM2模式		 
	TIM4->CCMR1|=1<<11;		//CH2 预装载使能	   
	TIM4->CCER|=1<<5;   	//OC2 输出反相
	TIM4->CCER|=1<<4;			//OC2 输出使能
	
	TIM4->CR1=0x0080;   //ARPE使能 
	TIM4->CR1|=0x01;    //使能定时器4
	
	CH1_PWM_VAL = Angle_to_PWM(0);	//初始化右舵机PWM占空比
	CH2_PWM_VAL = Angle_to_PWM(0);	//初始化左舵机PWM占空比
	
	MY_NVIC_Init(1,2,TIM4_IRQn,2);		//抢占1，子优先级2，组2
}

//角度值转换为PWM比较值（适用于180度舵机 ）
u16 Angle_to_PWM(u16 angle)
{
	angle = angle * 4 + 180;
	
	return 7200 - angle;
}


//设置舵机角度函数
void Set_Angle(u8 angle, char dir)
{
	switch(dir)
	{
		case 'A':	setLeft = angle;	break;
		case 'B':	setRight = angle;	break;
	}
	
	if(setLeft != leftAngle || setRight != rightAngle)
	{
		TIM4->DIER |= 1<<0;	// 允许更新中断
		servoRun = 1;				// 舵机运行状态置1
	}
	else
		servoFinish = 1;				// 舵机完成状态置1
}


// 获取舵机的运行状态
u8 Get_Servo_Status(void)
{
	return servoRun;		// 返回舵机运行状态
}


// 获取舵机的完成状态
u8 Get_Servo_Finish(void)
{
	u8 temp = servoFinish;
	
	servoFinish = 0;
	
	return temp;		// 返回舵机完成状态
}


// 设置舵机速度
void Set_Servo_Speed(u8 speed)
{
	servo_speed = speed;
}


// 定时器4中断服务函数
void TIM4_IRQHandler(void)
{
	if(TIM4->SR&0X0001)	//溢出中断
	{
		if(leftAngle < setLeft)	// 左舵机小于设定角度
		{
			leftAngle += (setLeft - leftAngle)/servo_speed + 1;
			CH2_PWM_VAL = Angle_to_PWM(leftAngle);
		}
		else if(leftAngle > setLeft)	// 左舵机大于设定角度
		{
			leftAngle -= (leftAngle - setLeft)/servo_speed + 1;
			CH2_PWM_VAL = Angle_to_PWM(leftAngle);
		}
		
		if(rightAngle < setRight)	// 右舵机小于设定角度
		{
			rightAngle += (setRight - rightAngle)/servo_speed + 1;
			CH1_PWM_VAL = Angle_to_PWM(rightAngle);
		}
		else if(rightAngle > setRight)	// 右舵机大于设定角度
		{
			rightAngle -= (rightAngle - setRight)/servo_speed + 1;
			CH1_PWM_VAL = Angle_to_PWM(rightAngle);
		}
		
		if(leftAngle == setLeft && rightAngle == setRight)	// 如果左右舵机均达到设定角度
		{
			servoRun = 0;						// 舵机运行状态置0
			servoFinish = 1;				// 舵机完成状态置1
			TIM4->DIER &= ~(1<<0);	// 关闭中断
		}
		
		TIM4->SR&=~(1<<0);	//清除中断标志位
	}
}
