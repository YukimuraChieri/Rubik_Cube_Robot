#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include "fullmode.h"
#include "simplemode.h"
#include "setupmode.h"
#include "manumode.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

    QByteArray cmd;

public slots:
    void btn_main_clicked();
    void btn_simple_clicked();
    void btn_setup_clicked();
    void btn_manual_clicked();
    void reshow();
    void shutdown();

};

#endif // MAINWINDOW_H
