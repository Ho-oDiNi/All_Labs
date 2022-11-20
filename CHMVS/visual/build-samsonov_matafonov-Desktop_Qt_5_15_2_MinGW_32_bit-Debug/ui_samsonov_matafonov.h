/********************************************************************************
** Form generated from reading UI file 'samsonov_matafonov.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SAMSONOV_MATAFONOV_H
#define UI_SAMSONOV_MATAFONOV_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Samsonov_Matafonov
{
public:
    QGridLayout *gridLayout;
    QLabel *label;
    QTextEdit *textEdit;
    QDialogButtonBox *buttonBox;

    void setupUi(QWidget *Samsonov_Matafonov)
    {
        if (Samsonov_Matafonov->objectName().isEmpty())
            Samsonov_Matafonov->setObjectName(QString::fromUtf8("Samsonov_Matafonov"));
        Samsonov_Matafonov->resize(542, 322);
        gridLayout = new QGridLayout(Samsonov_Matafonov);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(Samsonov_Matafonov);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMinimumSize(QSize(200, 0));
        label->setMaximumSize(QSize(200, 200));
        label->setFrameShape(QFrame::Box);
        label->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(label, 0, 0, 1, 1);

        textEdit = new QTextEdit(Samsonov_Matafonov);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setStyleSheet(QString::fromUtf8("font: 10pt \"xos4 Terminus\";"));

        gridLayout->addWidget(textEdit, 0, 1, 1, 1);

        buttonBox = new QDialogButtonBox(Samsonov_Matafonov);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setStyleSheet(QString::fromUtf8("background:rgb(224, 226, 255)"));
        buttonBox->setStandardButtons(QDialogButtonBox::Open|QDialogButtonBox::Reset|QDialogButtonBox::Save);

        gridLayout->addWidget(buttonBox, 1, 0, 1, 2);


        retranslateUi(Samsonov_Matafonov);

        QMetaObject::connectSlotsByName(Samsonov_Matafonov);
    } // setupUi

    void retranslateUi(QWidget *Samsonov_Matafonov)
    {
        Samsonov_Matafonov->setWindowTitle(QCoreApplication::translate("Samsonov_Matafonov", "Form", nullptr));
        label->setText(QCoreApplication::translate("Samsonov_Matafonov", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Samsonov_Matafonov: public Ui_Samsonov_Matafonov {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SAMSONOV_MATAFONOV_H
