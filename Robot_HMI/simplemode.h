#ifndef SIMPLEMODE_H
#define SIMPLEMODE_H

#include <QDialog>
#include <QTime>
#include <QTimer>
#include <QDateTime>
#include <QString>
#include <QDebug>
#include <QMessageBox>
#include "networkservice.h"
#include "messagebox.h"
#include "randomsetup.h"

namespace Ui {
class SimpleMode;
}

class SimpleMode : public QDialog
{
    Q_OBJECT

public:
    explicit SimpleMode(QWidget *parent = nullptr);
    ~SimpleMode();

private:
    Ui::SimpleMode *ui;

public slots:
    void updateDisplay();

    void btn_start_clicked();

    void btn_stop_clicked();

    void btn_random_clicked();

    void btn_back_clicked();

    void handleCubeReadReplyInfo(QString data);

    void handleCubeSolveReplyInfo(QString data);

    void handleKociembaReplyInfo(QString data);


signals:
    void sendsignal();  //这个函数向主界面通知关闭的消息


private:
    NetworkService* net;

    QTimer *pTimer;
    QTime baseTime;
    //显示的时间
    QString timeStr;

    int progress;
    int execRead;
    int execLen;
    QString runMode;
};

#endif // SIMPLEMODE_H
