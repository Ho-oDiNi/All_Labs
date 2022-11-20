#ifndef MAINWINDOW_IRIKOV_H
#define MAINWINDOW_IRIKOV_H

#include <QMainWindow>

namespace Ui {
class MainWindow_Irikov;
}

class MainWindow_Irikov : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow_Irikov(QWidget *parent = nullptr);
    ~MainWindow_Irikov();

private:
    Ui::MainWindow_Irikov *ui;
};

#endif // MAINWINDOW_IRIKOV_H
