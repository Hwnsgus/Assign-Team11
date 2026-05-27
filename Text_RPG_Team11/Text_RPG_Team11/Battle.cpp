#include "Battle.h"
#include "Monster.h"
#include "Character.h"
#include "LogManager.h"

#include "Item.h"
#include "Healthpotion.h"
#include "AttackBoost.h"

#include <iostream>
#include <cstdlib>
#include <conio.h>

using namespace std;

void Battle::startBattle(Character& character, Monster* monster)
{
	if (monster == nullptr) return;

    bool battleRunning = true;
    
    LogManager::getInstance().addLog("[" + monster->getname() + "]과(와) 전투를 시작했습니다.");

    AttackBoost* usedBuff = nullptr;
    while (battleRunning)
    {
        system("cls");
        cout << "===== 턴제 전투 모드 =====" << endl;
        cout << " 몬스터: " << monster->getname() << " (HP: " << monster->gethp() << ")" << endl;
        cout << " 플레이어: " << character.getName() << " (HP: " << character.gethp() << ")" << endl;
        cout << "==========================" << endl;
        cout << " [Z] 공격하기 [I] 아이템 사용  [X] 도망치기" << endl;
        cout << "==========================" << endl;
        cout << "선택: ";

        char choice = _getch();

        //아이템 사용 로직
        if (choice == 'i' || choice == 'I')
        {
            cout << "\n\n[ 인벤토리] \n";
            character.showInventory();
            cout <<"사용할 아이템 번호를 입력하세요 (취소: 0): ";
            int itemIdx;
            cin >> itemIdx;
            
            if (itemIdx > 0)
            {
                Item* itemToUse = character.getItem(itemIdx - 1);
                if (itemToUse == nullptr)
                {
                    itemToUse -> use(&character);
                    LogManager::getInstance().addLog(itemToUse->getItemName() + "을(를) 사용했습니다.");
                    
                    if (itemToUse->ItemEffect() == "공격력 증가")
                    {
                        usedBuff = (AttackBoost*)itemToUse;
                    }else
                    {
                        delete itemToUse;
                    }
                }
            }
            continue;
        }
        
        //플레이어 공격
        else if (choice == 'z' || choice == 'Z') {
            // 1. 플레이어의 선제 공격
            int damage = character.getatk();
            monster->sethp(monster->gethp() - damage);

			cout << "\n▶ " << character.getName() << "의 공격! [" << monster->getname() << "]에게 " << damage << " 대미지!" << endl;
			LogManager::getInstance().addLog(character.getName() + "이(가) " + monster->getname() + "에게 " + to_string(damage) + " 대미지를 입힘.");


			// 몬스터 처치( HP <= 0 ) 확인
			if (monster->gethp() <= 0)
			{
				cout << endl << "몬스터 처치 성공!" << endl;
				LogManager::getInstance().recordKill(monster->getname()); // 처치 로그 및 카운트 누적 (⭐)


				// 보상 경험치 및 골드 지급
				character.gainExp(50);
				int rewardGold = (rand() % 11) + 10; // 10~20 랜덤 골드
				character.gainGold(rewardGold);


				// 30% 확률로 아이템 획득 (아이템 담당 강대암님 연동 영역)
				int itemChance = rand() % 100;
				if (itemChance < 30)
				{
					cout << "[도전 성공] 보상 아이템을 획득했습니다!" << endl;
					LogManager::getInstance().addLog("전투 보상으로 전리품 아이템을 획득함.");
					Item* reward = nullptr;
					int itemType = rand() % 2;
					switch (itemType)
					{
					case 0:
						reward = new HealthPotion();
						break;
					case 1:
						reward = new AttackBoost();
						break;
					default:
						reward = new HealthPotion();
						break;
					}
					character.addItem(reward);
					cout << "\n" << reward->getItemName() << " 획득!" << endl;
				}
				else
				{
					cout << "아이템 획득 실패!" << endl;
				}

				battleRunning = false;
				_getch();
				break;
			}

			// 2. 몬스터의 반격 (고호진님 attack 함수 호출)
			monster->attack(&character);
			_getch();


            // 플레이어 사망 확인
            if (character.gethp() <= 0)
            {
                cout << endl << character.getName() << "가 쓰러졌습니다... 게임 오버!" << endl;
                LogManager::getInstance().addLog("플레이어가 전사하여 게임이 종료되었습니다.");
                battleRunning = false;
                _getch();
                break;
            }
        }
        else if (choice == 'x' || choice == 'X') {
            cout << "\n 전투에서 도망쳤습니다!" << endl;
            LogManager::getInstance().addLog("전투 중 도망침.");
            battleRunning = false;
            _getch();
            break;
        }
     
    }
    if (usedBuff != nullptr) {
        usedBuff->removeEffectAfterBattle(&character);
        delete usedBuff;
    }

}