


#include "Character.h"
#include "LogManager.h"
#include <sstream>
#include<iostream>
using namespace std;


Character::Character(string charName) : name(charName) {

	level = 1;
	maxHP = 200;
	currentHP = 200;
	attackPower = 30;
	defense = 30;
	exp = 0;
	gold = 0;


	LogManager::getInstance().addLog("캐릭터 [" + name + "] 생성 완료! (Lv.1, HP :200, ATK :30");
}


void Character::sethp(int hp) {
	currentHP = hp;
	if (currentHP < 0)
	{
		currentHP = 0;
	}
	if (currentHP > maxHP)
	{
		currentHP = maxHP;
	}
}


void Character::setAtk(int atk)
{
	attackPower = atk;

}


void Character::takeDamage(int damage) {
	currentHP -= damage;
	if (currentHP < 0) currentHP = 0;
}

void Character::gainExp(int amount) {
	exp += amount;

	LogManager::getInstance().addLog(to_string(amount) + " EXP 획득 (현재: " + to_string(exp) + "/100)");

	// 원래는 레벨업 클래스가 처리하겠지만 임시 검증용

	if (exp >= 100) {
		level++;
		exp -= 100;
		maxHP += 20;
		attackPower += 5;
		currentHP = maxHP;

		LogManager::getInstance().addLog("★ LEVEL UP! 현재 레벨: " + to_string(level));

	}
}

void Character::gainGold(int amount) {
	gold += amount;

	LogManager::getInstance().addLog(to_string(amount) + " 골드 획득!");

}


void Character::showStatus() const {
	cout << "\n========================================\n"

		<< " [" << name << " 의 상태]\n"
		<< " 레벨   : " << level << " (최대 10)\n"
		<< " 체력   : " << currentHP << " / " << maxHP << "\n"
		<< " 공격력 : " << attackPower << "\n"
		<< " 경험치 : " << exp << " / 100\n"
		<< " 골드   : " << gold << " G\n"
		<< "========================================\n";
}

// 아이템 담당 연동 함수 (현재는 틀만 제공)
void Character::addItem(Item* item) { /* 아이템 담당자가 구현 예정 */ }
void Character::useItem(Item* item) { /* 아이템 담당자가 구현 예정 */ }

