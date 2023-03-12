#!/usr/bin/env python3
# coding:utf-8
"""
Author:   电信187 朱韬亮 202032000342
Date:     2022/4/10 10:24
Note:     魔方机器人中心处理节点
"""
import rospy
import socket
import time
import sys
from std_msgs.msg import String
from std_srvs.srv import Empty
from stm32_serial.srv import Control
from face_read.srv import GetParameters, SetParameters
from kociemba_solve.srv import KociembaSolve, RandomSolve
from path_planning.srv import PathPlanning
import actionlib
from actionlib import GoalStatus
from central_proc.msg import CubeReadExecAction, CubeReadExecGoal
from central_proc.msg import CubeSolveExecAction, CubeSolveExecGoal
from sensor_msgs.msg import Image
from cv_bridge import CvBridge, CvBridgeError
import numpy as np
import cv2


# ROS服务器
class ROS_Server:
    # 初始化函数
    def __init__(self):
        self.runState = False   # 解序运行状态
        self.readState = False  # 颜色读取状态
        self.read_mode = "slow" # 读取模式：默认为慢速模式
        self.run_mode = "full"  # 运行模式：默认为完整执行模式
        self.six_str = ""       # 六面色块序列
        self.hand_axis = ""     # 夹爪坐标
        self.solve_result = ""  # 解序动作序列
        self.image_size = [640, 480]    # 图像大小
        self.left_img = np.zeros([480, 640, 3], np.uint8)
        self.right_img = np.zeros([480, 640, 3], np.uint8)
        # 服务器的IP地址和端口号
        self.server_address = ('127.0.0.1', 10000)
        self.BUFFER = 256
        # 客户端的IP地址和端口号
        self.client_addr = ('127.0.0.1', 10001)
        # 左摄像头图像数据接收端口
        self.client_LCAM_addr = ('127.0.0.1', 10002)
        # 右摄像头图像数据接收端口
        self.client_RCAM_addr = ('127.0.0.1', 10003)

        rospy.wait_for_service('control')           # 等待接入底层控制服务节点
        rospy.wait_for_service('kociemba_solve')    # 等待接入kociemba魔方解序服务节点
        rospy.wait_for_service('random_solve')      # 等待接入魔方乱序服务节点
        rospy.wait_for_service('path_planning')     # 等待接入路径规划服务节点
        rospy.wait_for_service('/get_para')         # 等待接入获取摄像头基准点参数服务节点
        rospy.wait_for_service('/set_para')         # 等待接入设置摄像头基准点参数服务节点
        rospy.wait_for_service('/left_cam/start_capture')   # 等待接入打开左摄像头服务
        rospy.wait_for_service('/left_cam/stop_capture')    # 等待接入关闭左摄像头服务
        rospy.wait_for_service('/right_cam/start_capture')  # 等待接入打开右摄像头服务
        rospy.wait_for_service('/right_cam/stop_capture')   # 等待接入关闭右摄像头服务
        rospy.wait_for_service('/left_cam/exposure_capture')    # 等待接入左摄像头曝光设置服务
        rospy.wait_for_service('/right_cam/exposure_capture')   # 等待接入右摄像头曝光设置服务

        self.stm32 = rospy.ServiceProxy('control', Control)
        self.kociemba_solve = rospy.ServiceProxy('kociemba_solve', KociembaSolve)
        self.random_solve = rospy.ServiceProxy('random_solve', RandomSolve)
        self.path_planning = rospy.ServiceProxy('path_planning', PathPlanning)
        self.get_para = rospy.ServiceProxy('/get_para', GetParameters)
        self.set_para = rospy.ServiceProxy('/set_para', SetParameters)
        self.leftcam_start = rospy.ServiceProxy('/left_cam/start_capture', Empty)
        self.leftcam_stop = rospy.ServiceProxy('/left_cam/stop_capture', Empty)
        self.rightcam_start = rospy.ServiceProxy('/right_cam/start_capture', Empty)
        self.rightcam_stop = rospy.ServiceProxy('/right_cam/stop_capture', Empty)
        self.left_exposure = rospy.ServiceProxy('/left_cam/exposure_capture', Empty)
        self.right_exposure = rospy.ServiceProxy('/right_cam/exposure_capture', Empty)

        self.client_read = actionlib.SimpleActionClient("do_cube_read", CubeReadExecAction)
        self.client_read.wait_for_server()
        self.client_solve = actionlib.SimpleActionClient("do_cube_solve", CubeSolveExecAction)
        self.client_solve.wait_for_server()

        self.leftcam_stop()      # 关闭左摄像头
        self.rightcam_stop()     # 关闭右摄像头

        # 订阅左摄像头图像数据
        self.sub_lc = rospy.Subscriber('left_cam/image_raw', Image, self.left_callback, queue_size=4)
        # 订阅右摄像头图像数据
        self.sub_rc = rospy.Subscriber('right_cam/image_raw', Image, self.right_callback, queue_size=4)
        
        rospy.loginfo("Central Proc Node Start")
        
        # 初始化服务器端口
        rospy.loginfo("UDP Server Init...")
        try:
            self.udp_socket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)  # udp协议
            self.udp_socket.bind(self.server_address)
            self.udp_socket.setblocking(False)   #  设置为非阻塞模式
        except socket.error as msg:
            print(msg)
            sys.exit(1)

    ##################################################网络处理部分函数##################################################
    # UDP接收数据，非阻塞式
    def udp_resv_msg(self):
        try:
            # data_bytes= self.udp_socket.recv(self.BUFFER, 0x40)
            data_bytes, addr= self.udp_socket.recvfrom(self.BUFFER)
        except:
            data_bytes = None
        
        if data_bytes != None:
            resv_msg = data_bytes.decode("utf-8")   # utf-8解码
            print("%s: %s" %(addr, resv_msg))
            return resv_msg
        else:
            return None

    # UDP发送数据
    def udp_send_msg(self, msg):
        msg_bytes = msg.encode('utf-8')   # utf-8编码
        self.udp_socket.sendto(msg_bytes, self.client_addr)

    # udp发送图像数据
    def udp_send_img(self, img, addr):
        img = cv2.resize(img, tuple(self.image_size))   # 图像缩放
        
        img_quality = 30    # 图像压缩质量
        result, data_encode = cv2.imencode('.jpg', img, [int(cv2.IMWRITE_JPEG_QUALITY), img_quality])   # jpg编码
        data_bytes = data_encode.tobytes()
        self.udp_socket.sendto(data_bytes, addr)

    ##################################################魔方六面读取回调函数##################################################
    # 当action激活后会调用该函数一次
    def read_action_callback(self):
        rospy.loginfo("goal action")
        self.udp_send_msg("[CubeRead]:[Start]:"+self.read_mode+" "+self.run_mode)   # UDP发送开始识别信息

    # 当action完成后会调用该回调函数一次
    def read_done_callback(self, state, res):

        rospy.loginfo(state)
        if state == GoalStatus.SUCCEEDED:   # 执行成功
            rospy.loginfo("finish:%s, hand_axis:%s", res.six_faces_str, res.hand_axis)
            self.six_str = res.six_faces_str
            self.hand_axis = res.hand_axis
            self.readState = True      # 颜色读取状态置True
            # print("runState:", self.runState, " readState:",self.readState)
            self.udp_send_msg("[CubeRead]:[Finish]:"+res.six_faces_str)    # UDP发送数据
        elif state  == GoalStatus.ABORTED:    # 执行失败
            rospy.logwarn("Read Six Face Failed!")
            self.runState = False    # 解序运行状态为False
            self.udp_send_msg("[CubeRead]:[Failed]:Error")   # UDP发送数据
        elif state  == GoalStatus.PREEMPTED:  # 执行中断
            rospy.logwarn("Read Six Face PREEMPTED!")
            self.runState = False    # 解序运行状态为False            
            self.udp_send_msg("[CubeRead]:[Failed]:Stop")   # UDP发送数据

        self.leftcam_stop()      # 关闭左摄像头
        self.rightcam_stop()     # 关闭右摄像头

    # 收到feedback后调用该回调函数
    def read_feedback_callback(self, fb):
        rospy.loginfo(fb)
        self.udp_send_msg("[CubeRead]:[FeedBack]:"+fb.now_read_faces)    # UDP发送数据

    ##################################################魔方解序执行回调函数####################################################
    # 当action激活后会调用该函数一次
    def solve_action_callback(self):
        rospy.loginfo("goal action")

    # 当action完成后会调用该回调函数一次
    def solve_done_callback(self, state, res):        
        rospy.loginfo(state)
        if state  == GoalStatus.SUCCEEDED:   # 执行成功
            rospy.loginfo("finish: %s", res.result)
            self.udp_send_msg("[CubeSolve]:[Finish]:"+res.result)    # UDP发送数据
            rosp = self.stm32("AH")     # 调用服务，左夹爪半松
            rosp = self.stm32("BH")     # 调用服务，右夹爪半松
        elif state  == GoalStatus.ABORTED:    # 执行失败
            rospy.logwarn("Exec Solve Failed!")
            self.udp_send_msg("[CubeSolve]:[Failed]:Error")    # UDP发送数据
        elif state  == GoalStatus.PREEMPTED:  # 执行中断
            rospy.logwarn("Exec Solve PREEMPTED!")
            self.udp_send_msg("[CubeSolve]:[Failed]:Stop")     # UDP发送数据
        
        self.runState = False    # 解序运行状态为False

    # 收到feedback后调用该回调函数
    def solve_feedback_callback(self, fb):
        rospy.loginfo(fb)
        self.udp_send_msg("[CubeSolve]:[FeedBack]:"+fb.now_cmd)    # UDP发送数据

    ##################################################摄像头数据回调函数######################################################
    # 左摄像头图像数据接收回调函数
    def left_callback(self, img_msg):
        cv_bridge = CvBridge()
        try:
            # rospy.loginfo("left camera img")
            self.left_img = cv_bridge.imgmsg_to_cv2(img_msg, desired_encoding="bgr8")
            # udp发送图像数据
            self.udp_send_img(self.left_img, self.client_LCAM_addr)
        except CvBridgeError as err:
            print(err)


    # 右摄像头图像数据接收回调函数
    def right_callback(self, img_msg):    
        cv_bridge = CvBridge()
        try:
            # rospy.loginfo("right camera img")
            self.right_img = cv_bridge.imgmsg_to_cv2(img_msg, desired_encoding="bgr8")
            # udp发送图像数据
            self.udp_send_img(self.right_img, self.client_RCAM_addr)
        except CvBridgeError as err:
            print(err)
    
    # 主逻辑处理循环
    def proc_loop(self):
        # 接收Qt客户端数据，非阻塞式
        data_msg = self.udp_resv_msg()
        
        if data_msg != None:
            [head, data] = data_msg.split(' ')       # 按空格符分割数据包
            
            # 手动模式
            if head == "[ManuMode]":
                try:
                    rosp = self.stm32(data)
                    rospy.loginfo("Message from Server:%s" %rosp.feedback)
                except rospy.ServiceException:
                    rospy.logwarn("Service call failed" )
                    
            # 主控模式
            elif head == "[MainMode]":
                if data == "Start" and self.runState == False:   # 开始解序
                    ####################################魔方六面识别####################################
                    self.leftcam_start()        # 打开左摄像头
                    self.rightcam_start()       # 打开右摄像头

                    rospy.sleep(0.8)

                    goal = CubeReadExecGoal()
                    goal.read_mode = self.read_mode # 设置读取模式

                    self.client_read.send_goal(goal, self.read_done_callback, self.read_action_callback, self.read_feedback_callback)

                    self.runState = True        # 解序运行状态为True
                    self.readState = False      # 读取状态为False
                    self.solve_result = ""      # 清空解序动作序列

                elif data == "Stop" and self.runState == True:   # 停止解序
                    self.runState = False       # 解序运行状态为False
                    self.readState = False      # 读取状态为False
                    self.solve_result = ""      # 清空解序动作序列
                    if self.client_read.get_state()  == GoalStatus.ACTIVE:   # 当前六面读取动作处于活动状态
                        self.client_read.cancel_goal()   # 取消执行六面读取动作
                    if self.client_solve.get_state()  == GoalStatus.ACTIVE:   # 当前六面读取动作处于活动状态
                        self.client_solve.cancel_goal()  # 取消执行魔方解序动作
                
                # 分布执行模式下，六面读取完成后再次按下开始键，开始执行解序动作
                elif data == "Start" and self.runState == True and self.run_mode == "step" and self.solve_result != "":
                    ####################################执行机械动作####################################
                    goal = CubeSolveExecGoal()
                    goal.cmd_list = self.solve_result   # 设置解序目标
                    self.udp_send_msg("[CubeSolve]:[Start]:" + goal.cmd_list)    # UDP发送数据
                    self.client_solve.send_goal(goal, self.solve_done_callback, self.solve_action_callback, self.solve_feedback_callback)
            
            # 亮度设置模式
            elif head == "[LightSetup]" and self.runState == False:
                if data == "CamerasOpen":
                    self.image_size = [320, 240] # 图像大小
                    self.leftcam_start()     # 打开左摄像头
                    self.rightcam_start()    # 打开右摄像头
                elif data == "CamerasClose":
                    self.leftcam_stop()     # 关闭左摄像头
                    self.rightcam_stop()    # 关闭右摄像头
                else:
                    try:
                        rosp = self.stm32("LED"+data)  # 发送LED亮度命令
                        rospy.loginfo("Message from Server:%s" %rosp.feedback)
                    except rospy.ServiceException:
                        rospy.logwarn("Service call failed" )
                        
            # 左摄像头曝光量设置
            elif head == "[LeftExposure]" and self.runState == False:
                rospy.set_param("/left_cam/exposure", int(data))    # 设置曝光量参数
                self.left_exposure()     # 设置左摄像头曝光量

            # 右摄像头曝光量设置
            elif head == "[RightExposure]" and self.runState == False:
                rospy.set_param("/right_cam/exposure", int(data))   # 设置曝光量参数
                self.right_exposure()    # 设置右摄像头曝光量
            
            # 基准点校验模式
            elif head == "[CalibrationSetup]" and self.runState == False:
                # 开始校验
                if data == "Start":
                    self.image_size = [640, 480] # 图像大小

                    rosp = self.get_para()   # 获取摄像头基准点参数

                    self.udp_send_msg("[GetPara]:"+rosp.paras)   # UDP发送数据
                    self.leftcam_start()      # 打开左摄像头
                    self.rightcam_stop()     # 关闭右摄像头
                    try:
                        rosp = self.stm32('B1')     # 调用服务，夹紧右夹爪
                        rospy.loginfo("Message from Server:%s" %rosp.feedback)
                        rosp = self.stm32('A0')     # 调用服务，松开左夹爪
                        rospy.loginfo("Message from Server:%s" %rosp.feedback)
                    except rospy.ServiceException:
                        rospy.logwarn("Service call failed")
                # 左摄像头打开
                elif data == "LeftCamOpen":
                    self.image_size = [640, 480] # 图像大小
                    self.leftcam_start()     # 打开左摄像头
                    self.rightcam_stop()     # 关闭右摄像头
                    try:
                        rosp = self.stm32('B1')     # 调用服务，夹紧右夹爪
                        rospy.loginfo("Message from Server:%s" %rosp.feedback)
                        rosp = self.stm32('A0')     # 调用服务，松开左夹爪
                        rospy.loginfo("Message from Server:%s" %rosp.feedback)
                    except rospy.ServiceException:
                        rospy.logwarn("Service call failed")
                # 右摄像头打开
                elif data == "RightCamOpen":
                    self.image_size = [640, 480] # 图像大小
                    self.rightcam_start()    # 打开右摄像头
                    self.leftcam_stop()      # 关闭左摄像头
                    try:
                        rosp = self.stm32('A1')     # 调用服务，夹紧左夹爪
                        rospy.loginfo("Message from Server:%s" %rosp.feedback)
                        rosp = self.stm32('B0')     # 调用服务，松开右夹爪
                        rospy.loginfo("Message from Server:%s" %rosp.feedback)
                    except rospy.ServiceException:
                        rospy.logwarn("Service call failed")
                # 退出校验
                elif data == "Quit":
                    self.leftcam_stop()      # 关闭左摄像头
                    self.rightcam_stop()     # 关闭右摄像头
                    try:
                        rosp = self.stm32('AH')     # 调用服务，半松左夹爪
                        rospy.loginfo("Message from Server:%s" %rosp.feedback)
                        rosp = self.stm32('BH')     # 调用服务，半松右夹爪
                        rospy.loginfo("Message from Server:%s" %rosp.feedback)
                    except rospy.ServiceException:
                        rospy.logwarn("Service call failed")
                # 参数设置
                else:
                    rospy.loginfo("Message from Qt Client:%s" %data)
                    try:
                        rosp = self.set_para(data)   # 设置摄像头基准点参数
                        self.udp_send_msg("[SetupFeedBack]:Finish")    # UDP返回设置成功信息
                    except rospy.ServiceException:
                        rospy.logwarn("Service call failed" )
                        self.udp_send_msg("[SetupFeedBack]:Failed")    # UDP返回设置失败信息

            # 速度设置模式
            elif head == "[SpeedSetup]" and self.runState == False:
                [readMode, actMode, runMode] = data.split(';')  # 按分号符分割数据包
                # 魔方六面识别模式
                if readMode == "Slow":     # 慢速(稳定)模式
                    self.read_mode = "slow"
                elif readMode == "Fast":   # 快速模式
                    self.read_mode = "fast"
                else:
                    self.udp_send_msg("[SetupFeedBack]:Failed")    # UDP返回设置失败信息
                    return

                # 动作模式
                if actMode == "Slow":     # 慢速(稳定)模式
                    try:
                        rosp = self.stm32("LS")  # 发送速度设置命令，LowSpeed
                        rospy.loginfo("Message from Server:%s" %rosp.feedback)
                    except rospy.ServiceException:
                        rospy.logwarn("Service call failed" )
                elif actMode == "Fast":   # 快速模式
                    try:
                        rosp = self.stm32("HS")  # 发送速度设置命令，HighSpeed
                        rospy.loginfo("Message from Server:%s" %rosp.feedback)
                    except rospy.ServiceException:
                        rospy.logwarn("Service call failed" )
                else:
                    self.udp_send_msg("[SetupFeedBack]:Failed")    # UDP返回设置失败信息
                    return
                
                # 运行模式
                if runMode == "Full":   # 整体执行模式
                    self.run_mode = "full"
                elif runMode == "Step": # 分布执行模式
                    self.run_mode = "step"
                
                self.udp_send_msg("[SetupFeedBack]:Finish")    # UDP返回设置成功信息
            
            # 打乱魔方
            elif head == "[RandomCube]" and self.runState == False:
                self.runState = True    # 运行状态置True
                #####################################生成乱序解序列#####################################
                step_num = int(data)    # 获取打乱步数
                try:
                    rosp = self.random_solve(step_num)  # 调用魔方打乱服务
                    rospy.loginfo("Message from Server:%s" %rosp.random_str)
                except rospy.ServiceException:
                    rospy.logwarn("Service call failed" )

                ####################################生成机械动作序列####################################
                rosp = self.path_planning(rosp.random_str, "DR")     # 调用服务，对解序结果进行机械臂动作路径规划
                rospy.loginfo("Path Planning:%s" %rosp.result)
                resultList = rosp.result.split(' ')     # 按空格分割为序列
                rospy.loginfo("CMD Length:%d", len(resultList))     # 机械步数
                # self.udp_send_msg("[ExecSolve]:" + rosp.result)     # UDP发送数据

                ####################################执行机械动作####################################
                goal = CubeSolveExecGoal()
                goal.cmd_list = rosp.result     # 设置解序目标
                self.udp_send_msg("[CubeSolve]:[Start]:" + goal.cmd_list)   # UDP发送数据
                self.client_solve.send_goal(goal, self.solve_done_callback, self.solve_action_callback, self.solve_feedback_callback)

                
        if self.runState and self.readState:    # 解序运行且识别完成
            self.readState = False  # 识别状态置False
            ####################################生成原始解序列####################################
            rosp = self.kociemba_solve(self.six_str)        # 调用服务，求解魔方解序结果
            self.solve_str = rosp.solve_str
            
            if self.solve_str != "":
                rospy.loginfo("Kociemba Solve:%s" %rosp.solve_str)
                self.udp_send_msg("[Kociemba]:[Finish]:%s" %rosp.solve_str)    # UDP返回求解成功信息
            else:
                rospy.logwarn("Kociemba Solve Failed!")         # 颜色识别错误，求解失败！
                self.udp_send_msg("[Kociemba]:[Failed]")   # UDP返回求解失败信息
                self.runState = False    # 解序运行状态为False
                return
            ####################################生成机械动作序列####################################
            rospy.loginfo("Hand Axis:%s" %self.hand_axis)
            rosp = self.path_planning(self.solve_str, self.hand_axis)  # 调用服务，对解序结果进行机械臂动作路径规划
            rospy.loginfo("Path Planning:%s" %rosp.result)
            resultList = rosp.result.split(' ')     # 按空格分割为序列
            rospy.loginfo("CMD Length:%d", len(resultList)) # 机械步数
            # self.udp_send_msg("[ExecSolve]:" + rosp.result)  # UDP发送数据

            if self.run_mode == "full":     # 完整执行模式
                ####################################执行机械动作####################################
                goal = CubeSolveExecGoal()
                goal.cmd_list = rosp.result     # 设置解序目标
                self.udp_send_msg("[CubeSolve]:[Start]:" + goal.cmd_list)    # UDP发送数据
                self.client_solve.send_goal(goal, self.solve_done_callback, self.solve_action_callback, self.solve_feedback_callback)

            elif self.run_mode == "step":     # 分布执行模式
                self.solve_result = rosp.result


#######################################################主程序############################################################
if __name__ == '__main__':
    
    rospy.init_node("central_proc_node")    # 初始化中央处理节点

    ros_server = ROS_Server()   # 创建ROS服务器

    rospy.loginfo("Link Start!")
    rate = rospy.Rate(50)   # 50hz
    
    while not rospy.is_shutdown():
        ros_server.proc_loop()  # 逻辑处理
        rate.sleep()        # 延时
    
    rospy.spin()
    ros_server.udp_socket.close()  	# 关闭套接字


