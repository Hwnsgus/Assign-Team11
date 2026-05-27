#pragma once

#include "Item.h"
#include "Character.h"


class Character;

class AttackBoost : public Item
{
protected:
	

public:

	AttackBoost();

	void use(Character* character);

	void removeEffectAfterBattle(Character* character);


};

