#include "networkservice.h"

//客户端地址端口
#define CLIENT_IP   "127.0.0.1"
#define CLIENT_PORT 10001       //ROS应答数据接收端口
#define CLIENT_LCAM_PORT 10002  //左摄像头图像数据接收端口
#define CLIENT_RCAM_PORT 10003  //右摄像头图像数据接收端口

//服务器地址端口
#define SERVER_IP   "127.0.0.1"
#define SERVER_PORT 10000

NetworkService *NetworkService::networkservice = nullptr;

NetworkService::NetworkService(QObject *parent) : QObject(parent)
{
    udpScoket = new QUdpSocket;
    udpScoket->bind(QHostAddress(CLIENT_IP), CLIENT_PORT);
    connect(udpScoket, SIGNAL(readyRead()), this, SLOT(handleRecvData()));

    udpScoket_cam_l = new QUdpSocket;
    udpScoket_cam_l->bind(QHostAddress(CLIENT_IP), CLIENT_LCAM_PORT);
    connect(udpScoket_cam_l, SIGNAL(readyRead()), this, SLOT(handleRecvData_leftcam()));

    udpScoket_cam_r = new QUdpSocket;
    udpScoket_cam_r->bind(QHostAddress(CLIENT_IP), CLIENT_RCAM_PORT);
    connect(udpScoket_cam_r, SIGNAL(readyRead()), this, SLOT(handleRecvData_rightcam()));
}

NetworkService::~NetworkService()
{
    udpScoket->disconnect();
    delete udpScoket;
    udpScoket = nullptr;

    udpScoket_cam_l->disconnect();
    delete udpScoket_cam_l;
    udpScoket_cam_l = nullptr;

    udpScoket_cam_r->disconnect();
    delete udpScoket_cam_r;
    udpScoket_cam_r = nullptr;
}


//接收槽函数
void NetworkService::handleRecvData()
{
    QByteArray datagram;
    qint64 len;

    while(udpScoket->hasPendingDatagrams())     //是否有未处理的数据
    {
        len = udpScoket->pendingDatagramSize(); //获取接收长度
        qDebug() << "Len:" << len;

        datagram.resize(len);                   //字节数组长度
        udpScoket->readDatagram(datagram.data(), len);  //读取网络接收的数据

        qDebug() << "[NetworkService::handleRecvData]: " << QString(datagram);

        pocessReplyDatagram(QString(datagram));     //应答信息处理
    }
}

void NetworkService::handleRecvData_leftcam()
{
    QByteArray datagram;
    while (udpScoket_cam_l->hasPendingDatagrams())
    {
        qint64 sizeLen=udpScoket_cam_l->pendingDatagramSize();
        datagram.resize(int(sizeLen));
        udpScoket_cam_l->readDatagram(datagram.data(),datagram.size());

//        qDebug() << "[NetworkService::handleRecvData_leftcam]: " << datagram.length();

        emit leftCameraData(datagram);   //发送左摄像头图像信号
    }
}

void NetworkService::handleRecvData_rightcam()
{
    QByteArray datagram;
    while (udpScoket_cam_r->hasPendingDatagrams())
    {
        qint64 sizeLen=udpScoket_cam_r->pendingDatagramSize();
        datagram.resize(int(sizeLen));
        udpScoket_cam_r->readDatagram(datagram.data(),datagram.size());

//        qDebug() << "[NetworkService::handleRecvData_rightcam]: " << datagram.length();

        emit rightCameraData(datagram);   //发送右摄像头图像信号
    }
}

//发送数据包
void NetworkService::sendPacket(QString data)
{
    udpScoket->writeDatagram(data.toUtf8(), QHostAddress(SERVER_IP), SERVER_PORT);
}

//获取实例对象接口
NetworkService *NetworkService::getNetworkServiceIntance()
{
    if(networkservice == nullptr)
    {
        networkservice = new NetworkService;
    }
    return networkservice;
}

//服务器应答信息处理
void NetworkService::pocessReplyDatagram(QString data)
{
    qDebug() << "[NetworkService::processDatagram] " << QString(data);

    if(data.contains("[CubeRead]"))          //魔方面读取
    {
        data = data.replace("[CubeRead]:", ""); // 去掉包头
        emit cubeReadReplyInfo(data);   //发送信号
    }
    else if(data.contains("[CubeSolve]"))   //处理信息
    {
        data = data.replace("[CubeSolve]:", ""); // 去掉包头
        emit cubeSloveReplyInfo(data);  //发送信号
    }
    else if(data.contains("[Kociemba]"))   //处理信息
    {
        data = data.replace("[Kociemba]:", ""); // 去掉包头
        emit kociembaReplyInfo(data);  //发送信号
    }
    else if(data.contains("[GetPara]")) //当前参数
    {
        data = data.replace("[GetPara]:", ""); // 去掉包头
        emit getParaReplyInfo(data);    //发送信号
    }
    else if(data.contains("[SetupFeedBack]"))
    {
        if(data.contains("Finish"))
            emit setupFeedBack(true);   //发送信号
        else if(data.contains("Failed"))
            emit setupFeedBack(false);  //发送信号
    }
}


