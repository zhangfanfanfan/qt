#include "tcpserver.h"
#include "ui_tcpserver.h"
#include <QDebug>
#define cout qDebug() << "[" << __FILE__ << ":" << __LINE__ << "]"

TcpServer::TcpServer(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TcpServer)
{
    ui->setupUi(this);
    ui->pushButtonClose->setEnabled(false);
    ui->pushButtonSend->setEnabled(false);
    tcpServer = new QTcpServer(this);
    this->setWindowTitle("服务器::10086");
    tcpServer->listen(QHostAddress::Any,10086);
    connect(tcpServer,&QTcpServer::newConnection,
            [=]()
    {
        tcpSocket = tcpServer->nextPendingConnection();
        QString Ip = tcpSocket->peerAddress().toString();
        qint16 port = tcpSocket->peerPort();
        QString temp = QString("[%1:%2]:已成功连接").arg(Ip).arg(port);
        ui->textEditRead->setText(temp);
        ui->pushButtonSend->setEnabled(true);
        ui->pushButtonClose->setEnabled(true);
        connect(tcpSocket,&QTcpSocket::readyRead,
                [=]()
        {
            QByteArray array = tcpSocket->readAll();
            if(array=="exit")
            {
                on_pushButtonClose_clicked();
                cout<<"客户端请求登出";
            }
            else
            {
                ui->textEditRead->append("客户端: "+array);
            }
        }
                );
    }
            );

}

TcpServer::~TcpServer()
{
    delete ui;
}

void TcpServer::on_pushButtonSend_clicked()
{
    QString temp = ui->textEditWrite->toPlainText();
    if(!temp.isEmpty())
    {
        tcpSocket->write(temp.toUtf8().data());
        ui->textEditWrite->clear();
        ui->textEditRead->append("服务器: "+temp);
    }
    else
    {
        cout<<"输入的字符串为空,请重新输入";
    }
}

void TcpServer::on_pushButtonClose_clicked()
{
    tcpSocket->write("exit");
    tcpSocket->disconnectFromHost();
    ui->pushButtonClose->setEnabled(false);
    ui->pushButtonSend->setEnabled(false);
    cout<<"服务器登出，已退出连接";
}
