#include <iostream>

#include "AttackBoost.h"


class Character;



AttackBoost::AttackBoost() :Item("공격력 증가 알약", "알약", "공격력 증가", 5)
{

	

}

void AttackBoost::use(Character* character)
{
	//사용했을 때 일어나는 효과 일어날 함수
	
	
		int PlayerAtk;
		PlayerAtk = character->getatk() + increaseAmount;
		character->setAtk(PlayerAtk);
		
	

	


}

void AttackBoost::removeEffectAfterBattle(Character* character)
{
	//전투 종료 시 실행되게 해주세요
	int PlayerAtk;
	PlayerAtk = character->getatk() - increaseAmount;
	character->setAtk(PlayerAtk);
}




