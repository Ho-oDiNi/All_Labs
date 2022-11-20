#ifndef FORMMP_H
#define FORMMP_H

#include <QWidget>
#include <QAbstractButton>
#include <QFile>
#include <QFileDialog>
#include <QTextStream>
#include <QString>

namespace Ui {
class FormMP;
}

class FormMP : public QWidget
{
    Q_OBJECT

public:
    explicit FormMP(QWidget *parent = 0);
    ~FormMP();

private:
    Ui::FormMP *ui;
    QString m_strFileName;

public slots:
    void recieveData(QString str);
    void on_buttonBox_clicked(QAbstractButton *button);
    void on_buttonBox_accepted();
    void slotSave();
    void slotSaveAs();

};

#endif // FORMMP_H
