#ifndef CLIENT_H
#define CLIENT_H

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
    explicit Client(QString,QWidget *parent = nullptr);
    ~Client();
     QTcpSocket * ClientSocket;
     QString IP;
public slots:
    void connectingToServer();
    void readingData();
    void writingData();
    void connectedToServer();
    void disconnectedFromServer();

private:
    Ui::Client *ui;

};

#endif // CLIENT_H
