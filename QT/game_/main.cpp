#include "mainwindow.h"
#include <QSplashScreen>
#include <QApplication>
#include <QTimer>
int main(int argc, char *argv[])
{
    Card* mainCards[42];
    QApplication a(argc, argv);

    QSplashScreen * splash=new QSplashScreen;
    splash->setPixmap(QPixmap(":/img/img/آرم بازی.png"));
    splash->show();
    MainWindow w;
    QTimer::singleShot(3000,splash,SLOT(close()));
    QTimer::singleShot(3000,&w,SLOT(show()));
    return a.exec();
}
