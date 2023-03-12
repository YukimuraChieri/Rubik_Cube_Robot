"""
Author:   电信187 朱韬亮 202032000342
Date:     2022/3/27 9:31
Note:     魔方状态二叉树结构建立
"""
import pygraphviz as pgv
# from binarytree import Node

# 各面的连接关系字典
link = {'U': 'FLBR', 'R': 'UBDF', 'F': 'LURD', 'D': 'LFRB', 'L': 'UFDB', 'B': 'RULD'}

graph = pgv.AGraph(directed=True, strict=True)


#  二叉树节点类
class Node(object):
    def __init__(self, data, distance=0, id=0, left=None, right=None, parent=None, op=None):
        self.data = data            # 节点数据
        self.left = left            # 左子节点指针
        self.right = right          # 右子节点指针
        self.parent = parent        # 父节点指针
        self.distance = distance    # 节点当前距离
        self.id = id                # 节点ID
        self.op = op                # 操作


# 遍历二叉树(先序)
def PreOrder(root):
    global graph

    if root == None:
        return
    # print(root.data, root.distance, end='; ')

    graph.add_node('node'+str(root.id), shape='ellipse', label=str(root.data)+str(root.distance), style='bold')

    if root.parent != None:
        graph.add_edge('node'+str(root.parent.id), 'node'+str(root.id))

    PreOrder(root.left)
    PreOrder(root.right)


# 二叉树绘制函数
def DrawBinTree(root):
    graph = pgv.AGraph(directed=True, strict=True)

    PreOrder(root)  # 遍历二叉树(先序)

    graph.layout('dot')
    graph.draw('.\\bin_tree.jpg')


# 距离计算函数
def Distance(now, goal):
    val = goal - now
    if val == 0:
        return 0
    elif val == 1 or val == -3:
        # return 2
        return -90
    elif val == 2 or val == -2:
        # return 1
        return 180
    elif val == 3 or val == -1:
        # return 2
        return 90


# 寻找节点列表中最小距离节点函数
def find_node_min(node_list):

    length = len(node_list)     # 获取节点长度
    node_min = None

    if length > 0:
        node_min = node_list[0]

        for i in range(length):     # 冒泡排序
            if node_min.distance > node_list[i].distance:
                node_min = node_list[i]

    return node_min    # 返回列表中最小距离节点


# 状态相同检验函数
def state_check(d1, d2):

    [f1, f2] = d2           # 获取d2状态数据
    d_reverse = [f2, f1]    # 反转状态数据

    if d1 == d2:            # d1状态和d2状态相同
        return True
    elif d1 == d_reverse:   # d1状态和d2反转状态相同
        return True
    else:
        return False


# 创建二叉树
def CreateBinaryTree(hand_axis, solveStr):
    root = Node(data=hand_axis)  # 根节点，初始状态
    cnt = 0

    # 将初始结果序列字符串分割为列表
    solveList = solveStr.split()

    node_list = []
    node_list_next = []
    node_list.append(root)
    for op in solveList:
        for n in node_list:
            f1 = n.data[0]
            f2 = n.data[1]

            if op[0] in link[f2]:
                cnt += 1
                goal = link[f2].index(op[0])  # 目标面序号
                now = link[f2].index(f1)  # 当前面序号
                dis = Distance(now, goal)  # 计算距离

                op_dict = {}  # 操作字典

                if dis == 90:
                    dis = 2
                    op_dict['A'] = [90, 0]   # A轴对应面顺时针翻动90度
                elif dis == -90:
                    dis = 2
                    op_dict['A'] = [-90, 0]  # A轴对应面逆时针翻动90度
                elif dis == 180:
                    dis = 1
                    op_dict['A'] = [180, 0]  # A轴对应面翻动180度
                elif dis == 0:
                    op_dict['A'] = [0, 0]    # A轴对应面不变

                if len(op) == 1:
                    op_dict['A'][1] = 90     # A轴顺时针拧动90度
                elif op[1] == "'":
                    op_dict['A'][1] = -90    # A轴逆时针拧动90度
                elif op[1] == "2":
                    op_dict['A'][1] = 180    # A轴拧动180度

                dis += n.distance  # 距离累加
                n.left = Node(data=[op[0], f2], parent=n, distance=dis, id=cnt, op=op_dict)  # 创建左子节点
                node_list_next.append(n.left)  # 下一层节点列表添加节点

            if op[0] in link[f1]:
                cnt += 1
                goal = link[f1].index(op[0])  # 目标面序号
                now = link[f1].index(f2)  # 当前面序号
                dis = Distance(now, goal)  # 计算距离

                op_dict = {}  # 操作字典
                
                if dis == 90:
                    dis = 2
                    op_dict['B'] = [90, 0]   # B轴对应面顺时针翻动90度
                elif dis == -90:
                    dis = 2
                    op_dict['B'] = [-90, 0]  # B轴对应面逆时针翻动90度
                elif dis == 180:
                    dis = 1
                    op_dict['B'] = [180, 0]  # B轴对应面翻动180度
                elif dis == 0:
                    op_dict['B'] = [0, 0]    # B轴对应面不变

                if len(op) == 1:
                    op_dict['B'][1] = 90     # B轴顺时针拧动90度
                elif op[1] == "'":
                    op_dict['B'][1] = -90    # B轴逆时针拧动90度
                elif op[1] == "2":
                    op_dict['B'][1] = 180    # B轴拧动180度

                dis += n.distance  # 距离累加
                n.right = Node(data=[f1, op[0]], parent=n, distance=dis, id=cnt, op=op_dict)  # 创建右子节点
                node_list_next.append(n.right)  # 下一层节点列表添加节点

        # 剪枝操作
        node_c1 = []  # 第一类状态列表
        node_c2 = []  # 第二类状态列表
        node_c3 = []  # 第三类状态列表
        node_c4 = []  # 第四类状态列表
        c1 = [op[0], link[op[0]][0]]  # 第一类状态
        c2 = [op[0], link[op[0]][1]]  # 第二类状态
        c3 = [op[0], link[op[0]][2]]  # 第三类状态
        c4 = [op[0], link[op[0]][3]]  # 第四类状态
        for n in node_list_next:
            if state_check(n.data, c1):  # 如果与第一类相同
                node_c1.append(n)  # 加入第一类状态列表
            elif state_check(n.data, c2):  # 如果与第二类相同
                node_c2.append(n)  # 加入第二类状态列表
            elif state_check(n.data, c3):  # 如果与第三类相同
                node_c3.append(n)  # 加入第三类状态列表
            elif state_check(n.data, c4):  # 如果与第四类相同
                node_c4.append(n)  # 加入第四类状态列表

        n1 = find_node_min(node_c1)  # 寻找第一类状态节点列表中最小距离节点
        n2 = find_node_min(node_c2)  # 寻找第二类状态节点列表中最小距离节点
        n3 = find_node_min(node_c3)  # 寻找第三类状态节点列表中最小距离节点
        n4 = find_node_min(node_c4)  # 寻找第四类状态节点列表中最小距离节点

        node_list_next.clear()

        if n1 != None:
            node_list_next.append(n1)
        if n2 != None:
            node_list_next.append(n2)
        if n3 != None:
            node_list_next.append(n3)
        if n4 != None:
            node_list_next.append(n4)

        node_c1.clear()  # 清空node_c1列表
        node_c2.clear()  # 清空node_c2列表
        node_c3.clear()  # 清空node_c3列表
        node_c4.clear()  # 清空node_c4列表

        node_list.clear()
        node_list = node_list_next.copy()
        node_list_next.clear()
        for n in node_list:
            print(n.data)
        print('*******************************')

    goal_node = find_node_min(node_list)     # 目标节点
    # goal_node = node_list[0]  # 目标节点

    return root, goal_node


# 寻找解序路径
def find_solve_path(goal_node):
    node = goal_node

    stack = []      # 节点栈
    queue = []      # 节点队列

    while node != None:
        stack.append(node)  # 将当前节点加入节点栈
        node = node.parent

    while len(stack) > 0:
        node = stack.pop()  # 从节点栈弹出一个节点
        queue.append(node)  # 将弹出节点加入节点队列

    return queue    # 返回节点队列


# 单步动作序列生成
def ActionGenerate(op_dict):
    op_str = ""

    val = op_dict.get('A')
    if val != None:
        # 添加机械臂翻动魔方动作序列
        if val[0] == 90:
            op_str += "A0 B- A1 B0 B+ B1 "
            # op_str += "AAxis90 "
        elif val[0] == -90:
            op_str += "A0 B+ A1 B0 B- B1 "
            # op_str += "AAxis-90 "
        elif val[0] == 180:
            if val[1] == 90:
                return "A0 B++ A+ A1 A- "
            elif val[1] == -90:
                return "A0 B++ A- A1 A+ "
            op_str += "A0 B++ A1 "
            # op_str += "AAxis180 "
        # 添加机械臂拧动魔方动作序列
        if val[1] == 90:                # A轴顺时针拧90
            op_str += "A- A0 A+ A1 "
            # op_str += "ARot90 \n"
        elif val[1] == -90:             # A轴逆时针拧90
            op_str += "A+ A0 A- A1 "
            # op_str += "ARot-90 \n"
        elif val[1] == 180:             # A轴拧180
            op_str += "A++ "
            # op_str += "ARot180 \n"

        return op_str

    val = op_dict.get('B')
    if val != None:
        # 添加机械臂翻动魔方动作序列
        if val[0] == 90:
            op_str += "B0 A- B1 A0 A+ A1 "
            # op_str += "BAxis90 "
        elif val[0] == -90:
            op_str += "B0 A+ B1 A0 A- A1 "
            # op_str += "BAxis-90 "
        elif val[0] == 180:
            if val[1] == 90:
                return "B0 A++ B+ B1 B- "
            elif val[1] == -90:
                return "B0 A++ B- B1 B+ "
            op_str += "B0 A++ B1 "
            # op_str += "BAxis180 "
        # 添加机械臂拧动魔方动作序列
        if val[1] == 90:  # B轴顺时针拧90
            op_str += "B- B0 B+ B1 "
            # op_str += "BRot90 \n"
        elif val[1] == -90:  # B轴逆时针拧90
            op_str += "B+ B0 B- B1 "
            # op_str += "BRot-90 \n"
        elif val[1] == 180:  # B轴拧180
            op_str += "B++ "
            # op_str += "BRot180 \n"

        return op_str


# 生成最终的机械动作序列
def FinalResult(queue):
    result = ""

    for node in queue:
        if node.op != None:
            result += ActionGenerate(node.op)     # 单步动作序列生成

    # 去除冗余操作
    result = result.replace('B1 B0 ', '')
    result = result.replace('A1 A0 ', '')

    return result.strip()   # 去掉首尾空格并返回


if __name__ == '__main__':
    import kociemba

    # cubestring = "UDUDUDUDURLRLRLRLRFBFBFBFBFDUDUDUDUDLRLRLRLRLBFBFBFBFB"
    # cubestring = "UDUDUUUUULLLRRLLRLBFBBFFBBBDUDDDUDDDRLRLLRRRRFBFFBBFFF"
    # cubestring = "LBDRUFLRUFLBBRLRURBFLDFDUUFBLDBDFDRUFDURLFLLRRUDDBBFUB"

    # 初始结果序列字符串
    # solveList = kociemba.solve(cubestring)

    solveList = "U F B L F U"
    # solveList = "B' R' D R L F' R' D B' R2 U D2 F2 B2 U' L2 B2 U D"

    # 初始坐标轴，A机械臂对D面，B机械臂对R面
    Axis = "DR"

    # 创建二叉树
    root, goal_node = CreateBinaryTree(Axis, solveList)

    print("goal_node", goal_node.data, goal_node.distance)

    solve_queue = find_solve_path(goal_node)  # 寻找解序路径

    result = FinalResult(solve_queue)

    PreOrder(root)  # 绘制二叉树(先序遍历)

    # for node in solve_queue:
    #     print(node.data, node.distance)

    print(result)

    res_list = result.split()

    print("机械步数：", len(res_list))

    graph.layout('dot')
    graph.draw('.\bin_tree.jpg')



