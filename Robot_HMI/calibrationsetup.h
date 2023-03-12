#ifndef CALIBRATIONSETUP_H
#define CALIBRATIONSETUP_H

#include <QDialog>
#include <QMouseEvent>
#include <opencv2/opencv.hpp>
#include <iostream>
#include <QMessageBox>
#include "networkservice.h"
#include "messagebox.h"

namespace Ui {
class CalibrationSetup;
}

class CalibrationSetup : public QDialog
{
    Q_OBJECT

public:
    explicit CalibrationSetup(QWidget *parent = nullptr);
    ~CalibrationSetup();

public slots:
    void btn_back_clicked();

    void btn_ok_clicked();

    void handleReadCamera(QByteArray data);

    void handleGetPara(QString data);

    void cameraCom_index_changed(int index);

    void handleSetupFeedBack(bool state);

protected:
    // 鼠标点击事件
    void mousePressEvent(QMouseEvent *event);

signals:
    void return_setup();  //这个函数向设置界面通知关闭的消息

private:
    Ui::CalibrationSetup *ui;

    NetworkService* net;

    std::string pos_info;

    cv::Point left_point_list[6];
    cv::Point right_point_list[6];
};

#endif // CALIBRATIONSETUP_H
