#include "randomsetup.h"
#include "ui_randomsetup.h"

RandomSetup::RandomSetup(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RandomSetup)
{
    ui->setupUi(this);

    step_num = 0;

    setWindowFlags(Qt::FramelessWindowHint | windowFlags());    //去窗口边框

    connect(ui->btn_ok, SIGNAL(clicked()), this, SLOT(btn_ok_clicked()));
    connect(ui->btn_cancel, SIGNAL(clicked()), this, SLOT(btn_cancel_clicked()));
}

RandomSetup::~RandomSetup()
{
    delete ui;
}

int RandomSetup::winShow()
{
    this->exec();
    return step_num;
}

void RandomSetup::btn_ok_clicked()
{
    step_num = ui->spinBox->value();

    this->hide();
}

void RandomSetup::btn_cancel_clicked()
{
    this->hide();
}
