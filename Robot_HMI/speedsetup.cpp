#include "speedsetup.h"
#include "ui_speedsetup.h"

SpeedSetup::SpeedSetup(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SpeedSetup)
{
    ui->setupUi(this);

    this->setAttribute(Qt::WA_DeleteOnClose, 1);   //窗口关闭自动删除

    net = NetworkService::getNetworkServiceIntance();   //获取实例对象接口

    connect(ui->btn_back, SIGNAL(clicked()), this, SLOT(btn_back_clicked()));
    connect(ui->btn_ok, SIGNAL(clicked()), this, SLOT(btn_ok_clicked()));

    connect(net, SIGNAL(setupFeedBack(bool)), this, SLOT(handleSetupFeedBack(bool)));
}

SpeedSetup::~SpeedSetup()
{
    delete ui;
}

void SpeedSetup::btn_back_clicked()
{
    emit return_setup();
    this->close();
}

void SpeedSetup::btn_ok_clicked()
{
    qDebug() << "[SpeedSetup::btn_ok_clicked]";

    bool read = ui->slow_read_btn->isChecked();
    bool action = ui->slow_action_btn->isChecked();
    bool run = ui->full_btn->isChecked();

    QString requestInfo = "[SpeedSetup] ";  // 数据包头

    if(read)
        requestInfo += "Slow;"; // 稳定模式
    else
        requestInfo += "Fast;"; // 快速模式

    if(action)
        requestInfo += "Slow;"; // 稳定模式
    else
        requestInfo += "Fast;"; // 快速模式

    if(run)
        requestInfo += "Full";  // 完整执行
    else
        requestInfo += "Step";  // 分布执行

    qDebug() << requestInfo;

    net->sendPacket(requestInfo);   // UDP发送数据包
}

void SpeedSetup::handleSetupFeedBack(bool state)
{
    if(state) {
//        QMessageBox::information(this, "提示", "设置成功！");
        MessageBox m;
        m.setMessageText("设置成功！");
        m.exec();
    }
    else {
//        QMessageBox::warning(this, "提示", "设置失败！");
        MessageBox m;
        m.setMessageText("设置失败！");
        m.exec();
    }
}


