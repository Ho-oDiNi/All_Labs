#ifndef INPUTDIALOG_IRIKOV_H
#define INPUTDIALOG_IRIKOV_H

#include <QDialog>
#include <QLineEdit>

class InputDialog_Irikov: public QDialog
{
    Q_OBJECT
private:
    QLineEdit* m_ptxtFirstName;
    QLineEdit* m_ptxtLastName;
public:
    InputDialog_Irikov(QWidget* pwgt = nullptr);

    QString firstName() const;
    QString lastName() const;
};

#endif // INPUTDIALOG_IRIKOV_H
