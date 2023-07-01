#ifndef MainMenu_H
#define MainMenu_H
#include <QMainWindow>
#include "Player.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QFormLayout>
namespace Ui {
class MainMenu;
}

class MainMenu : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainMenu(Player c,QWidget *parent = nullptr);
    ~MainMenu();

private slots:
    void on_history_clicked();

private slots:
    void on_ClientBtn_clicked();
    void on_logOutBtn_clicked();
    void on_ServerBtn_clicked();
    void on_changeInfo_clicked();

private:
    Ui::MainMenu *ui;
    Player player;
    QFormLayout* MainLayout;
};

#endif // MainMenu_H
