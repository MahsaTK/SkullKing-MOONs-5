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
    std::vector<Channels*> AllCLients;
    ~Server();

public slots:
    void newConnectionsSlot();
private:
    Ui::Server *ui;
    QTcpServer *myServer;

friend class::MainMenu;
};

#endif // SERVER_H
