#!/usr/bin/env python3
# coding=utf-8
import rospy
from std_msgs.msg import String
from kociemba_solve.srv import KociembaSolve, KociembaSolveResponse
from kociemba_solve.srv import RandomSolve, RandomSolveResponse
import kociemba		# 魔方解序库
import random
import sys


# 获取一个随机步骤函数
def get_random_step():
    random_step = ""       # 打乱步骤
    face_list = "URFDLB"
    angle_list = " '2"

    face_index = random.randint(0, 5)     # 随机面序号
    angle_index = random.randint(0, 2)    # 随机角度序号

    random_step += face_list[face_index]
    random_step += angle_list[angle_index]

    return random_step.strip()     # 去掉空格符


# 魔方求解服务回调函数
def kociemba_handle_function(req):
    rospy.loginfo("Request %s" %req.six_face_str)
    solve_str = ""  # 求解列表

    try:
        solve_str = kociemba.solve(req.six_face_str)   # 魔方解序生成初始序列
        rospy.loginfo(solve_str)            # 输出求解的步骤
    except:
        rospy.logwarn("Request Error!")
        return KociembaSolveResponse()      # 处理错误，返回空

    return KociembaSolveResponse(solve_str) # 处理正确，返回解序字符串


# 魔方乱序服务回调函数
def random_handle_function(req):
    rospy.loginfo("Request %d" %req.step_num)
    random_list = []
    random_str = ""     # 乱序列表

    if req.step_num > 0 and req.step_num <= 100:    # 限制打乱步数范围在1~100以内
        for i in range(req.step_num):
            # 获取一个随机步骤函数
            step = get_random_step()
            if i > 0:   # 随机序列长度大于0
                while step[0] == random_list[-1][0]:  # 新生成步骤与上一个步骤是拧动同一个面
                    step = get_random_step()    # 重新生成一个操作
                
            random_list.append(step)            # 添加新生成的步骤

        random_str = ' '.join(random_list)      # 将列表元素转换为字符串，分隔符为空格
        rospy.loginfo(random_str)               # 输出乱序的步骤
    else:
        rospy.logwarn("Request Error!")
        return RandomSolveResponse()        # 处理错误，返回空

    return RandomSolveResponse(random_str)  # 处理正确，返回乱序字符串


if __name__ == "__main__":
    # ros节点初始化
    rospy.init_node('kociemba_solve_node', anonymous=True)
    # 创建魔方求解服务回调函数
    ser_1 = rospy.Service("kociemba_solve", KociembaSolve, kociemba_handle_function)
    # 创建魔方乱序服务回调函数
    ser_2 = rospy.Service("random_solve", RandomSolve, random_handle_function)

    rospy.loginfo("kociemba_solve_node_start")

    rospy.spin()



