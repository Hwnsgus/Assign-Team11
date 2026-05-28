#pragma once
#include "Item.h"

class JunkItem : public Item
{
public:
	JunkItem(string name, string desc, int price);

	void use(Character* character) override;

	bool isUsable() override;

};

