#!/usr/bin/env python3
# coding=utf-8
"""
Author:   电信187 朱韬亮 202032000342
Date:     2022/4/10 9:34
Note:     利用二叉树结构进行路径规划程序
"""
import rospy
from std_msgs.msg import String
from path_planning.srv import PathPlanning, PathPlanningResponse
from binaryTreeCreate import *
import sys

# 服务回调函数
def handle_function(req):
    # 创建二叉树
    root, goal_node = CreateBinaryTree(req.hand_axis, req.solve_str)

    print("goal_node", goal_node.data, goal_node.distance)

    solve_queue = find_solve_path(goal_node)  # 寻找解序路径

    result = FinalResult(solve_queue)

    PreOrder(root)  # 绘制二叉树(先序遍历)

    print(result)

    res_list = result.split()

    print("机械步数：", len(res_list))

    graph.layout('dot')
    graph.draw('./bin_tree.jpg')

    return PathPlanningResponse(result)


if __name__ == '__main__':
    # ros节点初始化
    rospy.init_node('path_planning_node', anonymous=True)
    # 创建服务回调函数
    ser = rospy.Service("path_planning", PathPlanning, handle_function)

    rospy.loginfo("path_planning_node_start")

    rospy.spin()



