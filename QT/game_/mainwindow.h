#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QPushButton>
#include <QMainWindow>
#include <QPixmap>
#include <QLabel>
#include <QTextEdit>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QFormLayout>
#include "Player.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void login();
    void signUp();
    void  loginAndSignup();
private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_signUpOk_clicked();

    void on_loginOk_clicked();

private:
    Ui::MainWindow *ui;
    QLineEdit* loginUserEdit;
    QLineEdit* loginPassEdit;
    QLabel *loginUserLabel;
    QLabel *loginPassLabel;
    QFormLayout * loginMainForm;
    QLineEdit* signUpUserEdit;
    QLineEdit* signUpPassEdit;
    QLabel *signUpUserLabel;
    QLabel *signUpPassLabel;
    QFormLayout * signUpMainForm;
    QLineEdit* signUpNameEdit;
    QLineEdit* signUpLast_nameEdit;
    QLineEdit* signUpPhone_numberEdit;
    QLineEdit* signUpEmailEdit;
    QLineEdit* signUpAddressEdit;
    QLabel * signUpNameLabel;
    QLabel * signUpLast_nameLabel;
    QLabel * signUpPhone_numberLabel;
    QLabel * signUpEmailLabel;
    QLabel *signUpAddressLabel;
    GameInfo last_game;
    GameInfo current_game;
    QFormLayout * MainForm;
    int won;
    int lost;
    int coins;
};

//class SignUpWindow : public MainWindow{
//private:
//    QPushButton * signUpOK;
//public:
//    SignUpWindow(int);
//};



#endif // MAINWINDOW_H
