#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "messagebox.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //绑定信号槽函数
    connect(ui->btn_main, SIGNAL(clicked()), this, SLOT(btn_main_clicked()));
    connect(ui->btn_simple, SIGNAL(clicked()), this, SLOT(btn_simple_clicked()));
    connect(ui->btn_setup, SIGNAL(clicked()), this, SLOT(btn_setup_clicked()));
    connect(ui->btn_manual, SIGNAL(clicked()), this, SLOT(btn_manual_clicked()));
    connect(ui->btn_shutdown, SIGNAL(clicked()), this, SLOT(shutdown()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::btn_main_clicked()
{
    this->hide();   //主界面隐藏
    FullMode *full_win = new FullMode(this);    //新建子界面
    connect(full_win, SIGNAL(sendsignal()), this, SLOT(reshow())); //当点击子界面时，调用主界面的reshow()函数
    full_win->showFullScreen(); // 全屏显示
    full_win->show();   //子界面出现
}

void MainWindow::btn_simple_clicked()
{
    this->hide();   //主界面隐藏
    SimpleMode *simple_win = new SimpleMode(this);    //新建子界面
    connect(simple_win, SIGNAL(sendsignal()), this, SLOT(reshow())); //当点击子界面时，调用主界面的reshow()函数
    simple_win->showFullScreen(); // 全屏显示
    simple_win->show();   //子界面出现
}

void MainWindow::btn_setup_clicked()
{
    this->hide();   //主界面隐藏
    SetupMode *setup_win = new SetupMode(this);    //新建子界面
    connect(setup_win, SIGNAL(sendsignal()), this, SLOT(reshow())); //当点击子界面时，调用主界面的reshow()函数
    setup_win->showFullScreen(); // 全屏显示
    setup_win->show();   //子界面出现
}

void MainWindow::btn_manual_clicked()
{
    this->hide();   //主界面隐藏
    ManuMode *manu_win = new ManuMode(this);    //新建子界面
    connect(manu_win,SIGNAL(sendsignal()),this,SLOT(reshow())); //当点击子界面时，调用主界面的reshow()函数
    manu_win->showFullScreen(); // 全屏显示
    manu_win->show();   //子界面出现
}

void MainWindow::reshow()
{
    this->showFullScreen(); // 全屏显示
    this->show();
}

void MainWindow::shutdown()
{
    this->close();
}
