/********************************************************************************
** Form generated from reading UI file 'formmp.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORMMP_H
#define UI_FORMMP_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FormMP
{
public:
    QLabel *label;
    QTextEdit *textEdit;
    QDialogButtonBox *buttonBox;

    void setupUi(QWidget *FormMP)
    {
        if (FormMP->objectName().isEmpty())
            FormMP->setObjectName(QString::fromUtf8("FormMP"));
        FormMP->resize(400, 300);
        label = new QLabel(FormMP);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 90, 101, 51));
        label->setScaledContents(true);
        textEdit = new QTextEdit(FormMP);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setGeometry(QRect(130, 20, 231, 211));
        buttonBox = new QDialogButtonBox(FormMP);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(80, 260, 231, 23));
        buttonBox->setStandardButtons(QDialogButtonBox::Open|QDialogButtonBox::Reset|QDialogButtonBox::Save);
        buttonBox->setCenterButtons(false);

        retranslateUi(FormMP);

        QMetaObject::connectSlotsByName(FormMP);
    } // setupUi

    void retranslateUi(QWidget *FormMP)
    {
        FormMP->setWindowTitle(QCoreApplication::translate("FormMP", "Form", nullptr));
        label->setText(QCoreApplication::translate("FormMP", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FormMP: public Ui_FormMP {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMMP_H
