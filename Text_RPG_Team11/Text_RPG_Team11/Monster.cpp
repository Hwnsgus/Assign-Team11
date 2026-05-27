#include "Monster.h"
#include "Character.h"
#include <cstdlib>
#include <iostream>

using namespace std;

// ==========================================
// 부모 Monster 구현
// ==========================================

Monster::Monster(string name, int level) : MonsterName(name), MonsterLevel(level) {
    MonsterHp = randomstat(level * 20, level * 30);
    MonsterAtk = randomstat(level * 5, level * 10);
}

int Monster::randomstat(int min, int max) {
    return rand() % (max - min + 1) + min;
}

string Monster::getname() { return MonsterName; }
int Monster::gethp() { return MonsterHp; }
int Monster::getatk() { return MonsterAtk; }
int Monster::getlevel() { return MonsterLevel; }

void Monster::setname(string name) { this->MonsterName = name; }
void Monster::sethp(int hp) { this->MonsterHp = hp; }
void Monster::setatk(int atk) { this->MonsterAtk = atk; }
void Monster::setlevel(int level) { this->MonsterLevel = level; }

// 공통 일반 공격
void Monster::normalAttack(Character* character) {
    int damage = getatk() - character->getdef();
    if (damage <= 0) damage = 1;
    character->sethp(character->gethp() - damage);
    cout << "* [" << MonsterName << "]의 일반 공격!\n";
    cout << "  " << character->getName() << "에게 " << damage << " 데미지!\n";
}

// ==========================================
// 슬라임 - 특수기: 흡수
// 준 데미지만큼 자기 HP를 회복
// ==========================================

void Slime::specialAttack(Character* character) {
    int damage = getatk() - character->getdef();
    if (damage <= 0) damage = 1;
    character->sethp(character->gethp() - damage);

    // 준 데미지만큼 HP 회복
    MonsterHp += damage;
    cout << "* [" << MonsterName << "]의 흡수!\n";
    cout << "  " << character->getName() << "에게 " << damage << " 데미지!\n";
    cout << "  [" << MonsterName << "] HP +" << damage << " 회복!\n";
}

void Slime::attack(Character* character) {
    cout << "\n--- 몬스터 턴 ---\n";
    // 30% 확률로 특수공격
    if (rand() % 100 < 30) {
        specialAttack(character);
    }
    else {
        normalAttack(character);
    }
}

// ==========================================
// 오크 - 특수기: 강타
// 데미지 1.5배
// ==========================================

void Orc::specialAttack(Character* character) {
    int damage = (getatk() - character->getdef()) * 1.5;
    if (damage <= 0) damage = 2;
    character->sethp(character->gethp() - damage);
    cout << "* [" << MonsterName << "]의 강타!\n";
    cout << "  " << character->getName() << "에게 " << damage << " 데미지! \n";
}

void Orc::attack(Character* character) {
    cout << "\n--- 몬스터 턴 ---\n";
    // 25% 확률로 특수공격
    if (rand() % 100 < 25) {
        specialAttack(character);
    }
    else {
        normalAttack(character);
    }
}

// ==========================================
// 고블린 - 특수기: 아이템 훔치기
// 골드를 5~15 훔침
// ==========================================

void Goblin::specialAttack(Character* character) {
    int stolen = randomstat(5, 15);
    //character->loseGold(stolen); // Character에 loseGold() 추가 필요
    cout << "* [" << MonsterName << "]이(가) 골드를 훔쳤습니다!\n";
    cout << "  " << stolen << " 골드를 잃었습니다!\n";
}

void Goblin::attack(Character* character) {
    cout << "\n--- 몬스터 턴 ---\n";
    // 35% 확률로 특수공격
    if (rand() % 100 < 35) {
        specialAttack(character);
    }
    else {
        normalAttack(character);
    }
}

// ==========================================
// 스켈레톤 - 특수기: 부활
// HP 0 이하일 때 HP 100% 부활 (1회 한정)
// ==========================================

void Skeleton::specialAttack(Character* character) {

}

void Skeleton::attack(Character* character) {
    cout << "\n--- 몬스터 턴 ---\n";

    // HP가 0 이하이고 아직 부활 안 했으면
    if (!hasRevived && MonsterHp <= 0) {
        // 30% 확률로 부활
        if (rand() % 100 < 30) {
            MonsterHp = randomstat(MonsterLevel * 20, MonsterLevel * 30); // HP 100% 회복
            hasRevived = true;
            cout << "* [" << MonsterName << "]이(가) 달그락대며 부활했습니다!\n";
        }
        else {
            cout << "* [" << MonsterName << "]은(는) 뼛조각이 되었습니다...\n";
        }
        return; // 부활 턴엔 공격 안 함
    }

    normalAttack(character);
}

// ==========================================
// 늑대 - 특수기: 마구할퀴기
// 2~5회 연속으로 공격
// ==========================================

void Wolf::specialAttack(Character* character) {
    int hits = randomstat(2, 3); // 2~5회
    cout << "* [" << MonsterName << "]의 마구할퀴기! (" << hits << "회)\n";
    for (int i = 0; i < hits; i++) {
        int damage = (getatk() - character->getdef()) / 2;
        if (damage <= 0) damage = 1;
        character->sethp(character->gethp() - damage);
        cout << "  " << (i + 1) << "번째 할퀴기, " << character->getName() << "에게 " << damage << " 데미지!\n";
        if (character->gethp() <= 0) break; // 이미 죽으면 중단
    }
}

void Wolf::attack(Character* character) {
    cout << "\n--- 몬스터 턴 ---\n";
    // 30% 확률로 특수공격
    if (rand() % 100 < 30) {
        specialAttack(character);
    }
    else {
        normalAttack(character);
    }
}
