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
    int won;
    int lost;
    int coins;
    list <Card*> cards;


public:
    GameInfo current_game;
    GameInfo last_game;
//    int** get_last_game(){
//        int* arr[6];
//        arr[0]=last_game.get_character1();
//        arr[1]=last_game.get_character2();
//        arr[2]=last_game.get_predict1();
//        arr[3]=last_game.get_predict2();
//        arr[4]=last_game.get_result1();
//        arr[5]=last_game.get_result2();
//        return arr;
//    }
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
    void clearCards(){
        cards.clear();
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
    int get_coins(){return coins;}
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
    void decreaseCoins(int c){
        coins-=c;
    }
    void increaseCoins(int c){
        coins+=c;
    }
};

extern vector<Player> players;

#endif
