#include <iostream>

#include "Item.h"
#include "Character.h"


Item::Item(std::string name, string sort,string E_name,int E_value)
	:Item_name(name),Item_type(sort), effect_name(E_name), effect_value(E_value)
{


}

void Item::GetItemType()
{
	//아이템 설명하는 곳
	cout << "\n" << Item_name << " : " << 
		effect_name << "이 " << effect_value << "만큼 발동";
	if (Item_type == "알약")
	{
		cout << "\n이 아이템은 전투 종료 시 효과가 종료됩니다!";
	}

}






