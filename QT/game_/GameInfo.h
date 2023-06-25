#include <iostream>
using namespace std;


//copy constructor





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
    virtual void addPredict(int player, int round, int predict )
    {
        if (player == 1)
        {
            predict1[round - 1] = predict;
        }
        else
        {
            predict2[round - 1] = predict;
        }
    }
    virtual void addResult(int player, int round,int result)
    {
        if (player == 1)
        {
            result1[round - 1] = result;
        }
        else
        {
            result2[round - 1] = result;
        }
    }
    virtual void addCharacter(int player, int character) // character Queen=0 King=1 Pirot=2
    {
        if (player == 1)
        {
            character1[character]++;
        }
        else
        {
            character2[character]++;
        }
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
    virtual void addPredict(int player, int round, int predict)
    {
        if (player == 1)
        {
            predict1[round - 1] = predict;
        }
        else if(player==2)
        {
            predict2[round - 1] = predict;
        }
        else
        {
            predict3[round - 1] = predict;
        }
    }
    virtual void addResult(int player, int round, int result)
    {
        if (player == 1)
        {
            result1[round - 1] = result;
        }
        else if(player==2)
        {
            result2[round - 1] = result;
        }
        else {
            result3[round - 1] = result;
        }
    }
    virtual void addCharacter(int player, int character) // character Queen=0 King=1 Pirot=2
    {
        if (player == 1)
        {
            character1[character]++;
        }
        else if(player==2)
        {
            character2[character]++;
        }
        else {
            character3[character]++;
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
    virtual void addPredict(int player, int round, int predict)
    {
        if (player == 1)
        {
            predict1[round - 1] = predict;
        }
        else if (player == 2)
        {
            predict2[round - 1] = predict;
        }
        else if(player==3)
        {
            predict3[round - 1] = predict;
        }
        else {
            predict4[round - 1] = predict;
        }
    }
    virtual void addResult(int player, int round, int result)
    {
        if (player == 1)
        {
            result1[round - 1] = result;
        }
        else if (player == 2)
        {
            result2[round - 1] = result;
        }
        else if(player==3) {
            result3[round - 1] = result;
        }
        else {
            result4[round - 1] = result;
        }
    }
    virtual void addCharacter(int player, int character) // character Queen=0 King=1 Pirot=2
    {
        if (player == 1)
        {
            character1[character]++;
        }
        else if (player == 2)
        {
            character2[character]++;
        }
        else if(player==3) {
            character3[character]++;
        }
        else {
            character4[character]++;
        }
    }
};
