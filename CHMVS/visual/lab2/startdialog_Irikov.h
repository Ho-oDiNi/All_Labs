#ifndef STARTDIALOG_IRIKOV_H
#define STARTDIALOG_IRIKOV_H

#include <QWidget>
#include <QPushButton>
#include <QMessageBox>
#include "inputdialog_Irikov.h"

class StartDialog_Irikov : public QPushButton
{
    Q_OBJECT
public:
    StartDialog_Irikov(QWidget* pwgt = nullptr) : QPushButton("нажми", pwgt)
    {
        connect(this, SIGNAL(clicked()), SLOT(slotButtonClicked()));
    }

signals:

public slots:
    void slotButtonClicked()
    {
        InputDialog_Irikov* pInputDialog = new InputDialog_Irikov;
        if (pInputDialog->exec() == QDialog::Accepted) {
            QMessageBox::information(nullptr, "Ваша информация: ", "Имя: " + pInputDialog->firstName() + " Фамилия: " + pInputDialog->lastName());
        }
        delete pInputDialog;
    }
};

#endif // STARTDIALOG_IRIKOV_H
