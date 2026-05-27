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
	defense = 30;
	exp = 0;
	gold = 0;


	LogManager::getInstance().addLog("ĳ���� [" + name + "] ���� �Ϸ�! (Lv.1, HP :200, ATK :30");
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

void Character::addItem(Item* item)
{
	inventory.push_back(item);
	LogManager::getInstance().addLog(item->getItemName()+"을(를) 획득했습니다!");
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
		cout << "[" << i+1 << "]" << inventory[i]->getItemName() <<"("<<inventory[i]->ItemEffect()<<")"<<endl;
	}
}

Item* Character::getItem(int index)
{
	if (index >= 0 && index < inventory.size())
	{
		Item* selected = inventory[index];
		inventory.erase(inventory.begin()+index);
		return selected;
	}
	return nullptr;
}

void Character::takeDamage(int damage) {
	currentHP -= damage;
	if (currentHP < 0) currentHP = 0;
}

void Character::gainExp(int amount) {
	exp += amount;

	LogManager::getInstance().addLog(to_string(amount) + " EXP ȹ�� (����: " + to_string(exp) + "/100)");

	// ������ ������ Ŭ������ ó���ϰ����� �ӽ� ������

	if (exp >= 100) {
		level++;
		exp -= 100;
		maxHP += 20;
		attackPower += 5;
		currentHP = maxHP;

		LogManager::getInstance().addLog("�� LEVEL UP! ���� ����: " + to_string(level));

	}
}

void Character::gainGold(int amount) {
	gold += amount;

	LogManager::getInstance().addLog(to_string(amount) + " ��� ȹ��!");

}


void Character::showStatus() const {
	cout << "\n========================================\n"

		<< " [" << name << " �� ����]\n"
		<< " ����   : " << level << " (�ִ� 10)\n"
		<< " ü��   : " << currentHP << " / " << maxHP << "\n"
		<< " ���ݷ� : " << attackPower << "\n"
		<< " ����ġ : " << exp << " / 100\n"
		<< " ���   : " << gold << " G\n"
		<< "========================================\n";
}

// ������ ��� ���� �Լ� (����� Ʋ�� ����)
void Character::useItem(Item* item) { /* ������ ����ڰ� ���� ���� */ }

