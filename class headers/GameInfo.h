#include <iostream>
using namespace std;

class GameInfo
{
protected:
    int predict1[7];
    int predict2[7];
    int result1[7];
    int result2[7];
    int character1[3]; // in order from left to right Queen King Pirot
    int character2[3];

public:
    GameInfo()
    {
        for (int i = 0; i < 3; i++)
        {
            character1[i] = 0;
            character2[i] = 0;
        }
    }
    virtual void addPredict(int player, int round)
    {
        if (player == 1)
        {
        }
        else
        {
        }
    }
    virtual void addResult(int player, int round)
    {
    }
    virtual void addCharacter(int player, int character) // character Queen=0 King=1 Pirot=2
    {
    }
};

class ThreePlayer : public GameInfo
{
protected:
    int predict3[7];
    int result3[7];
    int character3[3];

public:
    ThreePlayer()
    {
        for (int i = 0; i < 3; i++)
        {
            character3[i] = 0;
        }
    }
};

class FourPlayer : public ThreePlayer
{
    int predict4[7];
    int result4[7];
    int character4[3];

public:
    FourPlayer()
    {
        for (int i = 0; i < 3; i++)
        {
            character4[i] = 0;
        }
    }
};