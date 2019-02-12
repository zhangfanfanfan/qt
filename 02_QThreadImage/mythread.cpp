#include "mythread.h"
#include <QPainter>
#include <QPen>
#include <QBrush>
MyThread::MyThread(QObject *parent) : QObject(parent)
{

}
void MyThread::drawImage()
{
    QImage image(500,500,QImage::Format_ARGB32);
    QPainter p(&image);
    QPen pen;
    pen.setWidth(5);
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::red);
    p.setPen(pen);
    p.setBrush(brush);
    p.drawImage(500,500,image);
    QPoint a[] =
    {
        QPoint(qrand()%500,qrand()%500),
        QPoint(qrand()%500,qrand()%500),
        QPoint(qrand()%500,qrand()%500),
        QPoint(qrand()%500,qrand()%500),
        QPoint(qrand()%500,qrand()%500)
    };
    p.drawPolygon(a,5);
    emit updateImage(image);
}
