#include <iostream>
#include "HealthPotion.h"
#include "Character.h"

HealthPotion::HealthPotion() : Item("빨간 포션", "물약", "HP 회복", 50)
{
}

void HealthPotion::use(Character* character)
{
    // 현재 체력에 50(healAmount)을 더함. (초과 회복은 Character::sethp 내부에서 maxHP로 잘라줌)
    int Playerhp = character->gethp() + healAmount;
    character->sethp(Playerhp);
}