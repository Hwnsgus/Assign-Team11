#include <iostream>

#include "HealthPotion.h"

class Character;


HealthPotion::HealthPotion():Item("","물약", "HP 회복", 10)
{
	
}

void HealthPotion::use(Character* character)
{
	//사용 시 효과

	
		int Playerhp;
		Playerhp = character->gethp() + healAmount;
		character->sethp(Playerhp);
		
	
}
