#include "mainwindow.h"
#include "MainMenu.h"
#include "ui_MainMenu.h"
#include "Client.h"
#include <Server.h>
#include <QInputDialog>
#include <QDialog>
#include <QMessageBox>
#include <QHostAddress>
#include <cstdlib>
#include <QHostInfo>
#include <QThread>
#include <QProgressDialog>
#include <twoplayerscreen.h>
#include <QTimer>
#include <changeinfo.h>
#include <history.h>
MainMenu::MainMenu(Player c,QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainMenu)
{
    QWidget::setWindowTitle("Skull King");
    setWindowIcon(QIcon(":/img/img/نام بازی.png"));
    ui->setupUi(this);
    this->setFixedSize(350,500);
    setCentralWidget(ui->layoutWidget);
    player=c;
}
MainMenu::~MainMenu()
{
    delete ui;
}

void MainMenu::on_ClientBtn_clicked()
{
    bool ok1;
    QString IP = QInputDialog::getText(this, tr("Client"), tr("IP of server:"), QLineEdit::Normal, "", &ok1);
    if (ok1 && !IP.isEmpty()){
        Client* client=new Client(player,QHostAddress(IP));
        TwoPlayerScreen * twoPlayerC=new TwoPlayerScreen(client);
        twoPlayerC->show();
        this->close();
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
            QProgressDialog * progressDialog=new QProgressDialog ("Loading...", "Cancel", 0, 100);
            progressDialog->setWindowModality(Qt::WindowModal); // Make the dialog modal

            // Set the dialog's properties
            progressDialog->setWindowTitle("Loading");
            progressDialog->setLabelText(ipAddress);
            progressDialog->setMinimumDuration(0);

            // Show the dialog
            progressDialog->show();

            // Update the progress bar
            bool flag=true;
            for (;playerServer->AllCLients.size()!=2 ; ) {
                progressDialog->setValue(50);
                QApplication::processEvents();
                if (progressDialog->wasCanceled()) {
                    flag=false;
                    break;
                }
            }
            if(flag){
                if(playerServer->AllCLients.size()==2) {
                    progressDialog->setValue(99);
                    /////// ipAddress=playerServer.AllCLients.back().player.
                    ipAddress+="\n"+playerServer->AllCLients.back()->playerName;
                    progressDialog->setLabelText(ipAddress);
                    QApplication::processEvents();
                    progressDialog->setValue(100);
                    QApplication::processEvents();
                    QThread::msleep(3000);
                    progressDialog->close();
                    TwoPlayerScreen* twoPlayerS=new TwoPlayerScreen(playerServer,clientServer);
                    this->close();
                    twoPlayerS->show();

                }
            }


        }
    }
}

void MainMenu::on_logOutBtn_clicked()
{
    this->close();
    MainWindow *logout=new MainWindow();
    logout->show();
}

void MainMenu::on_changeInfo_clicked()
{
    changeInfo* chi=new changeInfo(player);
//    this->close();
    chi->show();
//    while(chi->exec()!=QDialog::Accepted){}
    player=chi->get_player();
//    MainMenu* changed=new MainMenu(player);
//    changed->show();
}

void MainMenu::on_history_clicked()
{
    History* h=new History();
    h->show();
}

