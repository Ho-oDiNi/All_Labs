/********************************************************************************
** Form generated from reading UI file 'mainwindow_Irikov.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_IRIKOV_H
#define UI_MAINWINDOW_IRIKOV_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow_Irikov
{
public:
    QWidget *centralWidget;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow_Irikov)
    {
        if (MainWindow_Irikov->objectName().isEmpty())
            MainWindow_Irikov->setObjectName(QString::fromUtf8("MainWindow_Irikov"));
        MainWindow_Irikov->resize(400, 300);
        centralWidget = new QWidget(MainWindow_Irikov);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        MainWindow_Irikov->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow_Irikov);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 400, 22));
        MainWindow_Irikov->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow_Irikov);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow_Irikov->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow_Irikov);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow_Irikov->setStatusBar(statusBar);

        retranslateUi(MainWindow_Irikov);

        QMetaObject::connectSlotsByName(MainWindow_Irikov);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow_Irikov)
    {
        MainWindow_Irikov->setWindowTitle(QCoreApplication::translate("MainWindow_Irikov", "MainWindow_Irikov", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow_Irikov: public Ui_MainWindow_Irikov {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_IRIKOV_H
