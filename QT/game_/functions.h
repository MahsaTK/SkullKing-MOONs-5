#ifndef function
#define function
#include <iostream>
#include "Player.h"
#include "CharacterCard.h"
#include "NumberedCard.h"
using namespace std;
void switch_card(Player first, Player second) {
	first.cards.push_back(second.cards.front());
	second.cards.push_back(first.cards.front());
	first.cards.pop_front();
	second.cards.pop_front();
}



#endif 
