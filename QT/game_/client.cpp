#include "Client.h"
#include "ui_client.h"

Client::Client(QString Ip,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Client)
{
    IP=Ip;
    ui->setupUi(this);
    //connect(connectPBN,SIGNAL(clicked()),this,SLOT(connectingToServer());
    connect(ClientSocket,SIGNAL(bytesWritten(qint64)),this,SLOT(writingData()));
    connect(ClientSocket,SIGNAL(readyRead()),this,SLOT(readingData()));
    connect(ClientSocket,SIGNAL(disconnect()),this,SLOT(disconnectedFromServer()));

}
void Client::connectingToServer(){
    ClientSocket=new QTcpSocket();
    ClientSocket->connectToHost(IP,1025);
    connect(ClientSocket,SIGNAL(connected()),this,SLOT(connectedToServer()));
}
void Client::readingData(){
    QByteArray data=ClientSocket->readAll();
    ///
}
void Client::writingData(){
    qDebug()<<"written successfully\n";
}
void Client::connectedToServer(){
    qDebug()<<"connected successfully\n";
    //ClientSocket->write()
}
void Client::disconnectedFromServer(){
        qDebug()<<"disconnected successfully\n";
}
Client::~Client()
{
    delete ui;
}
