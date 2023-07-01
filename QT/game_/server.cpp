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
void Server::newConnectionsSlot()
{
    Channels * newClientChannel=new Channels(myServer->nextPendingConnection(),0);
    AllCLients.push_back(newClientChannel);

}
Server::~Server()
{
    delete ui;
}
void Server::writingData(){
    if(write==1){
        distributeCards();
    }
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
    QByteArray byteArray(toWrite.c_str(), static_cast<int>(toWrite.length()));  // cast std::string to QByteArray using constructor
    toWrite.push_back('\n');
     AllCLients.back()->socket->write(byteArray);;
}
