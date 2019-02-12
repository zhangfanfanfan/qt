#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "mythread.h"
#include <QImage>
#include "mythread.h"
#include <QThread>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
    void receImage(QImage);
protected:
    void paintEvent(QPaintEvent *event);
private:
    Ui::Widget *ui;
    QImage image;
    QThread *thread;
    MyThread *myT;
};

#endif // WIDGET_H
