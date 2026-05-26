#include <iostream>
#include "AttackBoost.h"
#include "Character.h"


AttackBoost::AttackBoost() : Item("공격력 증폭제", "버프", "공격력 증가", 10)
{
}

void AttackBoost::use(Character* character)
{
	// 오타 수정: setAtk() -> setatk() 로 통일
	int PlayerAtk = character->getatk() + increaseAmount;
	character->setAtk(PlayerAtk); 
}

void AttackBoost::removeEffectAfterBattle(Character* character)
{
	int PlayerAtk = character->getatk() - increaseAmount;
	character->setAtk(PlayerAtk);
}