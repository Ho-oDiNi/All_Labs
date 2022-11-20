/********************************************************************************
** Form generated from reading UI file 'inputdialog_Irikov.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INPUTDIALOG_IRIKOV_H
#define UI_INPUTDIALOG_IRIKOV_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow_Samsonov_Matafonov
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow_Samsonov_Matafonov)
    {
        if (MainWindow_Samsonov_Matafonov->objectName().isEmpty())
            MainWindow_Samsonov_Matafonov->setObjectName(QString::fromUtf8("MainWindow_Samsonov_Matafonov"));
        MainWindow_Samsonov_Matafonov->resize(400, 300);
        menuBar = new QMenuBar(MainWindow_Samsonov_Matafonov);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        MainWindow_Samsonov_Matafonov->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow_Samsonov_Matafonov);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow_Samsonov_Matafonov->addToolBar(mainToolBar);
        centralWidget = new QWidget(MainWindow_Samsonov_Matafonov);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        MainWindow_Samsonov_Matafonov->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(MainWindow_Samsonov_Matafonov);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow_Samsonov_Matafonov->setStatusBar(statusBar);

        retranslateUi(MainWindow_Samsonov_Matafonov);

        QMetaObject::connectSlotsByName(MainWindow_Samsonov_Matafonov);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow_Samsonov_Matafonov)
    {
        MainWindow_Samsonov_Matafonov->setWindowTitle(QCoreApplication::translate("MainWindow_Samsonov_Matafonov", "MainWindow_Samsonov_Matafonov", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow_Samsonov_Matafonov: public Ui_MainWindow_Samsonov_Matafonov {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INPUTDIALOG_IRIKOV_H
