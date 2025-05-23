#ifndef DOCWINDOW_H
#define DOCWINDOW_H

#include <QTextEdit>

class DocWindow : public QTextEdit
{
    Q_OBJECT

private:
    QString m_strFileName;

public:
    DocWindow(QWidget* pwgt = nullptr);

signals:
    void changeWindowTitle(const QString&);

public slots:
    void slotLoad();
    void slotSave();
    void slotSaveAs();
    void slotColor();

};

#endif // DOCWINDOW_H
