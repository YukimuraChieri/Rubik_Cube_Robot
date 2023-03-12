#!/usr/bin/env python3
# coding:utf-8
import rospy
import actionlib
from std_msgs.msg import String
from action_demo.msg import ActTestAction, ActTestGoal

# 当action激活后会调用该函数一次
def action_callback():
    rospy.loginfo("goal action")    

# 当action完成后会调用该回调函数一次
def done_callback(state, res):    
    rospy.loginfo(state)
    rospy.loginfo("Finish: %s" %res.result)

# 收到feedback后调用该回调函数
def feedback_callback(fb):
    rospy.loginfo("Progress: %.2f" %fb.progress)
    # if fb.progress > 0.6:
    #     client.cancel_goal()


if __name__ == "__main__":
    rospy.init_node("action_client_node")       # 动作客户端节点

    client = actionlib.SimpleActionClient("action_test", ActTestAction)
    client.wait_for_server()

    rate = rospy.Rate(10)   # 10hz

    while not rospy.is_shutdown():
        num = input("Please Input Goal:")
        num = int(num)
        goal = ActTestGoal()
        goal.step_num = num
        client.send_goal(goal, done_callback, action_callback, feedback_callback)

        rate.sleep()
    
    rospy.spin()


