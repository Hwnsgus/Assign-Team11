#include <iostream>

#include "HealthPotion.h"
#include "Character.h"



HealthPotion::HealthPotion():Item("체력 포션","물약", "HP 회복", 50)
{
	
}

void HealthPotion::use(Character* character)
{
	//사용 시 효과

	
		int Playerhp;
		Playerhp = character->gethp() + effect_value;
		character->sethp(Playerhp);
		
	
}
