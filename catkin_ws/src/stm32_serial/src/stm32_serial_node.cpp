/***************************************************************
Author:   电信187 朱韬亮 202032000342
Date:     2022/3/20 11:00
Note:     魔方机器人底层控制节点
***************************************************************/

#include "ros/ros.h"
#include "std_msgs/String.h"
#include <stm32_serial/Control.h>
#include <serial/serial.h>          //ROS内置的串口包
#include <iostream>

serial::Serial ser;                 //声明串口对象

bool handle_function(stm32_serial::Control::Request &req, stm32_serial::Control::Response &res)
{
    uint16_t timeout_cnt = 0;   // 超时计数
    bool retryFlag = false;     // 重发标志
    uint16_t retry_cnt = 0;     // 重发计数

    // 显示请求信息
    ROS_INFO("Request from %s", req.command.c_str());
    
    std::string tail = "\r\n";
    std::string sendCMD = req.command.c_str() + tail;

    ros::Rate loop_rate(50);    // 50Hz

    ser.flush();

    do
    {
        ser.write(sendCMD);     //发送串口命令
        
        while(ros::ok() && timeout_cnt<100)  // 2S内未返回应答信息即为超时
        {
            std::string rxData = ser.readline(32, "\r\n");		//串口读取一行数据 \r\n结尾
            
            if(!rxData.empty())   // 接收到串口数据
            {
                ROS_INFO_STREAM(rxData);
                res.feedback = rxData;

                if(rxData.compare("Receive Error\r\n") == 0)   // 通信错误
                {
                    retryFlag = true;       // 重发标志置1
                    retry_cnt++;            // 重发计数加1
                }
                else if(rxData.compare("BUSY\r\n") == 0)       // 系统繁忙
                {
                    loop_rate.sleep();      // 按循环频率延时
                    retryFlag = true;       // 重发标志置1
                    retry_cnt++;            // 重发计数加1
                }
                else if(rxData.compare("ALM_ON\r\n") == 0)       // 急停开关按下
                {
                    ROS_WARN("ALM_ON");
                    return false;   // 返回false, 停止操作
                }
                else if(rxData.compare("ILLegal Operation\r\n") == 0)    // 非法的操作
                {
                    ROS_WARN("ILLegal Operation");
                    return false;   // 返回false, 非法操作
                }
                else
                {
                    retryFlag = false;      // 重发标志置0
                    retry_cnt = 0;          // 重发计数清0
                }
                break;
            }
            loop_rate.sleep();      // 按循环频率延时
            timeout_cnt++;
        }

        if(timeout_cnt >= 100)      // 超时判断
        {
            ROS_WARN("Request TimeOut");
            return false;   // 返回false, 处理请求超时
        }

        if(retry_cnt >= 8)          // 重发次数判断
        {
            ROS_WARN("Request RetryOut");
            return false;   // 返回false, 处理请求错误次数过多
        }

    } while(retryFlag && retry_cnt < 8);
    
    return true;    // 返回true, 正确处理请求
}


int main(int argc, char **argv)
{
    ros::init(argc, argv, "stm32_serial_node");     //初始化节点
    ros::NodeHandle node_handle;		//声明节点句柄
    
    ros::ServiceServer service = node_handle.advertiseService("control", handle_function); // 提供服务

    ros::Publisher res_pub = node_handle.advertise<std_msgs::String>("response", 32);
    
    serial::Timeout to = serial::Timeout::simpleTimeout(100);
    ser.setPort("/dev/stm32_serial");   //设置要打开的串口名称
    ser.setBaudrate(115200);            //设置串口通信的波特率
    ser.setTimeout(to);

    try
    {
        ser.open();     //打开串口
    }
    catch(serial::IOException& e)
    {
        ROS_ERROR_STREAM("Unable to open port.");
        return -1;
    }

    //判断串口是否打开成功
    if(ser.isOpen())   
    {
        ROS_INFO_STREAM("/dev/stm32_serial is opened.");
        ser.flush();
    } 
    else
    {
        ROS_ERROR_STREAM("/dev/stm32_serial not opened.");    
        return -1;
    }
	
    ros::spin();    // 循环等待回调函数

	ser.close();    // 关闭串口

	return 0;
}








