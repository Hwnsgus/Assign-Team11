#pragma once

#include "Item.h"



class Character;

class AttackBoost : public Item
{
protected:
	

public:

	AttackBoost();

	void use(Character* character) override;

	void removeEffectAfterBattle(Character* character);


};

