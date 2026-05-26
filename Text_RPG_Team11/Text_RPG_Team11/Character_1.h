#ifndef CHARACTER_H
#define CHARACTER_H

#include <iostream>
#include <string>

using namespace std;

class Character
{
protected:
    string name;
    int level;
    int hp;
    int maxHp;
    int power;
    int defense;
    int exp;
    int gold;

public:
    Character(string n);

    int attack();

    void takeDamage(int damage);

    bool isDead();

    void levelUp();

    void addExp(int amount);

    void addGold(int amount);

    void printStatus();
};

#endif