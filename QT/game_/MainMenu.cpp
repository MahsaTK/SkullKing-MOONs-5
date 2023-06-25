#include "mainwindow.h"
#include "ui_MainMenu.h"

MainMenu::MainMenu(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainMenu)
{
    QWidget::setWindowTitle("Skull King");
    setWindowIcon(QIcon(":/img/img/نام بازی.png"));
    ui->setupUi(this);
}

MainMenu::MainMenu(Player c,QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainMenu)
{
    QWidget::setWindowTitle("Skull King");
    setWindowIcon(QIcon(":/img/img/نام بازی.png"));
    ui->setupUi(this);
    player=c;
}

MainMenu::~MainMenu()
{
    delete ui;
}
void MainMenu::Logout(){

}
