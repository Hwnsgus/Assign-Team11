// ===========================
// Shop.cpp
// ===========================
#include "Shop.h"

#include <iostream>

using namespace std;

bool Shop::openShop(Character* player)
{
	int choice;

	while (true)
	{
		cout << "\n========== 상점 ==========\n";
		cout << "1. 체력 회복 (20 Gold)\n";
		cout << "2. 나가기\n";
		cout << "==========================\n";

		cout << "선택 : ";
		cin >> choice;
		switch (choice)
		{
		case 1:
		{
			if (player->getgold() >= 20)
			{
				player->sethp(200);

				cout << "체력이 회복되었습니다!\n";
			}
			else
			{
				cout << "Gold가 부족합니다.\n";
			}
			break;
		}
		case 2:
		{
			cout << "상점을 나갑니다.\n";

			return true;
		}
		default:
		{
			cout << "잘못 입력했습니다.\n";
			break;
		}
		}

	}
}