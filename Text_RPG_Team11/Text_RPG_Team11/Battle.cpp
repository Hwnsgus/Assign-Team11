#include "Battle.h"
#include "Monster.h"
#include "Character.h"
#include "LogManager.h"

#include "Item.h"
#include "Healthpotion.h"
#include "AttackBoost.h"
#include "BossMonster.h"

#include <iostream>
#include <cstdlib>
#include <conio.h>

using namespace std;

// ===========================
// 전투 시작
// ===========================
void Battle::startBattle(Character& character, Monster* monster)
{
	cout << "========================================" << endl;
	cout << " 전투 시작!" << endl;
	cout << " [" << monster->getname() << "] 등장!" << endl;
	cout << "========================================" << endl;

	// ===========================
	// 전투 루프
	// ===========================
	while (true)
	{
		// ===========================
		// 플레이어 사망 체크
		// ===========================
		if (character.gethp() <= 0)
		{
			cout << endl;
			cout << character.getName() << " 이(가) 쓰러졌습니다..." << endl;

			LogManager::getInstance().addLog(character.getName() + " 사망");
			break;
		}

		// ===========================
		// 몬스터 사망 체크 (상단 루프 진입 시 혹은 몬스터 공격 후 체크용)
		// ===========================
		if (monster->gethp() <= 0)
		{
			cout << endl;
			cout << "[" << monster->getname() << "] 처치 완료!" << endl;

			LogManager::getInstance().recordKill(monster->getname());

			// 보상 지급
			int rewardGold = rand() % 11 + 10;
			character.gainGold(rewardGold);

			bool levelup = character.gainExp(50);
			if (levelup) {
				cout << endl;
				cout << "---" << endl;
				cout << " LEVEL UP!" << endl;
				cout << " 현재 레벨 : " << character.getlevel() << endl;
				cout << "---" << endl;
			}

			cout << "---" << endl << rewardGold << " Gold 획득!" << endl << "---" << endl << endl;

			// 30% 확률 아이템 드랍
			int itemChance = rand() % 100;
			if (itemChance < 30)
			{
				Item* dropItem = nullptr;
				int randomItem = rand() % 2;

				if (randomItem == 0) dropItem = new HealthPotion();
				else dropItem = new AttackBoost();

				character.addItem(dropItem);
				cout << endl;
				cout << "아이템 획득!" << endl;
				cout << "획득 아이템 : " << dropItem->getItemName() << endl;
			}

			// 공격력 버프 제거
			character.setAtk(character.getBaseAtk());
			break; // 전투 종료
		}

		// ===========================
		// 상태 출력
		// ===========================
		cout << endl;
		cout << "========================================" << endl;
		cout << "[" << character.getName() << "] HP : " << character.gethp() << endl;
		cout << "[" << monster->getname() << "] HP : " << monster->gethp() << endl;
		cout << "========================================" << endl;

		// ===========================
		// 플레이어 턴
		// ===========================
		cout << endl;
		cout << "--- 플레이어 턴 ---" << endl;

		// 랜덤 아이템 사용 (30% 확률)
		int useItemChance = rand() % 100;
		if (useItemChance < 30)
		{
			Item* selectedItem = character.getItem(0);
			if (selectedItem != nullptr)
			{
				cout << endl;
				cout << character.getName() << " 이(가) 아이템 사용!" << endl;
				selectedItem->ShowItemInfo();
				character.useItem(selectedItem);
				delete selectedItem;
			}
		}

		// 플레이어 공격
		int damage = character.getatk() - (monster->getlevel() * 2);
		if (damage <= 0) damage = 1;

		monster->sethp(monster->gethp() - damage);

		cout << endl;
		cout << "* [" << character.getName() << "]의 공격!" << endl;
		cout << "* [" << monster->getname() << "]에게 " << damage << " 데미지!" << endl;

		// ===========================
		// 플레이어 공격 후 몬스터 상태 체크
		// ===========================
		if (monster->gethp() <= 0)
		{
			// 1. 보스 몬스터 사망 체크 -> 바로 엔딩
			BossMonster* bossCheck = dynamic_cast<BossMonster*>(monster);
			if (bossCheck != nullptr)
			{
				cout << endl;
				cout << "========================================" << endl;
				cout << "          FINAL CLEAR!" << endl;
				cout << "========================================" << endl;
				cout << " 마왕을 처치했습니다!" << endl;
				cout << " 세계에 평화가 찾아왔습니다!" << endl;
				cout << "========================================" << endl;
				system("pause");
				exit(0);
			}

			// 2. 스켈레톤 부활 체크 -> 부활 성공 시 몬스터 턴을 건너뛰고 다시 플레이어 턴으로
			Skeleton* skel = dynamic_cast<Skeleton*>(monster);
			if (skel != nullptr)
			{
				skel->attack(&character);  // 팀원이 작성한 부활 시도 함수 호출
				if (monster->gethp() > 0)
				{
					// 부활에 성공했다면, 아래의 사망 정산(Gold/Exp)을 하지 않고 다음 턴으로 루프 재시작
					continue;
				}
			}

			// 일반 몬스터가 진짜 죽은 거라면 다음 루프의 상단 '몬스터 사망 체크'에서 정산되도록 continue
			continue;
		}

		// ===========================
		// 몬스터 턴 (살아있을 때만 실행됨)
		// ===========================
		cout << endl;
		
		monster->attack(&character);
	}

	cout << endl;
	cout << "전투 종료!" << endl;
	system("pause");
	system("cls");
}