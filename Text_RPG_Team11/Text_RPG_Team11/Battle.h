#ifndef BATTLE_H
#define BATTLE_H

#include "Character.h"
#include "Monster.h"

class Character;
class Monster;

class Battle
{
public:
    void startBattle(Character& character, Monster* monster);
};

#endif