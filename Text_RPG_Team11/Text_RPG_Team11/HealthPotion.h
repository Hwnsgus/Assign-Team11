#pragma once


#include "Item.h"


class Character;

class HealthPotion :public Item
{
protected:
	

public:

	HealthPotion();

	void use(Character* character);

	

};

