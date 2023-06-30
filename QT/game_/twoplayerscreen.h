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
    void ShareCards(Player p1,Player p2,int round,Card*mainCards2PLayers[]);
    explicit TwoPlayerScreen(Client *client,QWidget *parent = nullptr);
    explicit TwoPlayerScreen(Server *server, Client *cl, QWidget *parent = nullptr);
    ~TwoPlayerScreen();
    GameInfo gameInfo;
    Server *server;
    Client *clientServer;
    Client *client;
    Card* mainCards2PLayers[42];
    Player tempPlayer;
    void distributeCards();
    void ShowCards(Card *h);
private:
    Ui::TwoPlayerScreen *ui;
};


#endif // TWOPLAYERSCREEN_H
