#include "led.h"


// 板载LED初始化函数
void LED_Init(void)
{
	RCC->APB2ENR|=1<<2;		//使能PORTA时钟
	RCC->APB2ENR|=1<<4;		//使能PORTC时钟
	
	GPIOA->CRH&=0XFFFFFF0F; 
	GPIOA->CRH|=0X00000030;//PA.9 推挽输出
	
	GPIOC->CRH&=0XFF0FFFFF; 
	GPIOC->CRH|=0X00300000;//PC.13 推挽输出   	 
	GPIOC->ODR|=1<<13;     //PC.13 输出高
}

//通用定时器2中断初始化
//这里时钟选择为APB1的2倍，而APB1为36M
//arr：自动重装值。
//psc：时钟预分频数
//这里使用的是定时器2!
void TIM2_Int_Init(u16 arr,u16 psc)
{
	RCC->APB1ENR|=1<<0;	//TIM2时钟使能    
 	TIM2->ARR=arr;  		//设定计数器自动重装值
	TIM2->PSC=psc;  		//预分频器7200,得到10Khz的计数时钟		  
	TIM2->DIER|=1<<0;   //允许更新中断
	TIM2->SR&=~(1<<0);	//清除中断标志位
  MY_NVIC_Init(3,3,TIM2_IRQn,2);	//抢占3，子优先级3，组2									 
}


//通用定时器3中断初始化
//这里时钟选择为APB1的2倍，而APB1为36M
//arr：自动重装值。
//psc：时钟预分频数
//这里使用的是定时器3!
void TIM3_Int_Init(u16 arr,u16 psc)
{
	RCC->APB1ENR|=1<<1;	//TIM3时钟使能    
 	TIM3->ARR=arr;  		//设定计数器自动重装值
	TIM3->PSC=psc;  		//预分频器7200,得到10Khz的计数时钟		  
	TIM3->DIER|=1<<0;   //允许更新中断	 
//	TIM3->CR1|=0x01;    //使能定时器3	
	TIM3->SR&=~(1<<0);	//清除中断标志位
  MY_NVIC_Init(3,3,TIM3_IRQn,2);//抢占3，子优先级3，组2									 
}

//定时器2中断服务程序	 
void TIM2_IRQHandler(void)
{ 		    		  			    
	if(TIM2->SR&0X0001)//溢出中断
	{
		LED1 = 0;
		TIM2->CR1&=0xFE;	// 关闭定时器2
	}				   
	TIM2->SR&=~(1<<0);//清除中断标志位	
}

//定时器3中断服务程序	 
void TIM3_IRQHandler(void)
{ 		    		  			    
	if(TIM3->SR&0X0001)//溢出中断
	{
		LED1 = 1;
		TIM2->CR1|=0x01;    //使能定时器2
	}				   
	TIM3->SR&=~(1<<0);//清除中断标志位	
}


void Soft_PWM_Init(u16 freq, float dutyCycle)
{
	u16 arr1, arr2;
		
	arr1 = 10000/freq-1;
	arr2 = arr1*dutyCycle;
	
	if(arr2 >= arr1)	arr2 = arr1-1;
	if(arr2 == 0) 		arr2 = 1;
	
	TIM3_Int_Init(arr1, 7199);	//10Khz的计数频率
	TIM2_Int_Init(arr2, 7199);	//10Khz的计数频率
}

// 设置LED亮度函数
void SetLight(u16 dc)
{
	u16 arr1, arr2;
	
	while(TIM2->CR1&0x01);    //等待定时器2关闭
	
	TIM3->CR1&=0xFE;	//关闭定时器3
	TIM2->SR&=~(1<<0);	//清除中断标志位
	TIM3->SR&=~(1<<0);	//清除中断标志位
	
	if(dc > 0)
	{
		arr1 = TIM3->ARR;
		arr2 = arr1*((float)dc/100);
		
		if(arr2 >= arr1)	arr2 = arr1-1;
		if(arr2 == 0) 		arr2 = 1;
		
		TIM2->ARR = arr2;  		//设定计数器自动重装值
		
		TIM3->CR1|=0x01;	//启动定时器3
	}
}


