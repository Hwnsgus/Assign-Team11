#pragma once

#include "Item.h"
#include "Character.h"


class Character;

class AttackBoost : public Item
{
protected:
    int increaseAmount = 10;

public:

    AttackBoost();

    void use(Character* character);

    void removeEffectAfterBattle(Character* character);


};
