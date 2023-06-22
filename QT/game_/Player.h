#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
#include "GameInfo.h"
#include "Card.h"
#include <list>
#include <vector>
using namespace std;
class Player
{
    friend void switch_card(Player first, Player second);
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
    Player(){ won=0;lost=0;coins=0;}
    void set_cards(int round, int player) {
        for (int i = (player - 1) * (round) * 2; i != (player) * (round) * 2; i++) {
            cards.push_front(mainCards[i]);
        }
    }
    void set_name(string n){
        name=n;
    }
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


#endif
