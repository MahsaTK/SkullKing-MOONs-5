#ifndef SERVER_H
#define SERVER_H
#include <QTcpServer>
#include <QWidget>
#include <vector>
#include "channels.h"
namespace Ui {
class Server;
}

class Server : public QWidget
{
    Q_OBJECT

public:
    explicit Server(QWidget *parent = nullptr);
    ~Server();

public slots:
    void newConnectionsSlot();
private:
    Ui::Server *ui;
    QTcpServer *myServer;
    std::vector<Channels*> AllCLients;
};

#endif // SERVER_H
