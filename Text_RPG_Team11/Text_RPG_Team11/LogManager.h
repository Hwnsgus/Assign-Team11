#pragma once
#include <string>
#include <vector>
#include <map>
using namespace std;

class LogManager {

private:
	vector<string> eventLog;
	map<string, int> mosterKillCounts;

public:
	static LogManager& getInstance();

	void addLog(const string& message);
	void recordKill(const string& monsterName);

	void showLogs() const;
	void showKillCounts() const;
};