"""
Author:   电信187 朱韬亮 202032000342
Date:     2022/5/5 19:21
Note:     魔方的两相邻面识别，图像处理部分，两种识别方法的合并
"""
from math import *
import numpy as np
import cv2
# import matplotlib.pyplot as plt
# import matplotlib.patches as mpathes
# from matplotlib.font_manager import FontProperties

'''
HSV模型中颜色的参数分别是：色调（H），饱和度（S），明度（V）
下面的值是要识别的颜色范围
'''
############################ 参数一，适用于普亮磨砂面魔方 ##################################
# # 红色颜色分量范围
# RedLower_L = np.array([0, 43, 46])
# RedUpper_L = np.array([8, 255, 255])
# RedLower_H = np.array([160, 43, 46])
# RedUpper_H = np.array([180, 255, 255])
# # 绿色颜色分量范围
# GreenLower = np.array([35, 43, 46])
# GreenUpper = np.array([89, 255, 255])
# # 黄色颜色分量范围
# YellowLower = np.array([20, 43, 46])
# YellowUpper = np.array([32, 255, 255])
# # 蓝色颜色分量范围
# BlueLower = np.array([90, 43, 46])
# BlueUpper = np.array([120, 255, 255])
# # 橙色颜色分量范围
# OrangeLower = np.array([9, 43, 46])
# OrangeUpper = np.array([24, 255, 255])
# # 白色颜色分量范围
# WhiteLower = np.array([0, 0, 160])
# WhiteUpper = np.array([180, 40, 255])

############################ 参数二，适用于中高亮光面魔方 ##################################
# 红色颜色分量范围
RedLower_L = np.array([0, 43, 46])
RedUpper_L = np.array([8, 255, 255])
RedLower_H = np.array([146, 43, 46])
RedUpper_H = np.array([180, 255, 255])
# 绿色颜色分量范围
GreenLower = np.array([51, 43, 46])
GreenUpper = np.array([89, 255, 255])
# 黄色颜色分量范围
YellowLower = np.array([27, 43, 46])
YellowUpper = np.array([51, 255, 255])
# 蓝色颜色分量范围
BlueLower = np.array([89, 43, 46])
BlueUpper = np.array([145, 255, 255])
# 橙色颜色分量范围
OrangeLower = np.array([9, 43, 46])
OrangeUpper = np.array([24, 255, 255])
# 白色颜色分量范围
WhiteLower = np.array([0, 0, 160])
WhiteUpper = np.array([180, 40, 255])



# 魔方取色框类
class FaceBoxs(object):

    cube_box_size = [40, 40]    # 取色框大小
    box_origin = [25, 20]       # 取色框原点坐标
    box_step = 100              # 取色框移动步长

    def __init__(self, pos_LU, pos_RU, pos_LD, pos_RD):
        self.pos_LU = pos_LU    # 左上角点坐标
        self.pos_RU = pos_RU    # 右上角点坐标
        self.pos_LD = pos_LD    # 左下角点坐标
        self.pos_RD = pos_RD    # 右下角点坐标

    # 绘制取色框
    def draw_boxs(self, img):
        img_1 = img.copy()

        # 仿射变换，矫正图像
        pts1 = np.float32([self.pos_LU, self.pos_RU, self.pos_LD, self.pos_RD])
        pts2 = np.float32([[0, 0], [300, 0], [0, 300], [300, 300]])

        M = cv2.getPerspectiveTransform(pts1, pts2)
        dst = cv2.warpPerspective(img_1, M, (int(pts2[3][0]), int(pts2[3][1])))

        for raw in range(3):
            origin_y = self.box_origin[1] + self.box_step * raw
            for col in range(3):
                origin_x = self.box_origin[0] + self.box_step * col
                start_point = (origin_x, origin_y)
                end_point = (origin_x + self.cube_box_size[0], origin_y + self.cube_box_size[1])
                cv2.rectangle(dst, start_point, end_point, (0, 255, 0), 2)
        return dst

    # 获取取色框图片
    def get_boxs_img(self, img):
        # 仿射变换，矫正图像
        pts1 = np.float32([self.pos_LU, self.pos_RU, self.pos_LD, self.pos_RD])
        pts2 = np.float32([[0, 0], [300, 0], [0, 300], [300, 300]])

        M = cv2.getPerspectiveTransform(pts1, pts2)
        dst = cv2.warpPerspective(img, M, (int(pts2[3][0]), int(pts2[3][1])))

        # 取色框图片列表
        img_list = []

        for raw in range(3):
            origin_y = self.box_origin[1] + self.box_step * raw
            for col in range(3):
                origin_x = self.box_origin[0] + self.box_step * col
                start_point = (origin_x, origin_y)
                end_point = (origin_x + self.cube_box_size[0], origin_y + self.cube_box_size[1])
                box_img = dst[start_point[1]:end_point[1], start_point[0]:end_point[0]]
                img_list.append(box_img)
        return img_list


# 读取魔方两面类(旧版本识别方法，速度慢但稳定性高)
class CubeReadFace(object):

    def __init__(self, left_boxs, right_boxs, left_img, right_img):
        self.left_boxs = left_boxs      # 左摄像头取色框参数
        self.right_boxs = right_boxs    # 右摄像头取色框参数
        self.left_img = left_img        # 左摄像头拍摄图片
        self.right_img = right_img      # 右摄像头拍摄图片

    # 读取面转换
    def CubeTrans(self, left_list, right_list):
        # 预分配内存
        faceMat_1 = np.zeros([3, 3], dtype=np.string_)
        faceMat_2 = np.zeros([3, 3], dtype=np.string_)

        # 将左面序列转换为面矩阵
        for i, color in enumerate(left_list):
            faceMat_1[int(i / 3), i % 3] = color

        # 将右面序列转换为面矩阵
        for i, color in enumerate(right_list):
            faceMat_2[int(i / 3), i % 3] = color

        # 取中心色块
        cb = [faceMat_1[1, 1], faceMat_2[1, 1]]

        # 依据读取两面的中心色块，进行相应旋转
        if cb == [b'F', b'R']:
            faceMat_1 = np.rot90(faceMat_1, -1)
            faceMat_2 = np.rot90(faceMat_2, 1)
        elif cb == [b'R', b'F']:
            faceMat_1 = np.rot90(faceMat_1, 1)
            faceMat_2 = np.rot90(faceMat_2, -1)

        elif cb == [b'F', b'U']:
            faceMat_1 = np.rot90(faceMat_1, 0)
            faceMat_2 = np.rot90(faceMat_2, 2)
        elif cb == [b'U', b'F']:
            faceMat_1 = np.rot90(faceMat_1, 2)
            faceMat_2 = np.rot90(faceMat_2, 0)

        elif cb == [b'F', b'L']:
            faceMat_1 = np.rot90(faceMat_1, 1)
            faceMat_2 = np.rot90(faceMat_2, -1)
        elif cb == [b'L', b'F']:
            faceMat_1 = np.rot90(faceMat_1, -1)
            faceMat_2 = np.rot90(faceMat_2, 1)

        elif cb == [b'F', b'D']:
            faceMat_1 = np.rot90(faceMat_1, 2)
            faceMat_2 = np.rot90(faceMat_2, 0)
        elif cb == [b'D', b'F']:
            faceMat_1 = np.rot90(faceMat_1, 0)
            faceMat_2 = np.rot90(faceMat_2, 2)

        elif cb == [b'R', b'B']:
            faceMat_1 = np.rot90(faceMat_1, -1)
            faceMat_2 = np.rot90(faceMat_2, 1)
        elif cb == [b'B', b'R']:
            faceMat_1 = np.rot90(faceMat_1, 1)
            faceMat_2 = np.rot90(faceMat_2, -1)

        elif cb == [b'R', b'U']:
            faceMat_1 = np.rot90(faceMat_1, 0)
            faceMat_2 = np.rot90(faceMat_2, -1)
        elif cb == [b'U', b'R']:
            faceMat_1 = np.rot90(faceMat_1, -1)
            faceMat_2 = np.rot90(faceMat_2, 0)

        elif cb == [b'R', b'D']:
            faceMat_1 = np.rot90(faceMat_1, 2)
            faceMat_2 = np.rot90(faceMat_2, -1)
        elif cb == [b'D', b'R']:
            faceMat_1 = np.rot90(faceMat_1, -1)
            faceMat_2 = np.rot90(faceMat_2, 2)

        elif cb == [b'B', b'L']:
            faceMat_1 = np.rot90(faceMat_1, -1)
            faceMat_2 = np.rot90(faceMat_2, 1)
        elif cb == [b'L', b'B']:
            faceMat_1 = np.rot90(faceMat_1, 1)
            faceMat_2 = np.rot90(faceMat_2, -1)

        elif cb == [b'B', b'U']:
            faceMat_1 = np.rot90(faceMat_1, 0)
            faceMat_2 = np.rot90(faceMat_2, 0)
        elif cb == [b'U', b'B']:
            faceMat_1 = np.rot90(faceMat_1, 0)
            faceMat_2 = np.rot90(faceMat_2, 0)

        elif cb == [b'B', b'D']:
            faceMat_1 = np.rot90(faceMat_1, 2)
            faceMat_2 = np.rot90(faceMat_2, 2)
        elif cb == [b'D', b'B']:
            faceMat_1 = np.rot90(faceMat_1, 2)
            faceMat_2 = np.rot90(faceMat_2, 2)

        elif cb == [b'L', b'U']:
            faceMat_1 = np.rot90(faceMat_1, 0)
            faceMat_2 = np.rot90(faceMat_2, 1)
        elif cb == [b'U', b'L']:
            faceMat_1 = np.rot90(faceMat_1, 1)
            faceMat_2 = np.rot90(faceMat_2, 0)

        elif cb == [b'L', b'D']:
            faceMat_1 = np.rot90(faceMat_1, 2)
            faceMat_2 = np.rot90(faceMat_2, 1)
        elif cb == [b'D', b'L']:
            faceMat_1 = np.rot90(faceMat_1, 1)
            faceMat_2 = np.rot90(faceMat_2, 2)

        faceStr_1 = str(faceMat_1.reshape(1, 9)[0].tostring(), 'utf-8')
        faceStr_2 = str(faceMat_2.reshape(1, 9)[0].tostring(), 'utf-8')

        return faceStr_1, faceStr_2

    # 读取魔方相邻两面的序列并旋正
    def readTwoFaces(self):
        left_face = readOneFace(para_boxs=self.left_boxs, img=self.left_img)   # 读取左摄像头拍摄面
        right_face = readOneFace(para_boxs=self.right_boxs, img=self.right_img)  # 读取右摄像头拍摄面

        left_result, right_result = self.CubeTrans(left_face, right_face)     # 根据左右摄像头拍摄方向对读取结果进行旋正

        return left_result, right_result    # 返回最终结果


# 读取魔方两面类(新版本识别方法，速度快但稳定性低，对外部光照条件要求高)
class CubeReadFaceNew(object):

    def __init__(self, up_boxs, down_boxs, img):
        self.up_boxs = up_boxs      # 上表面取色框参数
        self.down_boxs = down_boxs  # 下表面取色框参数
        self.img = img              # 摄像头拍摄图片

    # 蓝光抑制
    def blueLoss(self, img, gain):
        loss_img = img.copy()
        print(img[:, :, 0].shape)

        loss_img[:, :, 0] = loss_img[:, :, 0].dot(gain)

        return loss_img

    # 读取面转换
    def CubeTrans(self, left_list, right_list):
        # 预分配内存
        faceMat_1 = np.zeros([3, 3], dtype=np.string_)
        faceMat_2 = np.zeros([3, 3], dtype=np.string_)

        # 将上表面序列转换为面矩阵
        for i, color in enumerate(left_list):
            faceMat_1[int(i / 3), i % 3] = color

        # 将下表面序列转换为面矩阵
        for i, color in enumerate(right_list):
            faceMat_2[int(i / 3), i % 3] = color

        # 取中心色块
        cb = [faceMat_1[1, 1], faceMat_2[1, 1]]

        # 依据读取两面的中心色块，进行相应旋转
        if cb == [b'F', b'R']:
            faceMat_1 = np.rot90(faceMat_1, 1)
            faceMat_2 = np.rot90(faceMat_2, 1)
        elif cb == [b'R', b'F']:
            faceMat_1 = np.rot90(faceMat_1, -1)
            faceMat_2 = np.rot90(faceMat_2, -1)

        elif cb == [b'F', b'U']:
            faceMat_1 = np.rot90(faceMat_1, 2)
            faceMat_2 = np.rot90(faceMat_2, 2)
        elif cb == [b'U', b'F']:
            faceMat_1 = np.rot90(faceMat_1, 0)
            faceMat_2 = np.rot90(faceMat_2, 0)

        elif cb == [b'F', b'L']:
            faceMat_1 = np.rot90(faceMat_1, -1)
            faceMat_2 = np.rot90(faceMat_2, -1)
        elif cb == [b'L', b'F']:
            faceMat_1 = np.rot90(faceMat_1, 1)
            faceMat_2 = np.rot90(faceMat_2, 1)

        elif cb == [b'F', b'D']:
            faceMat_1 = np.rot90(faceMat_1, 0)
            faceMat_2 = np.rot90(faceMat_2, 0)
        elif cb == [b'D', b'F']:
            faceMat_1 = np.rot90(faceMat_1, 2)
            faceMat_2 = np.rot90(faceMat_2, 2)

        elif cb == [b'R', b'B']:
            faceMat_1 = np.rot90(faceMat_1, 1)
            faceMat_2 = np.rot90(faceMat_2, 1)
        elif cb == [b'B', b'R']:
            faceMat_1 = np.rot90(faceMat_1, -1)
            faceMat_2 = np.rot90(faceMat_2, -1)

        elif cb == [b'R', b'U']:
            faceMat_1 = np.rot90(faceMat_1, 2)
            faceMat_2 = np.rot90(faceMat_2, -1)
        elif cb == [b'U', b'R']:
            faceMat_1 = np.rot90(faceMat_1, 1)
            faceMat_2 = np.rot90(faceMat_2, 0)

        elif cb == [b'R', b'D']:
            faceMat_1 = np.rot90(faceMat_1, 0)
            faceMat_2 = np.rot90(faceMat_2, -1)
        elif cb == [b'D', b'R']:
            faceMat_1 = np.rot90(faceMat_1, 1)
            faceMat_2 = np.rot90(faceMat_2, 2)

        elif cb == [b'B', b'L']:
            faceMat_1 = np.rot90(faceMat_1, 1)
            faceMat_2 = np.rot90(faceMat_2, 1)
        elif cb == [b'L', b'B']:
            faceMat_1 = np.rot90(faceMat_1, -1)
            faceMat_2 = np.rot90(faceMat_2, -1)

        elif cb == [b'B', b'U']:
            faceMat_1 = np.rot90(faceMat_1, 2)
            faceMat_2 = np.rot90(faceMat_2, 0)
        elif cb == [b'U', b'B']:
            faceMat_1 = np.rot90(faceMat_1, 2)
            faceMat_2 = np.rot90(faceMat_2, 0)

        elif cb == [b'B', b'D']:
            faceMat_1 = np.rot90(faceMat_1, 0)
            faceMat_2 = np.rot90(faceMat_2, 2)
        elif cb == [b'D', b'B']:
            faceMat_1 = np.rot90(faceMat_1, 0)
            faceMat_2 = np.rot90(faceMat_2, 2)

        elif cb == [b'L', b'U']:
            faceMat_1 = np.rot90(faceMat_1, 2)
            faceMat_2 = np.rot90(faceMat_2, 1)
        elif cb == [b'U', b'L']:
            faceMat_1 = np.rot90(faceMat_1, -1)
            faceMat_2 = np.rot90(faceMat_2, 0)

        elif cb == [b'L', b'D']:
            faceMat_1 = np.rot90(faceMat_1, 0)
            faceMat_2 = np.rot90(faceMat_2, 1)
        elif cb == [b'D', b'L']:
            faceMat_1 = np.rot90(faceMat_1, -1)
            faceMat_2 = np.rot90(faceMat_2, 2)

        faceStr_1 = str(faceMat_1.reshape(1, 9)[0].tostring(), 'utf-8')
        faceStr_2 = str(faceMat_2.reshape(1, 9)[0].tostring(), 'utf-8')

        return faceStr_1, faceStr_2

    # 读取魔方相邻两面的序列并旋正
    def readTwoFaces(self):
        up_face = readOneFace(para_boxs=self.up_boxs, img=self.img)        # 读取上表面色块序列
        down_face = readOneFace(para_boxs=self.down_boxs, img=self.img)    # 读取下表面色块序列

        up_result, down_result = self.CubeTrans(up_face, down_face)  # 根据摄像头拍摄方向对读取面进行旋正

        return up_result, down_result  # 返回最终结果


# 求取色框中颜色的HSV均值
def HSV_mean(img):
    # # 求图像RGB平均值
    # R_mean = np.mean(img[:, :, 2])  # 红色分量均值
    # G_mean = np.mean(img[:, :, 1])  # 绿色分量均值
    # B_mean = np.mean(img[:, :, 0])  # 蓝色分量均值

    # # 把BGR值转换为HSV值
    # HSV = cv2.cvtColor(np.array([[[B_mean, G_mean, R_mean]]], dtype=np.uint8), cv2.COLOR_BGR2HSV)

    hsv_img = cv2.cvtColor(img, cv2.COLOR_BGR2HSV)
    H_mean = np.mean(hsv_img[:, :, 0])
    S_mean = np.mean(hsv_img[:, :, 1])
    V_mean = np.mean(hsv_img[:, :, 2])

    HSV = np.array([[[H_mean, S_mean, V_mean]]])

    return HSV  # 返回HSV值（单像素）


# 单面读取函数
def readOneFace(para_boxs, img):
    result = ""     # 摄像头读取单面色块结果字符串

    box_list = para_boxs.get_boxs_img(img)

    # 遍历取色区域列表
    for i, box in enumerate(box_list):
        hsv = HSV_mean(box)
        # print(hsv)
        mask_U = cv2.inRange(hsv, YellowLower, YellowUpper)  # 识别黄色
        mask_RL = cv2.inRange(hsv, RedLower_L, RedUpper_L)  # 识别红色
        mask_RH = cv2.inRange(hsv, RedLower_H, RedUpper_H)  # 识别红色
        mask_F = cv2.inRange(hsv, BlueLower, BlueUpper)  # 识别蓝色
        mask_D = cv2.inRange(hsv, WhiteLower, WhiteUpper)  # 识别白色
        mask_L = cv2.inRange(hsv, OrangeLower, OrangeUpper)  # 识别橘色
        mask_B = cv2.inRange(hsv, GreenLower, GreenUpper)  # 识别绿色

        if mask_U[0, 0] == 255:
            result += 'U'  # 识别为顶面色块
        elif mask_RL[0, 0] == 255 or mask_RH[0, 0] == 255:
            # elif mask_RL[0, 0] == 255:
            result += 'R'  # 识别为右面色块
        elif mask_F[0, 0] == 255:
            result += 'F'  # 识别为前面色块
        elif mask_D[0, 0] == 255:
            result += 'D'  # 识别为底面色块
        elif mask_L[0, 0] == 255:
            result += 'L'  # 识别为左面色块
        elif mask_B[0, 0] == 255:
            result += 'B'  # 识别为后面色块
        else:
            result += 'X'  # 未识别到

    return result   # 返回识别结果字符串


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


if __name__ == "__main__":
    img_1 = cv2.imread("./img/left_img_1.jpg")
    img_2 = cv2.imread("./img/right_img_1.jpg")

    left_boxs = FaceBoxs(pos_LU=(140, 60), pos_RU=(455, 55), pos_LD=(125, 368), pos_RD=(470, 365))
    right_boxs = FaceBoxs(pos_LU=(146, 67), pos_RU=(443, 55), pos_LD=(149, 360), pos_RD=(473, 340))

    faces = CubeReadFace(left_boxs=left_boxs, right_boxs=right_boxs, left_img=img_1, right_img=img_2)

    left_face, right_face = faces.readTwoFaces()

    print("左面：", left_face)
    print("右面：", right_face)

    print(facePack([left_face, right_face]))

    img_boxs_left = left_boxs.draw_boxs(img_1)
    img_boxs_right = right_boxs.draw_boxs(img_2)

    box_list = left_boxs.get_boxs_img(img_1)
    # box_list = right_boxs.get_boxs_img(img_2)

    cv2.imshow("img with boxs left", img_boxs_left)
    cv2.imshow("img with boxs right", img_boxs_right)

    cv2.waitKey(0)

    result = ""  # 结果序列

    for i, box in enumerate(box_list):
        hsv = HSV_mean(box)
        # print(hsv)

        mask_U = cv2.inRange(hsv, YellowLower, YellowUpper)  # 识别黄色
        mask_RL = cv2.inRange(hsv, RedLower_L, RedUpper_L)  # 识别红色
        mask_RH = cv2.inRange(hsv, RedLower_H, RedUpper_H)  # 识别红色
        mask_F = cv2.inRange(hsv, BlueLower, BlueUpper)  # 识别蓝色
        mask_D = cv2.inRange(hsv, WhiteLower, WhiteUpper)  # 识别白色
        mask_L = cv2.inRange(hsv, OrangeLower, OrangeUpper)  # 识别橘色
        mask_B = cv2.inRange(hsv, GreenLower, GreenUpper)  # 识别绿色

        if mask_U[0, 0] == 255:
            result += 'U'  # 识别为顶面色块
        elif mask_RL[0, 0] == 255 or mask_RH[0, 0] == 255:
            result += 'R'  # 识别为右面色块
        elif mask_F[0, 0] == 255:
            result += 'F'  # 识别为前面色块
        elif mask_D[0, 0] == 255:
            result += 'D'  # 识别为底面色块
        elif mask_L[0, 0] == 255:
            result += 'L'  # 识别为左面色块
        elif mask_B[0, 0] == 255:
            result += 'B'  # 识别为后面色块
        else:
            result += 'X'  # 未识别到

    #     # BGR转换为RGB格式
    #     box = cv2.cvtColor(box, cv2.COLOR_BGR2RGB)
    #     plt.subplot(3, 3, i+1)
    #     plt.imshow(box)
    #     plt.xticks([]), plt.yticks([])  # 去除坐标轴
    #
    print(result)
    # plt.show()

    print("#####################################################################################################")
    print("图像识别测试")

    face_list = []

    """  第一次识别  """
    left_img = cv2.imread("./img/left_faces1.jpg")
    right_img = cv2.imread("./img/right_faces2.jpg")

    # 显示原始图片
    cv2.imshow("left_img", left_img)
    cv2.imshow("right_img", right_img)

    cv2.waitKey(0)  # 等待按键按下

    # 左摄像头拍摄图片识别
    up_boxs = FaceBoxs(pos_LU=(183, 18), pos_RU=(493, 10), pos_LD=(149, 270), pos_RD=(538, 258))  # 上表面取色框参数
    down_boxs = FaceBoxs(pos_LU=(149, 270), pos_RU=(538, 258), pos_LD=(202, 442), pos_RD=(497, 434))  # 下表面取色框参数

    left_faces = CubeReadFaceNew(up_boxs=up_boxs, down_boxs=down_boxs, img=left_img)

    up_boxs_img = up_boxs.draw_boxs(left_img)
    down_boxs_img = down_boxs.draw_boxs(left_img)

    cv2.imshow("up img with boxs", up_boxs_img)
    cv2.imshow("down img with boxs", down_boxs_img)

    up_face, down_face = left_faces.readTwoFaces()

    print("上表面：", up_face)
    print("下表面：", down_face)

    # 添加到读取面列表
    face_list.append(up_face)
    face_list.append(down_face)

    cv2.waitKey(0)

    # 右摄像头拍摄图片识别
    up_boxs = FaceBoxs(pos_LU=(178, 11), pos_RU=(483, 16), pos_LD=(132, 261), pos_RD=(517, 269))  # 上表面取色框参数
    down_boxs = FaceBoxs(pos_LU=(132, 261), pos_RU=(517, 269), pos_LD=(174, 428), pos_RD=(465, 438))  # 下表面取色框参数

    right_faces = CubeReadFaceNew(up_boxs=up_boxs, down_boxs=down_boxs, img=right_img)

    up_boxs_img = up_boxs.draw_boxs(right_img)
    down_boxs_img = down_boxs.draw_boxs(right_img)

    cv2.imshow("up img with boxs", up_boxs_img)
    cv2.imshow("down img with boxs", down_boxs_img)

    up_face, down_face = right_faces.readTwoFaces()

    print("上表面：", up_face)
    print("下表面：", down_face)

    # 添加到读取面列表
    face_list.append(up_face)
    face_list.append(down_face)

    cv2.waitKey(0)  # 等待按键按下

    """  第二次识别  """
    left_img = cv2.imread("./img/left_faces3.jpg")
    right_img = cv2.imread("./img/right_faces4.jpg")

    # 显示原始图片
    cv2.imshow("left_img", left_img)
    cv2.imshow("right_img", right_img)

    cv2.waitKey(0)  # 等待按键按下

    # 左摄像头拍摄图片识别
    up_boxs = FaceBoxs(pos_LU=(183, 18), pos_RU=(493, 10), pos_LD=(149, 270), pos_RD=(538, 258))  # 上表面取色框参数
    down_boxs = FaceBoxs(pos_LU=(149, 270), pos_RU=(538, 258), pos_LD=(202, 442), pos_RD=(497, 434))  # 下表面取色框参数

    left_faces = CubeReadFaceNew(up_boxs=up_boxs, down_boxs=down_boxs, img=left_img)

    up_boxs_img = up_boxs.draw_boxs(left_img)
    down_boxs_img = down_boxs.draw_boxs(left_img)

    cv2.imshow("up img with boxs", up_boxs_img)
    cv2.imshow("down img with boxs", down_boxs_img)

    up_face, down_face = left_faces.readTwoFaces()

    print("上表面：", up_face)
    print("下表面：", down_face)

    # 添加到读取面列表
    face_list.append(up_face)
    face_list.append(down_face)

    cv2.waitKey(0)

    # 右摄像头拍摄图片识别
    up_boxs = FaceBoxs(pos_LU=(178, 11), pos_RU=(483, 16), pos_LD=(132, 261), pos_RD=(517, 269))  # 上表面取色框参数
    down_boxs = FaceBoxs(pos_LU=(132, 261), pos_RU=(517, 269), pos_LD=(174, 428), pos_RD=(465, 438))  # 下表面取色框参数

    right_faces = CubeReadFaceNew(up_boxs=up_boxs, down_boxs=down_boxs, img=right_img)

    up_boxs_img = up_boxs.draw_boxs(right_img)
    down_boxs_img = down_boxs.draw_boxs(right_img)

    cv2.imshow("up img with boxs", up_boxs_img)
    cv2.imshow("down img with boxs", down_boxs_img)

    up_face, down_face = right_faces.readTwoFaces()

    print("上表面：", up_face)
    print("下表面：", down_face)

    face_list.append(up_face)
    face_list.append(down_face)

    cv2.waitKey(0)

    print("读取面列表：", face_list)

    six_face = facePack(face_list)     # 将读取面合成完整六面

    print("魔方六面：", six_face, len(six_face))


