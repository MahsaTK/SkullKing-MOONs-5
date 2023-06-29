#ifndef PLAYER_H
#define PLAYER_H
#pragma once
#include <iostream>
#include "GameInfo.h"
#include "NumberedCard.h"
#include <list>
#include <vector>
#include <QTextStream>
#include <QFile>
#include <QCoreApplication>
#include <QDir>
using namespace std;
class Player
{
    friend void switch_card(Player first, Player second);
    friend QTextStream& operator>>(QTextStream &in,Player& c);
    friend QTextStream& operator<<(QTextStream &out,Player& c);
private:
    string name;
    string last_name;
    string username;
    string phone_number;
    string email;
    string address;
    string password;
    GameInfo last_game;
    GameInfo current_game;
    int won;
    int lost;
    int coins;
    list <Card*> cards;

public:
    Player(const Player& c){
        name=c.name;
        last_name=c.last_name;
        username=c.username;
        phone_number=c.phone_number;
        email=c.email;
        address=c.address;
        password=c.password;
        last_game=c.last_game;
        current_game=c.current_game;
        won=c.won;
        lost=c.lost;
        coins=c.coins;
        cards=c.cards;

    }
    Player(){ won=0;lost=0;coins=0;}
    void set_cards(int round, int player, Card* mainCards[]) {
        for (int i = (player - 1) * (round) * 2; i != (player) * (round) * 2; i++) {
            cards.push_front(mainCards[i]);
        }
    }
    void set_name(string n){
        name=n;
    }
    //    void set_number(string n){
    //        phone_number=n;
    //    }
    string get_number(){
        return phone_number;
    }
    string get_pass(){return password;}
    string get_username(){return username;}
    void set_last_name(string n){
        last_name=n;
    }
    void set_username(string n){
        username=n;
    }
    void set_phone_number(string n){
        phone_number=n;
    }
    void set_email(string n){
        email=n;
    }
    void set_address(string n){
        address=n;
    }
    void set_password(string n){
        password=n;
    }

};

//QTextStream& operator<<(QTextStream &out,Player c){
//    out<< QString::fromStdString(c.name)<<'\n'
//        <<QString::fromStdString(c.last_name)<<'\n'
//        <<QString::fromStdString(c.username)<<'\n'
//        <<QString::fromStdString(c.address)<<'\n'
//        <<QString::fromStdString(c.phone_number)<<'\n'
//        <<QString::fromStdString(c.password)<<'\n'
//        <<QString::fromStdString(c.email)<<'\n'
//        <<QString::number(c.won)<<'\n'
//        <<QString::number(c.lost)<<'\n'
//        <<QString::number(c.coins)<<'\n';
//    //<<c.last_game;
//    return out;
//}
//QTextStream& operator>>(QTextStream &in,Player& c){
//    c.name=in.readLine().toStdString();
//    c.last_name=in.readLine().toStdString();
//    c.username=in.readLine().toStdString();
//    c.address=in.readLine().toStdString();
//    c.phone_number=in.readLine().toStdString();
//    c.password=in.readLine().toStdString();
//    c.email=in.readLine().toStdString();
//    c.won=in.readLine().toInt();
//    c.lost=in.readLine().toInt();
//    c.coins=in.readLine().toInt();
//    //    >>c.last_game>>
//    //    >>c.current_game;
//    return in;
//}

extern vector<Player> players;

#endif
