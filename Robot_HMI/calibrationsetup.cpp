#include "calibrationsetup.h"
#include "ui_calibrationsetup.h"

CalibrationSetup::CalibrationSetup(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CalibrationSetup)
{
    ui->setupUi(this);

    this->setAttribute(Qt::WA_DeleteOnClose, 1);   //窗口关闭自动删除

    net = NetworkService::getNetworkServiceIntance();   //获取实例对象接口

    connect(ui->btn_back, SIGNAL(clicked()), this, SLOT(btn_back_clicked()));
    connect(ui->btn_ok, SIGNAL(clicked()), this, SLOT(btn_ok_clicked()));
    connect(net, SIGNAL(leftCameraData(QByteArray)), this, SLOT(handleReadCamera(QByteArray)));
    connect(net, SIGNAL(rightCameraData(QByteArray)), this, SLOT(handleReadCamera(QByteArray)));
    connect(net, SIGNAL(getParaReplyInfo(QString)), this, SLOT(handleGetPara(QString)));
    connect(net, SIGNAL(setupFeedBack(bool)), this, SLOT(handleSetupFeedBack(bool)));

    connect(ui->cameraCom, SIGNAL(currentIndexChanged(int)), this, SLOT(cameraCom_index_changed(int)));

    QString requestInfo;
    requestInfo = "[CalibrationSetup] ";    // 数据包头
    requestInfo += "Start";           // 添加指令
    // 0,10;20,14;30,30;60,45;80,100;123,90

    net->sendPacket(requestInfo);           // UDP发送数据包

    for(int i = 0; i < 6; i++)
    {
        left_point_list[0].x = 0;
        left_point_list[0].y = 0;
        right_point_list[0].x = 0;
        right_point_list[0].y = 0;
    }

    pos_info = "point:[0, 0]";
}

CalibrationSetup::~CalibrationSetup()
{
    delete ui;
}

void CalibrationSetup::btn_back_clicked()
{
    QString requestInfo;
    requestInfo = "[CalibrationSetup] ";    // 数据包头
    requestInfo += "Quit";                  // 添加指令

    net->sendPacket(requestInfo);           // UDP发送数据包

    emit return_setup();
    this->close();
}

void CalibrationSetup::btn_ok_clicked()
{
    QString requestInfo;
    requestInfo = "[CalibrationSetup] ";    // 数据包头

    for(int i = 0; i < 6; i++)  // 左摄像头基准点坐标上传数据
    {
        requestInfo += QString::number(left_point_list[i].x);
        requestInfo += ",";
        requestInfo += QString::number(left_point_list[i].y);
        requestInfo += ";";
    }
    for(int i = 0; i < 6; i++)  // 右摄像头基准点坐标上传数据
    {
        requestInfo += QString::number(right_point_list[i].x);
        requestInfo += ",";
        requestInfo += QString::number(right_point_list[i].y);
        requestInfo += ";";
    }    

    qDebug() << requestInfo;

    net->sendPacket(requestInfo);           // UDP发送数据包
}

void CalibrationSetup::handleReadCamera(QByteArray data)
{
    char* datagram = data.data();
    qint64 len = data.length();
    cv::Mat img_decode;
    std::vector<uchar> img_data;

    for (int i = 0; i < len; i++){
        img_data.push_back(datagram[i]);
    }
    if(len > 0){
        img_decode = cv::imdecode(img_data, cv::IMREAD_COLOR);
        // 最小分辨率（640x480像素）
        cv::Size dsize = cv::Size(640, 480);
        cv::resize(img_decode, img_decode, dsize, 0, 0, cv::INTER_AREA);
        try {
            //设置绘制文本的相关参数
            int font_face = cv::FONT_HERSHEY_COMPLEX;
            double font_scale = 0.8;
            int thickness = 1;
            int baseline;
            //获取文本框的长宽
            cv::Size text_size = cv::getTextSize(pos_info, font_face, font_scale, thickness, &baseline);

            //将文本框显示在左上角
            cv::Point origin;
            origin.x = img_decode.cols - text_size.width;
            origin.y = text_size.height;
            cv::putText(img_decode, pos_info, origin, font_face, font_scale, cv::Scalar(0, 128, 0), thickness, 2, 0);

            std::vector<cv::Point> pts;

            int index = ui->cameraCom->currentIndex();
            if(index == 0)
                for(int i = 0; i < 6; i++)
                    pts.push_back(left_point_list[i]);
            else if(index == 1)
                for(int i = 0; i < 6; i++)
                    pts.push_back(right_point_list[i]);

            cv::polylines(img_decode, pts, true, cv::Scalar(0, 255, 0), 2, 8, 0);
            cv::line(img_decode, pts.at(5), pts.at(2), cv::Scalar(0, 255, 0), 2);

            cv::cvtColor(img_decode, img_decode, cv::COLOR_BGR2RGB);    //BGR convert to RGB
            QImage Qtemp = QImage((const unsigned char*)(img_decode.data), img_decode.cols, img_decode.rows, img_decode.step, QImage::Format_RGB888);
            ui->camFrame->setPixmap(QPixmap::fromImage(Qtemp));
            ui->camFrame->resize(Qtemp.size());
            ui->camFrame->show();

        } catch (...) {
            qDebug() << "err";
        }
    }
}

void CalibrationSetup::handleGetPara(QString data)
{
    qDebug() << "[CalibrationSetup::handleGetPara]: " << data;

    QStringList data_list =  data.split(';');// 按分号符分割数据包

    if(data_list.length() == 12)
    {
        for(int i = 0; i < 6; i++)  // 取前6个坐标点
        {
            QStringList point_data = data_list.at(i).split(',');// 按逗号符分割坐标点数据
            left_point_list[i].x = point_data.at(0).toInt();
            left_point_list[i].y = point_data.at(1).toInt();
        }
        for(int i = 0; i < 6; i++)  // 取后6个坐标点
        {
            QStringList point_data = data_list.at(i+6).split(',');// 按逗号符分割坐标点数据
            right_point_list[i].x = point_data.at(0).toInt();
            right_point_list[i].y = point_data.at(1).toInt();
        }
    }
}

void CalibrationSetup::cameraCom_index_changed(int index)
{
    qDebug() << "[CalibrationSetup::combox_index_changed]" << index;
    QString requestInfo;

    if(index == 0)
    {
        requestInfo = "[CalibrationSetup] ";    // 数据包头
        requestInfo += "LeftCamOpen";           // 添加指令
        net->sendPacket(requestInfo);           // UDP发送数据包
        pos_info = "point:[0, 0]";
    }
    else if(index == 1)
    {
        requestInfo = "[CalibrationSetup] ";    // 数据包头
        requestInfo += "RightCamOpen";          // 添加指令
        net->sendPacket(requestInfo);           // UDP发送数据包
        pos_info = "point:[0, 0]";
    }
}

void CalibrationSetup::handleSetupFeedBack(bool state)
{
    if(state) {
//        QMessageBox::information(this, "提示", "设置成功！");
        MessageBox m;
        m.setMessageText("设置成功！");
        m.exec();
    }
    else {
//        QMessageBox::information(this, "提示", "设置失败！");
        MessageBox m;
        m.setMessageText("设置失败！");
        m.exec();
    }
}

// 鼠标点击事件
void CalibrationSetup::mousePressEvent(QMouseEvent *event)
{
    int x = event->x() - 160;
    int y = event->y();

    if(x >= 0 && event->button() == Qt::LeftButton)
    {
        std::stringstream info;
        info << "point:[" << x << ", " << y << "]";
        pos_info = info.str();

        qDebug() << QString::fromStdString(pos_info);

        int index = ui->cameraCom->currentIndex();
        if(index == 0)
        {
            index = ui->pointCom->currentIndex();
            left_point_list[index].x = x;
            left_point_list[index].y = y;
        }
        else if(index == 1)
        {
            index = ui->pointCom->currentIndex();
            right_point_list[index].x = x;
            right_point_list[index].y = y;
        }
    }
}
