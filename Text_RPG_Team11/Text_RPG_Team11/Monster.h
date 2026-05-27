#pragma once
#include <string>
#include <iostream>

class Character; // 전방 선언 (Character 헤더 중복 참조 방지)

// 모든 몬스터의 부모가 되는 기본 클래스
class Monster {
public:
    Monster(std::string name, int level);
    virtual ~Monster() {}

    int randomstat(int min, int max);

    // Getters
    std::string getname();
    int gethp();
    int getatk();
    int getlevel();

    // Setters
    void setname(std::string name);
    void sethp(int hp);
    void setatk(int atk);
    void setlevel(int level);

    // 일반 공격 (공통)
    void normalAttack(Character* character);

    // 특수 공격 (각 몬스터가 각자 구현)
    virtual void specialAttack(Character* character) = 0;

    // 턴마다 일반/특수 중 하나를 골라 공격
    virtual void attack(Character* character) = 0;

protected:
    std::string MonsterName;
    int MonsterHp;
    int MonsterAtk;
    int MonsterLevel;
};

// ==========================================
// 하위 몬스터 클래스 선언 영역
// ==========================================

// 슬라임 - 특수기: 흡수 (준 데미지만큼 자기 HP 회복)
class Slime : public Monster {
public:
    Slime(std::string name, int level) : Monster(name, level) {}
    void specialAttack(Character* character) override;
    void attack(Character* character) override;
};

// 오크 - 특수기: 강타 (데미지 1.5배)
class Orc : public Monster {
public:
    Orc(std::string name, int level) : Monster(name, level) {}
    void specialAttack(Character* character) override;
    void attack(Character* character) override;
};

// 고블린 - 특수기: 아이템 훔치기 (골드 훔침)
class Goblin : public Monster {
public:
    Goblin(std::string name, int level) : Monster(name, level) {}
    void specialAttack(Character* character) override;
    void attack(Character* character) override;
};

// 스켈레톤 - 특수기: 부활 (HP 100% 회복, 1회 제한)
class Skeleton : public Monster {
public:
    Skeleton(std::string name, int level) : Monster(name, level), hasRevived(false) {}
    void specialAttack(Character* character) override;
    void attack(Character* character) override;
private:
    bool hasRevived; // 부활은 1번만 가능
};

// 늑대 - 특수기: 연속공격 (2~3회 연속 공격)
class Wolf : public Monster {
public:
    Wolf(std::string name, int level) : Monster(name, level) {}
    void specialAttack(Character* character) override;
    void attack(Character* character) override;
};
