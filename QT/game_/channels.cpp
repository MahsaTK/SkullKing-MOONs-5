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

    while(true){
        //
    }
}
Channels::~Channels()
{
    Thread.join();
    delete ui;
}
