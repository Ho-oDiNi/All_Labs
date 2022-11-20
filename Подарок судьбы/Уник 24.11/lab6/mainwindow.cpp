#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QFileDialog>
#include <QTextStream>
#include <QMessageBox>
#include <QColorDialog>
#include <QApplication>
#include <QtWidgets>
#include <QSplashScreen>
#include <QTime>
#include <QElapsedTimer>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    myform = new FormMP();

    connect(ui->pushButton, SIGNAL(clicked()), myform, SLOT(show()));
    connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(onButtonSend()));
    connect(this, SIGNAL(sendData(QString)), myform, SLOT(recieveData(QString)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_2_clicked()
{
    QString filename = QFileDialog::getOpenFileName(0, "Выберите изображение", QDir::currentPath(), "*.png *.jpg *.jpeg *.gif");
    if(filename.isEmpty()){
       QMessageBox::information(this, "Ошибка", "Файл не выбран");
       return;
    }
    ui->lineEdit_3->setText(filename);
    QImage image1(filename);
    ui->label->setPixmap(QPixmap::fromImage((image1)));

    QString st = ui->lineEdit_3->text()+"*"+ ui->lineEdit->text()+"\n"+ui->lineEdit_2->text()+"\n"+ui->dateEdit->text();

    if(ui->radioButton->isChecked()==true) st+="\nпол: мужской";
        else st+="\nпол: женский";

    emit sendData(st);
}



