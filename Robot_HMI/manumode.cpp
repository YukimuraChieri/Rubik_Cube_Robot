#include "manumode.h"
#include "ui_manumode.h"

ManuMode::ManuMode(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ManuMode)
{
    ui->setupUi(this);

    this->setAttribute(Qt::WA_DeleteOnClose, 1);   //窗口关闭自动删除

    net = NetworkService::getNetworkServiceIntance();   //获取实例对象接口

    connect(ui->btn_left_catch, SIGNAL(clicked()), this, SLOT(btn_left_catch_clicked()));
    connect(ui->btn_left_loose, SIGNAL(clicked()), this, SLOT(btn_left_loose_clicked()));
    connect(ui->btn_left_half, SIGNAL(clicked()), this, SLOT(btn_left_half_clicked()));
    connect(ui->btn_left_90, SIGNAL(clicked()), this, SLOT(btn_left_90_clicked()));
    connect(ui->btn_left_90_inv, SIGNAL(clicked()), this, SLOT(btn_left_90_inv_clicked()));
    connect(ui->btn_left_180, SIGNAL(clicked()), this, SLOT(btn_left_180_clicked()));

    connect(ui->btn_right_catch, SIGNAL(clicked()), this, SLOT(btn_right_catch_clicked()));
    connect(ui->btn_right_loose, SIGNAL(clicked()), this, SLOT(btn_right_loose_clicked()));
    connect(ui->btn_right_half, SIGNAL(clicked()), this, SLOT(btn_right_half_clicked()));
    connect(ui->btn_right_90, SIGNAL(clicked()), this, SLOT(btn_right_90_clicked()));
    connect(ui->btn_right_90_inv, SIGNAL(clicked()), this, SLOT(btn_right_90_inv_clicked()));
    connect(ui->btn_right_180, SIGNAL(clicked()), this, SLOT(btn_right_180_clicked()));

    connect(ui->btn_back, SIGNAL(clicked()), this, SLOT(btn_back_clicked()));
}

ManuMode::~ManuMode()
{
    delete ui;
}

void ManuMode::btn_left_catch_clicked()
{
    QString requestInfo;
    requestInfo = "[ManuMode] ";    // 数据包头
    requestInfo += "A1";            // 添加指令
    net->sendPacket(requestInfo);   // UDP发送数据包
}

void ManuMode::btn_left_loose_clicked()
{
    QString requestInfo;
    requestInfo = "[ManuMode] ";    // 数据包头
    requestInfo += "A0";            // 添加指令
    net->sendPacket(requestInfo);   // UDP发送数据包
}

void ManuMode::btn_left_half_clicked()
{
    QString requestInfo;
    requestInfo = "[ManuMode] ";    // 数据包头
    requestInfo += "AH";            // 添加指令
    net->sendPacket(requestInfo);   // UDP发送数据包
}

void ManuMode::btn_left_90_clicked()
{
    QString requestInfo;
    requestInfo = "[ManuMode] ";    // 数据包头
    requestInfo += "A+";            // 添加指令
    net->sendPacket(requestInfo);   // UDP发送数据包
}

void ManuMode::btn_left_90_inv_clicked()
{
    QString requestInfo;
    requestInfo = "[ManuMode] ";    // 数据包头
    requestInfo += "A-";            // 添加指令
    net->sendPacket(requestInfo);   // UDP发送数据包
}

void ManuMode::btn_left_180_clicked()
{
    QString requestInfo;
    requestInfo = "[ManuMode] ";    // 数据包头
    requestInfo += "A++";           // 添加指令
    net->sendPacket(requestInfo);   // UDP发送数据包
}

void ManuMode::btn_right_catch_clicked()
{
    QString requestInfo;
    requestInfo = "[ManuMode] ";    // 数据包头
    requestInfo += "B1";            // 添加指令
    net->sendPacket(requestInfo);   // UDP发送数据包
}

void ManuMode::btn_right_loose_clicked()
{
    QString requestInfo;
    requestInfo = "[ManuMode] ";    // 数据包头
    requestInfo += "B0";            // 添加指令
    net->sendPacket(requestInfo);   // UDP发送数据包
}

void ManuMode::btn_right_half_clicked()
{
    QString requestInfo;
    requestInfo = "[ManuMode] ";    // 数据包头
    requestInfo += "BH";            // 添加指令
    net->sendPacket(requestInfo);   // UDP发送数据包
}

void ManuMode::btn_right_90_clicked()
{
    QString requestInfo;
    requestInfo = "[ManuMode] ";    // 数据包头
    requestInfo += "B+";            // 添加指令
    net->sendPacket(requestInfo);   // UDP发送数据包
}

void ManuMode::btn_right_90_inv_clicked()
{
    QString requestInfo;
    requestInfo = "[ManuMode] ";    // 数据包头
    requestInfo += "B-";            // 添加指令
    net->sendPacket(requestInfo);   // UDP发送数据包
}

void ManuMode::btn_right_180_clicked()
{
    QString requestInfo;
    requestInfo = "[ManuMode] ";    // 数据包头
    requestInfo += "B++";           // 添加指令
    net->sendPacket(requestInfo);   // UDP发送数据包
}

void ManuMode::btn_back_clicked()
{
    emit sendsignal();
    this->close();
}
