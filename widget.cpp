#include "widget.h"
#include "ui_widget.h"
#include <QMessageBox>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    ui->pbCoffee->setEnabled(false);
    ui->pbTea->setEnabled(false);
    ui->pbMilk->setEnabled(false);
    ui->pbRest->setEnabled(false);
}

Widget::~Widget()
{
    delete ui;
}

// int money = 0;

void  Widget::changeMoney(int diff)
{
    money += diff;
    ui ->lcdNumber->display(money);
    drinkEnable(money);
}

void  Widget::drinkEnable(int diff)
{
    if(diff >= 10)
        ui->pbRest->setEnabled(true);
    if(diff >= 100)
        ui->pbCoffee->setEnabled(true);
    if(diff >= 150)
        ui->pbTea->setEnabled(true);
    if(diff >= 200)
        ui->pbMilk->setEnabled(true);
}


void Widget::on_pb10_clicked()
{
    changeMoney(10);
}



void Widget::on_pb50_clicked()
{
    changeMoney(50);
}

void Widget::on_pb100_clicked()
{
    changeMoney(100);
}

void Widget::on_pb500_clicked()
{
    changeMoney(500);
}

void Widget::on_pbCoffee_clicked()
{
    changeMoney(-100);
    //money -= 100;
    // ui ->lcdNumber->display(money);
}


void Widget::on_pbTea_clicked()
{
    changeMoney(-150);
}

void Widget::on_pbMilk_clicked()
{
    changeMoney(-200);
}

void Widget::on_pbRest_clicked()
{
    // money back
    int coin500 = 0;
    int coin100 = 0;
    int coin50 = 0;
    int coin10 = 0;

    coin500 = money/500;
    money = money % 500;

    coin100 = money/100;
    money = money % 100;

    coin50 = money/50;
    money = money % 50;

    coin10 = money/10;
    money = money % 10;


    QMessageBox m;
    m.information(nullptr, "Return Money",
                  QString("500 : %1, 100 : %2, 50 : %3, 10 : %4")
                  .arg(coin500).arg(coin100).arg(coin50).arg(coin10));
    money = 0;
    ui ->lcdNumber->display(money);
}
