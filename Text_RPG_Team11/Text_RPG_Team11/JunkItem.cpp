#include <iostream>

#include "JunkItem.h"
#include "Character.h"



JunkItem::JunkItem(string name, string desc, int price):Item(name,"잡템",desc,0,price)
{

}

void JunkItem::use(Character* character)
{

	std::cout << Item_name << "은(는) 사용할 수 없는 아이템입니다.\n";
}

bool JunkItem::isUsable()
{
	return false;
}

