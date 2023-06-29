#ifndef TWOPLAYERSCREEN_H
#define TWOPLAYERSCREEN_H
#include "Client.h"
#include "Player.h"
#include "server.h"
#include <QMainWindow>
namespace Ui {
class TwoPlayerScreen;
}

class TwoPlayerScreen : public QMainWindow
{
    Q_OBJECT

public:
    explicit TwoPlayerScreen(Client *client,QWidget *parent = nullptr);
    explicit TwoPlayerScreen(Server *server, Client *cl, QWidget *parent = nullptr);
    ~TwoPlayerScreen();
     void ShowCards(Card *h);
     GameInfo gameInfo;
     Server *server;
     Client *clientServer;
     Client *client;
     void ShareCards(Player p1,Player p2,int round,Card*mainCards2PLayers[]);
     Card* mainCards2PLayers[42];
private:
    Ui::TwoPlayerScreen *ui;
};


#endif // TWOPLAYERSCREEN_H
