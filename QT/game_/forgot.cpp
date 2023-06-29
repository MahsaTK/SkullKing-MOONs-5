#include "forgot.h"
#include "ui_forgot.h"
#include <QMessageBox>

Forgot::Forgot(QWidget *parent) :
    QDialog(parent),
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

void Forgot::on_buttonBox_accepted()
{
    READ_FILE(players);
    int found=0;
    for(auto &user: players){
        if(user.get_number()==ui->forgotUserEdit->text().toStdString()){
            user.set_password(ui->forgotPassEdit->text().toStdString());
            found=1;
            QMessageBox::information(this,tr("Forgot Password"),tr("Password Updated successfully"));
            WRITE_FILE(players);
            break;
        }
    }
    if(found==0){
        QMessageBox::information(this,tr("Forgot Password"),tr("Username Can Not Be Found!"));
       ui->forgotUserEdit->setText("");
        ui->forgotPassEdit->setText("");
    }
    else{
        delete ui->forgotPassEdit;
        delete ui->forgotPassLabel;
        delete ui->forgotUserEdit;
        delete ui->forgotUserLabel;
        //        login();
    }
}

