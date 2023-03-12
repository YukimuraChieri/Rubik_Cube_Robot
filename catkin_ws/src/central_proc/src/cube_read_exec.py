#!/usr/bin/env python3
# coding:utf-8
"""
Author: 电信187 朱韬亮 202032000342
Date:   2022/4/19 11:21
Note:   魔方完整六面读取节点
"""
import rospy
import actionlib
from std_msgs.msg import String
from stm32_serial.srv import Control
from face_read.srv import ReadTwoFaces
from central_proc.msg import CubeReadExecAction, CubeReadExecFeedback, CubeReadExecResult
import time
import sys


cmd_list = ['A1', 'B0', 'A+', 'B1', 'A0', 'A-', 'B-', 'A1', 'B0', 'B+', 'BH', 'AH']		# 翻面指令序列

cmd_list_1 = ['B1', 'A0']		# 翻面指令序列1
cmd_list_2 = ['A1', 'B0']		# 翻面指令序列2
cmd_list_3 = ['A+', 'B1', 'A0', 'A-']		# 翻面指令序列3
cmd_list_4 = ['A1', 'B0']		# 翻面指令序列4
cmd_list_5 = ['BH', 'AH']		# 翻面指令序列5


# 将读取面合成完整六面
def facePack(face_list):
    # 六面字符串
    six_face_str = ""
    # 六面顺序：U R F D L B
    six_face_list = [None, None, None, None, None, None]

    # 遍历传入参数的列表，将面添加到six_face_list相应位置
    for face in face_list:
        if face[4] == 'U':
            six_face_list[0] = face
        elif face[4] == 'R':
            six_face_list[1] = face
        elif face[4] == 'F':
            six_face_list[2] = face
        elif face[4] == 'D':
            six_face_list[3] = face
        elif face[4] == 'L':
            six_face_list[4] = face
        elif face[4] == 'B':
            six_face_list[5] = face

    # 再遍历six_face_list，将六面合成为一个字符串
    for face in six_face_list:
        if face != None:
            six_face_str += face
        else:
            six_face_str += "XXXXXXXXX"

    return six_face_str


# 根据当前读取两面序列获取夹爪坐标(旧版本，慢速模式)
def getHandAxis(face_L, face_R):
    hand_axis = ""

    if face_R[4] == 'F':
        hand_axis += 'B'
    elif face_R[4] == 'B':
        hand_axis += 'F'
    elif face_R[4] == 'L':
        hand_axis += 'R'
    elif face_R[4] == 'R':
        hand_axis += 'L'
    elif face_R[4] == 'U':
        hand_axis += 'D'
    elif face_R[4] == 'D':
        hand_axis += 'U'

    if face_L[4] == 'F':
        hand_axis += 'B'
    elif face_L[4] == 'B':
        hand_axis += 'F'
    elif face_L[4] == 'L':
        hand_axis += 'R'
    elif face_L[4] == 'R':
        hand_axis += 'L'
    elif face_L[4] == 'U':
        hand_axis += 'D'
    elif face_L[4] == 'D':
        hand_axis += 'U'    

    return hand_axis


# 根据当前读取两面序列获取夹爪坐标(新版本，快速模式)
def getHandAxisNew(face_U, face_D):
    hand_axis = ""

    if face_U[4] == 'F':
        hand_axis += 'B'
    elif face_U[4] == 'B':
        hand_axis += 'F'
    elif face_U[4] == 'L':
        hand_axis += 'R'
    elif face_U[4] == 'R':
        hand_axis += 'L'
    elif face_U[4] == 'U':
        hand_axis += 'D'
    elif face_U[4] == 'D':
        hand_axis += 'U'

    hand_axis += face_D[4]

    return hand_axis

class CubeReadServer:
    def __init__(self):
        self.server = actionlib.SimpleActionServer('do_cube_read', CubeReadExecAction, self.execute_read, False)
        self.server.start()     # 启动服务
    
    # 魔方六面识别方法
    def execute_read(self, goal="slow"):
        feedback = CubeReadExecFeedback()
        result = CubeReadExecResult()        

        rospy.loginfo("Cube Read Execute Start!")

        rospy.loginfo("Execute Start:%s" %goal.read_mode)

        face_str_list = []  # 魔方六面列表

        if goal.read_mode == "fast":    # 快速读取模式
            for cmd in cmd_list_1:
                try:
                    rosp = stm32(cmd)     # 调用服务，控制机械臂运动
                    rospy.loginfo("Message from Server:%s" %rosp.feedback)
                except rospy.ServiceException:
                    rospy.logwarn("Service call failed")
                    break
                if self.server.is_preempt_requested():   # 是否发生中断                
                    self.server.set_preempted(result, "exec preempted")
                    return
            rospy.sleep(0.3)
            
            rosp = read_two_faces(side = "left")    # 调用服务，读取左摄像头魔方两面
            if self.server.is_preempt_requested():   # 是否发生中断            
                self.server.set_preempted(result, "exec preempted")
                return

            face_str_list.append(rosp.face_1)   # 添加读取面字符串
            face_str_list.append(rosp.face_2)
            six_str = facePack(face_str_list)   # 将读取面合成完整六面

            feedback.now_read_faces = six_str
            self.server.publish_feedback(feedback)   # 发布过程反馈信息
            
            for cmd in cmd_list_2:
                try:
                    rosp = stm32(cmd)     # 调用服务，控制机械臂运动
                    rospy.loginfo("Message from Server:%s" %rosp.feedback)
                except rospy.ServiceException:
                    rospy.logwarn("Service call failed")
                    break
                if self.server.is_preempt_requested():   # 是否发生中断
                    self.server.set_preempted(result, "exec preempted")
                    return

            rospy.sleep(0.2)

            rosp = read_two_faces(side = "right")   # 调用服务，读取右摄像头魔方两面
            if self.server.is_preempt_requested():   # 是否发生中断            
                self.server.set_preempted(result, "exec preempted")
                return

            face_str_list.append(rosp.face_1)   # 添加读取面字符串
            face_str_list.append(rosp.face_2)
            six_str = facePack(face_str_list)   # 将读取面合成完整六面

            feedback.now_read_faces = six_str
            self.server.publish_feedback(feedback)   # 发布过程反馈信息

            for cmd in cmd_list_3:            
                try:
                    rosp = stm32(cmd)     # 调用服务，控制机械臂运动
                    rospy.loginfo("Message from Server:%s" %rosp.feedback)
                except rospy.ServiceException:
                    rospy.logwarn("Service call failed")
                    break
                if self.server.is_preempt_requested():   # 是否发生中断                
                    self.server.set_preempted(result, "exec preempted")
                    return

            rospy.sleep(0.3)

            rosp = read_two_faces(side = "left")    # 调用服务，读取左摄像头魔方两面
            if self.server.is_preempt_requested():   # 是否发生中断
                self.server.set_preempted(result, "exec preempted")
                return

            face_str_list.append(rosp.face_1)   # 添加读取面字符串
            face_str_list.append(rosp.face_2)
            six_str = facePack(face_str_list)   # 将读取面合成完整六面

            feedback.now_read_faces = six_str
            self.server.publish_feedback(feedback)   # 发布过程反馈信息

            for cmd in cmd_list_4:            
                try:
                    rosp = stm32(cmd)     # 调用服务，控制机械臂运动
                    rospy.loginfo("Message from Server:%s" %rosp.feedback)
                except rospy.ServiceException:
                    rospy.logwarn("Service call failed")
                    break
                if self.server.is_preempt_requested():   # 是否发生中断
                    self.server.set_preempted(result, "exec preempted")
                    return
            
            rospy.sleep(0.2)
            
            rosp = read_two_faces(side = "right")   # 调用服务，读取右摄像头魔方两面
            if self.server.is_preempt_requested():   # 是否发生中断
                self.server.set_preempted(result, "exec preempted")
                return

            face_str_list.append(rosp.face_1)   # 添加读取面字符串
            face_str_list.append(rosp.face_2)
            six_str = facePack(face_str_list)   # 将读取面合成完整六面

            for cmd in cmd_list_5:
                try:
                    rosp = stm32(cmd)     # 调用服务，控制机械臂运动
                    rospy.loginfo("Message from Server:%s" %rosp.feedback)
                except rospy.ServiceException:
                    rospy.logwarn("Service call failed")
                    break
                if self.server.is_preempt_requested():   # 是否发生中断                
                    self.server.set_preempted(result, "exec preempted")
                    return

            if "X" in six_str:      # 如果结果中有未识别到的色块
                self.server.set_aborted(result, "exec aborted")
                return

            hand_axis = getHandAxisNew(face_str_list[6], face_str_list[7])   # 根据最后读取两面序列获取夹爪坐标

            result.six_faces_str = six_str
            result.hand_axis = hand_axis
            self.server.set_succeeded(result)   # 发布完成信息

        elif goal.read_mode == "slow":      # 慢速读取模式
                for cmd in cmd_list_5:
                    try:
                        rosp = stm32(cmd)     # 调用服务，控制机械臂运动
                        rospy.loginfo("Message from Server:%s" %rosp.feedback)
                    except rospy.ServiceException:
                        rospy.logwarn("Service call failed")
                        break
                    if self.server.is_preempt_requested():   # 是否发生中断                
                        self.server.set_preempted(result, "exec preempted")
                        return
                
                # rospy.sleep(0.2)    # 延时0.2S

                rosp = read_two_faces(side = "both")    # 调用服务，读取左右摄像头拍摄魔方两面
                if self.server.is_preempt_requested():  # 是否发生中断            
                    self.server.set_preempted(result, "exec preempted")
                    return
                
                face_str_list.append(rosp.face_1)   # 添加读取面字符串
                face_str_list.append(rosp.face_2)
                six_str = facePack(face_str_list)   # 将读取面合成完整六面

                feedback.now_read_faces = six_str
                self.server.publish_feedback(feedback)   # 发布过程反馈信息

                for cmd in cmd_list:        # 翻转魔方
                    try:
                        rosp = stm32(cmd)   # 调用服务，控制机械臂运动
                        rospy.loginfo("Message from Server:%s" %rosp.feedback)
                    except rospy.ServiceException:
                        rospy.logwarn("Service call failed")
                        break
                    if self.server.is_preempt_requested():   # 是否发生中断                
                        self.server.set_preempted(result, "exec preempted")
                        return
                rospy.sleep(0.1)

                rosp = read_two_faces(side = "both")    # 调用服务，读取左右摄像头拍摄魔方两面
                if self.server.is_preempt_requested():  # 是否发生中断            
                    self.server.set_preempted(result, "exec preempted")
                    return

                face_str_list.append(rosp.face_1)   # 添加读取面字符串
                face_str_list.append(rosp.face_2)
                six_str = facePack(face_str_list)   # 将读取面合成完整六面

                feedback.now_read_faces = six_str
                self.server.publish_feedback(feedback)   # 发布过程反馈信息

                for cmd in cmd_list:        # 翻转魔方
                    try:
                        rosp = stm32(cmd)   # 调用服务，控制机械臂运动
                        rospy.loginfo("Message from Server:%s" %rosp.feedback)
                    except rospy.ServiceException:
                        rospy.logwarn("Service call failed")
                        break
                    if self.server.is_preempt_requested():   # 是否发生中断                
                        self.server.set_preempted(result, "exec preempted")
                        return
                rospy.sleep(0.1)

                rosp = read_two_faces(side = "both")    # 调用服务，读取左右摄像头拍摄魔方两面
                if self.server.is_preempt_requested():  # 是否发生中断            
                    self.server.set_preempted(result, "exec preempted")
                    return
                
                face_str_list.append(rosp.face_1)   # 添加读取面字符串
                face_str_list.append(rosp.face_2)
                six_str = facePack(face_str_list)   # 将读取面合成完整六面

                if "X" in six_str:      # 如果结果中有未识别到的色块
                    self.server.set_aborted(result, "exec aborted")
                    return

                hand_axis = getHandAxis(face_str_list[4], face_str_list[5])   # 根据最后读取两面序列获取夹爪坐标            

                result.six_faces_str = six_str
                result.hand_axis = hand_axis
                self.server.set_succeeded(result)   # 发布完成信息

        face_str_list.clear()   # 清空魔方六面识别列表




if __name__ == "__main__":
    rospy.init_node("cube_read_node")           # 初始化六面读取节点
    rospy.wait_for_service('control')           # 等待接入底层控制服务节点
    rospy.wait_for_service('read_two_faces')    # 等待接入两面读取服务节点

    stm32 = rospy.ServiceProxy('control', Control)
    read_two_faces = rospy.ServiceProxy('read_two_faces', ReadTwoFaces)

    server = CubeReadServer()   # 创建action服务器

    rospy.loginfo("Cube Read Node Start")

    rospy.spin()

