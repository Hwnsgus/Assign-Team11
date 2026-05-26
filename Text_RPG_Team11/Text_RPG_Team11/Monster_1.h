#ifndef MONSTER_H
#define MONSTER_H

#include <iostream>
#include <string>

using namespace std;

class Monster
{
private:
    string name;
    int hp;
    int power;
    int defense;

public:
    Monster();

    void attack();

    void takeDamage(int damage);

    bool isDead();

    int getPower();
};

#endif