#pragma once
#ifndef NUMBEREDCARD_H
#define NUMBEREDCARD_H
#include <iostream>
#include "CharacterCard.h"
using namespace std;

class NumberedCard : public Card
{
private:
    int number;

public:
    NumberedCard(int n,cardType t):Card(t){
        number=n;

    }
    int GetNumber(){return number;}
    bool operator>(Card &card) // left card is the first played card
    {
        if (type == card.getType())
        {
            NumberedCard &cardptr = dynamic_cast<NumberedCard &>(card);
            return number > cardptr.number;
        }
        if (type == 4)
        {
            if (card.getType() > 4)
            {
                return false;
            }
            else
                return true;
        }
        if (type < 4)
        {
            if (card.getType() > 3)
            {
                return false;
            }
            else
                return true;
        }
    }
};

#endif
