#include "Client.h"
#include "ui_client.h"
//Player
Client::Client(Player p,QHostAddress Ip,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Client)
{playerClient=p;
    round=1;
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

    {
        QByteArray byteArray=ClientSocket->readLine();
        char* Read= byteArray.data();  // cast QByteArray to char*
        int size =strlen(Read);for(int i=0;i<size;){
            if (Read[i]!='a'){
                if(Read[i]!='M'){
                    if(Read[i+1]!='M'){
                        if(Read[i]==1){
                            Card * temp=new NumberedCard(Read[i+2],Treasure);
                            playerClient.set_cards(temp);
                            i+=4;

                        }
                        else if(Read[i]==2){
                            Card * temp=new NumberedCard(Read[i+2],Map);
                            playerClient.set_cards(temp);
                            i+=4;

                        }
                        else if(Read[i]==3){
                            Card * temp=new NumberedCard(Read[i+2],Parrot);
                            playerClient.set_cards(temp);
                            i+=4;

                        }
                        else if(Read[i]==4){
                            Card * temp=new NumberedCard(Read[i+2],Hokm);
                            playerClient.set_cards(temp);
                            i+=4;
                        }
                    }
                    else{
                        if(Read[i]==5){
                            Card * temp=new CharacterCard(King);
                            playerClient.set_cards(temp);
                            i+=2;

                        }
                        else if(Read[i]==6){
                            Card * temp=new CharacterCard(Queen);
                            playerClient.set_cards(temp);
                            i+=2;

                        }
                        else if(Read[i]==7){
                            Card * temp=new CharacterCard(Pirot);
                            playerClient.set_cards(temp);
                            i+=2;

                        }
                    }}
            }}
    }
    ClientSocket->write("recived");
}
void Client::writingData(){
    qDebug()<<"written successfully\n";
}
void Client::connectedToServer(){
    qDebug()<<"connected successfully\n";
    string temp=playerClient.get_username();
    temp+='\n';
    QByteArray byteArray(temp.c_str(), static_cast<int>(temp.length()));
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
