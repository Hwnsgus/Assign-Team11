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

    // 순수 가상 함수: 하위 몬스터들은 이 공격 함수를 무조건 각자 구현해야 함
    virtual void attack(Character* character) = 0;

protected:
    std::string Name;
    int Hp;
    int Atk;
    int Level;
};

// ==========================================
// 하위 몬스터 클래스 선언 영역 (고호진 님 추가 자리)
// ==========================================

class Slime : public Monster {
public:
    Slime(std::string name, int level) : Monster(name, level) {}
    void attack(Character* character) override; // 설계도에는 선언만!
};

class Goblin : public Monster {
public:
    Goblin(std::string name, int level) : Monster(name, level) {}
    void attack(Character* character) override;
};