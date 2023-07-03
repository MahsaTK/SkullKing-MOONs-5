#pragma once
#ifndef GAMEINFO_H
#define GAMEINFO_H
#include <iostream>
#include <QTextStream>
using namespace std;

////copy constructor

class GameInfo
{
    friend QTextStream& operator<<(QTextStream &out,GameInfo& g);
    friend QTextStream& operator>>(QTextStream &in,GameInfo& g);
protected:
    int predict1[7];
    int predict2[7];
    int result1[7];
    int result2[7];
    int character1[3]; // in order from left to right Queen King Pirot
    int character2[3];
public:
    int* get_predict1(){
        int * r=predict1;
        return r;
    }
    int* get_predict2(){
        int * r=predict2;
        return r;
    }
    int* get_result1(){
        int * r=predict1;
        return r;
    }
    int* get_result2(){
        int * r=predict1;
        return r;
    }
    int* get_character1(){
        int * r=predict1;
        return r;
    }
    int* get_character2(){
        int * r=predict1;
        return r;
    }
    GameInfo(GameInfo &copy){
        for(int i=0 ;i!=7;i++){
            predict1[i]=copy.predict1[i];
            predict2[i]=copy.predict2[i];
            result1[i]=copy.result1[i];
            result2[i]=copy.result2[i];
        }
        for (int i = 0; i < 3; i++)
        {
            character1[i] = copy.character1[i];
            character2[i] =copy.character2[i] ;
        }
    }

    GameInfo()
    {
        for(int i=0 ;i!=7;i++){
            predict1[i]=0;
            predict2[i]=0;
            result1[i]=0;
            result2[i]=0;
        }
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
    virtual void addResult(int player, int round)
    {
        if (player == 1)
        {
            result1[round - 1] ++;
        }
        else
        {
            result2[round - 1] ++;
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
    ThreePlayer(ThreePlayer & copy):GameInfo(copy){
        for(int i=0 ;i!=7;i++){
            predict3[i]=copy.predict3[i];
            result3[i]=copy.result3[i];
        }
        for (int i = 0; i < 3; i++)
        {
            character3[i] =copy.character3[i] ;
        }
    }
    ThreePlayer():GameInfo()
    {
        for(int i=0 ;i!=7;i++){
            predict3[i]=0;
            result3[i]=0;
        }
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
    FourPlayer(FourPlayer & copy):ThreePlayer(copy){
        for(int i=0 ;i!=7;i++){
            predict3[i]=copy.predict4[i];
            result3[i]=copy.result4[i];
        }
        for (int i = 0; i < 3; i++)
        {
            character4[i] =copy.character4[i] ;
        }
    }
    FourPlayer():ThreePlayer()
    {
        for(int i=0 ;i!=7;i++){
            predict4[i]=0;
            result4[i]=0;
        }
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

#endif
