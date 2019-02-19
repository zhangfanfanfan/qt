#include "calcwidget.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    CalcWidget w;
    w.show();

    return a.exec();
}
