#include "tcpclient.h"
#include "ui_tcpclient.h"
#include <QHostAddress>
#include <QDebug>
#define cout qDebug() << "[" << __FILE__ << ":" << __LINE__ << "]"

TcpClient::TcpClient(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TcpClient)
{
    ui->setupUi(this);
    tcpSocket = new QTcpSocket(this);
    this->setWindowTitle("客户端");
    ui->pushButtonClose->setEnabled(false);
    ui->pushButtonSend->setEnabled(false);
    connect(tcpSocket,&QTcpSocket::connected,
            [=]()
    {
        ui->textEditRead->setText("成功连接服务器");
    }
            );
    connect(tcpSocket,&QTcpSocket::readyRead,
            [=]()
    {
       QByteArray array = tcpSocket->readAll();
       if(array=="exit")
       {
          on_pushButtonClose_clicked();
          cout<<"服务器请求结束会话";
       }
       else
       {
          ui->textEditRead->append("服务器: "+array);
       }
    }
            );
}

TcpClient::~TcpClient()
{
    delete ui;
}

void TcpClient::on_pushButtonConnect_clicked()
{
    QString Ip = ui->lineEditIp->text();
    qint16 port = ui->lineEditPort->text().toInt();
    tcpSocket->connectToHost(QHostAddress(Ip),port);
    ui->pushButtonClose->setEnabled(true);
    ui->pushButtonSend->setEnabled(true);
    ui->pushButtonConnect->setEnabled(false);
}

void TcpClient::on_pushButtonSend_clicked()
{
    QString str = ui->textEditWrite->toPlainText();
    tcpSocket->write(str.toUtf8().data());
    ui->textEditWrite->clear();
    ui->textEditRead->append("客户端: "+str);
}

void TcpClient::on_pushButtonClose_clicked()
{
    tcpSocket->write("exit");
    tcpSocket->disconnectFromHost();
    ui->pushButtonClose->setEnabled(false);
    ui->pushButtonSend->setEnabled(false);
    ui->pushButtonConnect->setEnabled(true);


}
