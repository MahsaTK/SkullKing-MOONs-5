#include "twoplayerscreen.h"
#include "ui_twoplayerscreen.h"
#include <QListWidget>
#include <QListWidgetItem>
#include <QIcon>
#include <QListView>
#include <algorithm>
#include <random>
#include <QMessageBox>
void TwoPlayerScreen::chooseTheStater(){
    srand(time(nullptr)); // Seed the random number generator
    int randomNumber1 = rand() % 8 +1;
    int randomNumber2= rand() % 8 +1;
    while(randomNumber1==randomNumber2){
        randomNumber2= rand() % 8 +1;}// Generate a random number between1 8
    QListWidgetItem* myItem = new QListWidgetItem("Parrot "+QString::number(randomNumber1), ui->playGround);
    QListWidgetItem* myItem2 = new QListWidgetItem("Parrot "+QString::number(randomNumber2), ui->playGround);
    myItem2->setIcon(QIcon(":/img/img/طوطی.png"));
    myItem->setIcon(QIcon(":/img/img/طوطی.png"));
    server->parrotServer=randomNumber1;
    server->parrotClient=randomNumber2;
    ui->playGround->addItem(myItem);
    ui->playGround->addItem(myItem2);
    QString toWrite=QString::number(randomNumber1)+' '+QString::number(randomNumber2)+'\n';
    QByteArray myByteArray= toWrite.toUtf8(); // Convert the QString to a QByteArray
    server->AllCLients.back()->socket->write('$'+myByteArray);
    server->AllCLients.back()->socket->waitForBytesWritten(-1);
}

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
    ui->playGround->setLayoutMode(QListView::Batched);
    ui->playGround->setViewMode(QListView::IconMode);
    ui->playGround->setIconSize(QSize(300, 300));
     ui->playGround->setDragEnabled(false);
    ui->textBrowser->setText(QString::fromStdString(clientServer->playerClient.get_username()));
    ui->textBrowser_2->setText(server->AllCLients.back()->playerName);
    server->AllCLients.back()->socket->write(QByteArray::fromStdString("?"+clientServer->playerClient.get_username()+"\n"));
    server->AllCLients.back()->socket->waitForBytesWritten(-1);
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
    chooseTheStater();
    //server->write=1;
//    for(auto &x: clientServer->playerClient.get_cards()){
//        ShowCards(x);
//    }
//    server->writingData();

   //    clientServer->playerClient->decreaseCoin(50);
    server->writingData();

}



TwoPlayerScreen::TwoPlayerScreen(Client *cl,QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::TwoPlayerScreen)
{
    client=cl;
    client->ClientSocket->waitForReadyRead(-1);
    QWidget::setWindowTitle("Skull King");
    setWindowIcon(QIcon(":/img/img/نام بازی.png"));
    ui->setupUi(this);
    ui->textBrowser->setText(client->player_username_server);
    ui->textBrowser_2->setText(QString::fromStdString(client->playerClient.get_username()));
    ui->playGround->setLayoutMode(QListView::Batched);
    ui->playGround->setViewMode(QListView::IconMode);
    ui->playGround->setIconSize(QSize(300, 300));
    ui->playGround->setDragEnabled(false);
    ui->listWidget->setLayoutMode(QListView::Batched);
    ui->listWidget->setViewMode(QListView::IconMode);
    ui->listWidget->setIconSize(QSize(200, 200));
    client->ClientSocket->waitForReadyRead(-1);
    QListWidgetItem* myItem = new QListWidgetItem("Parrot "+QString::number(client->parrotServer), ui->playGround);
    QListWidgetItem* myItem2 = new QListWidgetItem("Parrot "+QString::number(client->parrotClient), ui->playGround);
    myItem2->setIcon(QIcon(":/img/img/طوطی.png"));
    myItem->setIcon(QIcon(":/img/img/طوطی.png"));
    ui->playGround->addItem(myItem);
    ui->playGround->addItem(myItem2);

//    for(auto &x: client->playerClient.get_cards()){
//        ShowCards(x);
//    }

    //        client->playerClient->decreaseCoin(50);
}
void TwoPlayerScreen::whoStart(){
    if(client->parrotServer>client->parrotClient){
     QMessageBox::information(nullptr, "Starter", "Starter is"+client->player_username_server);
     starter=1;
    }
    else{
        QMessageBox::information(nullptr, "Starter", "Starter is"+QString::fromStdString(client->playerClient.get_username()));
        starter=2;
    }
    ui->playGround->clear();
    while (client->playerClient.get_cards().size()<=0) {
        qDebug()<<"wait for cards";
    }    for(auto &x: client->playerClient.get_cards()){
       ShowCards(x);
    }
}
void TwoPlayerScreen::whoStartServer(){
    if(server->parrotServer>server->parrotClient){
     QMessageBox::information(nullptr, "Starter", "Starter is"+QString::fromStdString(clientServer->playerClient.get_username()));
     starter=1;
    }
    else{
        QMessageBox::information(nullptr, "Starter", "Starter is"+server->AllCLients.back()->playerName);
        starter=2;
    }
    ui->playGround->clear();
    server->write=1;
        for(auto &x: clientServer->playerClient.get_cards()){
            ShowCards(x);
        }


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
