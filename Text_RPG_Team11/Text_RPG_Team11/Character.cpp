#include "Character.h"
#include "LogManager.h"
#include <sstream>
#include<iostream>

#include "Item.h"
using namespace std;


Character::Character(string charName) : name(charName) {

	level = 1;
	maxHP = 200;
	currentHP = 200;
	attackPower = 30;
	defense = 10;
	exp = 0;
	gold = 0;
	baseAtk = attackPower;

	LogManager::getInstance().addLog("캐릭터 [" + name + "] 생성 완료!(Lv.1, HP :200, ATK : 30)");
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

void Character::showInventory()
{
	if (inventory.empty())
	{
		cout << "인벤토리가 비어 있습니다. \n";
		return;
	}

	for (size_t i = 0; i < inventory.size(); i++)
	{
		cout << "[" << i + 1 << "]" << inventory[i]->getItemName() << "(" << inventory[i]->ItemEffect() << ")" << endl;
	}
}

Item* Character::getItem(int index)
{
	if (index >= 0 && index < inventory.size())
	{
		Item* selected = inventory[index];
		inventory.erase(inventory.begin() + index);
		return selected;
	}
	return nullptr;
}

void Character::takeDamage(int damage) {
	currentHP -= damage;
	if (currentHP < 0) currentHP = 0;
}

bool Character::gainExp(int amount) {
	exp += amount;
	if (level == 10)
	{
		cout << endl;

		cout << "========================================"
			<< endl;

		cout << " 이제 일반 몬스터는 상대도 안 된다!"
			<< endl;

		cout << " 보스 몬스터가 등장합니다!"
			<< endl;

		cout << "========================================"
			<< endl;

		LogManager::getInstance().addLog(
			"레벨 10 달성!"
		);
	}

	LogManager::getInstance().addLog(to_string(amount) + " EXP 획득(현재: " + to_string(exp) + "/100)");

	if (exp >= 100) {
		level++;
		exp -= 100;
		maxHP += 20;
		attackPower += 5;
		currentHP = maxHP;
		baseAtk = attackPower;
		LogManager::getInstance().addLog("LEVEL UP! 현재 레벨: " + to_string(level));
		return true;
	}
	return false;
}

void Character::gainGold(int amount) {
	gold += amount;

	LogManager::getInstance().addLog(to_string(amount) + " 골드 획득!");

}

void Character::loseGold(int amount) {
	gold -= amount;
	if (gold < 0) gold = 0;
}

void Character::showStatus() const {
	cout << "\n========================================\n"

		<< " [" << name << " 의 상태]\n"
		<< "레벨   : " << level << " (최대 10)\n"
		<< "체력  : " << currentHP << " / " << maxHP << "\n"
		<< "공격력 : " << attackPower << "\n"
		<< "방어력 : " << defense << "\n"
		<< "경험치 : " << exp << " / 100\n"
		<< "골드   : " << gold << " G\n"
		<< "========================================\n";
}

// 아이템 추가 (대암님)

void Character::addItem(Item* item)
{
	inventory.push_back(item);
}

void Character::useItem(Item* item)
{
	if (item == nullptr)return;
	if (!item->isUsable())
	{
	
		return;
	}

	item->use(this);
}