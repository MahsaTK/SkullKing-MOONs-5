#ifndef function_
#define function_
#include <iostream>
#include "Player.h"
#include <QTextStream>
#include <QFile>
#include <QCoreApplication>
#include <QDir>
using namespace std;
void switch_card(Player first, Player second) {
    first.cards.push_back(second.cards.front());
    second.cards.push_back(first.cards.front());
    first.cards.pop_front();
    second.cards.pop_front();
}
QTextStream& operator<<(QTextStream &out,Player c){
    out<< QString::fromStdString(c.name)<<'\n'
      <<QString::fromStdString(c.last_name)<<'\n'
     <<QString::fromStdString(c.username)<<'\n'
    <<QString::fromStdString(c.address)<<'\n'
    <<QString::fromStdString(c.phone_number)<<'\n'
    <<QString::fromStdString(c.password)<<'\n'
    <<QString::fromStdString(c.email)<<'\n'
    <<QString::number(c.won)<<'\n'
    <<QString::number(c.lost)<<'\n'
    <<QString::number(c.coins)<<'\n';
    //<<c.last_game;
    return out;
}
void READ_FILE(vector<Player> &users){
    if(!users.empty()){return;}
    QString projectDir = QCoreApplication::applicationDirPath();
    QFile file(projectDir+"/"+"Player_Info.txt");
     if (!file.open(QIODevice::ReadOnly))
         return;

     QTextStream in(&file);
     while( !in.atEnd()){
        Player player;
         in>>player;
        users.push_back(player);
     }
      file.close();
}
void WRITE_FILE(vector<Player> &users){
QString projectDir = QCoreApplication::applicationDirPath();
QFile file(projectDir+"/"+"Player_Info.txt");
 if (!file.open(QIODevice::WriteOnly))
     return;
 QTextStream out(&file);
for(auto &c :users){
 out << c<<'\n';
  }
 file.close();
}

QTextStream& operator>>(QTextStream &in,Player& c){
    c.name=in.readLine().toStdString();
    c.last_name=in.readLine().toStdString();
            c.username=in.readLine().toStdString();
            c.address=in.readLine().toStdString();
            c.phone_number=in.readLine().toStdString();
            c.password=in.readLine().toStdString();
            c.email=in.readLine().toStdString();
            c.won=in.readLine().toInt();
            c.lost=in.readLine().toInt();
            c.coins=in.readLine().toInt();
    //    >>c.last_game>>
    //    >>c.current_game;
    return in;
}

#endif 
