#ifndef TCPSERVER_H
#define TCPSERVER_H

#include <QWidget>
#include <QTcpServer>
#include <QTcpSocket>

namespace Ui {
class TcpServer;
}

class TcpServer : public QWidget
{
    Q_OBJECT

public:
    explicit TcpServer(QWidget *parent = 0);
    ~TcpServer();

private slots:
    void on_pushButtonSend_clicked();

    void on_pushButtonClose_clicked();

private:
    Ui::TcpServer *ui;
    QTcpServer *tcpServer;
    QTcpSocket *tcpSocket;
};

#endif // TCPSERVER_H
