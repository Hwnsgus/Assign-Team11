// ===========================
// BossMonster.cpp
// ===========================
#include <iostream>

#include "BossMonster.h"
#include "Character.h"

using namespace std;

// ==========================================
// 생성자
// 기존 몬스터보다 1.5배 강함
// ==========================================
BossMonster::BossMonster(string name, int level)
	: Monster(name, level)
{
	MonsterHp =
		randomstat(level * 30,
			level * 45);

	MonsterAtk =
		randomstat(level * 10,
			level * 15);
}

// ==========================================
// 특수 공격
// 강력한 암흑 폭발
// ==========================================
void BossMonster::specialAttack(Character* character)
{
	int damage;

	damage =
		(getatk() * 2)
		- character->getdef();

	if (damage <= 0)
	{
		damage = 5;
	}

	character->sethp(
		character->gethp() - damage
	);

	cout << endl;

	cout << "========================================"
		<< endl;

	cout << " [BOSS] 암흑 폭발 발동!"
		<< endl;

	cout << "========================================"
		<< endl;

	cout << character->getName()
		<< " 에게 "
		<< damage
		<< " 치명적인 데미지!"
		<< endl;
}

// ==========================================
// 보스 공격
// ==========================================
void BossMonster::attack(Character* character)
{
	cout << endl;

	cout << "========== 보스 턴 =========="
		<< endl;

	// 40% 특수 공격
	if (rand() % 100 < 40)
	{
		specialAttack(character);
	}

	else
	{
		normalAttack(character);
	}
}