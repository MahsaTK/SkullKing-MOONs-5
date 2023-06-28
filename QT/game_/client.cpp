#include "Client.h"
#include "ui_client.h"

Client::Client(QTcpSocket * socket,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Client)
{
    ClientSocket=socket;
    ui->setupUi(this);

    Thread=std::thread(&Client::communicate(),this);
}
void Client::communicate(){
    while (true) {
        while(!ClientSocket->waitForReadyRead(-1)){
            //what send !!
            //readAll
            //wrte
        }
    }
}
Client::~Client()
{ Thread.join();
    delete ui;
}
