#include <iostream>
#include "Item.h"
#include "Character.h"

using namespace std;

Item::Item(string name, string sort, string E_name, int E_value)
    :Item_name(name), Item_type(sort), effect_name(E_name), effect_value(E_value)
{
}

void Item::getItemType()
{
    cout << "\n[" << Item_type << "] " << Item_name << " : "
         << effect_name << "을(를) " << effect_value << "만큼 올려줍니다.";
    if (Item_type == "물약")
    {
        cout << "\n(이 아이템은 전투 중 사용 시 즉시 효과가 적용됩니다!)\n";
    }
}