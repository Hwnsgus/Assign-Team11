#include <iostream>
#include <ctime>

#include "Character.h"
#include "Battle.h"
#include "Shop.h"

using namespace std;

int main()
{
    srand(time(NULL));

    string name;

    cout << "캐릭터 이름 입력 : ";
    cin >> name;

    Character character(name);

    Battle battle;

    Shop shop;

    bool gameRunning = true;

    cout << endl;
    cout << "[ S ] 키를 입력하면 언제든 현재 능력치를 확인할 수 있습니다." << endl;

    while (gameRunning)
    {
        battle.startBattle(character);

        if (character.isDead())
        {
            cout << endl;
            cout << "게임 오버" << endl;

            gameRunning = false;

            break;
        }

        bool fighting = true;

        while (fighting)
        {
            string choice;

            cout << endl;
            cout << "===== 다음 행동 =====" << endl;
            cout << "1. 상점 방문" << endl;
            cout << "2. 다음 전투 진행" << endl;
            cout << "0. 게임 종료" << endl;
            cout << "선택 : ";

            cin >> choice;

            // 현재 능력치 확인
            if (choice == "s" || choice == "S")
            {
                character.printStatus();

                cout << endl;
                cout << "0. 이전 메뉴로 돌아가기" << endl;

                string backChoice;

                cin >> backChoice;

                continue;
            }

            // 상점
            else if (choice == "1")
            {
                shop.openShop();

                fighting = false;
            }

            // 다음 전투
            else if (choice == "2")
            {
                cout << "다음 전투로 이동합니다!" << endl;

                fighting = false;
            }

            // 게임 종료
            else if (choice == "0")
            {
                gameRunning = false;

                fighting = false;
            }

            else
            {
                cout << "잘못된 입력입니다." << endl;
            }
        }
    }

    return 0;
}