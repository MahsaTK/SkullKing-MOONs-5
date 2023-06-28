#ifndef TWOPLAYERSCREEN_H
#define TWOPLAYERSCREEN_H
#include "Player.h"
#include <QMainWindow>
namespace Ui {
class TwoPlayerScreen;
}

class TwoPlayerScreen : public QMainWindow
{
    Q_OBJECT

public:
    explicit TwoPlayerScreen(QWidget *parent = nullptr);
    ~TwoPlayerScreen();
     void ShowCards(Card *h);
     GameInfo gameInfo;
     Player player1;
     Player player2;
     void ShareCards(Player p1,Player p2,int round,Card*mainCards2PLayers[]);
     Card* mainCards2PLayers[42];
private:
    Ui::TwoPlayerScreen *ui;
};


#endif // TWOPLAYERSCREEN_H
