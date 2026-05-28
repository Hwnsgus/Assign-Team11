#pragma once
#include <string>


class Character;


using std::string;

class Item
{
protected:
	string Item_name;
	string Item_type;
	string effect_name;
	int effect_value;
	int Item_Price;
	

public:
	Item(string name,string sort, string E_name, int E_value, int pri);

	string getItemName()
	{
		return Item_name;
	}

	void ShowItemInfo();

	string ItemEffect()
	{
		return effect_name;
	}

	int getEffectValue()
	{
		return effect_value;
	}

	int getItemPrice()
	{
		return Item_Price;
	}


	virtual void use(Character* character) = 0;
	virtual bool isUsable() { return true; }
	
	
	

};

