#ifndef STARTTHEGAME_H
#define STARTTHEGAME_H
#include <QMainWindow>
#include "Player.h"
namespace Ui {
class StartTheGame;
}

class StartTheGame : public QMainWindow
{
    Q_OBJECT

public:
    explicit StartTheGame(QWidget *parent = nullptr);
    explicit StartTheGame(Player c,QWidget *parent = nullptr);
    void Logout();
    ~StartTheGame();

private:
    Ui::StartTheGame *ui;
    Player player;
};

#endif // STARTTHEGAME_H
