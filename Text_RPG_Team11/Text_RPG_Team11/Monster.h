#pragma once
#include <string>
#include <iostream>

class Character; // 전방 선언

class Monster {
public:
    Monster(std::string name, int level);
    virtual ~Monster() {} // 가상 소멸자 추가

    int randomstat(int min, int max);

    std::string getname();
    int gethp();
    int getatk();
    int getdef();
    int getlevel();

    void setname(std::string name);
    void sethp(int hp);
    void setatk(int atk);
    void setdef(int def);
    void setlevel(int level);

    // 팀원 코드 수정: 기존 Player* 대신 Character*로 통일하여 연동
    virtual void attack(Character* character) = 0;

protected:
    std::string Name;
    int Hp;
    int Atk;
    int Level;
};

// --- 하위 몬스터 클래스 선언들 ---
class Slime : public Monster {
public:
    Slime(std::string name, int level) : Monster(name, level) {}
    void attack(Character* player) override;
};

class Goblin : public Monster {
public:
    Goblin(std::string name, int level) : Monster(name, level) {}
    void attack(Character* player) override { /* 추후 구현 */ }
};

class Orc : public Monster {
public:
    Orc(std::string name, int level) : Monster(name, level) {}
    void attack(Character* player) override { /* 추후 구현 */ }
};