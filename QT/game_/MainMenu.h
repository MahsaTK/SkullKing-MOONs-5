#ifndef MainMenu_H
#define MainMenu_H
#include <QMainWindow>
#include "Player.h"
namespace Ui {
class MainMenu;
}

class MainMenu : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainMenu(QWidget *parent = nullptr);
    explicit MainMenu(Player c,QWidget *parent = nullptr);
    void Logout();
    ~MainMenu();

private:
    Ui::MainMenu *ui;
    Player player;
};

#endif // MainMenu_H
