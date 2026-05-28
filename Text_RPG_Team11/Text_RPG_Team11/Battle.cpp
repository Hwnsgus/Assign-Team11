#include "Battle.h"
#include "Monster.h"
#include "Character.h"
#include "LogManager.h"

#include "Item.h"
#include "Healthpotion.h"
#include "AttackBoost.h"
#include "JunkItem.h"
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



			character.gainGold(rewardGold);

			bool levelup = character.gainExp(50);
			if (levelup) {
				cout << endl;
				cout << "---" << endl;
				cout << " LEVEL UP!" << endl;
				cout << " 현재 레벨 : " << character.getlevel() << endl;
				cout << "---" << endl;
			}

			cout << "---" << endl
				<< rewardGold << " Gold 획득!" << endl
				<< "---" << endl
				<< endl;

			// ===========================
			// 30% 확률 아이템 드랍
			// ===========================
			int itemChance, potionChance;

			itemChance = rand() % 100;
			potionChance = rand() % 100;

			if (itemChance < 30)
			{
				string name = monster->getname();

				Item* junk = nullptr;

				if (name == "야생 슬라임")
					junk = new JunkItem("슬라임 액체", "미끌한 점액", 30);
				else if (name == "야생 오크")
					junk = new JunkItem("오크고기", "질긴 고기", 60);
				else if (name == "야생 스켈레톤")
					junk = new JunkItem("뼈조각", "부러진 뼈", 40);
				else if (name == "야생 고블린")
					junk = new JunkItem("몽둥이 조각", "부서진 몽둥이의 조각", 40);
				else if (name == "야생 늑대")
					junk = new JunkItem("질긴 가죽", "늑대의 가죽", 40);

				if (junk != nullptr)
				{
					character.addItem(junk);

					cout << "\n잡템 획득: "
						<< junk->getItemName()
						<< endl;
				}
			}

			if (potionChance < 30)
			{
				Item* dropPotion = nullptr;

				int randomItem;

				randomItem = rand() % 2;

				// 체력 포션
				if (randomItem == 0)
				{
					dropPotion = new HealthPotion();
				}

				// 공격력 증가 알약
				else
				{
					dropPotion = new AttackBoost();
				}

				character.addItem(dropPotion);

				cout << endl;
				cout << "아이템 획득!" << endl;

				cout << "획득 아이템 : "
					<< dropPotion->getItemName()
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

		cout << "========================================" << endl;


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



				//잡템이면 사용 못하게끔 처리
				if (!selectedItem->isUsable())
				{
					cout << selectedItem->getItemName()
						<< "은(는) 사용할 수 없습니다!\n";
					character.addItem(selectedItem);

				
				}
				else
				{
					character.useItem(selectedItem);
					selectedItem->ShowItemInfo();
					cout << "\n" << character.getName()
						<< " 이(가) 아이템 사용!"
						<< endl;
					delete selectedItem;
				}
					
				


				
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

			BossMonster* bossCheck = dynamic_cast<BossMonster*>(monster);

			// ==========================================
			// 보스 처치 시 엔딩
			// ==========================================
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
			continue;
		}
			// 스켈레톤이면 부활 기회 줌
			Skeleton* skel = dynamic_cast<Skeleton*>(monster);
			if (skel != nullptr)
			{
				skel->attack(&character);  // 부활 시도
				if (monster->gethp() > 0) continue;  // 부활했으면 전투 계속, 플레이어 턴부터
			}

			continue;  // 다른 몬스터면 그냥 처치 처리로
		
	
		// 몬스터 턴 (살아있을 때만)
		// ==========================================
		monster->attack(&character);
		
		
		BossMonster* bossCheck =
			dynamic_cast<BossMonster*>(monster);

		
		
	}
	cout << endl;
	cout << "전투 종료!" << endl;

	system("pause");
	system("cls");
}
