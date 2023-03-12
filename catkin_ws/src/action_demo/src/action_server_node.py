#!/usr/bin/env python3
# coding:utf-8
import rospy
import actionlib
from std_msgs.msg import String
from action_demo.msg import ActTestAction, ActTestFeedback, ActTestResult


class ActionServer:
    def __init__(self):
        self.server = actionlib.SimpleActionServer('action_test', ActTestAction, self.execute, False)
        self.server.start()     # 启动服务

    def execute(self, goal):
        feedback = ActTestFeedback()
        result = ActTestResult()

        rate = rospy.Rate(2)   # 2hz

        rospy.loginfo("Execute Start:%d" %goal.step_num)

        for i in range(goal.step_num):
            if self.server.is_preempt_requested():   # 是否发生中断
                result.result = "AWSL"
                self.server.set_preempted(result, "exec preempted")
                return
            feedback.progress = i/goal.step_num            
            self.server.publish_feedback(feedback)   # 发布过程反馈信息
            rospy.loginfo("FeedBack: %.2f" %feedback.progress)
            rate.sleep()

        result.result = "Result"
        self.server.set_succeeded(result, "completed successfully")   # 发布完成信息


if __name__ == "__main__":
    rospy.init_node("action_server_node")       # 动作服务器节点    

    server = ActionServer()   # 创建action服务器

    rospy.loginfo("Action Server Node Start")

    rospy.spin()


