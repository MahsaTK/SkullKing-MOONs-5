#include <iostream>
#include "GameInfo.h"
using namespace std;

class Player
{
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
    
};