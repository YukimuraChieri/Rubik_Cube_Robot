#ifndef LIGHTSETUP_H
#define LIGHTSETUP_H

#include <QDialog>
#include <QDebug>
#include <opencv2/opencv.hpp>
#include "networkservice.h"

//using namespace cv;

namespace Ui {
class LightSetup;
}

class LightSetup : public QDialog
{
    Q_OBJECT

public:
    explicit LightSetup(QWidget *parent = nullptr);
    ~LightSetup();

public slots:

    void btn_back_clicked();

    void dial_light_change();

    void left_exposure_change();

    void right_exposure_change();

    void handleReadLeftCamera(QByteArray data);

    void handleReadRightCamera(QByteArray data);

signals:
    void return_setup();  //这个函数向设置界面通知关闭的消息

private:
    Ui::LightSetup *ui;

    NetworkService* net;
};

#endif // LIGHTSETUP_H
