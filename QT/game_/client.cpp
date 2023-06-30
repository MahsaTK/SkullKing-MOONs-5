#include "Client.h"
#include "ui_client.h"
//Player
Client::Client(Player p,QHostAddress Ip,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Client)
{playerClient=p;
    IP=Ip;
    ui->setupUi(this);
    ClientSocket=new QTcpSocket();
    ClientSocket->connectToHost(IP,1025);
    connect(ClientSocket,SIGNAL(connected()),this,SLOT(connectedToServer()));
    connect(ClientSocket,SIGNAL(bytesWritten(qint64)),this,SLOT(writingData()));
    connect(ClientSocket,SIGNAL(readyRead()),this,SLOT(readingData()));
    connect(ClientSocket,SIGNAL(disconnect()),this,SLOT(disconnectedFromServer()));
    connect(ClientSocket,SIGNAL(connected()),this,SLOT(connectedToServer()));

}
void Client::readingData(){
    QByteArray byteArray=ClientSocket->readLine();
    char* Read= byteArray.data();  // cast QByteArray to char*
    if (Read[0]!='a'){
        if(strlen(Read)==4){
            if(Read[0]==1){
                Card * temp=new NumberedCard(Read[2],Treasure);
                playerClient.set_cards(temp);
            }
            else if(Read[0]==2){
                Card * temp=new NumberedCard(Read[2],Map);
                playerClient.set_cards(temp);

            }
            else if(Read[0]==3){
                Card * temp=new NumberedCard(Read[2],Parrot);
                playerClient.set_cards(temp);

            }
            else if(Read[0]==4){
                Card * temp=new NumberedCard(Read[2],Hokm);
                playerClient.set_cards(temp);

            }
        }
        else{
            if(Read[0]==5){
                Card * temp=new CharacterCard(King);
                playerClient.set_cards(temp);

            }
            else if(Read[0]==6){
                Card * temp=new CharacterCard(Queen);
                playerClient.set_cards(temp);

            }
            else if(Read[0]==7){
                Card * temp=new CharacterCard(Pirot);
                playerClient.set_cards(temp);

            }
        }

    }
}
void Client::writingData(){
    qDebug()<<"written successfully\n";
}
void Client::connectedToServer(){
    qDebug()<<"connected successfully\n";
    QByteArray byteArray(playerClient.get_username().c_str(), static_cast<int>(playerClient.get_username().length()));
    qDebug()<< byteArray;
    ClientSocket->write(byteArray);
}
void Client::disconnectedFromServer(){
    qDebug()<<"disconnected successfully\n";
}
Client::~Client()
{
    delete ui;
}
