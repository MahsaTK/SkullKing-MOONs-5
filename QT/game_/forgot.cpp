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
    //    forgotMainForm=new QFormLayout();
    //    forgotUserEdit=new QLineEdit();
    //    forgotPassEdit=new QLineEdit();
    //    forgotUserLabel=new QLabel();
    //    forgotPassLabel=new QLabel();
    //    forgotUserLabel->setText("Phone Number: ");
    //    forgotPassLabel->setText("Password: ");

    //    ui->forgotPassEdit->setEchoMode(QLineEdit::Password);
    //    forgotMainForm->addRow(forgotUserLabel,forgotUserEdit);
    //    forgotMainForm->addRow(forgotPassLabel,forgotPassEdit);
    //    QWidget *widget = new QWidget();
    //    widget->setLayout(forgotMainForm);
    //    this->setCentralWidget(widget);
}

Forgot::~Forgot()
{
    delete ui;
}

void Forgot::on_buttonBox_accepted()
{
    READ_FILE(players);
    int found=0;
    for(auto user: players){
        if(user.get_number()==forgotUserEdit->text().toStdString()){
            user.set_password(forgotPassEdit->text().toStdString());
            found=1;
            QMessageBox::information(this,tr("Forgot Password"),tr("Password Updated successfully"));
            WRITE_FILE(players);
            break;
        }
    }
    if(found==0){
        QMessageBox::information(this,tr("Forgot Password"),tr("Username Can Not Be Found!"));
        forgotUserEdit->setText("");
        forgotPassEdit->setText("");
    }
    else{
        delete forgotPassEdit;
        delete forgotPassLabel;
        delete forgotUserEdit;
        delete forgotUserLabel;
        delete forgotMainForm;
        //        login();
    }
}

