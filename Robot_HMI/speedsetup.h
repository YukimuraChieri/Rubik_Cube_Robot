#ifndef SPEEDSETUP_H
#define SPEEDSETUP_H

#include <QDialog>
#include <QDebug>
#include <QMessageBox>
#include "networkservice.h"
#include "messagebox.h"

namespace Ui {
class SpeedSetup;
}

class SpeedSetup : public QDialog
{
    Q_OBJECT

public:
    explicit SpeedSetup(QWidget *parent = nullptr);
    ~SpeedSetup();

public slots:
    void btn_back_clicked();

    void btn_ok_clicked();

    void handleSetupFeedBack(bool state);

signals:
    void return_setup();  //这个函数向设置界面通知关闭的消息

private:
    Ui::SpeedSetup *ui;

    NetworkService* net;
};

#endif // SPEEDSETUP_H
