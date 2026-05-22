#pragma once
#include <string>
#include <vector>
#include <map>
using namespace std;
class Monster; // 몬스터 클래스 전방 선언
class Item;

class Character {
private:
    string name;
    int level;
    int currentHP;
    int maxHP;
    int attackPower;
    int defense;
    int exp;
    int gold;

    // 게임 로그와 몬스터 처치 기록을 관리하기 위한 컨테이너
    vector<Item*> inventory;

public:
    Character(std::string charName);

    void takeDamage(int damage);
    void gainExp(int amount);
    void gainGold(int amount);
    void showStatus() const;

    // 팀원들이 연동할 Getters / Setters
    std::string getName() const { return name; }
    int gethp() const { return currentHP; }
    int getdef() const { return defense; }
    int getatk() const { return attackPower; }

    void sethp(int hp);


    // [아이템 담당 팀원 연동용 인터페이스 가이드]
    void addItem(Item* item);
    void useItem(Item* item);
};