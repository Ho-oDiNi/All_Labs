/********************************************************************************
** Form generated from reading UI file 'sdiprogram_samsonov_matafonov.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SDIPROGRAM_SAMSONOV_MATAFONOV_H
#define UI_SDIPROGRAM_SAMSONOV_MATAFONOV_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SDIProgram_Samsonov_Matafonov
{
public:
    QWidget *centralWidget;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *SDIProgram_Samsonov_Matafonov)
    {
        if (SDIProgram_Samsonov_Matafonov->objectName().isEmpty())
            SDIProgram_Samsonov_Matafonov->setObjectName(QString::fromUtf8("SDIProgram_Samsonov_Matafonov"));
        SDIProgram_Samsonov_Matafonov->resize(400, 300);
        centralWidget = new QWidget(SDIProgram_Samsonov_Matafonov);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        SDIProgram_Samsonov_Matafonov->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(SDIProgram_Samsonov_Matafonov);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 400, 24));
        SDIProgram_Samsonov_Matafonov->setMenuBar(menuBar);
        mainToolBar = new QToolBar(SDIProgram_Samsonov_Matafonov);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        SDIProgram_Samsonov_Matafonov->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(SDIProgram_Samsonov_Matafonov);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        SDIProgram_Samsonov_Matafonov->setStatusBar(statusBar);

        retranslateUi(SDIProgram_Samsonov_Matafonov);

        QMetaObject::connectSlotsByName(SDIProgram_Samsonov_Matafonov);
    } // setupUi

    void retranslateUi(QMainWindow *SDIProgram_Samsonov_Matafonov)
    {
        SDIProgram_Samsonov_Matafonov->setWindowTitle(QCoreApplication::translate("SDIProgram_Samsonov_Matafonov", "SDIProgram_Samsonov_Matafonov", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SDIProgram_Samsonov_Matafonov: public Ui_SDIProgram_Samsonov_Matafonov {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SDIPROGRAM_SAMSONOV_MATAFONOV_H
