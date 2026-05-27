#include <iostream>
#include <string>
#include <conio.h>
#include "Game.h"
#include "Character.h"
#include "Monster.h"
#include "LogManager.h"
#include "Battle.h"
using namespace std;

Game::Game() : player(nullptr){}

Game::~Game() {
	if (player) delete player;
}

void Game::initGame() {
    string name;
    cout << "========================================\n";
    cout << "          팀 11 프로젝트 TEXT RPG        \n";
    cout << "========================================\n";
    cout << "캐릭터 이름을 입력하세요: ";
    cin >> name;
    player = new Character(name);
}

void Game::showMenu() {
    while (true) {
        system("cls");
        cout << "========================================\n";
        cout << "             [ 설정 / 메뉴 ]            \n";
        cout << "========================================\n";
        cout << " 1. 캐릭터 상세 상태 확인\n";
        cout << " 2. 게임 로그 확인 \n";
        cout << " 3. 처치한 몬스터 목록 보기 \n";
        cout << " 0. 창 닫기 (게임으로 돌아가기)\n";
        cout << "========================================\n";
        cout << "선택: ";

        char choice = _getch();

        if (choice == '1') {
            system("cls"); player->showStatus(); _getch();
        }
        else if (choice == '2') {
            system("cls"); LogManager::getInstance().showLogs(); _getch();
        }
        else if (choice == '3') {
            system("cls"); LogManager::getInstance().showKillCounts(); _getch();
        }
        else if (choice == '0') {
            break;
        }
    }
}

void Game::run() {
    initGame(); // 캐릭터 생성 실행

    while (true) {
        // 플레이어 사망 시 게임 전면 종료
        if (player->gethp() <= 0) {
            system("cls");
            cout << "\n [ GAME OVER ] \n메인 화면으로 돌아갑니다.\n";
            break;
        }

        system("cls");
        cout << "========================================\n";
        cout << "         TEXT RPG 메인 월드 (마을)       \n";
        cout << "========================================\n";
        cout << " 플레이어: " << player->getName() << " (HP: " << player->gethp() << ")\n";
        cout << "========================================\n";
        cout << " [1] 던전 입장 (턴제 전투 돌입)\n";
        cout << " [C] 설정 및 로그 메뉴 열기\n";
        cout << " [Q] 게임 완전히 종료\n";
        cout << "========================================\n";
        cout << "선택: ";

        char input = _getch();

        if (input == '1') {
            system("cls");

            // 1. 랜덤 몬스터 동적 스폰 (고호진님 스폰 데이터 연동)
            int random = rand() % 5;
            int monsterLevel = player->getlevel();
            Monster* currentMonster = nullptr;

            if (random == 0)      currentMonster = new Slime("야생 슬라임", monsterLevel);
            else if (random == 1) currentMonster = new Orc("오크 전사", monsterLevel);
            else if (random == 2) currentMonster = new Goblin("고블린", monsterLevel);
            else if (random == 3) currentMonster = new Skeleton("스켈레톤", monsterLevel);
            else if (random == 4) currentMonster = new Wolf("야생 늑대", monsterLevel);

            // 2. 팀원이 추가해 준 Battle 객체 가동 및 위임!
            Battle battleSystem;
            battleSystem.startBattle(*player, currentMonster);

            // 3. 전투 종료 후 메모리 해제
            delete currentMonster;
        }
        else if (input == 'c' || input == 'C') {
            showMenu(); // 설정 메뉴 진입
        }
        else if (input == 'q' || input == 'Q') {
            cout << "\n게임을 종료합니다.\n";
            break;
        }
    }
}
