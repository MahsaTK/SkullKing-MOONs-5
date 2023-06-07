#include <iostream>
using namespace std;

enum cardType
{
    Treasure = 1,
    Map,
    Parrot,
    Hokm,
    King,
    Queen,
    Pirot
};

class Card
{
protected:
    cardType type;

public:
    int getType()
    {
        return type;
    }
    virtual bool operator>(Card& card) = 0;
};