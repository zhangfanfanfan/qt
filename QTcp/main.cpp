#include "tcpserver.h"
#include <QApplication>
#include "tcpclient.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    TcpServer w1;
    TcpClient w2;
    w1.show();
    w2.show();

    return a.exec();
}
