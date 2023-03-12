#ifndef NETWORKSERVICE_H
#define NETWORKSERVICE_H

#include <QObject>
#include <QUdpSocket>
#include <QHostAddress>
#include <QDebug>

class NetworkService : public QObject
{
    Q_OBJECT
public:
    explicit NetworkService(QObject *parent = nullptr);
    ~NetworkService();

signals:
    void cubeReadReplyInfo(QString data);   //魔方面读取信号
    void cubeSloveReplyInfo(QString data);  //魔方解序信号
    void kociembaReplyInfo(QString data);   //kociemba求解信息
    void leftCameraData(QByteArray data);   //左摄像头图像信号
    void rightCameraData(QByteArray data);  //左摄像头图像信号
    void alarmInterrupt(QString data);      //急停开关中断信号
    void getParaReplyInfo(QString data);    //获取参数信号
    void setupFeedBack(bool state);         //设置状态反馈信号

public slots:
    void handleRecvData(void);      //接收槽函数
    void handleRecvData_leftcam(void);  //左摄像头接收槽函数
    void handleRecvData_rightcam(void);  //右摄像头接收槽函数

    void sendPacket(QString data);  //发送数据

    static NetworkService* getNetworkServiceIntance(void);  //获取实例对象接口

    void pocessReplyDatagram(QString data); //服务器应答信息处理

private:
    QUdpSocket* udpScoket;
    QUdpSocket* udpScoket_cam_l;
    QUdpSocket* udpScoket_cam_r;

    static NetworkService* networkservice;

};

#endif // NETWORKSERVICE_H
