#include "twoplayerscreen.h"
#include "ui_twoplayerscreen.h"
#include <QListWidget>
#include <QListWidgetItem>
#include <QIcon>
#include <QListView>
#include <algorithm>
#include <random>

void TwoPlayerScreen::ShareCards(Player &p1,Player &p2,int round,Card*mainCards2PLayers[]){
    p1.set_cards(round,1,mainCards2PLayers);
    p2.set_cards(round,2,mainCards2PLayers);
}

TwoPlayerScreen::TwoPlayerScreen(Server *ser, Client *cl,QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::TwoPlayerScreen)
{
    server=ser;
    clientServer=cl;
    QWidget::setWindowTitle("Skull King");
    setWindowIcon(QIcon(":/img/img/نام بازی.png"));
    ui->setupUi(this);
    ui->listWidget->setLayoutMode(QListView::Batched);
    ui->listWidget->setViewMode(QListView::IconMode);
    ui->listWidget->setIconSize(QSize(200, 200));
    ui->textBrowser->setText(server->AllCLients.front()->playerName);
    ui->textBrowser_2->setText(server->AllCLients.back()->playerName);

    for(int i=0;i!=8;i++){
        mainCards2PLayers[i]=new NumberedCard(i+1,Treasure);
        mainCards2PLayers[i+8]=new NumberedCard(i+1,Map);
        mainCards2PLayers[i+16]=new NumberedCard(i+1,Parrot);
        mainCards2PLayers[i+24]=new NumberedCard(i+1,Hokm);
    }
    for(int i=32;i!=35;i++){
        mainCards2PLayers[i]=new CharacterCard(King);
        mainCards2PLayers[i+3]=new CharacterCard(Queen);
        mainCards2PLayers[i+6]=new CharacterCard(Pirot);
    }
    mainCards2PLayers[41]=new CharacterCard(Pirot);
    int size = sizeof(mainCards2PLayers) / sizeof(mainCards2PLayers[0]);
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle( mainCards2PLayers, mainCards2PLayers+ size, g);
    ShareCards(clientServer->playerClient,server->temp,1,mainCards2PLayers);
    server->write=1;
    server->writingData();
    for(auto &x: clientServer->playerClient.get_cards()){
        ShowCards(x);
    }

//    clientServer->playerClient->decreaseCoin(50);
}



TwoPlayerScreen::TwoPlayerScreen(Client *cl,QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::TwoPlayerScreen)
{
    client=cl;
    QWidget::setWindowTitle("Skull King");
    setWindowIcon(QIcon(":/img/img/نام بازی.png"));
    ui->setupUi(this);
    ui->listWidget->setLayoutMode(QListView::Batched);
    ui->listWidget->setViewMode(QListView::IconMode);
    ui->listWidget->setIconSize(QSize(200, 200));
       client->ClientSocket->waitForReadyRead(-1);
    for(auto &x: client->playerClient.get_cards()){
        ShowCards(x);
    }

//        client->playerClient->decreaseCoin(50);
}

void TwoPlayerScreen::ShowCards(Card *card){
    if(card->getType()==1){
        NumberedCard *cardptr = dynamic_cast<NumberedCard *>(card);
        int Number =cardptr->GetNumber();
        QString number=QString::number(Number);
        QListWidgetItem* item = new QListWidgetItem("Treasure "+number, ui->listWidget);
        item->setIcon(QIcon(":/img/img/گنج.png"));
        ui->listWidget->addItem(item);

    }
    else if(card->getType()==2){
        NumberedCard *cardptr = dynamic_cast<NumberedCard *>(card);
        int Number =cardptr->GetNumber();
        QString number=QString::number(Number);
        QListWidgetItem* item = new QListWidgetItem("Map "+number, ui->listWidget);
        item->setIcon(QIcon(":/img/img/نقشه .png"));
        ui->listWidget->addItem(item);
    }
    else if(card->getType()==3){
        NumberedCard *cardptr = dynamic_cast<NumberedCard *>(card);
        int Number =cardptr->GetNumber();
        QString number=QString::number(Number);
        QListWidgetItem* item = new QListWidgetItem("Parrot "+number, ui->listWidget);
        item->setIcon(QIcon(":/img/img/طوطی.png"));
        ui->listWidget->addItem(item);
    }
    else if(card->getType()==4){
        NumberedCard *cardptr = dynamic_cast<NumberedCard *>(card);
        int Number =cardptr->GetNumber();
        QString number=QString::number(Number);
        QListWidgetItem* item = new QListWidgetItem("Pirate flag "+number, ui->listWidget);
        item->setIcon(QIcon(":/img/img/پرچم دزد دریایی.png"));
        ui->listWidget->addItem(item);
    }
    else if(card->getType()==5){

        QListWidgetItem* item = new QListWidgetItem("King ", ui->listWidget);
        item->setIcon(QIcon(":/img/img/پادشاه جمجمه.png"));
        ui->listWidget->addItem(item);
    }
    else if(card->getType()==6){

        QListWidgetItem* item = new QListWidgetItem("Queen ", ui->listWidget);
        item->setIcon(QIcon(":/img/img/ملکه.png"));
        ui->listWidget->addItem(item);
    }
    else if(card->getType()==7){

        QListWidgetItem* item = new QListWidgetItem("Pirot ", ui->listWidget);
        item->setIcon(QIcon(":/img/img/دزد دریایی.png"));
        ui->listWidget->addItem(item);
    }
}

TwoPlayerScreen::~TwoPlayerScreen()
{
    delete ui;
}
