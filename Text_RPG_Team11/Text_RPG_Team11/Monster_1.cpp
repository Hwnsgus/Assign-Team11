#include "Monster.h"

Monster::Monster()
{
    int randomMonster = rand() % 3;

    if (randomMonster == 0)
    {
        name = "슬라임";
        hp = 50;
        power = 10;
        defense = 2;
    }
    else if (randomMonster == 1)
    {
        name = "고블린";
        hp = 70;
        power = 15;
        defense = 3;
    }
    else
    {
        name = "오크";
        hp = 100;
        power = 20;
        defense = 5;
    }

    cout << endl;
    cout << name << " 이(가) 난입했다!" << endl;
}

void Monster::attack()
{
    cout << endl;
    cout << name << "의 공격!" << endl;
}

void Monster::takeDamage(int damage)
{
    damage -= defense;

    if (damage < 0)
    {
        damage = 0;
    }

    hp -= damage;

    if (hp < 0)
    {
        hp = 0;
    }

    cout << name << "가 " << damage << "의 피해를 입었습니다." << endl;
    cout << name << " HP : " << hp << endl;
}

bool Monster::isDead()
{
    return hp <= 0;
}

int Monster::getPower()
{
    return power;
}