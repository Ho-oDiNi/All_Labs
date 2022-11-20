/********************************************************************************
** Form generated from reading UI file 'lab6.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LAB6_H
#define UI_LAB6_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Irikov
{
public:
    QGridLayout *gridLayout;
    QLabel *label;
    QTextEdit *textEdit;
    QDialogButtonBox *buttonBox;

    void setupUi(QWidget *Irikov)
    {
        if (Irikov->objectName().isEmpty())
            Irikov->setObjectName(QString::fromUtf8("Irikov"));
        Irikov->resize(542, 322);
        gridLayout = new QGridLayout(Irikov);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(Irikov);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMinimumSize(QSize(200, 0));
        label->setMaximumSize(QSize(200, 200));
        label->setFrameShape(QFrame::Box);
        label->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(label, 0, 0, 1, 1);

        textEdit = new QTextEdit(Irikov);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setStyleSheet(QString::fromUtf8("font: 10pt \"xos4 Terminus\";"));

        gridLayout->addWidget(textEdit, 0, 1, 1, 1);

        buttonBox = new QDialogButtonBox(Irikov);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setStyleSheet(QString::fromUtf8("background:rgb(224, 226, 255)"));
        buttonBox->setStandardButtons(QDialogButtonBox::Open|QDialogButtonBox::Reset|QDialogButtonBox::Save);

        gridLayout->addWidget(buttonBox, 1, 0, 1, 2);


        retranslateUi(Irikov);

        QMetaObject::connectSlotsByName(Irikov);
    } // setupUi

    void retranslateUi(QWidget *Irikov)
    {
        Irikov->setWindowTitle(QCoreApplication::translate("Irikov", "Form", nullptr));
        label->setText(QCoreApplication::translate("Irikov", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Irikov: public Ui_Irikov {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LAB6_H
