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
    QByteArray byteArray=socket->readLine();
    QString temp=QString::fromUtf8(byteArray);
    temp.chop(1);  // Remove the last character

    qDebug()<<temp<<"\n"<<"read temp" ;
    // cast QByteArray to QString using constructor
    playerName=temp;
    while(true){
        socket->waitForReadyRead(-1);
        QByteArray byteArray=socket->readLine();
        QString temp=QString::fromUtf8(byteArray);
        if('r'==temp[0]){
            qDebug()<<"recived\n";
        }

    }
}
Channels::~Channels()
{
    Thread.join();
    delete ui;
}
