#include "qsixface.h"

QSixFace::QSixFace(QWidget *parent) : QWidget(parent)
{
}

void QSixFace::setSixFace(QByteArray data)
{
    if(data.length() == 54) //校验序列长度
    {
        cubelist = data;
//        emit sixFaceChanged(data);
        repaint();
    }
}

QSize QSixFace::sizeHint()
{
    int H = this->height();
    int W = this->width();
    QSize size(W, H);
    return size;
}

void QSixFace::paintEvent(QPaintEvent *event)
{
    //界面组件的绘制
    Q_UNUSED(event);

    QPainter painter(this);
    QRect rect(0, 0, width(), height());
    painter.setViewport(rect);
    painter.setWindow(0, 0, 140, 106);	//设置窗口大小，逻辑坐标
    painter.setRenderHint(QPainter::Antialiasing);
    painter.setRenderHint(QPainter::TextAntialiasing);

    //绘制边框
    QPen pen;
    pen.setWidth(1);
    pen.setColor(mColorBorder);
    pen.setStyle(Qt::SolidLine);
    pen.setCapStyle(Qt::FlatCap);
    pen.setJoinStyle(Qt::BevelJoin);
    painter.setPen(pen);

    QBrush brush;
    brush.setColor(mColorBack);
    brush.setStyle(Qt::SolidPattern);
    painter.setBrush(brush);

    rect.setRect(0, 0, 140, 106);
    painter.drawRect(rect);		//绘制边框


    pen.setColor(mColorBorder);

    for(int i=0; i<54; i++)
    {
        switch(cubelist[i])      // 设置画刷颜色
        {
        case 'X':   brush.setColor(mColorUnknow);   break;
        case 'F':   brush.setColor(mColorF);        break;
        case 'B':   brush.setColor(mColorB);        break;
        case 'L':   brush.setColor(mColorL);        break;
        case 'R':   brush.setColor(mColorR);        break;
        case 'U':   brush.setColor(mColorU);        break;
        case 'D':   brush.setColor(mColorD);        break;
        }

        painter.setBrush(brush);
        painter.setPen(pen);

        rect.setRect(pointList[i][0], pointList[i][1], 10, 10);
        painter.drawRect(rect);		//绘制色块
    }
}
