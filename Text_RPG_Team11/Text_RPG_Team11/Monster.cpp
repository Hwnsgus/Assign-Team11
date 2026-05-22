#include "Monster.h"

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

// 메인에 시작할떄 srand(time(NULL)); 넣기

class Monster {
public:
	Monster(string name, int level) : Name(name), Level(level)
	{
		//Hp = (rand() % (level * 30 - level * 20 + 1)) + level * 20;
		//Atk = (rand() % (level * 10 - level * 5 + 1)) + level * 5;

		Hp = randomstat(level * 20, level * 30);
		Atk = randomstat(level * 5, level * 10);

	}

	int randomstat(int min, int max)
	{
		return rand() % (max - min + 1) + min;
	}

	string getname()
	{
		return Name;
	}

	int gethp()
	{
		return Hp;
	}

	int getatk()
	{
		return Atk;
	}

	int getlevel()
	{
		return Level;
	}


	void setname(string name)
	{
		this->Name = name;
	}

	void sethp(int hp)
	{
		this->Hp = hp;
	}

	void setatk(int atk)
	{
		this->Atk = atk;
	}

	void setlevel(int level)
	{
		this->Level = level;
	}

	virtual void attack(Player* player) = 0;


protected:
	string Name;
	int Hp;
	int Atk;
	int Level;

};

class Slime : public Monster {
public:
	Slime(string name, int level) : Monster(name, level) {}

	void attack(Player* player) override;
};

void Slime::attack(Player* player) {

	int damage;
	damage = getatk() - player->getdef();

	if (getatk() >= player->getdef())
	{
		player->sethp(player->gethp() - (getatk() - player->getdef()));
	}
	else
	{
		player->sethp(player->gethp() - 1);
	}

	if (damage <= 0)
	{
		damage = 1;
	}

	cout << "\n--- 몬스터 턴 ---\n";
	cout << "* 점액공격! \n";
	cout << "전사?에게 " << damage << " 데미지! \n";
	if (getatk() >= player->getdef())
	{
		cout << "전사 HP : " << player->gethp() + (getatk() - player->getdef()) << "->" << player->gethp() << endl;
	}
	else
	{
		cout << "전사 HP : " << player->gethp() + 1 << "->" << player->gethp() << endl;
	}


	if (player->gethp() <= 0)
	{
		cout << "(사망)";
	}
}



class Goblin : public Monster {
public:
	Goblin(string name, int level) : Monster(name, level) {}
};

class Orc : public Monster {
public:
	Orc(string name, int level) : Monster(name, level) {}
};

class Skeleton : public Monster {
public:
	Skeleton(string name, int level) : Monster(name, level) {}
};

class Zombie : public Monster {
public:
	Zombie(string name, int level) : Monster(name, level) {}
};