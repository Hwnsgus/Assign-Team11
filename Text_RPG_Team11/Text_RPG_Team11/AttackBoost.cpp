#include <iostream>

#include "AttackBoost.h"
#include "Character.h"




AttackBoost::AttackBoost() 
	:Item("공격력 증가 알약", "알약", "공격력 증가", 10,25)
{

	

}

void AttackBoost::use(Character* character)
{
	//사용했을 때 일어나는 효과 일어날 함수
	
	
	character->setAtk(character->getBaseAtk() + effect_value);
		
	

	


}

void AttackBoost::removeEffectAfterBattle(Character* character)
{
	//공격력 증가 버프 제거 함수, 전투 종료 시 한 번 실행해주세요
	
	character->setAtk(character->getBaseAtk());
}




