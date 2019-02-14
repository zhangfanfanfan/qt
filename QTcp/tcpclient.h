#ifndef TCPCLIENT_H
#define TCPCLIENT_H

#include <QWidget>
#include <QTcpSocket>
namespace Ui {
class TcpClient;
}

class TcpClient : public QWidget
{
    Q_OBJECT

public:
    explicit TcpClient(QWidget *parent = 0);
    ~TcpClient();

private slots:
    void on_pushButtonConnect_clicked();

    void on_pushButtonSend_clicked();

    void on_pushButtonClose_clicked();

private:
    Ui::TcpClient *ui;
    QTcpSocket *tcpSocket;

};

#endif // TCPCLIENT_H
