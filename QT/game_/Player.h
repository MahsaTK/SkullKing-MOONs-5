#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
#include "GameInfo.h"
#include "NumberedCard.h"
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
    void set_cards(int round, int player) {
        for (int i = (player - 1) * (round) * 2; i != (player) * (round) * 2; i++) {
            cards.push_front(mainCards[i]);
        }
    }
    void set_name(string n){
        name=n;
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
    friend istream& operator>>(istream &in,Player& c);
    friend ostream& operator<<(ostream &out,Player c);

};

#endif
