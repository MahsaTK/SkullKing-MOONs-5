#ifndef TWOPLAYERSCREEN_H
#define TWOPLAYERSCREEN_H
#include "Client.h"
#include "Player.h"
#include "server.h"
#include <QMainWindow>
#include <QListWidget>
namespace Ui {
class TwoPlayerScreen;
}

class TwoPlayerScreen : public QMainWindow
{
    Q_OBJECT

public:
    void ShareCards(Player & p1,Player & p2,int round,Card*mainCards2PLayers[]);
    explicit TwoPlayerScreen(Client *client,QWidget *parent = nullptr);
    explicit TwoPlayerScreen(Server *server, Client *cl, QWidget *parent = nullptr);
    ~TwoPlayerScreen();
    GameInfo gameInfo;
    Server *server;
    Client *clientServer;
    Client *client;
    Card* mainCards2PLayers[42];
    void ShowCards(Card *h);
    void whoStartServer();
    void whoStart();
    void GameRound1client();
    void chooseTheStater();
    void SendCardToServer(int type, int number );
    void SendCardToCLient(int type, int number );
    void ShowCards(int type, int n,QString name);
    void GameRound1server();
public slots:
    void onItemClicked(QListWidgetItem *item);
    void onItemClickedserver(QListWidgetItem *item);
private:
    int starter;
    Ui::TwoPlayerScreen *ui;
};


#endif // TWOPLAYERSCREEN_H
