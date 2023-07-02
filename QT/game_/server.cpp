#include "server.h"
#include "channels.h"
#include "ui_server.h"
#include <QDebug>
Server::Server(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Server)
{
    ui->setupUi(this);
    myServer=new QTcpServer();
    myServer->listen(QHostAddress::Any, 1025);
    if(!myServer->isListening())
        qDebug()<<"error: not listening";
    else{
        qDebug()<<"listening";
        connect(myServer,SIGNAL(newConnection()),this,SLOT(newConnectionsSlot()));
    }

}
void Server::readingData(){

    QByteArray byteArray=AllCLients.back()->socket->readLine();
    char* Read= byteArray.data();
    QString temp=QString::fromUtf8(byteArray);
   // cast QByteArray to char*
    if(Read[0]=='#'){
        temp.chop(1);
        temp.remove(0,1);// Remove the last character
        qDebug()<<temp<<"\n"<<"read temp" ;
        // cast QByteArray to QString using constructor
        AllCLients.back()->playerName=temp;
    }
    if(Read[0]=='p'){
        current.addPredict(2,Read[1]-'0',Read[2]-'0');
        return;
    }
    if(Read[0]=='!'){
        type=Read[1]-'0';
        if(type<5){
            number=Read[3]-'0';
        }
    }
}

void Server::newConnectionsSlot()
{
    Channels * newClientChannel=new Channels(myServer->nextPendingConnection(),0);
    AllCLients.push_back(newClientChannel);
    if(AllCLients.size()>1)
    connect(AllCLients.back()->socket,SIGNAL(readyRead()),this,SLOT(readingData()));


}
Server::~Server()
{
    delete ui;
}
void Server::writingData(){
   // if(write==1){
        distributeCards();
    //}
}
void Server::distributeCards(){
    string toWrite;
    for(auto x: temp.get_cards()){
        int type=x->getType();
        if(type>4){
            toWrite.push_back(static_cast<char>(type));
            toWrite.push_back('M');
            qDebug() <<"write a card";

       }
        else{
           int num=dynamic_cast<NumberedCard&>(*x).GetNumber();
           toWrite.push_back(static_cast<char>(type));
           toWrite.push_back(' ');
           toWrite.push_back(static_cast<char>(num));
           toWrite.push_back('M');
           qDebug() << "write a card";


        }
    }
    toWrite.push_back('\n');
    QByteArray byteArray(toWrite.c_str(), static_cast<int>(toWrite.length()));  // cast std::string to QByteArray using constructor
    AllCLients.back()->socket->write(byteArray);;
    AllCLients.back()->socket->waitForBytesWritten(-1);
    qDebug()<<"All Cards send"<<"\n";
}
