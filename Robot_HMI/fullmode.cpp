#include "fullmode.h"
#include "ui_fullmode.h"

FullMode::FullMode(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FullMode)
{
    ui->setupUi(this);

    this->setAttribute(Qt::WA_DeleteOnClose, 1);   //窗口关闭自动删除

    net = NetworkService::getNetworkServiceIntance();   //获取实例对象接口

    //默认显示
    ui->lcdNumber->display("00:00:000");

    this->pTimer = new QTimer;
    //绑定定时器的信号
    connect(this->pTimer, SIGNAL(timeout()), this, SLOT(updateDisplay()));
    connect(ui->btn_start, SIGNAL(clicked()), this, SLOT(btn_start_clicked()));
    connect(ui->btn_stop, SIGNAL(clicked()), this, SLOT(btn_stop_clicked()));
    connect(ui->btn_random, SIGNAL(clicked()), this, SLOT(btn_random_clicked()));
    connect(ui->btn_back, SIGNAL(clicked()), this, SLOT(btn_back_clicked()));
    connect(ui->loginfo, &QTextEdit::textChanged, this, [=](){
        ui->loginfo->moveCursor(QTextCursor::End);
    });

    connect(net, SIGNAL(cubeReadReplyInfo(QString)), this, SLOT(handleCubeReadReplyInfo(QString)));
    connect(net, SIGNAL(cubeSloveReplyInfo(QString)), this, SLOT(handleCubeSolveReplyInfo(QString)));
    connect(net, SIGNAL(kociembaReplyInfo(QString)), this, SLOT(handleKociembaReplyInfo(QString)));

    progress = 0;   // 进度置0
    execRead = 0;   // 六面读取步数置0
    execLen = 0;    // 机械指令步数置0
    runMode = "full";   // 完整执行模式

    //保持编辑器在光标最后一行
    QTextCursor cursor=ui->loginfo->textCursor();
    cursor.movePosition(QTextCursor::End);
    ui->loginfo->setTextCursor(cursor);
}

FullMode::~FullMode()
{
    delete ui;
}

void FullMode::updateDisplay()
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
    ui->lcdNumber->display(timeStr);
}

void FullMode::btn_start_clicked()
{
    QString requestInfo;
    requestInfo = "[MainMode] ";    // 数据包头
    requestInfo += "Start";         // 添加指令
    net->sendPacket(requestInfo);   // UDP发送数据包

    ui->btn_start->setEnabled(false);
    ui->btn_random->setEnabled(false);
    ui->btn_back->setEnabled(false);

    ui->loginfo->clear();   // 清除解序信息
    ui->loginfo->insertPlainText("\r\n******************************\r\n");
    ui->loginfo->insertPlainText("开始解序");

    //获取当前时间
    this->baseTime = this->baseTime.currentTime();
    this->pTimer->start(50); //每50ms溢出一次进入槽函数
}

void FullMode::btn_stop_clicked()
{
    QString requestInfo;
    requestInfo = "[MainMode] ";    // 数据包头
    requestInfo += "Stop";         // 添加指令
    net->sendPacket(requestInfo);   // UDP发送数据包

    ui->loginfo->insertPlainText("\r\n解序停止");

    this->pTimer->stop();
    ui->btn_start->setEnabled(true);
    ui->btn_random->setEnabled(true);
    ui->btn_back->setEnabled(true);
}

void FullMode::btn_random_clicked()
{
    ui->loginfo->insertPlainText("\r\n******************************\r\n");
    ui->loginfo->insertPlainText("打乱魔方\r\n");
    ui->btn_start->setEnabled(false);
    ui->btn_random->setEnabled(false);
    ui->btn_back->setEnabled(false);

    RandomSetup r;
    int step_num = r.winShow();
    qDebug() << "Step Num" << step_num;

    if(step_num > 0)
    {
        ui->loginfo->insertPlainText("打乱步数"+QString::number(step_num)+"\r\n");
        QString requestInfo;
        requestInfo = "[RandomCube] ";  // 数据包头

        requestInfo += QString::number(step_num);

        qDebug() << requestInfo;

        net->sendPacket(requestInfo);   // UDP发送数据包
    }
    else
    {
        ui->loginfo->insertPlainText("取消打乱\r\n");
        ui->btn_start->setEnabled(true);
        ui->btn_random->setEnabled(true);
        ui->btn_back->setEnabled(true);
    }
}

void FullMode::btn_back_clicked()
{
    emit sendsignal();
    this->close();
}

void FullMode::handleCubeReadReplyInfo(QString data)
{
    qDebug() << "[FullMode::handleCubeReadReplyInfo]: " << data;

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
        ui->sixFace->setSixFace("XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX");
        progress = 0;
        ui->progressBar->setValue(progress);
        ui->loginfo->insertPlainText("\r\n开始六面读取");
    }
    else if(data.contains("[FeedBack]"))    // 过程回调
    {
        data = data.replace("[FeedBack]:", ""); // 去掉包头
        ui->sixFace->setSixFace(data.toUtf8());
        progress++;
        ui->progressBar->setValue(progress);
        ui->loginfo->insertPlainText("\r\n当前读取面:");
        ui->loginfo->insertPlainText(data);
    }
    else if(data.contains("[Finish]"))    // 识别完成
    {
        data = data.replace("[Finish]:", ""); // 去掉包头
        ui->sixFace->setSixFace(data.toUtf8());
        ui->progressBar->setValue(execRead);
        progress = 0;
        ui->loginfo->insertPlainText("\r\n六面读取完成:");
        ui->loginfo->insertPlainText(data);

        if(runMode == "full")   // 完整执行模式
        {}
        else if(runMode == "step")  // 分步执行模式
        {
            this->pTimer->stop();
            ui->loginfo->insertPlainText("\r\n请再次按下开始键进行解序");
            ui->btn_start->setEnabled(true);
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
            ui->loginfo->insertPlainText("\r\n六面读取错误！");
//            QMessageBox::information(this, "提示", "识别错误！");
            MessageBox m;
            m.setMessageText("识别错误！");
            m.exec();
        }
        else if(data.contains("Stop"))
        {
            ui->loginfo->insertPlainText("\r\n六面读取中断！");
//            QMessageBox::information(this, "提示", "识别中断！");
            MessageBox m;
            m.setMessageText("识别中断！");
            m.exec();
        }
    }
}

void FullMode::handleCubeSolveReplyInfo(QString data)
{
    qDebug() << "[FullMode::handleCubeSolveReplyInfo]: " << data;

    if(data.contains("[Start]"))  // 开始执行解序动作
    {
        data = data.replace("[Start]:", "");    // 去掉包头
        QStringList data_list = data.split(" ");// 按空格符分割数据包
        execLen = data_list.length();                // 获取机械动作个数

        qDebug() << "execLen:" << execLen;

        ui->label_4->setText("执行进度");
        ui->progressBar->setValue(0);
        ui->progressBar->setRange(0, execLen);

        ui->loginfo->insertPlainText("\r\n开始执行动作指令");
        ui->loginfo->insertPlainText("\r\n动作指令长度:");
        ui->loginfo->insertPlainText(QString::number(execLen));

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
        ui->loginfo->insertPlainText("\r\n执行完成！");
//        QMessageBox::information(this, "提示", "执行完成！");
        MessageBox m;
        m.setMessageText("执行完成！");
        m.exec();
    }
    else if(data.contains("[Failed]"))    // 执行失败
    {
        progress = 0;
        this->pTimer->stop();
        ui->btn_start->setEnabled(true);
        ui->btn_random->setEnabled(true);
        ui->btn_back->setEnabled(true);

        data = data.replace("[Failed]:", ""); // 去掉包头
        if(data.contains("Error"))
        {
            ui->loginfo->insertPlainText("\r\n执行错误！");
//            QMessageBox::information(this, "提示", "执行错误！");
            MessageBox m;
            m.setMessageText("执行错误！");
            m.exec();
        }
        else if(data.contains("Stop"))
        {
            ui->loginfo->insertPlainText("\r\n执行中断！");
//            QMessageBox::information(this, "提示", "执行中断！");
            MessageBox m;
            m.setMessageText("执行中断！");
            m.exec();
        }
    }
}

void FullMode::handleKociembaReplyInfo(QString data)
{
    qDebug() << "[FullMode::handleKociembaReplyInfo]: " << data;

    if(data.contains("[Finish]"))  // 求解成功
    {
        data = data.replace("[Finish]:", ""); // 去掉包头
        ui->loginfo->insertPlainText("\r\nKociemba求解结果:");
        ui->loginfo->insertPlainText(data);
    }
    else if(data.contains("[Failed]"))  // 求解失败
    {
        progress = 0;
        this->pTimer->stop();
        ui->btn_start->setEnabled(true);
        ui->btn_random->setEnabled(true);
        ui->btn_back->setEnabled(true);

//        QMessageBox::information(this, "提示", "求解失败！");
        MessageBox m;
        m.setMessageText("求解失败！");
        m.exec();
    }
}

