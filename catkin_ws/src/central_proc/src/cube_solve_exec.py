#!/usr/bin/env python3
# coding:utf-8
"""
Author: 电信187 朱韬亮 202032000342
Date:   2022/4/19 11:21
Note:   魔方解序动作执行节点
"""
import rospy
import actionlib
from std_msgs.msg import String
from stm32_serial.srv import Control
from central_proc.msg import CubeSolveExecAction, CubeSolveExecFeedback, CubeSolveExecResult
import time
import sys


class CubeSolveServer:
    def __init__(self):
        self.server = actionlib.SimpleActionServer('do_cube_solve', CubeSolveExecAction, self.execute_solve, False)
        self.server.start()     # 启动服务
    
    # 魔方解序动作指令执行方法
    def execute_solve(self, goal):

        feedback = CubeSolveExecFeedback()
        result = CubeSolveExecResult()

        rospy.loginfo("Cube Read Execute Start!")

        rospy.loginfo("Execute Start:%s" %goal.cmd_list)

        cmd_list = goal.cmd_list.split(' ')     # 按空格分割为序列

        rosp = stm32("A1")     # 调用服务，夹紧左夹爪
        rosp = stm32("B1")     # 调用服务，夹紧右夹爪

        for cmd in cmd_list:
            try:
                rosp = stm32(cmd)     # 调用服务，控制机械臂运动
                rospy.loginfo("Message from Server:%s" %rosp.feedback)
            except rospy.ServiceException:
                rospy.logwarn("Service call failed")
                result.result = "Error"
                self.server.set_aborted(result, "exec aborted")
                return
            if self.server.is_preempt_requested():   # 是否发生中断
                result.result = "Stop"
                self.server.set_preempted(result, "exec preempted")
                return
            else:
                feedback.now_cmd = cmd
                self.server.publish_feedback(feedback)   # 发布过程反馈信息
        
        result.result = "Finish"
        self.server.set_succeeded(result)   # 发布完成信息


if __name__ == "__main__":
    rospy.init_node("cube_solve_node")          # 初始化魔方解序节点
    rospy.wait_for_service('control')           # 等待接入底层控制服务节点

    stm32 = rospy.ServiceProxy('control', Control)

    server = CubeSolveServer()   # 创建action服务器

    rospy.loginfo("Cube Solve Node Start")

    rospy.spin()


