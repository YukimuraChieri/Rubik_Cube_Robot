#include "lightsetup.h"
#include "ui_lightsetup.h"

LightSetup::LightSetup(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LightSetup)
{
    ui->setupUi(this);

    this->setAttribute(Qt::WA_DeleteOnClose, 1);   //窗口关闭自动删除

    net = NetworkService::getNetworkServiceIntance();   //获取实例对象接口

    connect(ui->btn_back, SIGNAL(clicked()), this, SLOT(btn_back_clicked()));
    connect(ui->lightDial, SIGNAL(sliderReleased()), this, SLOT(dial_light_change()));
    connect(ui->leftExposureDial, SIGNAL(sliderReleased()), this, SLOT(left_exposure_change()));
    connect(ui->rightExposureDial, SIGNAL(sliderReleased()), this, SLOT(right_exposure_change()));

    connect(net, SIGNAL(leftCameraData(QByteArray)), this, SLOT(handleReadLeftCamera(QByteArray)));
    connect(net, SIGNAL(rightCameraData(QByteArray)), this, SLOT(handleReadRightCamera(QByteArray)));

    QString requestInfo;
    requestInfo = "[LightSetup] ";  // 数据包头
    requestInfo += "CamerasOpen";   // 添加指令

    net->sendPacket(requestInfo);   // UDP发送数据包
}

LightSetup::~LightSetup()
{
    delete ui;
}

void LightSetup::btn_back_clicked()
{
    QString requestInfo;
    requestInfo = "[LightSetup] ";  // 数据包头
    requestInfo += "CamerasClose";  // 添加指令

    net->sendPacket(requestInfo);   // UDP发送数据包

    emit return_setup();
    this->close();
}

void LightSetup::dial_light_change()
{
    int value = ui->lightDial->value();
    qDebug() << "[LightSetup::dial_light_change] " << value;
    QString requestInfo;
    requestInfo = "[LightSetup] ";    // 数据包头
    requestInfo += QString::number(value);  // 添加指令
    net->sendPacket(requestInfo);   // UDP发送数据包
}

void LightSetup::left_exposure_change()
{
    int value = ui->leftExposureDial->value();
    qDebug() << "[LightSetup::left_exposure_change] " << value;
    QString requestInfo;
    requestInfo = "[LeftExposure] ";    // 数据包头
    requestInfo += QString::number(value);  // 添加指令
    net->sendPacket(requestInfo);   // UDP发送数据包
}

void LightSetup::right_exposure_change()
{
    int value = ui->rightExposureDial->value();
    qDebug() << "[LightSetup::right_exposure_change] " << value;
    QString requestInfo;
    requestInfo = "[RightExposure] ";    // 数据包头
    requestInfo += QString::number(value);  // 添加指令
    net->sendPacket(requestInfo);   // UDP发送数据包
}

void LightSetup::handleReadLeftCamera(QByteArray data)
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
        // 最小分辨率（320x240像素）
        cv::Size dsize = cv::Size(320, 240);
        cv::resize(img_decode, img_decode, dsize, 0, 0, cv::INTER_AREA);
        try {
            cvtColor(img_decode, img_decode, cv::COLOR_BGR2RGB);    //BGR convert to RGB
            QImage Qtemp = QImage((const unsigned char*)(img_decode.data), img_decode.cols, img_decode.rows, img_decode.step, QImage::Format_RGB888);
            ui->leftFrame->setPixmap(QPixmap::fromImage(Qtemp));
            ui->leftFrame->resize(Qtemp.size());
            ui->leftFrame->show();

        } catch (...) {
            qDebug() << "err";
        }
    }
}

void LightSetup::handleReadRightCamera(QByteArray data)
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
        // 最小分辨率（320x240像素）
        cv::Size dsize = cv::Size(320, 240);
        cv::resize(img_decode, img_decode, dsize, 0, 0, cv::INTER_AREA);
        try {
            cvtColor(img_decode, img_decode, cv::COLOR_BGR2RGB);    //BGR convert to RGB
            QImage Qtemp = QImage((const unsigned char*)(img_decode.data), img_decode.cols, img_decode.rows, img_decode.step, QImage::Format_RGB888);
            ui->rightFrame->setPixmap(QPixmap::fromImage(Qtemp));
            ui->rightFrame->resize(Qtemp.size());
            ui->rightFrame->show();

        } catch (...) {
            qDebug() << "err";
        }
    }
}
