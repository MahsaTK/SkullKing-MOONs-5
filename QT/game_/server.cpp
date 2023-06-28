#include "server.h"
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
        connect(myServer,SIGNAL(newConnection),this,SLOT(newConnectionSlot()));
    }
}
void Server::newConnectionsSlot(){
    myServer->new
}
Server::~Server()
{
    delete ui;
}
