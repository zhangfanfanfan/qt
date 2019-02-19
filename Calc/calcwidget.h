#ifndef CALCWIDGET_H
#define CALCWIDGET_H

#include <QWidget>

namespace Ui {
class CalcWidget;
}

class CalcWidget : public QWidget
{
    Q_OBJECT

public:
    explicit CalcWidget(QWidget *parent = 0);
    ~CalcWidget();
    void Count();

private:
    Ui::CalcWidget *ui;
    QString resultStr;
    char yunsuan;
    double leftNum;
    double rightNum;
    bool isRight;
    bool isDouble;
    bool isBaiFenHao;
};

#endif // CALCWIDGET_H
