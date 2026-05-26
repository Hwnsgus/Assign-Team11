<<<<<<< HEAD
﻿#include <iostream>
#include "LogManager.h"
=======
﻿#include "LogManager.h"
#include <iostream>
>>>>>>> origin/feature/player

using namespace std;

LogManager& LogManager::getInstance() {
	static LogManager instance;
	return instance;
}

void LogManager::addLog(const string& message) {
	eventLog.push_back(message);
}

void LogManager::recordKill(const string& monsterName) {
	mosterKillCounts[monsterName]++;
	addLog("[" + monsterName + "]을(를) 처치했습니다");
}

<<<<<<< HEAD
void LogManager::showLogs() const {
=======
void LogManager::showLogs() const{
>>>>>>> origin/feature/player
	cout << "\n========================================\n";
	cout << "               [ 게임 로그 ]            \n";
	cout << "========================================\n";
	if (eventLog.empty())
	{
		cout << "기록된 로그가 없습니다\n";
	}
	for (const auto& log : eventLog)
	{
		cout << "▶ " << log << "\n";
	}
	cout << "========================================\n";
}

void LogManager::showKillCounts() const {
	cout << "\n========================================\n";
	cout << "           [ 처치한 몬스터 통계 ]         \n";
	cout << "========================================\n";
	if (mosterKillCounts.empty())
	{
		cout << "아직 처치한 몬스터가 없습니다\n";
	}
	for (const auto& pair : mosterKillCounts) {
<<<<<<< HEAD
		cout << " 💀 " << pair.first << " : 총 " << pair.second << " 마리\n";
	}
	cout << "========================================\n";

=======
		cout << " ■ " << pair.first << " : 총 " << pair.second << " 마리\n";
	}
	cout << "========================================\n";
	
>>>>>>> origin/feature/player
}