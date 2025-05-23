#include "docwindow_Irikov.h"
#include <QFileDialog>
#include <QTextStream>
#include <QMessageBox>
#include <QColorDialog>

DocWindow_Irikov::DocWindow_Irikov(QWidget* pwgt): QTextEdit(pwgt)
{

}

void DocWindow_Irikov::slotLoad()
{
    QString str = QFileDialog::getOpenFileName();
    if (str.isEmpty()) {
        return;
    }

    QFile file(str);
    if(file.open(QIODevice::ReadOnly)) {
        QTextStream stream(&file);
        setPlainText(stream.readAll());
        file.close();

        m_strFileName = str;
        emit changeWindowTitle(m_strFileName);
    }
}

void DocWindow_Irikov::slotSaveAs()
{
    QString str = QFileDialog::getSaveFileName(nullptr, m_strFileName);
    if (!str.isEmpty()) {
        m_strFileName=str;
        slotSave();
    }
}

void DocWindow_Irikov::slotSave()
{
    if (m_strFileName.isEmpty()) {
        slotSaveAs();
        return;
    }

    QFile file(m_strFileName);

    if (file.open(QIODevice::WriteOnly)) {
        QTextStream(&file) << toPlainText();
        file.close();
        emit changeWindowTitle(m_strFileName);
        QMessageBox::information(this, "Файл сохранён", "Файл успешно сохранён");

    }

}
void DocWindow_Irikov::slotColor()
{
    setTextColor(QColorDialog::getColor());
}
