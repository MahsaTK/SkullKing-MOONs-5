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
void Server::newConnectionsSlot(){
  Channels * newClientChannel=new Channels(myServer->nextPendingConnection(),0);
         AllCLients.push_back(newClientChannel);
}
Server::~Server()
{
    delete ui;
}
