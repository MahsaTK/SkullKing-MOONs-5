#ifndef function_h
#define function_h
#pragma once
#include <iostream>
#include <QTextStream>
#include <QFile>
#include <QCoreApplication>
#include <QDir>
#include <Player.h>
using namespace std;
void switch_card(Player , Player );
QTextStream& operator<<(QTextStream &,Player& );
QTextStream& operator>>(QTextStream &,Player&);
QTextStream& operator<<(QTextStream &out,GameInfo& g);
QTextStream& operator>>(QTextStream &in,GameInfo& g);
void READ_FILE(vector<Player> &);
void WRITE_FILE(vector<Player>&);

#endif 
