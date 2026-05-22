#include <iostream>
#include <conio.h>
#include "Character.h"
#include "Monster.h"
#include "LogManager.h" // 로그 시스템 결합

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
    srand(static_cast<unsigned int>(time(NULL)));

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

            // ------------------------------------------------------------
            // TODO: [전투 담당 팀원 연동 영역]
            // 여기에서 턴제 전투 루프(플레이어 공격 <-> 몬스터 공격)가 실행되어야 함.
            // ------------------------------------------------------------

            // [팀원 코드 호출 테스트] 몬스터가 플레이어를 공격함 (방어력 차감 적용)
            currentMonster->attack(&player);

            cout << "\n[가상 전투 종료] 플레이어가 몬스터를 처치했습니다!\n";

            // ------------------------------------------------------------
            // TODO: [아이템 담당 팀원 연동 영역]
            // 기획서: "전투 승리 시 30% 확률로 아이템 획득"
            // 예시: 
            // int dropChance = rand() % 100;
            // if(dropChance < 30) { 
            //     Item* droppedItem = ItemManager::getRandomItem();
            //     player.addItem(droppedItem);
            //     LogManager::getInstance().addLog("아이템 획득!");
            // }
            // ------------------------------------------------------------

            
            LogManager::getInstance().recordKill(currentMonster->getname());
            player.gainGold(20);
            player.gainExperience(50);

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

    delete currentMonster;
    return 0;
}