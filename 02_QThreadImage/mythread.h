#ifndef MYTHREAD_H
#define MYTHREAD_H

#include <QObject>
#include <QImage>
class MyThread : public QObject
{
    Q_OBJECT
public:
    explicit MyThread(QObject *parent = nullptr);
    void drawImage();
signals:
    void updateImage(QImage);
public slots:
};

#endif // MYTHREAD_H
