#include "sdiprogram.h"
#include <QApplication>
#include <QtWidgets>
#include <QSplashScreen>
#include <QTime>
#include <QElapsedTimer>
#include <unistd.h>
#include <iostream>

void loadModules(QSplashScreen* psplash)
{
    psplash->showMessage("Loading Modules: " + QString::number(0) + "%",
                         Qt::AlignCenter, Qt::blue);
    for(int i = 0; i <= 100; i+=10){
        sleep(1);

        qApp->processEvents();
    }
    psplash->showMessage("Loading Modules: " + QString::number(100) + "%",
                         Qt::AlignCenter, Qt::blue);
}

int main(int argc, char *argv[])
{
        QApplication a(argc, argv);
        QSplashScreen splash(QPixmap("D:/QtReps/lab3/pepega.png"));
        splash.show();
        SDIProgram sdi;
        loadModules(&splash);
        splash.finish(&sdi);
        sdi.show();

        return a.exec();
}
