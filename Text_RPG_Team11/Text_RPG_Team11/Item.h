
#pragma once
#include <string>

#include "Character.h"


using std::string;

class Item
{
protected:
    string Item_name;
    string Item_type;
    string effect_name;
    int effect_value;
	

public:
    Item(string name,string sort, string E_name, int E_value);

    string getItemName()
    {
        return Item_name;
    }

    void getItemType();

    string ItemEffect()
    {
        return effect_name;
    }

    int getEffectValue()
    {
        return effect_value;
    }

    virtual void use(Character* character) = 0;
	
	
	
	

};



