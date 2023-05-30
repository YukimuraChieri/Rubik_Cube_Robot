#include "simplemode.h"
#include "ui_simplemode.h"

SimpleMode::SimpleMode(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SimpleMode)
{
    ui->setupUi(this);

    this->setAttribute(Qt::WA_DeleteOnClose, 1);   //窗口关闭自动删除

    net = NetworkService::getNetworkServiceIntance();   //获取实例对象接口

    //默认显示
    this->ui->lcdNumber->display("00:00:000");

    this->pTimer = new QTimer;

    //绑定槽函数
    connect(this->pTimer,SIGNAL(timeout()),this,SLOT(updateDisplay()));
    connect(this->ui->btn_start,SIGNAL(clicked()),this,SLOT(btn_start_clicked()));
    connect(this->ui->btn_stop,SIGNAL(clicked()),this,SLOT(btn_stop_clicked()));
    connect(this->ui->btn_random,SIGNAL(clicked()),this,SLOT(btn_random_clicked()));
    connect(this->ui->btn_back,SIGNAL(clicked()),this,SLOT(btn_back_clicked()));

    connect(net, SIGNAL(cubeReadReplyInfo(QString)), this, SLOT(handleCubeReadReplyInfo(QString)));
    connect(net, SIGNAL(cubeSloveReplyInfo(QString)), this, SLOT(handleCubeSolveReplyInfo(QString)));
    connect(net, SIGNAL(kociembaReplyInfo(QString)), this, SLOT(handleKociembaReplyInfo(QString)));

    progress = 0;   // 进度置0
    execRead = 0;   // 六面读取步数置0
    execLen = 0;    // 机械指令步数置0
    runMode = "full";   // 完整执行模式
}

SimpleMode::~SimpleMode()
{
    delete ui;
}

void SimpleMode::updateDisplay()
{
    /*
    * 1.点击开始后获取到当前的时间并且赋值给baseTime
    * 2.启动定时器,间隔1s
    * 3.槽函数中再次获取当前的时间currTime
    * 4.计算两个时间的差值t
    * 5.声明一个showTime对象给他加上t的差值
    * 6.格式化后设置显示
    */

    QTime currTime = QTime::currentTime();
    int t = this->baseTime.msecsTo(currTime);
    QTime showTime(0,0,0);
    showTime = showTime.addMSecs(t);
    this->timeStr = showTime.toString("mm:ss:zzz");
    this->ui->lcdNumber->display(timeStr);
}

void SimpleMode::btn_start_clicked()
{
    //获取当前时间
    this->baseTime = this->baseTime.currentTime();
    this->pTimer->start(50); //每50ms溢出一次进入槽函数

    QString requestInfo;
    requestInfo = "[MainMode] ";    // 数据包头
    requestInfo += "Start";         // 添加指令
    net->sendPacket(requestInfo);   // UDP发送数据包

    ui->btn_start->setEnabled(false);
    ui->btn_random->setEnabled(false);
    ui->btn_back->setEnabled(false);

    //获取当前时间
    this->baseTime = this->baseTime.currentTime();
    this->pTimer->start(50); //每50ms溢出一次进入槽函数
}

void SimpleMode::btn_stop_clicked()
{
    QString requestInfo;
    requestInfo = "[MainMode] ";    // 数据包头
    requestInfo += "Stop";         // 添加指令
    net->sendPacket(requestInfo);   // UDP发送数据包

    this->pTimer->stop();
    ui->btn_start->setEnabled(true);
    ui->btn_random->setEnabled(true);
    ui->btn_back->setEnabled(true);
}

void SimpleMode::btn_random_clicked()
{
    this->pTimer->stop();
    ui->lcdNumber->display("00:00:000");
    progress = 0;
    ui->progressBar->setValue(0);

    ui->btn_start->setEnabled(false);
    ui->btn_random->setEnabled(false);
    ui->btn_back->setEnabled(false);

    RandomSetup r;
    int step_num = r.winShow();
    qDebug() << "Step Num" << step_num;

    if(step_num > 0)
    {
        QString requestInfo;
        requestInfo = "[RandomCube] ";  // 数据包头

        requestInfo += QString::number(step_num);

        qDebug() << requestInfo;

        net->sendPacket(requestInfo);   // UDP发送数据包
    }
    else
    {
        ui->btn_start->setEnabled(true);
        ui->btn_random->setEnabled(true);
        ui->btn_back->setEnabled(true);
    }
}

void SimpleMode::btn_back_clicked()
{
    emit sendsignal();
    this->close();
}

void SimpleMode::handleCubeReadReplyInfo(QString data)
{
    qDebug() << "[SimpleMode::handleCubeReadReplyInfo]: " << data;

    if(data.contains("[Start]"))  // 开始识别
    {
        data = data.replace("[Start]:", ""); // 去掉包头
        if(data.contains("slow"))
            execRead = 3;
        else if(data.contains("fast"))
            execRead = 4;
        if(data.contains("full"))
            runMode = "full";
        else if(data.contains("step"))
            runMode = "step";

        ui->progressBar->setRange(0, execRead);
        ui->label_4->setText("六面识别进度");
        progress = 0;
        ui->progressBar->setValue(progress);
    }
    else if(data.contains("[FeedBack]"))    // 过程回调
    {
        data = data.replace("[FeedBack]:", ""); // 去掉包头
        progress++;
        ui->progressBar->setValue(progress);
    }
    else if(data.contains("[Finish]"))    // 识别完成
    {
        data = data.replace("[Finish]:", ""); // 去掉包头
        ui->progressBar->setValue(execRead);
        progress = 0;

        if(runMode == "full")   // 完整执行模式
        {}
        else if(runMode == "step")  // 分步执行模式
        {
            this->pTimer->stop();
            ui->btn_start->setEnabled(true);
            MessageBox m;
            m.setMessageText("读取完成\r\n请再次按下开始键进行解序");
            m.exec();
        }
    }
    else if(data.contains("[Failed]"))    // 识别失败
    {
        progress = 0;
        this->pTimer->stop();
        ui->btn_start->setEnabled(true);
        ui->btn_random->setEnabled(true);
        ui->btn_back->setEnabled(true);

        data = data.replace("[Failed]:", ""); // 去掉包头
        if(data.contains("Error"))
        {
//            QMessageBox::information(this, "提示", "识别错误！");
            MessageBox m;
            m.setMessageText("识别错误！");
            m.exec();
        }
        else if(data.contains("Stop"))
        {
//            QMessageBox::information(this, "提示", "识别中断！");
            MessageBox m;
            m.setMessageText("识别中断！");
            m.exec();
        }
    }
}

void SimpleMode::handleCubeSolveReplyInfo(QString data)
{
    qDebug() << "[SimpleMode::handleCubeSolveReplyInfo]: " << data;

    if(data.contains("[Start]"))  // 开始解序
    {
        data = data.replace("[Start]:", "");    // 去掉包头
        QStringList data_list = data.split(" ");// 按空格符分割数据包
        execLen = data_list.length();                // 获取机械动作个数

        qDebug() << "execLen:" << execLen;

        ui->label_4->setText("解序进度");
        ui->progressBar->setValue(0);
        ui->progressBar->setRange(0, execLen);

        progress = 0;
    }
    else if(data.contains("[FeedBack]"))    // 过程回调
    {
        data = data.replace("[FeedBack]:", ""); // 去掉包头
        progress++;
        ui->progressBar->setValue(progress);
    }
    else if(data.contains("[Finish]"))    // 解序完成
    {
        data = data.replace("[Finish]:", ""); // 去掉包头
        this->pTimer->stop();
        ui->btn_start->setEnabled(true);
        ui->btn_random->setEnabled(true);
        ui->btn_back->setEnabled(true);
        ui->progressBar->setValue(execLen);
        progress = 0;
//        QMessageBox::information(this, "提示", "解序完成！");
//        MessageBox m;
//        m.setMessageText("解序完成！");
//        m.exec();
    }
    else if(data.contains("[Failed]"))    // 解序失败
    {
        progress = 0;
        this->pTimer->stop();
        ui->btn_start->setEnabled(true);
        ui->btn_random->setEnabled(true);
        ui->btn_back->setEnabled(true);

        data = data.replace("[Failed]:", ""); // 去掉包头
        if(data.contains("Error"))
        {
//            QMessageBox::information(this, "提示", "解序错误！");
            MessageBox m;
            m.setMessageText("解序错误！");
            m.exec();
        }
        else if(data.contains("Stop"))
        {
//            QMessageBox::information(this, "提示", "解序中断！");
            MessageBox m;
            m.setMessageText("解序中断！");
            m.exec();
        }
    }
}

void SimpleMode::handleKociembaReplyInfo(QString data)
{
    qDebug() << "[SimpleMode::handleKociembaReplyInfo]: " << data;

    if(data.contains("[Finish]"))  // 求解成功
    {
        data = data.replace("[Finish]:", ""); // 去掉包头
    }
    else if(data.contains("[Failed]"))  // 求解失败
    {
        progress = 0;
        this->pTimer->stop();
        ui->btn_start->setEnabled(true);
        ui->btn_random->setEnabled(true);
        ui->btn_back->setEnabled(true);

        QMessageBox::information(this, "提示", "求解失败！");
    }
}
