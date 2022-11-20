#include "formmp.h"
#include "ui_formmp.h"



FormMP::FormMP(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormMP)
{
    ui->setupUi(this);
}

FormMP::~FormMP()
{
    delete ui;
}

void FormMP::recieveData(QString str)
{
    QStringList lst = str.split("*");
    ui->textEdit->setText(lst.at(1) + "\n" + lst.at(0));
    if(lst.size()>1)
    {
        QImage image1(lst.at(0));
        ui->label->setPixmap(QPixmap::fromImage((image1)));
    }
}

void FormMP::slotSave()
{
    if(m_strFileName.isEmpty()){
        slotSaveAs();
        return;
    }
    QFile file(m_strFileName);
    if(file.open(QIODevice::WriteOnly)){
        QTextStream out(&file);
        out << ui->textEdit->toPlainText();
        file.close();

    }
}

void FormMP::slotSaveAs()
{
    QString str = QFileDialog::getSaveFileName(0, m_strFileName);
    if(!str.isEmpty()){
        m_strFileName = str;
        slotSave();
    }
}

void FormMP::on_buttonBox_clicked(QAbstractButton *button)
{
    if(button->text()=="Reset")
    {
        QString filename = 0;
        ui->textEdit->setPlainText("");
        QImage image1(filename);
        ui->label->setPixmap(QPixmap::fromImage(image1));
    }
    if(button->text()=="Open")
    {
        QString str = QFileDialog::getOpenFileName();

        if(str.isEmpty())
        {
            return;
        }

        QFile file(str);

        if(file.open(QIODevice::ReadOnly)){
            QTextStream stream(&file);
            ui->textEdit->setText((stream.readAll()));
            QStringList inf = ui->textEdit->toPlainText().split("\n");
            QImage image2(inf.at(4));
            ui->label->setPixmap(QPixmap::fromImage(image2));
            file.close();

        }
        m_strFileName = str;
        //emit changeWindowTitle(m_strFileName);

    }
    if(button->text()=="Save")
    {
        slotSaveAs();
    }
}
