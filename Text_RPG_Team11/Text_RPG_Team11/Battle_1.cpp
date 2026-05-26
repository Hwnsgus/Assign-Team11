#include "Battle.h"

void Battle::startBattle(Character& character)
{
    Monster monster;

    bool battleRunning = true;

    while (battleRunning)
    {
        cout << endl;
        cout << "===== 전투 시작 =====" << endl;

        int damage = character.attack();

        monster.takeDamage(damage);

        if (monster.isDead())
        {
            cout << endl;
            cout << "몬스터 처치 성공!" << endl;

            character.addExp(50);

            int rewardGold = (rand() % 11) + 10;

            character.addGold(rewardGold);

            int itemChance = rand() % 100;

            if (itemChance < 30)
            {
                cout << "아이템 획득!" << endl;
            }
            else
            {
                cout << "아이템 획득 실패!" << endl;
            }

            battleRunning = false;

            break;
        }

        monster.attack();

        character.takeDamage(monster.getPower());

        if (character.isDead())
        {
            cout << endl;
            cout << "Character가 쓰러졌습니다..." << endl;

            battleRunning = false;
        }
    }
}