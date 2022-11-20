/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout_4;
    QGridLayout *gridLayout_3;
    QVBoxLayout *verticalLayout;
    QLabel *label_photo;
    QLineEdit *lineEdit_path;
    QPushButton *pushButton_load;
    QGridLayout *gridLayout_2;
    QLabel *label_birthday;
    QHBoxLayout *horizontalLayout;
    QRadioButton *radioButton_m;
    QRadioButton *radioButton_f;
    QDateEdit *dateEdit;
    QLineEdit *lineEdit_phone;
    QLabel *label_phone;
    QGridLayout *gridLayout;
    QLineEdit *lineEdit_dolzhnost;
    QLineEdit *lineEdit_fio;
    QLabel *label_dolzhnost;
    QLabel *label_fio;
    QSpacerItem *verticalSpacer;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *pushButton;
    QSpacerItem *horizontalSpacer_3;
    QMenuBar *menuBar;
    QStatusBar *statusBar;
    QToolBar *mainToolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(487, 444);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout_4 = new QGridLayout(centralWidget);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        gridLayout_3 = new QGridLayout();
        gridLayout_3->setSpacing(6);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label_photo = new QLabel(centralWidget);
        label_photo->setObjectName(QString::fromUtf8("label_photo"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_photo->sizePolicy().hasHeightForWidth());
        label_photo->setSizePolicy(sizePolicy);
        label_photo->setMinimumSize(QSize(200, 200));
        label_photo->setStyleSheet(QString::fromUtf8("font: 10pt \"xos4 Terminus\";\n"
"color:rgb(104, 0, 130)"));
        label_photo->setFrameShape(QFrame::Box);
        label_photo->setFrameShadow(QFrame::Sunken);
        label_photo->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_photo);

        lineEdit_path = new QLineEdit(centralWidget);
        lineEdit_path->setObjectName(QString::fromUtf8("lineEdit_path"));

        verticalLayout->addWidget(lineEdit_path);

        pushButton_load = new QPushButton(centralWidget);
        pushButton_load->setObjectName(QString::fromUtf8("pushButton_load"));
        pushButton_load->setStyleSheet(QString::fromUtf8("background:rgb(133, 192, 255)"));

        verticalLayout->addWidget(pushButton_load);


        gridLayout_3->addLayout(verticalLayout, 0, 0, 2, 1);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(6);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        label_birthday = new QLabel(centralWidget);
        label_birthday->setObjectName(QString::fromUtf8("label_birthday"));
        label_birthday->setStyleSheet(QString::fromUtf8("font: 10pt \"xos4 Terminus\";\n"
"color:rgb(104, 0, 130)"));

        gridLayout_2->addWidget(label_birthday, 0, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        radioButton_m = new QRadioButton(centralWidget);
        radioButton_m->setObjectName(QString::fromUtf8("radioButton_m"));
        radioButton_m->setStyleSheet(QString::fromUtf8("font: 10pt \"xos4 Terminus\";"));

        horizontalLayout->addWidget(radioButton_m);

        radioButton_f = new QRadioButton(centralWidget);
        radioButton_f->setObjectName(QString::fromUtf8("radioButton_f"));
        radioButton_f->setStyleSheet(QString::fromUtf8("font: 10pt \"xos4 Terminus\";"));

        horizontalLayout->addWidget(radioButton_f);


        gridLayout_2->addLayout(horizontalLayout, 2, 0, 1, 2);

        dateEdit = new QDateEdit(centralWidget);
        dateEdit->setObjectName(QString::fromUtf8("dateEdit"));
        dateEdit->setStyleSheet(QString::fromUtf8(""));

        gridLayout_2->addWidget(dateEdit, 0, 1, 1, 1);

        lineEdit_phone = new QLineEdit(centralWidget);
        lineEdit_phone->setObjectName(QString::fromUtf8("lineEdit_phone"));
        lineEdit_phone->setStyleSheet(QString::fromUtf8(""));

        gridLayout_2->addWidget(lineEdit_phone, 1, 1, 1, 1);

        label_phone = new QLabel(centralWidget);
        label_phone->setObjectName(QString::fromUtf8("label_phone"));
        label_phone->setStyleSheet(QString::fromUtf8("font: 10pt \"xos4 Terminus\";\n"
"color:rgb(104, 0, 130)"));

        gridLayout_2->addWidget(label_phone, 1, 0, 1, 1);


        gridLayout_3->addLayout(gridLayout_2, 1, 1, 1, 1);

        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        lineEdit_dolzhnost = new QLineEdit(centralWidget);
        lineEdit_dolzhnost->setObjectName(QString::fromUtf8("lineEdit_dolzhnost"));

        gridLayout->addWidget(lineEdit_dolzhnost, 1, 1, 1, 1);

        lineEdit_fio = new QLineEdit(centralWidget);
        lineEdit_fio->setObjectName(QString::fromUtf8("lineEdit_fio"));

        gridLayout->addWidget(lineEdit_fio, 0, 1, 1, 1);

        label_dolzhnost = new QLabel(centralWidget);
        label_dolzhnost->setObjectName(QString::fromUtf8("label_dolzhnost"));
        label_dolzhnost->setStyleSheet(QString::fromUtf8("font: 10pt \"xos4 Terminus\";\n"
"color:rgb(104, 0, 130)"));

        gridLayout->addWidget(label_dolzhnost, 1, 0, 1, 1);

        label_fio = new QLabel(centralWidget);
        label_fio->setObjectName(QString::fromUtf8("label_fio"));
        label_fio->setStyleSheet(QString::fromUtf8("font: 10pt \"xos4 Terminus\";\n"
"color:rgb(104, 0, 130)"));

        gridLayout->addWidget(label_fio, 0, 0, 1, 1);


        gridLayout_3->addLayout(gridLayout, 0, 1, 1, 1);


        gridLayout_4->addLayout(gridLayout_3, 0, 0, 1, 3);

        verticalSpacer = new QSpacerItem(20, 86, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_4->addItem(verticalSpacer, 1, 1, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(177, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_4->addItem(horizontalSpacer_2, 2, 0, 1, 1);

        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setStyleSheet(QString::fromUtf8("background:rgb(176, 255, 185)"));

        gridLayout_4->addWidget(pushButton, 2, 1, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(177, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_4->addItem(horizontalSpacer_3, 2, 2, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 487, 24));
        MainWindow->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label_photo->setText(QCoreApplication::translate("MainWindow", "\320\244\320\276\321\202\320\276", nullptr));
        pushButton_load->setText(QCoreApplication::translate("MainWindow", "\320\227\320\260\320\263\321\200\321\203\320\267\320\270\321\202\321\214", nullptr));
        label_birthday->setText(QCoreApplication::translate("MainWindow", "\320\224\320\260\321\202\320\260 \321\200\320\276\320\266\320\264\320\265\320\275\320\270\321\217", nullptr));
        radioButton_m->setText(QCoreApplication::translate("MainWindow", "\320\234", nullptr));
        radioButton_f->setText(QCoreApplication::translate("MainWindow", "\320\226", nullptr));
        label_phone->setText(QCoreApplication::translate("MainWindow", "\320\235\320\276\320\274\320\265\321\200 \321\202\320\265\320\273\320\265\321\204\320\276\320\275\320\260", nullptr));
        lineEdit_fio->setText(QString());
        label_dolzhnost->setText(QCoreApplication::translate("MainWindow", "\320\224\320\276\320\273\320\266\320\275\320\276\321\201\321\202\321\214", nullptr));
        label_fio->setText(QCoreApplication::translate("MainWindow", "\320\244\320\230\320\236", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "\320\223\320\276\321\202\320\276\320\262\320\276", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
