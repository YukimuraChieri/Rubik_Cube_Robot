#!/usr/bin/env python3
# coding=utf-8
import rospy
from std_msgs.msg import String
from sensor_msgs.msg import Image
import sys
import numpy as np
import cv2
import time
from cv_bridge import CvBridge, CvBridgeError
from face_read.srv import ReadTwoFaces, ReadTwoFacesResponse
from face_read.srv import GetParameters, GetParametersResponse
from face_read.srv import SetParameters, SetParametersResponse
from image_proc import *
import os


left_img = np.zeros([480, 640, 3], np.uint8)    # 左摄像头拍摄图像
right_img = np.zeros([480, 640, 3], np.uint8)   # 右摄像头拍摄图像


# 左摄像头图像数据接收回调函数
def left_callback(img_msg):
    global left_img     # 左摄像头拍摄图像
    cv_bridge = CvBridge()
    try:
        left_img = cv_bridge.imgmsg_to_cv2(img_msg, desired_encoding="bgr8")
        # rospy.loginfo("left camera img")
    except CvBridgeError as err:
        print(err)


# 右摄像头图像数据接收回调函数
def right_callback(img_msg):
    global right_img    # 右摄像头拍摄图像
    cv_bridge = CvBridge()
    try:
        right_img = cv_bridge.imgmsg_to_cv2(img_msg, desired_encoding="bgr8")
        # rospy.loginfo("right camera img")
    except CvBridgeError as err:
        print(err)


# 服务回调函数，读取魔方相邻两面
def handle_readfaces(req):
    global right_img    # 右摄像头拍摄图像
    global left_img     # 左摄像头拍摄图像

    up_face = ""        # 上表面色块序列
    down_face = ""      # 下表面色块序列

    left_face = ""      # 左面色块序列 
    right_face = ""     # 右面色块序列

    img_path = "/home/pi/project/catkin_ws/src/face_read/img/"  # 图片保存路径

    img_list = []       # 图片列表
    left_points = []    # 左基准点列表
    right_points = []   # 右基准点列表

    rospy.loginfo("Request %s" %req.side)   # 打印请求信息

    for i in range(6):  # 从参数管理器初始化左摄像头基准点
        x = rospy.get_param('/camera/left/point'+str(i+1)+'/x')     # 获取左摄像头基准点坐标X值
        y = rospy.get_param('/camera/left/point'+str(i+1)+'/y')     # 获取左摄像头基准点坐标Y值
        left_points.append([x, y])  # 将获取点添加到左基准点列表
    
    for i in range(6):  # 从参数管理器初始化右摄像头基准点 
        x = rospy.get_param('/camera/right/point'+str(i+1)+'/x')    # 获取右摄像头基准点坐标X值
        y = rospy.get_param('/camera/right/point'+str(i+1)+'/y')    # 获取右摄像头基准点坐标Y值
        right_points.append([x, y]) # 将获取点添加到右基准点列表

    # 左摄像头拍摄图片识别
    if req.side == "left":
        # 上表面取色框参数
        up_boxs = FaceBoxs(pos_LU=left_points[0], pos_RU=left_points[1], pos_LD=left_points[5], pos_RD=left_points[2])
        # 下表面取色框参数
        down_boxs = FaceBoxs(pos_LU=left_points[5], pos_RU=left_points[2], pos_LD=left_points[4], pos_RD=left_points[3])
        left_faces = CubeReadFaceNew(up_boxs=up_boxs, down_boxs=down_boxs, img=left_img)
        up_face, down_face = left_faces.readTwoFaces()
        # 保存图像
        # t = int(time.time()*100) % 36000    # 生成时间戳
        # cv2.imwrite(img_path+req.side+"_faces"+str(t)+".jpg", left_img)

        return ReadTwoFacesResponse(up_face, down_face)

    # 右摄像头拍摄图片识别
    elif req.side == "right":
        # 上表面取色框参数
        up_boxs = FaceBoxs(pos_LU=right_points[0], pos_RU=right_points[1], pos_LD=right_points[5], pos_RD=right_points[2])
        # 下表面取色框参数
        down_boxs = FaceBoxs(pos_LU=right_points[5], pos_RU=right_points[2], pos_LD=right_points[4], pos_RD=right_points[3])
        right_faces = CubeReadFaceNew(up_boxs=up_boxs, down_boxs=down_boxs, img=right_img)
        up_face, down_face = right_faces.readTwoFaces()
        # 保存图像
        # t = int(time.time()*100) % 36000    # 生成时间戳
        # cv2.imwrite(img_path+req.side+"_faces"+str(t)+".jpg", right_img)

        return ReadTwoFacesResponse(up_face, down_face)

    # 同时读取两个摄像头(旧版的识别方法，速度慢但识别的稳定性高)
    elif req.side == "both":
        left_boxs = FaceBoxs(pos_LU=left_points[0], pos_RU=left_points[1], pos_LD=left_points[5], pos_RD=left_points[2])
        right_boxs = FaceBoxs(pos_LU=right_points[0], pos_RU=right_points[1], pos_LD=right_points[5], pos_RD=right_points[2])

        faces = CubeReadFace(left_boxs=left_boxs, right_boxs=right_boxs, left_img=left_img, right_img=right_img)

        left_face, right_face = faces.readTwoFaces()

        # # 保存图像
        # t = int(time.time()*100) % 36000    # 生成时间戳
        # cv2.imwrite(img_path+"left_face"+str(t)+".jpg", left_img)
        # cv2.imwrite(img_path+"right_face"+str(t)+".jpg", right_img)

        return ReadTwoFacesResponse(left_face, right_face)


# 服务回调函数，获取当前坐标点参数
def handle_getpara(req):    
    paras = ""    

    for i in range(6):
        x = rospy.get_param('/camera/left/point'+str(i+1)+'/x')     # 获取左摄像头基准点坐标X值
        y = rospy.get_param('/camera/left/point'+str(i+1)+'/y')     # 获取左摄像头基准点坐标Y值
        paras += str(x) + "," + str(y) + ";"     # 转换为字符串并添加到para
    
    for i in range(6):
        x = rospy.get_param('/camera/right/point'+str(i+1)+'/x')    # 获取右摄像头基准点坐标X值
        y = rospy.get_param('/camera/right/point'+str(i+1)+'/y')    # 获取右摄像头基准点坐标Y值
        paras += str(x) + "," + str(y) + ";"     # 转换为字符串并添加到para
    
    paras = paras.strip(";")    # 去掉首尾的';'字符

    rospy.loginfo("GetPara %s" %paras)
    
    return GetParametersResponse(paras)


# 服务回调函数，设置坐标点参数
def handle_setpara(req):

    rospy.loginfo("Request Set Para %s" %req.paras)

    data_str = req.paras.strip(";") # 去掉首尾的';'字符
    points = data_str.split(';')    # 按分号分割请求数据字符串   

    if len(points) != 12:   # 基准点数量不为12个
        rospy.logwarn("Request Error") # 输出警告
        feedback = "Error"  # 返回错误
        return SetParametersResponse(feedback)


    for i, point in enumerate(points):
        [x, y] = point.split(',')     # 按逗号分割基准点坐标字符串
        if i < 6:
            rospy.set_param('/camera/left/point'+str(i+1)+'/x', int(x))     # 设置左摄像头基准点坐标X值
            rospy.set_param('/camera/left/point'+str(i+1)+'/y', int(y))     # 设置左摄像头基准点坐标Y值            
        elif i < 12:
            rospy.set_param('/camera/right/point'+str(i-5)+'/x', int(x))    # 设置右摄像头基准点坐标X值
            rospy.set_param('/camera/right/point'+str(i-5)+'/y', int(y))    # 设置右摄像头基准点坐标Y值            
    
    # rospy.dump('../config/camera_points.yaml')
    # 保存参数，但是参数文件的路径需要与命令中完全一致，如果将此功能包移植到其他地方可能就无法执行
    os.system('rosparam dump /home/pi/project/catkin_ws/src/face_read/config/camera_points.yaml /camera')

    feedback = "OK"
    
    return SetParametersResponse(feedback)


if __name__ == "__main__":

    # ros节点初始化
    rospy.init_node('face_read_node', anonymous=True)

    # 订阅左摄像头图像数据
    rospy.Subscriber('left_cam/image_raw', Image, left_callback, queue_size=1)
    # 订阅右摄像头图像数据
    rospy.Subscriber('right_cam/image_raw', Image, right_callback, queue_size=1)
    # 创建服务回调函数
    ser = rospy.Service("read_two_faces", ReadTwoFaces, handle_readfaces)   # 读取两面服务
    ser = rospy.Service("get_para", GetParameters, handle_getpara)          # 获取参数服务
    ser = rospy.Service("set_para", SetParameters, handle_setpara)          # 设置参数服务
    
    rospy.loginfo("face_read_node_start")

    rospy.spin()    # 




