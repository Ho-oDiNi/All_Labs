/********************************************************************************
** Form generated from reading UI file 'sdiprogram_Irikov.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SDIPROGRAM_IRIKOV_H
#define UI_SDIPROGRAM_IRIKOV_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SDIProgram_Irikov
{
public:
    QWidget *centralWidget;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *SDIProgram_Irikov)
    {
        if (SDIProgram_Irikov->objectName().isEmpty())
            SDIProgram_Irikov->setObjectName(QString::fromUtf8("SDIProgram_Irikov"));
        SDIProgram_Irikov->resize(400, 300);
        centralWidget = new QWidget(SDIProgram_Irikov);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        SDIProgram_Irikov->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(SDIProgram_Irikov);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 400, 22));
        SDIProgram_Irikov->setMenuBar(menuBar);
        mainToolBar = new QToolBar(SDIProgram_Irikov);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        SDIProgram_Irikov->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(SDIProgram_Irikov);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        SDIProgram_Irikov->setStatusBar(statusBar);

        retranslateUi(SDIProgram_Irikov);

        QMetaObject::connectSlotsByName(SDIProgram_Irikov);
    } // setupUi

    void retranslateUi(QMainWindow *SDIProgram_Irikov)
    {
        SDIProgram_Irikov->setWindowTitle(QCoreApplication::translate("SDIProgram_Irikov", "SDIProgram_Irikov", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SDIProgram_Irikov: public Ui_SDIProgram_Irikov {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SDIPROGRAM_IRIKOV_H
