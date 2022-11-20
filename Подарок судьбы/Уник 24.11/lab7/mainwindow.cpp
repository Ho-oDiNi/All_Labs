#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "graphicscene1.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    scene = new graphicscene1(this);

    ui->graphicsView->setScene(scene);
}

MainWindow::~MainWindow()
{
delete ui;
}
