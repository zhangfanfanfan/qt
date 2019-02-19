#include "calcwidget.h"
#include "ui_calcwidget.h"
#include <QDebug>
#define cout qDebug() << "[" << __FILE__ << ":" << __LINE__ << "]"
CalcWidget::CalcWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CalcWidget)
{
    ui->setupUi(this);
    leftNum = 0;
    rightNum = 0;
    isRight = false;
    isDouble = false;
    isBaiFenHao = false;

    connect(ui->pushButtonZero,&QPushButton::clicked,this,&CalcWidget::Count);
    connect(ui->pushButtonOne,&QPushButton::clicked,this,&CalcWidget::Count);
    connect(ui->pushButtonTwo,&QPushButton::clicked,this,&CalcWidget::Count);
    connect(ui->pushButtonThree,&QPushButton::clicked,this,&CalcWidget::Count);
    connect(ui->pushButtonFour,&QPushButton::clicked,this,&CalcWidget::Count);
    connect(ui->pushButtonFive,&QPushButton::clicked,this,&CalcWidget::Count);
    connect(ui->pushButtonSix,&QPushButton::clicked,this,&CalcWidget::Count);
    connect(ui->pushButtonSeven,&QPushButton::clicked,this,&CalcWidget::Count);
    connect(ui->pushButtonEight,&QPushButton::clicked,this,&CalcWidget::Count);
    connect(ui->pushButtonNine,&QPushButton::clicked,this,&CalcWidget::Count);
    connect(ui->pushButtonPoint,&QPushButton::clicked,this,&CalcWidget::Count);
    connect(ui->pushButtonDengyu,&QPushButton::clicked,this,&CalcWidget::Count);
    connect(ui->pushButtonLeftkuohao,&QPushButton::clicked,this,&CalcWidget::Count);
    connect(ui->pushButtonRightkuohao,&QPushButton::clicked,this,&CalcWidget::Count);
    connect(ui->pushButtonQuyu,&QPushButton::clicked,this,&CalcWidget::Count);
    connect(ui->pushButtonClear,&QPushButton::clicked,this,&CalcWidget::Count);
    connect(ui->pushButtonChuhao,&QPushButton::clicked,this,&CalcWidget::Count);
    connect(ui->pushButtonChenghao,&QPushButton::clicked,this,&CalcWidget::Count);
    connect(ui->pushButtonJianhao,&QPushButton::clicked,this,&CalcWidget::Count);
    connect(ui->pushButtonJiahao,&QPushButton::clicked,this,&CalcWidget::Count);

}

CalcWidget::~CalcWidget()
{
    delete ui;
}

void CalcWidget::Count()
{
    QObject *mySender = sender();
    QPushButton *p = (QPushButton *)mySender;
    if(p==NULL)
    {
        cout<<"按钮发送为空";
        return;
    }
    QString str = p->text();
    resultStr += str;
    ui->textEdit->setText(resultStr);
    if(str=="+"||str=="-"||str=="*"||str=="/"||str=="%")
    {
        isRight=true;
        yunsuan = *(str.toUtf8().data());
        if(str=="%")
        {
           isBaiFenHao = true;
        }
    }
    if(str==".")
    {
        isDouble = true;
    }
    if(str>="0"&&str<="9"&&isRight==false&&isDouble==false)
    {
        leftNum = leftNum*10 + str.toInt();
    }
    if(str>='0'&&str<='9'&&isRight==true&&isDouble==false)
    {
        rightNum = rightNum*10 + str.toInt();
    }

    if(str=="=")
    {
        if(isDouble==false)
        {
            int result = 0;
            switch(yunsuan)
            {
             case '+':
                result = leftNum+rightNum;
                break;
             case '-':
                result = leftNum-rightNum;
                break;
             case  '*':
                result = leftNum*rightNum;
                break;
             case '/':
                result = leftNum/rightNum;
                break;
             case '%':
                int a = (int)leftNum;
                int b = (int)rightNum;
                result = a%b;
            }
        QString temp = QString("运算结果为:%1").arg(result);
        ui->textEdit->append(temp);
      }
      else
        {
            QString temp = QString("运算结果为:%1").arg(leftNum/100);
        }
    }
    if(str=='C')
    {
        ui->textEdit->clear();
        leftNum = 0;
        rightNum = 0;
        resultStr.clear();
        isRight = false;
        isDouble = false;
    }

}
