#pragma once


#include "Item.h"
#include "Character.h"

class Character;

class HealthPotion :public Item
{
protected:
    int healAmount = 50;

public:

    HealthPotion();

    void use(Character* character);

	

};
