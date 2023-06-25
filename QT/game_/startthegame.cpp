#include "mainwindow.h"
#include "ui_startthegame.h"

StartTheGame::StartTheGame(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::StartTheGame)
{
    QWidget::setWindowTitle("Skull King");
    setWindowIcon(QIcon(":/img/img/نام بازی.png"));
    ui->setupUi(this);
}

StartTheGame::StartTheGame(Player c,QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::StartTheGame)
{
    QWidget::setWindowTitle("Skull King");
    setWindowIcon(QIcon(":/img/img/نام بازی.png"));
    ui->setupUi(this);
    player=c;
}

StartTheGame::~StartTheGame()
{
    delete ui;
}
void StartTheGame::Logout(){

}
