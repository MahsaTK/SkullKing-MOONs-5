#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QPixmap>
#include <QLabel>
#include <QTextEdit>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QMessageBox>
#include <QFormLayout>
#include <functions.h>

vector<Player> players;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QWidget::setWindowTitle("Skull King");
    setWindowIcon(QIcon(":/img/img/نام بازی.png"));
    ui->forgotPassword->hide();
    ui->signUpOk->hide();
    ui->loginOk->hide();
    // QPixmap bkgnd(":/img/img/background.png");
    //   bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    // QPalette palette;
    //palette.setBrush(QPalette::Window, bkgnd);
    //this->setPalette(palette);
    //this->setStyleSheet("background-image: url(:/img/img/flag_0001a.jpg);"
    //"background-repeat: no-repeat;"
    // );
    // setCentralWidget(ui->pushButton);
    //setCentralWidget(ui->pushButton_2);


    this->setFixedSize(350,500);

}

MainWindow::~MainWindow()
{

}

void MainWindow::on_pushButton_clicked()
{
    login();

}
void MainWindow::start_game(Player player){
    MainMenu *game=new MainMenu(player);
    game->show();
    this->close();
}
void MainWindow::on_pushButton_2_clicked()
{
    signUp();
}

void MainWindow ::login(){
    if(ui->pushButton->isVisible()==true){
        ui->pushButton->hide();
        ui->pushButton_2->hide();}
    if(ui->signUpOk->isVisible()==true){
        ui->signUpOk->hide();
    }
    QWidget::setWindowTitle("Login");
    loginMainForm=new QFormLayout();
    loginUserEdit=new QLineEdit();
    loginPassEdit=new QLineEdit();
    loginUserLabel=new QLabel();
    loginPassLabel=new QLabel();
    loginUserLabel->setText("Username: ");
    loginPassLabel->setText("Password: ");
    loginPassEdit->setEchoMode(QLineEdit::Password);
    loginMainForm->addRow(loginUserLabel,loginUserEdit);
    loginMainForm->addRow(loginPassLabel,loginPassEdit);
    ui->loginOk->show();
    ui->forgotPassword->show();
    loginMainForm->addRow(ui->forgotPassword,ui->loginOk);
    QWidget *widget = new QWidget();
    widget->setLayout(loginMainForm);
    this->setCentralWidget(widget);


}

void MainWindow ::signUp(){
    if(ui->pushButton->isVisible()==true){
        ui->pushButton->hide();
        ui->pushButton_2->hide();}
    if(ui->loginOk->isVisible()==true){
        ui->loginOk->hide();
        ui->forgotPassword->hide();}
    QWidget::setWindowTitle("Sign Up");
    signUpMainForm=new QFormLayout();
    signUpUserEdit=new QLineEdit();
    signUpPassEdit=new QLineEdit();
    signUpPassLabel=new QLabel("Password: ");
    signUpUserLabel=new QLabel("Username: ");
    signUpPassEdit->setEchoMode(QLineEdit::Password);
    signUpNameEdit=new QLineEdit();
    signUpLast_nameEdit=new QLineEdit();
    signUpPhone_numberEdit=new QLineEdit();
    signUpEmailEdit=new QLineEdit();
    signUpAddressEdit=new QLineEdit();
    signUpNameLabel=new QLabel("Name: ");
    signUpLast_nameLabel=new QLabel("Last Name: ");
    signUpPhone_numberLabel=new QLabel("Phone Number: ");
    signUpEmailLabel=new QLabel("Email: ");
    signUpAddressLabel=new QLabel("Address: ");
    signUpMainForm->addRow(signUpUserLabel,signUpUserEdit);
    signUpMainForm->addRow(signUpPassLabel,signUpPassEdit);
    signUpMainForm->addRow(signUpNameLabel,signUpNameEdit);
    signUpMainForm->addRow(signUpLast_nameLabel,signUpLast_nameEdit);
    signUpMainForm->addRow(signUpPhone_numberLabel,signUpPhone_numberEdit);
    signUpMainForm->addRow(signUpEmailLabel,signUpEmailEdit);
    signUpMainForm->addRow(signUpAddressLabel,signUpAddressEdit);
    ui->signUpOk->show();
    signUpMainForm->addRow(ui->signUpOk);
    QWidget *widget = new QWidget();
    widget->setLayout(signUpMainForm);
    this->setCentralWidget(widget);

}

void MainWindow::on_signUpOk_clicked()
{
    if(signUpUserEdit->text().isEmpty()||signUpAddressEdit->text().isEmpty()||
            signUpEmailEdit->text().isEmpty()||signUpPhone_numberEdit->text().isEmpty()||
            signUpLast_nameEdit->text().isEmpty()||signUpPassEdit->text().isEmpty()||signUpNameEdit->text().isEmpty()){
        QMessageBox::information(this,tr("Sign up"),tr("Please fill the form!"));
    }
    else{
        Player newPlayer;
        newPlayer.set_username(signUpUserEdit->text().toStdString());
        newPlayer.set_address(signUpAddressEdit->text().toStdString());
        newPlayer.set_email(signUpEmailEdit->text().toStdString());
        newPlayer.set_last_name(signUpLast_nameEdit->text().toStdString());
        newPlayer.set_phone_number(signUpPhone_numberEdit->text().toStdString());
        newPlayer.set_password(signUpPassEdit->text().toStdString());
        newPlayer.set_name(signUpNameEdit->text().toStdString());
        players.push_back(newPlayer);
        start_game(newPlayer);
        WRITE_FILE(players);
        DELSignup();
        this->close();
    }
}

void MainWindow:: DELSignup(){

    delete signUpUserEdit;
    delete signUpPassEdit;
    delete signUpUserLabel;
    delete signUpPassLabel;
    delete signUpMainForm;
    delete signUpNameEdit;
    delete signUpLast_nameEdit;
    delete signUpPhone_numberEdit;
    delete signUpEmailEdit;
    delete signUpAddressEdit;
    delete signUpNameLabel;
    delete signUpLast_nameLabel;
    delete signUpPhone_numberLabel;
    delete signUpEmailLabel;
    delete signUpAddressLabel;
}
void MainWindow:: DELLogin(){
    delete loginUserEdit;
    delete loginPassEdit;
    delete loginUserLabel;
    delete loginPassLabel;
    delete loginMainForm;

}


void MainWindow::on_loginOk_clicked()
{
    READ_FILE(players);
    int found=0;
    for(auto user: players){
        if(user.get_username()==loginUserEdit->text().toStdString()&&user.get_pass()==loginPassEdit->text().toStdString()){
            start_game(user);
            this->close();
            found=1;
        }
    }
    if(found==0){
        QMessageBox::information(this,tr("Login"),tr("Username or Password is not correct"));
        loginUserEdit->setText("");
        loginPassEdit->setText("");
    }
}



