#include "mainwindow_Irikov.h"
#include "ui_mainwindow_Irikov.h"

MainWindow_Irikov::MainWindow_Irikov(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow_Irikov)
{
    ui->setupUi(this);
}

MainWindow_Irikov::~MainWindow_Irikov()
{
    delete ui;
}
