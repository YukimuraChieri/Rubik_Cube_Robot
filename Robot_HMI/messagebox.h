#ifndef MESSAGEBOX_H
#define MESSAGEBOX_H

#include <QDialog>
#include <QPainter>
#include <QPaintEvent>


namespace Ui {
class MessageBox;
}

class MessageBox : public QDialog
{
    Q_OBJECT

public:
    explicit MessageBox(QWidget *parent = nullptr);
    ~MessageBox();

    void setMessageText(QString mess);

public slots:
    void btn_ok_clicked();

private:
    Ui::MessageBox *ui;    
};

#endif // MESSAGEBOX_H
