#include <iostream>
#include "GameInfo.h"
#include "card.h"
#include <list>
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
    void set_cards(int round, int player) {
        for (int i = (player - 1) * (round) * 2; i != (player) * (round) * 2; i++) {
            cards.push_front(mainCards[i]);
        }
    }
    
};
