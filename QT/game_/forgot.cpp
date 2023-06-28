#include "forgot.h"
#include "ui_forgot.h"

Forgot::Forgot(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Forgot)
{
    ui->setupUi(this);
    this->setFixedSize(350,500);
    QWidget::setWindowTitle("Forgot Password");

}

Forgot::~Forgot()
{
    delete ui;
}
