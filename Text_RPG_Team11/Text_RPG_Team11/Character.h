#pragma once
#include <string>
#include <vector>
#include <map>
using namespace std;
class Monster; // ���� Ŭ���� ���� ����
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

    // ���� �α׿� ���� óġ ����� �����ϱ� ���� �����̳�
    vector<Item*> inventory;

public:
    Character(std::string charName);

    void takeDamage(int damage);
    void gainExp(int amount);
    void gainGold(int amount);
    void showStatus() const;

    // �������� ������ Getters / Setters
    std::string getName() const { return name; }
    int gethp() const { return currentHP; }
    int getdef() const { return defense; }
    int getatk() const { return attackPower; }

    void sethp(int hp);
    void setAtk(int atk);


    // [������ ��� ���� ������ �������̽� ���̵�]
    void addItem(Item* item);
    void useItem(Item* item);
    void showInventory();
    Item* getItem(int index);

};


