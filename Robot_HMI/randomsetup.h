#ifndef RANDOMSETUP_H
#define RANDOMSETUP_H

#include <QDialog>

namespace Ui {
class RandomSetup;
}

class RandomSetup : public QDialog
{
    Q_OBJECT

public:
    explicit RandomSetup(QWidget *parent = nullptr);
    ~RandomSetup();

    int winShow();

public slots:
    void btn_ok_clicked();
    void btn_cancel_clicked();

private:
    Ui::RandomSetup *ui;

    int step_num;
};

#endif // RANDOMSETUP_H
