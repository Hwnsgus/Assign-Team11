#include "Character.h"

Character::Character(string n)
{
    name = n;

    // 요구사항 기본 스탯
    level = 1;
    hp = 200;
    maxHp = 200;
    power = 30;
    exp = 0;

    // 추가 시스템
    defense = 0;
    gold = 0;
}

int Character::attack()
{
    int damage = power;

    cout << endl;
    cout << name << "의 베어 가르기!" << endl;

    return damage;
}

void Character::takeDamage(int damage)
{
    damage -= defense;

    if (damage < 0)
    {
        damage = 0;
    }

    hp -= damage;

    if (hp < 0)
    {
        hp = 0;
    }

    cout << name << "가 " << damage << "의 피해를 입었습니다." << endl;
    cout << name << " HP : " << hp << " / " << maxHp << endl;
}

bool Character::isDead()
{
    return hp <= 0;
}

void Character::levelUp()
{
    // 최대 레벨 제한
    if (level >= 10)
    {
        cout << "이미 최대 레벨입니다." << endl;

        return;
    }

    level++;

    // 레벨 비례 상승
    maxHp += level * 20;
    power += level * 5;

    // 최대 체력까지 회복
    hp = maxHp;

    cout << endl;
    cout << "레벨 업!" << endl;
    cout << "현재 레벨 : " << level << endl;
    cout << "최대 HP 증가! 현재 HP : " << hp << " / " << maxHp << endl;
    cout << "공격력 증가! 현재 공격력 : " << power << endl;
}

void Character::addExp(int amount)
{
    // 최대 레벨이면 경험치 획득 불가
    if (level >= 10)
    {
        cout << "최대 레벨입니다." << endl;

        return;
    }

    exp += amount;

    cout << "경험치 +" << amount << endl;

    // 레벨업 필요 경험치 100 고정
    if (exp >= 100)
    {
        exp -= 100;

        levelUp();
    }
}

void Character::addGold(int amount)
{
    gold += amount;

    cout << amount << " 골드 획득!" << endl;
}

void Character::printStatus()
{
    cout << endl;

    cout << "===== 현재 능력치 =====" << endl;
    cout << "이름 : " << name << "    레벨 : " << level << endl;
    cout << "HP : " << hp << " / " << maxHp << "    공격력 : " << power << "    방어력 : " << defense << endl;
    cout << "EXP : " << exp << " / 100    GOLD : " << gold << endl;
    cout << "======================" << endl;
}