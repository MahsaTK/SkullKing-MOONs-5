#include "changeinfo.h"
#include "ui_changeinfo.h"
#include <QMessageBox>

changeInfo::changeInfo(Player& person,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::changeInfo)
{
    player=person;
    ui->setupUi(this);
    this->setFixedSize(350,500);
    QWidget::setWindowTitle("Change Info");
    MainForm=new QFormLayout();
    UserEdit=new QLineEdit();
    PassEdit=new QLineEdit();
    PassLabel=new QLabel("Password: ");
    UserLabel=new QLabel("Username: ");
    PassEdit->setEchoMode(QLineEdit::Password);
    NameEdit=new QLineEdit();
    Last_nameEdit=new QLineEdit();
    Phone_numberEdit=new QLineEdit();
    EmailEdit=new QLineEdit();
    AddressEdit=new QLineEdit();
    explain=new QLabel("Please fill in all of the fields!");
    NameLabel=new QLabel("Name: ");
    Last_nameLabel=new QLabel("Last Name: ");
    Phone_numberLabel=new QLabel("Phone Number: ");
    EmailLabel=new QLabel("Email: ");
    AddressLabel=new QLabel("Address: ");
    MainForm->addRow(explain);
    MainForm->addRow(UserLabel,UserEdit);
    MainForm->addRow(PassLabel,PassEdit);
    MainForm->addRow(NameLabel,NameEdit);
    MainForm->addRow(Last_nameLabel,Last_nameEdit);
    MainForm->addRow(Phone_numberLabel,Phone_numberEdit);
    MainForm->addRow(EmailLabel,EmailEdit);
    MainForm->addRow(AddressLabel,AddressEdit);
    MainForm->addRow(ui->buttonBox);
    setLayout(MainForm);
}

changeInfo::~changeInfo()
{
    delete ui;
}

void changeInfo::on_buttonBox_accepted()
{
    if(UserEdit->text().isEmpty()||AddressEdit->text().isEmpty()||
        EmailEdit->text().isEmpty()||Phone_numberEdit->text().isEmpty()||
        Last_nameEdit->text().isEmpty()||PassEdit->text().isEmpty()||NameEdit->text().isEmpty()){
        QMessageBox::information(this,tr("Change Info"),tr("Please fill the form!"));
    }
    else{
        READ_FILE(players);
        for(auto& p : players){
            if(p.get_username()==player.get_username()){
                player.set_username(UserEdit->text().toStdString());
                player.set_address(AddressEdit->text().toStdString());
                player.set_email(EmailEdit->text().toStdString());
                player.set_last_name(Last_nameEdit->text().toStdString());
                player.set_phone_number(Phone_numberEdit->text().toStdString());
                player.set_password(PassEdit->text().toStdString());
                player.set_name(NameEdit->text().toStdString());
                p=player;
            }
        }
        WRITE_FILE(players);
        this->close();
    }
}
