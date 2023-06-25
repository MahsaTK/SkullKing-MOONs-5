#ifndef function_
#define function_
#include <iostream>
#include "Player.h"
#include <fstream>
#include <QFile>
using namespace std;
void switch_card(Player first, Player second) {
    first.cards.push_back(second.cards.front());
    second.cards.push_back(first.cards.front());
    first.cards.pop_front();
    second.cards.pop_front();
}
void READ_FILE(vector<Player> &users){
    ifstream ifile("./Players_Info.txt");
    if(ifile.is_open()){
        ifile.seekg(0);
        while(!ifile.eof()){
            Player player;
            ifile>>player;
            users.push_back(player);
        }
        ifile.close();
    }
}
void WRITE_FILE(vector<Player> &users){
    qDebug()<<"Yes\n";
    ofstream ofile("./Players_Info.txt", std::ios::out | std::ios::trunc);
    if(ofile.is_open()){
        ofile.seekp(0);
        for(auto &x:users){
            ofile<<x;
        }
        ofile.close();
    }
}
ostream& operator<<(ostream &out,Player c){
    out<<c.name
      <<c.last_name
     <<c.username
    <<c.address
    <<c.phone_number
    <<c.password
    <<c.email
    <<c.won
    <<c.lost
    <<c.coins;
    //        <<c.last_game
    //        <<c.current_game;
    return out;
}
istream& operator>>(istream &in,Player& c){
    in>>c.name
            >>c.last_name
            >>c.username
            >>c.address
            >>c.phone_number
            >>c.password
            >>c.email
            >>c.won
            >>c.lost
            >>c.coins;
    //    >>c.last_game>>
    //    >>c.current_game;
    return in;
}

#endif 
