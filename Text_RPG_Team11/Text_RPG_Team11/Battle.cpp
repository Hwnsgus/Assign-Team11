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
	cout << " ["
		<< monster->getname()
		<< "] 등장!"
		<< endl;
	cout << "========================================" << endl;

	// ===========================
	// 전투 루프
	// ===========================
	while (true)
	{
		// ===========================
		// 플레이어 사망
		// ===========================
		if (character.gethp() <= 0)
		{
			cout << endl;
			cout << character.getName()
				<< " 이(가) 쓰러졌습니다..."
				<< endl;

			LogManager::getInstance().addLog(
				character.getName()
				+ " 사망"
			);

			break;
		}

		// ===========================
		// 몬스터 사망
		// ===========================
		if (monster->gethp() <= 0)
		{
			cout << endl;
			cout << "["
				<< monster->getname()
				<< "] 처치 완료!"
				<< endl;

			LogManager::getInstance().recordKill(
				monster->getname()
			);

			// ===========================
			// 보상 지급
			// ===========================
			int rewardGold;

			rewardGold = rand() % 11 + 10;

			character.gainExp(50);

			character.gainGold(rewardGold);

			cout << endl;
			cout << "EXP 50 획득!" << endl;

			cout << rewardGold
				<< " Gold 획득!"
				<< endl;

			// ===========================
			// 30% 확률 아이템 드랍
			// ===========================
			int itemChance;

			itemChance = rand() % 100;

			if (itemChance < 30)
			{
				Item* dropItem = nullptr;

				int randomItem;

				randomItem = rand() % 2;

				// 체력 포션
				if (randomItem == 0)
				{
					dropItem = new HealthPotion();
				}

				// 공격력 증가 알약
				else
				{
					dropItem = new AttackBoost();
				}

				character.addItem(dropItem);

				cout << endl;
				cout << "아이템 획득!" << endl;

				cout << "획득 아이템 : "
					<< dropItem->getItemName()
					<< endl;
			}

			// ===========================
			// 공격력 버프 제거
			// ===========================
			character.setAtk(
				character.getBaseAtk()
			);

			break;
		}

		// ===========================
		// 상태 출력
		// ===========================
		cout << endl;

		cout << "========================================"
			<< endl;

		cout << "["
			<< character.getName()
			<< "] HP : "
			<< character.gethp()
			<< endl;

		cout << "["
			<< monster->getname()
			<< "] HP : "
			<< monster->gethp()
			<< endl;

		cout << "========================================"
			<< endl;

		// ===========================
		// 플레이어 턴
		// ===========================
		cout << endl;
		cout << "--- 플레이어 턴 ---" << endl;

		// ===========================
		// 랜덤 아이템 사용
		// ===========================
		int useItemChance;

		useItemChance = rand() % 100;

		// 30% 확률 사용
		if (useItemChance < 30)
		{
			Item* selectedItem;

			selectedItem = character.getItem(0);

			if (selectedItem != nullptr)
			{
				cout << endl;
				cout << character.getName()
					<< " 이(가) 아이템 사용!"
					<< endl;

				selectedItem->ShowItemInfo();

				character.useItem(selectedItem);

				delete selectedItem;
			}
		}

		// ===========================
		// 플레이어 공격
		// ===========================
		int damage;

		damage = character.getatk() - (monster->getlevel() * 2);

		if (damage <= 0)
		{
			damage = 1;
		}

		monster->sethp(
			monster->gethp() - damage
		);

		cout << endl;

		cout << character.getName()
			<< " 의 공격!"
			<< endl;

		cout << monster->getname()
			<< " 에게 "
			<< damage
			<< " 데미지!"
			<< endl;

		// 몬스터 사망 체크
		if (monster->gethp() <= 0)
		{
			// 스켈레톤이면 부활 기회 줌
			Skeleton* skel = dynamic_cast<Skeleton*>(monster);
			if (skel != nullptr)
			{
				skel->attack(&character);  // 부활 시도
				if (monster->gethp() > 0) continue;  // 부활했으면 전투 계속
			}

			continue;  // 다른 몬스터면 그냥 처치 처리로
		}
		BossMonster* bossCheck =
			dynamic_cast<BossMonster*>(monster);

		// 몬스터 턴 (살아있을 때만)
		// ==========================================
		// 보스 처치 시 엔딩
		// ==========================================
		if (bossCheck != nullptr)
		{
			cout << endl;

			cout << "========================================"
				<< endl;

			cout << "          FINAL CLEAR!"
				<< endl;

			cout << "========================================"
				<< endl;

			cout << " 마왕을 처치했습니다!"
				<< endl;

			cout << " 세계에 평화가 찾아왔습니다!"
				<< endl;

			cout << "========================================"
				<< endl;

			system("pause");

			exit(0);
		}
		// ===========================
		// 몬스터 턴
		// ===========================
		monster->attack(&character);

		
		
	}

	cout << endl;
	cout << "전투 종료!" << endl;
}
