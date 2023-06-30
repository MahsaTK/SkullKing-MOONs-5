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
     Player playerClient;
public slots:
    void readingData();
    void writingData();
    void connectedToServer();
    void disconnectedFromServer();

private:
    Ui::Client *ui;

};

#endif // CLIENT_H
