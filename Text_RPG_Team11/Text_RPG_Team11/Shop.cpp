// ===========================
// Shop.cpp
// 최종 상점 시스템
// ===========================
#include <iostream>
#include <conio.h>

#include "Shop.h"

#include "Character.h"

#include "HealthPotion.h"
#include "AttackBoost.h"

#include "Item.h"

using namespace std;

// ===========================
// 상점 열기
// ===========================
void Shop::openShop(Character* player)
{
	while (true)
	{
		system("cls");

		cout << "========================================" << endl;
		cout << "               [ 상점 ]                " << endl;
		cout << "========================================" << endl;

		cout << "보유 골드 : "
			<< player->getgold()
			<< " G"
			<< endl;

		cout << "========================================" << endl;

		cout << "[1] 체력 포션 구매 (15 G)" << endl;
		cout << "[2] 공격력 증가 알약 구매 (25 G)" << endl;
		cout << "[3] 고급 체력 포션 구매 (30 G)" << endl;
		cout << "[4] 아이템 판매" << endl;
		cout << "[0] 상점 나가기" << endl;

		cout << "========================================" << endl;
		cout << "선택 : ";

		char input;

		input = _getch();

		// ===========================
		// 체력 포션 구매
		// ===========================
		if (input == '1')
		{
			if (player->getgold() >= 15)
			{
				player->gainGold(-15);

				player->addItem(
					new HealthPotion()
				);

				cout << endl;
				cout << "체력 포션 구매 완료!"
					<< endl;

				cout << "인벤토리에 즉시 추가되었습니다."
					<< endl;
			}

			else
			{
				cout << endl;
				cout << "골드가 부족합니다!"
					<< endl;
			}

			_getch();
		}

		// ===========================
		// 공격력 증가 알약 구매
		// ===========================
		else if (input == '2')
		{
			if (player->getgold() >= 25)
			{
				player->gainGold(-25);

				player->addItem(
					new AttackBoost()
				);

				cout << endl;
				cout << "공격력 증가 알약 구매 완료!"
					<< endl;

				cout << "인벤토리에 즉시 추가되었습니다."
					<< endl;
			}

			else
			{
				cout << endl;
				cout << "골드가 부족합니다!"
					<< endl;
			}

			_getch();
		}

		// ===========================
		// 고급 체력 포션
		// ===========================
		else if (input == '3')
		{
			if (player->getgold() >= 30)
			{
				player->gainGold(-30);

				player->addItem(
					new HealthPotion()
				);

				player->addItem(
					new HealthPotion()
				);

				cout << endl;
				cout << "고급 체력 포션 세트 구매 완료!"
					<< endl;

				cout << "체력 포션 2개 지급!"
					<< endl;
			}

			else
			{
				cout << endl;
				cout << "골드가 부족합니다!"
					<< endl;
			}

			_getch();
		}

		// ===========================
		// 아이템 판매
		// 판매 가격 = 원가의 60%
		// ===========================
		else if (input == '4')
		{
			system("cls");

			cout << "========== 아이템 판매 =========="
				<< endl;

			player->showInventory();

			cout << endl;
			cout << "판매할 번호 입력 (0 : 취소) : ";

			int sellChoice;

			cin >> sellChoice;

			if (sellChoice == 0)
			{
				continue;
			}

			Item* sellItem;

			sellItem = player->getItem(
				sellChoice - 1
			);

			if (sellItem != nullptr)
			{
				

				// ===========================
				// 판매 가격 계산
				// ===========================
				int sellPrice = sellItem->getItemPrice() * 0.6;

				player->gainGold(sellPrice);

				cout << endl;

				cout << sellItem->getItemName()
					<< " 판매 완료!"
					<< endl;

				cout << sellPrice
					<< " G 획득!"
					<< endl;

				cout << "인벤토리에서 제거되었습니다."
					<< endl;

				delete sellItem;
			}

			else
			{
				cout << endl;
				cout << "잘못된 선택입니다!"
					<< endl;
			}

			_getch();
		}

		// ===========================
		// 상점 종료
		// ===========================
		else if (input == '0')
		{
			cout << endl;
			cout << "상점을 나갑니다!"
				<< endl;

			_getch();

			break;
		}
	}
}