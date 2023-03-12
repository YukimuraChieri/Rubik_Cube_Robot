#include "setupmode.h"
#include "ui_setupmode.h"

SetupMode::SetupMode(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SetupMode)
{
    ui->setupUi(this);

    this->setAttribute(Qt::WA_DeleteOnClose, 1);   //窗口关闭自动删除

    connect(ui->btn_back,SIGNAL(clicked()),this,SLOT(btn_back_clicked()));
    connect(ui->btn_calibration, SIGNAL(clicked()), this, SLOT(btn_calibration_clicked()));
    connect(ui->btn_light, SIGNAL(clicked()), this, SLOT(btn_lightsetup_clicked()));
    connect(ui->btn_speed, SIGNAL(clicked()), this, SLOT(btn_speedsetup_clicked()));
}

SetupMode::~SetupMode()
{
    delete ui;
}

void SetupMode::btn_back_clicked()
{
    emit sendsignal();
    this->close();
}

void SetupMode::btn_calibration_clicked()
{
    this->hide();   //主界面隐藏
    CalibrationSetup *calibrate_win = new CalibrationSetup(this);    //新建子界面
    connect(calibrate_win, SIGNAL(return_setup()), this, SLOT(reshow())); //当点击子界面时，调用主界面的reshow()函数
    calibrate_win->showFullScreen(); // 全屏显示
    calibrate_win->show();   //子界面出现
}

void SetupMode::btn_lightsetup_clicked()
{
    this->hide();   //主界面隐藏
    LightSetup *light_win = new LightSetup(this);    //新建子界面
    connect(light_win, SIGNAL(return_setup()), this, SLOT(reshow())); //当点击子界面时，调用主界面的reshow()函数
    light_win->showFullScreen(); // 全屏显示
    light_win->show();   //子界面出现
}

void SetupMode::btn_speedsetup_clicked()
{
    this->hide();   //主界面隐藏
    SpeedSetup *speed_win = new SpeedSetup(this);    //新建子界面
    connect(speed_win, SIGNAL(return_setup()), this, SLOT(reshow())); //当点击子界面时，调用主界面的reshow()函数
    speed_win->showFullScreen(); // 全屏显示
    speed_win->show();   //子界面出现
}

void SetupMode::reshow()
{
    this->showFullScreen(); // 全屏显示
    this->show();
}


