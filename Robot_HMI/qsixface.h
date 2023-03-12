#ifndef QSIXFACE_H
#define QSIXFACE_H

#include <QWidget>
#include <QLabel>
#include <QPainter>
#include <QColor>
#include <QSize>

class QSixFace : public QWidget
{
    Q_OBJECT
public:
    explicit QSixFace(QWidget *parent = nullptr);
    void setSixFace(QByteArray data);   //设置六面色块
    QSize sizeHint();					//缺省大小

private:
    QColor mColorBack = Qt::white;          //背景颜色
    QColor mColorBorder = Qt::black;        //边框颜色
    QColor mColorUnknow = Qt::black;        //未知面颜色
    QColor mColorF = Qt::blue;              //魔方前面颜色
    QColor mColorB = Qt::green;             //魔方后面颜色
    QColor mColorL = QColor(255, 165, 0);   //魔方左面颜色
    QColor mColorR = Qt::red;               //魔方右面颜色
    QColor mColorU = Qt::yellow;            //魔方顶面颜色
    QColor mColorD = Qt::white;             //魔方底面颜色

    // 六面色块序列
    QByteArray cubelist = "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX";
    // 色块坐标起始点
    int pointList[54][2] = {
        {38, 4}, {48, 4}, {58, 4},      // U
        {38, 14}, {48, 14}, {58, 14},
        {38, 24}, {48, 24}, {58, 24},

        {72, 38}, {82, 38}, {92, 38},   // R
        {72, 48}, {82, 48}, {92, 48},
        {72, 58}, {82, 58}, {92, 58},

        {38, 38}, {48, 38}, {58, 38},   // F
        {38, 48}, {48, 48}, {58, 48},
        {38, 58}, {48, 58}, {58, 58},

        {38, 72}, {48, 72}, {58, 72},   // D
        {38, 82}, {48, 82}, {58, 82},
        {38, 92}, {48, 92}, {58, 92},

        {4, 38}, {14, 38}, {24, 38},    // L
        {4, 48}, {14, 48}, {24, 48},
        {4, 58}, {14, 58}, {24, 58},

        {106, 38}, {116, 38}, {126, 38},// B
        {106, 48}, {116, 48}, {126, 48},
        {106, 58}, {116, 58}, {126, 58}
    };

protected:
    void paintEvent(QPaintEvent *event) Q_DECL_OVERRIDE;

signals:
//    void sixFaceChanged(QByteArray);
};

#endif // QSIXFACE_H
