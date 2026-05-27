#include <iostream>
#include <string>
#include <conio.h>

#include "Game.h"

#include "Character.h"
#include "Monster.h"

#include "Battle.h"
#include "Shop.h"

#include "LogManager.h"
#include "BossMonster.h"

using namespace std;

// ===========================
// 생성자
// ===========================
Game::Game()
	: player(nullptr)
{
}

// ===========================
// 소멸자
// ===========================
Game::~Game()
{
	if (player)
	{
		delete player;
	}
}

// ===========================
// 게임 초기화
// ===========================
void Game::initGame()
{
	string name;

	system("cls");

	cout << "========================================"
		<< endl;

	cout << "          팀 11 프로젝트 TEXT RPG       "
		<< endl;

	cout << "========================================"
		<< endl;

	cout << "캐릭터 이름을 입력하세요 : ";

	cin >> name;

	player = new Character(name);

	cout << endl;

	cout << "캐릭터 생성 완료!"	<< endl;
	
}

// ===========================
// 메뉴 출력
// ===========================
void Game::showMenu()
{
	while (true)
	{
		system("cls");

		cout << "========================================"
			<< endl;

		cout << "             [ 설정 / 메뉴 ]            "
			<< endl;

		cout << "========================================"
			<< endl;

		cout << " 1. 캐릭터 상태 확인"
			<< endl;

		cout << " 2. 게임 로그 확인"
			<< endl;

		cout << " 3. 처치 몬스터 통계"
			<< endl;

		cout << " 4. 인벤토리 확인"
			<< endl;

		cout << " 0. 돌아가기"
			<< endl;

		cout << "========================================"
			<< endl;

		cout << "선택 : ";

		char choice;

		choice = _getch();

		// ===========================
		// 상태창
		// ===========================
		if (choice == '1')
		{
			system("cls");

			player->showStatus();

			system("pause");
		}

		// ===========================
		// 로그
		// ===========================
		else if (choice == '2')
		{
			system("cls");

			LogManager::getInstance().showLogs();

			system("pause");
		}

		// ===========================
		// 처치 통계
		// ===========================
		else if (choice == '3')
		{
			system("cls");

			LogManager::getInstance().showKillCounts();

			system("pause");
		}

		// ===========================
		// 인벤토리
		// ===========================
		else if (choice == '4')
		{
			system("cls");

			player->showInventory();

			system("pause");
		}

		// ===========================
		// 종료
		// ===========================
		else if (choice == '0')
		{
			break;
		}
	}
}

// ===========================
// 게임 메인 루프
// ===========================
void Game::run()
{
	// 캐릭터 생성
	initGame();

	// ===========================
	// 메인 게임 루프
	// ===========================
	while (true)
	{
		// ===========================
		// 플레이어 사망
		// ===========================
		if (player->gethp() <= 0)
		{
			system("cls");

			cout << endl;

			cout << "========================================"
				<< endl;

			cout << "              GAME OVER"
				<< endl;

			cout << "========================================"
				<< endl;

			cout << player->getName()
				<< " 이(가) 사망했습니다..."
				<< endl;

			cout << endl;

			system("pause");

			break;
		}

		system("cls");

		// ===========================
		// 메인 화면
		// ===========================
		cout << "========================================"
			<< endl;

		cout << "            TEXT RPG 메인 월드          "
			<< endl;

		cout << "========================================"
			<< endl;

		cout << "플레이어 : "
			<< player->getName()
			<< endl;

		cout << "현재 HP : "
			<< player->gethp()
			<< endl;

		cout << "현재 골드 : "
			<< player->getgold()
			<< " G"
			<< endl;

		cout << "========================================"
			<< endl;

		cout << "[1] 던전 입장"
			<< endl;

		cout << "[C] 상태창 / 로그 메뉴"
			<< endl;

		cout << "[Q] 게임 종료"
			<< endl;

		cout << "========================================"
			<< endl;

		cout << "선택 : ";

		char input;

		input = _getch();

		// ===========================
		// 던전 입장
		// ===========================
		if (input == '1')
		{
			system("cls");

			Monster* currentMonster = nullptr;

			// ===========================
			// 랜덤 몬스터 생성
			// ===========================

			// 몬스터 생성 부분 수정

			// ==========================================
			// 레벨 10 이상이면 보스 등장
			// ==========================================
			if (player->getlevel() >= 10)
			{
				system("cls");

				cout << endl;

				cout << "========================================"
					<< endl;

				cout << "          !!! WARNING !!!"
					<< endl;

				cout << "========================================"
					<< endl;

				cout << " 엄청난 기운이 느껴진다..."
					<< endl;

				cout << " 마왕이 등장했습니다!"
					<< endl;

				cout << "========================================"
					<< endl;

				system("pause");

				currentMonster =
					new BossMonster(
						"마왕 벨제브부",
						player->getlevel()
					);
			}

			// ==========================================
			// 일반 몬스터
			// ==========================================
			else
			{
				int randomMonster;

				randomMonster = rand() % 5;

				switch (randomMonster)
				{
				case 0:
					currentMonster =
						new Slime(
							"야생 슬라임",
							player->getlevel()
						);
					break;

				case 1:
					currentMonster =
						new Goblin(
							"야생 고블린",
							player->getlevel()
						);
					break;

				case 2:
					currentMonster =
						new Orc(
							"야생 오크",
							player->getlevel()
						);
					break;

				case 3:
					currentMonster =
						new Skeleton(
							"야생 스켈레톤",
							player->getlevel()
						);
					break;

				case 4:
					currentMonster =
						new Wolf(
							"야생 늑대",
							player->getlevel()
						);
					break;
				}
			}


			// ===========================
			// 전투 시작
			// ===========================
			Battle battleSystem;

			battleSystem.startBattle(
				*player,
				currentMonster
			);

			// ===========================
			// 몬스터 메모리 해제
			// ===========================
			delete currentMonster;

			// ===========================
			// 플레이어 생존 시
			// 상점 입장 여부 질문
			// ===========================
			if (player->gethp() > 0)
			{
				char shopChoice;

				cout << endl;

				cout << "========================================"
					<< endl;

				cout << "상점에 입장하시겠습니까?"
					<< endl;

				cout << "========================================"
					<< endl;

				cout << "[Y] 상점 입장"
					<< endl;

				cout << "[N] 다음 전투 진행"
					<< endl;

				cout << "========================================"
					<< endl;

				cout << "선택 : ";

				shopChoice = _getch();

				// ===========================
				// 상점 입장
				// ===========================
				if (shopChoice == 'Y'
					|| shopChoice == 'y')
				{
					Shop::openShop(player);

					cout << endl;

					cout << "상점 이용 완료!"
						<< endl;

					cout << "전투를 다시 시작합니다!"
						<< endl;

				}

				// ===========================
				// 상점 스킵
				// ===========================
				else
				{
					cout << endl;

					cout << "상점을 스킵했습니다!"
						<< endl;

					cout << "다음 전투를 진행합니다!"
						<< endl;

				}
			}
		}

		// ===========================
		// 메뉴
		// ===========================
		else if (input == 'c'
			|| input == 'C')
		{
			showMenu();
		}

		// ===========================
		// 게임 종료
		// ===========================
		else if (input == 'q'
			|| input == 'Q')
		{
			cout << endl;

			cout << "게임을 종료합니다."
				<< endl;

			system("pause");

			break;
		}
	}
}