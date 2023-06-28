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
    explicit Client(QTcpSocket*c, QWidget *parent = nullptr);
    ~Client();
    void communicate();

private:
    Ui::Client *ui;
    QTcpSocket *ClientSocket;
    std::thread Thread;
};

#endif // CLIENT_H
