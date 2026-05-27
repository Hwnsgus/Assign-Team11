#include <iostream>
#include <conio.h>
#include "Character.h"
#include "Monster.h"
#include "LogManager.h" // 로그 시스템 결합
//#include <windows.h>


using namespace std;

// C키 전용 설정 및 로그 확인 메뉴
void showMenu(Character& player) {
    while (true) {
        system("cls");
        cout << "========================================\n";
        cout << "             [ 설정 / 메뉴 ]            \n";
        cout << "========================================\n";
        cout << " 1. 캐릭터 상세 상태 확인\n";
        cout << " 2. 게임 로그 확인 (⭐)\n";
        cout << " 3. 처치한 몬스터 목록 보기 (⭐)\n";
        cout << " 0. 창 닫기 (게임으로 돌아가기)\n";
        cout << "========================================\n";
        cout << "선택: ";

        char choice = _getch();

        if (choice == '1') {
            system("cls"); player.showStatus(); _getch();
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

int main() {
    //SetConsoleOutputCP(65001);
    //SetConsoleCP(65001);
    srand(static_cast<unsigned int>(time(NULL)));
    

    //캐릭터 생성
    string name;
    cout << "캐릭터 이름을 입력하세요: ";
    cin >> name;
    Character player(name);

    Monster* currentMonster = new Slime("초록슬라임", 1);
    LogManager::getInstance().addLog("[" + currentMonster->getname() + "]이(가) 스폰되었습니다.");

    while (true) {
        system("cls");
        cout << "========================================\n";
        cout << "         TEXT RPG 메인 월드 화면         \n";
        cout << "========================================\n";
        cout << " [1] 던전 입장 (전투 시뮬레이션)\n";
        cout << " [C] 설정 및 로그 메뉴 열기\n";
        cout << " [Q] 게임 종료\n";
        cout << "========================================\n";

        char input = _getch();

        if (input == '1') {
            system("cls");
            cout << "=== 던전에 진입했습니다! ===\n";

            // 고호진 님 영역: 캐릭터 레벨에 비례한 랜덤 몬스터 스폰 로직이 들어갈 곳
            Monster* currentMonster = new Slime("초록슬라임", 1);
            LogManager::getInstance().addLog("[" + currentMonster->getname() + "]이(가) 나타났습니다!");

            cout << "=== 전투 시작: " << currentMonster->getname() << " ===\n";

            // ------------------------------------------------------------
            // TODO: 장정현 님 (턴제 전투 로직 구현 영역)
            // ------------------------------------------------------------
            // 예시 가이드:
            // while(player.gethp() > 0 && currentMonster->gethp() > 0) {
            //     cout << "1. 공격 | 2. 아이템 사용 : ";
            //     (플레이어 행동 처리)
            //     if(currentMonster->gethp() <= 0) break;
            //     currentMonster->attack(&player); (고호진님 함수 호출)
            // }

            // 임시 가상 전투 수행 (테스트용)


            currentMonster->attack(&player);

            cout << "\n[전투 종료 테스트] 플레이어가 몬스터를 처치했습니다!\n";

            // ------------------------------------------------------------
            // TODO: 강대암 님 (아이템 드롭 연동 영역)
            // ------------------------------------------------------------
            // int dropChance = rand() % 100;
            // if(dropChance < 30) {
            //     // Item* potion = new Potion();
            //     // player.addItem(potion);
            //     LogManager::getInstance().addLog("전투 보상으로 아이템을 획득했습니다!");
            // }

            // ------------------------------------------------------------
            // 보상 및 성장 연동 영역 (지현준 님 gainExp 로직과 결합됨)
            // ------------------------------------------------------------

            
            LogManager::getInstance().recordKill(currentMonster->getname());


            player.gainGold(20);
            player.gainExp(50);

            delete currentMonster; // 메모리 해제 필수
            cout << "\n전투가 끝났습니다. 아무 키나 누르세요.";
            _getch();
        }
        else if (input == 'c' || input == 'C') {
            showMenu(player);
        }
        else if (input == 'q' || input == 'Q') {
            cout << "게임을 마칩니다.\n";
            break;
        }
    }
    return 0;
}