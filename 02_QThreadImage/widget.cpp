#include "widget.h"
#include "ui_widget.h"
#include <QPaintEvent>
#include <QPainter>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    thread = new QThread(this);
    myT = new MyThread;
    myT->moveToThread(thread);
    thread->start();
    connect(ui->pushButton,&QPushButton::pressed,myT,&MyThread::drawImage);
    connect(myT,&MyThread::updateImage,this,&Widget::receImage);
}

Widget::~Widget()
{
    delete ui;
}
void Widget::receImage(QImage temp)
{
    image = temp;
    update();
}
void Widget::paintEvent(QPaintEvent *event)
{
    QPainter p(this);
    p.drawImage(50,50,image);
}
