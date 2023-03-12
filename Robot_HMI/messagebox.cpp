#include "messagebox.h"
#include "ui_messagebox.h"

MessageBox::MessageBox(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MessageBox)
{
    ui->setupUi(this);
//    setAutoFillBackground(false);  //这个不设置的话就背景变黑
    setWindowFlags(Qt::FramelessWindowHint | windowFlags());    //去窗口边框
//    setAttribute(Qt::WA_TranslucentBackground);   //把窗口背景设置为透明

//    connect(ui->btn_ok, &QPushButton::clicked, this, &QDialog::close);
    connect(ui->btn_ok, SIGNAL(clicked()), this, SLOT(btn_ok_clicked()));
}

MessageBox::~MessageBox()
{
    delete ui;
}

void MessageBox::setMessageText(QString mess)
{
    ui->mess_label->setText(mess);
}

void MessageBox::btn_ok_clicked()
{
    this->hide();
}
