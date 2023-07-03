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
    Card* castToCard(int type,int number);
    void WhoWin(Card *h,int round,int set,int type,int number,int player);
    void ShareCards(Player & p1,Player & p2,int round,Card*mainCards2PLayers[]);
    explicit TwoPlayerScreen(Client *client,QWidget *parent = nullptr);
    explicit TwoPlayerScreen(Server *server, Client *cl, QWidget *parent = nullptr);
    ~TwoPlayerScreen();
    GameInfo gameInfo;
    Card* mainCards2PLayers[42];
    void ShowCards(Card *h);
    void whoStartServer();
    void whoStart();
    void GameRound1client(int Round,int set);
    void chooseTheStater();
    void SendCardToServer(int type, int number );
    void SendCardToCLient(int type, int number );
    void ShowCards(int type, int n,QString name);
    void GameRound1server(int Round,int set);
public slots:
    void onItemClicked(QListWidgetItem *item);
    void onItemClickedserver(QListWidgetItem *item);
private:
    int typeItem;
    int numberItem;
    int starter;
    Server *server;
    Client *clientServer;
    Client *client;
    Ui::TwoPlayerScreen *ui;
};


#endif // TWOPLAYERSCREEN_H
