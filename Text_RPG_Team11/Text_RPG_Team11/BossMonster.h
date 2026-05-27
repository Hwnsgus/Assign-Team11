// ===========================
// BossMonster.h
// ===========================
#pragma once

#include "Monster.h"

class Character;

// ==========================================
// 보스 몬스터 클래스
// 기존 몬스터 스탯의 1.5배
// ==========================================
class BossMonster : public Monster
{
public:
	BossMonster(std::string name, int level);

	void specialAttack(Character* character) override;

	void attack(Character* character) override;
};