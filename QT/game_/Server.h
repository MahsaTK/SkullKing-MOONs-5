#ifndef SERVER_H
#define SERVER_H
#include <QTcpServer>
#include <QWidget>
#include <vector>
#include "channels.h"
#include "MainMenu.h"
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
    std::vector<Channels*> AllCLients;
private:
    Ui::Server *ui;
    QTcpServer *myServer;

friend class::MainMenu;
};

#endif // SERVER_H
