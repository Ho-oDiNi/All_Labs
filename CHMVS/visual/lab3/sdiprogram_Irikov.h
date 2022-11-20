#ifndef SDIPROGRAM_IRIKOV_H
#define SDIPROGRAM_IRIKOV_H

#include <QMainWindow>
#include <QMenu>
#include <QMessageBox>
#include <QMenuBar>
#include <QStatusBar>
#include <QApplication>
#include "docwindow_Irikov.h"

namespace Ui {
class SDIProgram_Irikov;
}

class SDIProgram_Irikov : public QMainWindow
{
    Q_OBJECT

public:
    SDIProgram_Irikov(QWidget *pwgt = nullptr) : QMainWindow(pwgt)
    {
        QMenu* pmnuFile = new QMenu("&File");
        QMenu* pmnuHelp = new QMenu("&Help");
        DocWindow_Irikov* pdoc = new DocWindow_Irikov;
        pmnuFile->addAction("&Open...", pdoc, SLOT(slotLoad()), QKeySequence("CTRL+O"));
        pmnuFile->addAction("&Save",  pdoc, SLOT(slotSave()), QKeySequence("CTRL+S"));
        pmnuFile->addAction("&Save As...",  pdoc, SLOT(slotSaveAs()));
        pmnuFile->addSeparator();
        pmnuFile->addAction("&Quit", qApp, SLOT(quit()), QKeySequence("CTRL+Q"));

        pmnuHelp->addAction("&About", this, SLOT(slotAbout()), Qt::Key_F1);

        menuBar()->addMenu(pmnuFile);
        menuBar()->addMenu(pmnuHelp);
        setCentralWidget(pdoc);

        connect(pdoc, SIGNAL(changeWindowTitle(const QString&)), SLOT(slotChangeWindowTitle(const QString&)));
        statusBar()->showMessage("Ready", 2000);

        pmnuFile->addAction("&Color", pdoc, SLOT(slotColor()));
    }

    ~SDIProgram_Irikov();
public slots:
    void slotAbout()
    {
        QMessageBox::about(this, "Application", "Samsonov, Matafonov");
    }
    void slotChangeWindowTitle(const QString& str)
    {
        setWindowTitle(str);
    }
private:
    Ui::SDIProgram_Irikov *ui;
};

#endif // SDIPROGRAM_IRIKOV_H
