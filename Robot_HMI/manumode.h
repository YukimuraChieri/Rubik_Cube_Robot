#ifndef MANUMODE_H
#define MANUMODE_H

#include <QDialog>
#include <QDebug>
#include "networkservice.h"

namespace Ui {
class ManuMode;
}

class ManuMode : public QDialog
{
    Q_OBJECT

public:
    explicit ManuMode(QWidget *parent = nullptr);
    ~ManuMode();

public slots:
    void btn_left_catch_clicked();
    void btn_left_loose_clicked();
    void btn_left_half_clicked();
    void btn_left_90_clicked();
    void btn_left_90_inv_clicked();
    void btn_left_180_clicked();

    void btn_right_catch_clicked();
    void btn_right_loose_clicked();
    void btn_right_half_clicked();
    void btn_right_90_clicked();
    void btn_right_90_inv_clicked();
    void btn_right_180_clicked();

    void btn_back_clicked();

signals:
    void sendsignal();  //这个函数向主界面通知关闭的消息

private:
    Ui::ManuMode *ui;

    NetworkService* net;
};

#endif // MANUMODE_H
