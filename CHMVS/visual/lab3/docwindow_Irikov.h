#ifndef DOCWINDOW_IRIKOV_H
#define DOCWINDOW_IRIKOV_H

#include <QTextEdit>

class DocWindow_Irikov : public QTextEdit
{
    Q_OBJECT
private:
    QString m_strFileName;
public:
    DocWindow_Irikov(QWidget* pwgt = nullptr);
signals:
    void changeWindowTitle(const QString&);
public slots:
    void slotLoad();
    void slotSave();
    void slotSaveAs();
    void slotColor();
};

#endif // DOCWINDOW_IRIKOV_H
