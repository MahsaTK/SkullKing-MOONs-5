#include "mainwindow.h"
#include "MainMenu.h"
#include "ui_MainMenu.h"
#include "Client.h"
MainMenu::MainMenu(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainMenu)
{


    ui->setupUi(this);
    QWidget::setWindowTitle("Skull King");
    setWindowIcon(QIcon(":/img/img/نام بازی.png"));
    MainLayout=new QFormLayout();
    this->setFixedSize(350,500);
     MainLayout->addRow(ui->ServerBtn);
     MainLayout->addRow(ui->ClientBtn);

    QWidget *widget = new QWidget();
    widget->setLayout(MainLayout);
    this->setCentralWidget(widget);
}

MainMenu::MainMenu(Player c,QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainMenu)
{
    QWidget::setWindowTitle("Skull King");
    setWindowIcon(QIcon(":/img/img/نام بازی.png"));
    ui->setupUi(this);
    MainLayout=new QFormLayout();
    this->setFixedSize(350,500);
    MainLayout->addRow(ui->ServerBtn);
    MainLayout->addRow(ui->ClientBtn);
    QWidget *widget = new QWidget();
    widget->setLayout(MainLayout);
    this->setCentralWidget(widget);
    player=c;
}
MainMenu::~MainMenu()
{
    delete ui;
}
void MainMenu::Logout(){

}

void MainMenu::on_ClientBtn_clicked()
{

}

