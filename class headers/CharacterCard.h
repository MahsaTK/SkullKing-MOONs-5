#include <iostream>
#include "Card.h"
using namespace std;

class CharacterCard : public Card
{
public:
    bool operator>(Card &card) // left card is the first played card
    {
        if (type == card.getType())
        {
            return true;
        }
        if (card.getType() < 5)
        {
            return true;
        }
        if (type == 5)
        {
            if (card.getType() == 6)
                return false;
            else
                return true;
        }
        if (type == 6)
        {
            if (card.getType() == 7)
                return false;
            else
                return true;
        }
        if (type == 7)
        {
            if (card.getType() == 5)
                return false;
            else
                return true;
        }
    }
};