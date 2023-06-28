#include "mainwindow.h"
#include <QSplashScreen>
#include <QApplication>
#include <QTimer>
#include <QListWidgetItem>
#include "twoplayerscreen.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QSplashScreen * splash=new QSplashScreen;
    splash->setPixmap(QPixmap(":/img/img/آرم بازی.png"));
    splash->show();
    MainWindow w;
//    TwoPlayerScreen s;
//    s.show();
    QTimer::singleShot(3000,splash,SLOT(close()));
    QTimer::singleShot(3000,&w,SLOT(show()));
    return a.exec();
}
