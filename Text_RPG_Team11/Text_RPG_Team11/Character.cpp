#include "Character.h"
#include <sstream>
#include<iostream>
using namespace std;

Character::Character(std::string charName) : name(charName), level() {
    maxHP = 200;
    currentHP = 200;
    attackPower = 30;
    experience = 0;
    gold = 0;
    level = new level();
    level = Level(1);
}

void Character::takeDamage(int damage) {
    currentHP -= damage;
    if (currentHP < 0) currentHP = 0;
}

void Character::gainExperience(int amount) {
    experience += amount;
  
    while (level.checkLevelUp(experience) && level.getCurrentLevel() < level.getMaxLevel()) {
        experience -= 100; // expPerLevel
        level.levelUp();
        
        // 보너스 스탯 적용
        maxHP = 200 + level.calculateHPBonus() - 20; // 1렙 기준 기본 200 유지 보정
        attackPower = 30 + level.calculateAttackBonus() - 5; 
        currentHP = maxHP; // 체력 회복
    }
}

void Character::gainGold(int amount) {
    gold += amount;
}

string Character::getStatus() const {
    stringstream ss;
    ss << "========================================\n"
       << " [" << name << " 의 상태]\n"
       << " 레벨   : " << level.getCurrentLevel() << " / " << level.getMaxLevel() << "\n"
       << " 체력   : " << currentHP << " / " << maxHP << "\n"
       << " 공격력 : " << attackPower << "\n"
       << " 경험치 : " << experience << " / 100\n"
       << " 골드   : " << gold << " G\n"
       << "========================================\n";
    return ss.str();
}

void Character::attack(Monster* target) { /* 전투 로직 구현부 */ }
void Character::useItem(Item* item) { /* 아이템 사용 로직 구현부 */ }
void Character::addItem(Item* item) { inventory.push_back(item); }
void Character::removeItem(Item* item) { /* 인벤토리 삭제 로직 */ }