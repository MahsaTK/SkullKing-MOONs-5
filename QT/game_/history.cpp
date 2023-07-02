#include "history.h"
#include "ui_history.h"
#include <QTableWidget>
#include <QString>

History::History(GameInfo g2,QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::History)
{
    ui->setupUi(this);
    setWindowTitle("History");
    ui->charTable->setItem(0, 0, new QTableWidgetItem("Item 1"));
    ui->charTable->setItem(0, 1, new QTableWidgetItem("Value 1"));
    ui->charTable->setItem(0, 2, new QTableWidgetItem("Item 2"));
    ui->charTable->setItem(1, 0, new QTableWidgetItem("Value 2"));
    ui->charTable->setItem(1, 1, new QTableWidgetItem("Item 3"));
    ui->charTable->setItem(1, 2, new QTableWidgetItem(QString::number(g2.get_predict1()[0])));
    for(int j=0;j<7;j++){
        ui->mainTable->setItem(0, j, new QTableWidgetItem(QString::number(g2.get_predict1()[j])));
        ui->mainTable->setItem(1, j, new QTableWidgetItem(QString::number(g2.get_predict2()[j])));
        ui->mainTable->setItem(2, j, new QTableWidgetItem(QString::number(g2.get_result1()[j])));
        ui->mainTable->setItem(3, j, new QTableWidgetItem(QString::number(g2.get_result2()[j])));
    }
    for(int j=0;j<3;j++){
        ui->charTable->setItem(0, j, new QTableWidgetItem(QString::number(g2.get_character1()[j])));
        ui->charTable->setItem(1, j, new QTableWidgetItem(QString::number(g2.get_character2()[j])));
    }
}

History::~History()
{
    delete ui;
}
