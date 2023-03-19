# Rubik_Cube_Robot
## 毕业设计：双臂二指魔方机器人  
该项目完成于2022年6月  
整体结构图如下：  
![image](https://github.com/YukimuraChieri/Rubik_Cube_Robot/tree/master/img/pic_all.jpg)  
该机器人使用两个闭环步进电机驱动夹爪旋转，使用高速舵机驱动夹爪动作。  
机器人的控制系统主要为下位机+上位机，下位机与上位机之间通过USB串口通信  
下位机硬件基于STM32F103C8T6制作，上位机硬件为树莓派4B，操作系统为Ubuntu+ROS。  
其中上位机外接了一个触摸屏用于显示人机交互界面，该界面采用Qt开发。
仓库中的catkin_ws为ROS部分的代码。  
Robot_HMI为Qt界面的代码。  
matlab程序为计算S曲线加减速的相关代码。  

## 注意事项  
STM32下位机程序的开发环境为keil5，如果出现乱码的情况需要将编码设置为GB2312。  
PCB工程需要使用Altium Designer09软件打开。  
整体结构需要使用solidworks2015或者以上版本的软件打开。  
  
更多细节见《毕业论文_最终版1》  
