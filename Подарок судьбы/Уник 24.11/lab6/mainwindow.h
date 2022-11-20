#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include "formmp.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();


private:
    FormMP *myform;
    Ui::MainWindow *ui;

signals:
    void sendData(QString str);

private slots:
    void onButtonSend();
    void on_pushButton_2_clicked();
};

#endif // MAINWINDOW_H
