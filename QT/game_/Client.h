#ifndef CLIENT_H
#define CLIENT_H

#include "Player.h"
#include <QWidget>
#include <QTcpSocket>
#include <thread>
namespace Ui {
class Client;
}

class Client : public QWidget
{
    Q_OBJECT

public:
    explicit Client(Player,QHostAddress ,QWidget *parent = nullptr);
    ~Client();
     QTcpSocket * ClientSocket;
     QHostAddress IP;
     int round;
     Player playerClient;
     QString player_username_server;
     int parrotClient;
     int parrotServer;
     int type;
     int number;
public slots:
    void readingData();
    void writingData();
    void connectedToServer();
    void disconnectedFromServer();

private:
    Ui::Client *ui;

};

#endif // CLIENT_H
