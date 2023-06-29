#include "mainwindow.h"
#include "MainMenu.h"
#include "ui_MainMenu.h"
#include "Client.h"
#include "server.h"
#include <QInputDialog>
#include <QDialog>
#include <QMessageBox>
#include <QHostAddress>
#include <cstdlib>
#include <QHostInfo>
#include <QThread>
#include <QProgressDialog>
#include <twoplayerscreen.h>
MainMenu::MainMenu(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainMenu)
{


    ui->setupUi(this);
    QWidget::setWindowTitle("Skull King");
    setWindowIcon(QIcon(":/img/img/نام بازی.png"));
    MainLayout=new QFormLayout();
    this->setFixedSize(350,500);
    MainLayout->addRow(ui->ServerBtn);
    MainLayout->addRow(ui->ClientBtn);

    QWidget *widget = new QWidget();
    widget->setLayout(MainLayout);
    this->setCentralWidget(widget);
}

MainMenu::MainMenu(Player c,QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainMenu)
{
    QWidget::setWindowTitle("Skull King");
    setWindowIcon(QIcon(":/img/img/نام بازی.png"));
    ui->setupUi(this);
    MainLayout=new QFormLayout();
    this->setFixedSize(350,500);
    MainLayout->addRow(ui->ServerBtn);
    MainLayout->addRow(ui->ClientBtn);
    QWidget *widget = new QWidget();
    widget->setLayout(MainLayout);
    this->setCentralWidget(widget);
    player=c;
}
MainMenu::~MainMenu()
{
    delete ui;
}
void MainMenu::Logout(){

}

void MainMenu::on_ClientBtn_clicked()
{
    bool ok1;
    QString IP = QInputDialog::getText(this, tr("Client"), tr("IP of server:"), QLineEdit::Normal, "", &ok1);
    if (ok1 && !IP.isEmpty()){
        Client* client=new Client(player,QHostAddress(IP));
        TwoPlayerScreen * twoPlayerC=new TwoPlayerScreen(client);
        twoPlayerC->show();
    }

}


void MainMenu::on_ServerBtn_clicked()
{
    bool ok1;

    QString numbersOfPlayers = QInputDialog::getText(this, tr("Server"), tr("Number of Players"), QLineEdit::Normal, "", &ok1);
    if (ok1 && !numbersOfPlayers.isEmpty()){
        int number=numbersOfPlayers.toInt();
        if(number==2){
            Server* playerServer=new Server();
            Client* clientServer=new Client(player,QHostAddress::LocalHost);
            //QHostAddress serverAddress = clientServer.ClientSocket->peerAddress();
            QString ipAddress;
            foreach(const QHostAddress &address,QHostInfo::fromName(QHostInfo::localHostName()).addresses()){
                if(address.protocol()==QAbstractSocket::IPv4Protocol){
                    ipAddress = address.toString();
                }
            }
            ipAddress="IP: "+ipAddress+"\n"+QString::fromStdString(player.get_username());
            // do something with charArray
            // Create a QProgressDialog object with a message and a cancel button
            QProgressDialog progressDialog("Loading...", "Cancel", 0, 100);
            progressDialog.setWindowModality(Qt::WindowModal); // Make the dialog modal

            // Set the dialog's properties
            progressDialog.setWindowTitle("Loading");
            progressDialog.setLabelText(ipAddress);

            // Show the dialog
            progressDialog.show();

            // Update the progress bar
            for (;playerServer->AllCLients.size()!=2 ; ) {
                progressDialog.setValue(50);
                qApp->processEvents(); // Allow the UI to update
                if (progressDialog.wasCanceled()) {   //if cancel
                    break;
                }
            }
            if(playerServer->AllCLients.size()==2) {
                progressDialog.setValue(100);
                /////// ipAddress=playerServer.AllCLients.back().player.
                ipAddress+="\nClient 2";
                progressDialog.setLabelText(ipAddress);
                QThread::sleep(3);
                TwoPlayerScreen* twoPlayerS=new TwoPlayerScreen(playerServer,clientServer);
                twoPlayerS->show();
            }

            progressDialog.close();

        }
    }


}

