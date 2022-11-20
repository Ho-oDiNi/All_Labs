#include "startdialog_Irikov.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    StartDialog_Irikov startDialog;
    startDialog.show();

    return a.exec();
}
