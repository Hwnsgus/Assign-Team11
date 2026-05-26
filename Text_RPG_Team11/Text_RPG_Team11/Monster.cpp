#include "Monster.h"
#include "Character.h" // 캐릭터의 gethp(), sethp() 등을 쓰기 위해 포함
#include <cstdlib>

using namespace std;

// 부모 몬스터 생성자 구현
Monster::Monster(string name, int level) : Name(name), Level(level) {
    Hp = randomstat(level * 20, level * 30);
    Atk = randomstat(level * 5, level * 10);
}

int Monster::randomstat(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// 몬스터 멤버 함수들 실제 구현
string Monster::getname() { return Name; }
int Monster::gethp() { return Hp; }
int Monster::getatk() { return Atk; }
int Monster::getlevel() { return Level; }

void Monster::setname(string name) { this->Name = name; }
void Monster::sethp(int hp) { this->Hp = hp; }
void Monster::setatk(int atk) { this->Atk = atk; }
void Monster::setlevel(int level) { this->Level = level; }


// ==========================================
// 고호진 님 전용 영역: 각 몬스터의 공격 방식 구현
// ==========================================

// 1. 슬라임의 공격 로직 (Character 방어력 적용 완동 완료)
void Slime::attack(Character* character) {
    int damage = getatk() - character->getdef();
    if (damage <= 0) damage = 1; // 최소 데미지 보정

    // 캐릭터 체력 차감
    character->sethp(character->gethp() - damage);

    cout << "\n--- 몬스터 턴 ---\n";
    cout << "* [" << Name << "]의 찐득한 점액 공격! \n";
    cout << "▶ " << character->getName() << "에게 " << damage << " 데미지! \n";
}

// 2. 고블린의 공격 로직 
void Goblin::attack(Character* character) {
    int damage = getatk() - character->getdef();
    if (damage <= 0) damage = 1;

    character->sethp(character->gethp() - damage);

    cout << "\n--- 몬스터 턴 ---\n";
    cout << "* [" << Name << "]이(가) 날카로운 둔기를 휘둘렀습니다! \n";
    cout << "▶ " << character->getName() << "에게 " << damage << " 데미지! \n";
}