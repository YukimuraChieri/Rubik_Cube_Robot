#ifndef SETUPMODE_H
#define SETUPMODE_H

#include <QDialog>
#include "calibrationsetup.h"
#include "lightsetup.h"
#include "speedsetup.h"

namespace Ui {
class SetupMode;
}

class SetupMode : public QDialog
{
    Q_OBJECT

public:
    explicit SetupMode(QWidget *parent = nullptr);
    ~SetupMode();

public slots:
    void btn_back_clicked();
    void btn_calibration_clicked();
    void btn_lightsetup_clicked();
    void btn_speedsetup_clicked();

    void reshow();

signals:
    void sendsignal();  //这个函数向主界面通知关闭的消息

private:
    Ui::SetupMode *ui;

};

#endif // SETUPMODE_H
