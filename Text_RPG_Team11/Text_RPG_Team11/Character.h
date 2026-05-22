#pragma once
#include <string>
#include <vector>
using namespace std;

class Monster;
class Item;

class Character {
    
private:
    std::string name;
    int currentHP;
    int maxHP;
    int attackPower;
    int experience;
    int level; //  
    vector<Item*> inventory; 
    int gold;

public:
    Character(string charName);

    void takeDamage(int damage);
    void attack(Monster* target);
    void useItem(Item* item);
    void gainExperience(int amount);
    void gainGold(int amount);
    string getStatus() const; 
    
    void addItem(Item* item);
    void removeItem(Item* item);

    // Getters
    string getName() const { return name; }
    int getCurrentHP() const { return currentHP; }
    int getAttackPower() const { return attackPower; }
};