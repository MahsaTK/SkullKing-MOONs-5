#include "Client.h"
#include "ui_client.h"
//Player
Client::Client(Player p,QHostAddress Ip,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Client)
{
    playerClient=p;
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
        char* Read= byteArray.data();
       // cast QByteArray to char*
        if(Read[0]=='p'){
            playerClient.current_game.addPredict(1,Read[1]-'0',Read[2]-'0');
            return;
        }
        if(Read[0]=='$'){
            parrotServer=Read[1]-'0';
            parrotClient=Read[3]-'0';
//            ClientSocket->write("Done");
//            ClientSocket->waitForBytesWritten(-1);
            return;
        }
        if(Read[0]=='?'){
            player_username_server=QString::fromUtf8(byteArray);
            player_username_server.chop(1);
            player_username_server.remove(0, 1); // Delete the first character
//            ClientSocket->write("Done");
//            ClientSocket->waitForBytesWritten(-1);
            return;
        }
        int size =strlen(Read);
        if (Read[0]!='!'){
        for(int i=0;i<size-1;){
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
        else if(Read[0]=='!'){
            type=Read[1]-'0';
            if(type<5){
                number=Read[3]-'0';
            }
        }
    }
//    ClientSocket->write("Done");
//    ClientSocket->waitForBytesWritten(-1);

}
void Client::writingData(){
    qDebug()<<"written successfully\n";
}
void Client::connectedToServer(){
    qDebug()<<"connected successfully\n";
    string temp="#"+playerClient.get_username();
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
