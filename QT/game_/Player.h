#ifndef PLAYER_H
#define PLAYER_H
#pragma once
#include <iostream>
#include "GameInfo.h"
#include <list>
#include <vector>
#include <QTextStream>
#include <QFile>
#include <QCoreApplication>
#include <QDir>
#include "NumberedCard.h"
using namespace std;
class Player
{
    friend void switch_card(Player first, Player second);
    friend QTextStream& operator>>(QTextStream &in,Player& c);
    friend QTextStream& operator<<(QTextStream &out,Player& c);
    friend void WRITE_FILE(vector<Player> &users);
    friend void READ_FILE(vector<Player> &users);
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
    void set_cards(Card * card){
        cards.push_front(card);
    }
    list <Card*>& get_cards(){

        return cards;
    }

    void set_name(string n){
        name=n;
    }
        void set_number(string n){
            phone_number=n;
        }
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

extern vector<Player> players;

#endif
