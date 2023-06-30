#include "channels.h"
#include "ui_channels.h"

Channels::Channels(QTcpSocket * Socket,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Channels)
{
    socket=Socket;
    ui->setupUi(this);
    Thread=std::thread(&Channels::communicate,this);
}
void Channels::communicate(){
    socket->waitForReadyRead(-1);
    QByteArray byteArray=socket->readAll();
    QString temp=QString::fromUtf8(byteArray);
    qDebug()<<temp<<"\n"<<"read temp" ;
    // cast QByteArray to QString using constructor
    playerName=temp;
    while(true){

    }
}
Channels::~Channels()
{
    Thread.join();
    delete ui;
}
