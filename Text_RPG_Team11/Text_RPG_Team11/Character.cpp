<<<<<<< HEAD


#include "Character.h"
=======
ï»?include "Character.h"
>>>>>>> origin/feature/player
#include "LogManager.h"
#include <sstream>
#include<iostream>
using namespace std;

<<<<<<< HEAD
Character::Character(string charName) : name(charName) {
=======
Character::Character(string charName) : name(charName){
>>>>>>> origin/feature/player

	level = 1;
	maxHP = 200;
	currentHP = 200;
	attackPower = 30;
	defense = 30;
	exp = 0;
	gold = 0;

<<<<<<< HEAD
	LogManager::getInstance().addLog("Ä³¸¯ÅÍ [" + name + "] »ý¼º ¿Ï·á! (Lv.1, HP :200, ATK :30");
=======
	LogManager::getInstance().addLog("ìºë¦­??[" + name + "] ?ì„± ?„ë£Œ! (Lv.1, HP :200, ATK :30");
>>>>>>> origin/feature/player
}

void Character::sethp(int hp) {
	currentHP = hp;
	if (currentHP < 0)
	{
		currentHP = 0;
	}
	if (currentHP > maxHP)
	{
		currentHP = maxHP;
	}
}

<<<<<<< HEAD
void Character::setAtk(int atk)
{
	attackPower = atk;

}

=======
>>>>>>> origin/feature/player
void Character::takeDamage(int damage) {
	currentHP -= damage;
	if (currentHP < 0) currentHP = 0;
}

void Character::gainExp(int amount) {
	exp += amount;
<<<<<<< HEAD
	LogManager::getInstance().addLog(to_string(amount) + " EXP È¹µæ (ÇöÀç: " + to_string(exp) + "/100)");

	// ¿ø·¡´Â ·¹º§¾÷ Å¬·¡½º°¡ Ã³¸®ÇÏ°ÚÁö¸¸ ÀÓ½Ã °ËÁõ¿ë
=======
	LogManager::getInstance().addLog(to_string(amount) + " EXP ?ë“ (?„ìž¬: " + to_string(exp) + "/100)");

	// ?ëž˜???ˆë²¨???´ëž˜?¤ê? ì²˜ë¦¬?˜ê² ì§€ë§??„ì‹œ ê²€ì¦ìš©
>>>>>>> origin/feature/player
	if (exp >= 100) {
		level++;
		exp -= 100;
		maxHP += 20;
		attackPower += 5;
		currentHP = maxHP;
<<<<<<< HEAD
		LogManager::getInstance().addLog("¡Ú LEVEL UP! ÇöÀç ·¹º§: " + to_string(level));
=======
		LogManager::getInstance().addLog("??LEVEL UP! ?„ìž¬ ?ˆë²¨: " + to_string(level));
>>>>>>> origin/feature/player
	}
}

void Character::gainGold(int amount) {
	gold += amount;
<<<<<<< HEAD
	LogManager::getInstance().addLog(to_string(amount) + " °ñµå È¹µæ!");
=======
	LogManager::getInstance().addLog(to_string(amount) + " ê³¨ë“œ ?ë“!");
>>>>>>> origin/feature/player
}


void Character::showStatus() const {
	cout << "\n========================================\n"
<<<<<<< HEAD
		<< " [" << name << " ÀÇ »óÅÂ]\n"
		<< " ·¹º§   : " << level << " (ÃÖ´ë 10)\n"
		<< " Ã¼·Â   : " << currentHP << " / " << maxHP << "\n"
		<< " °ø°Ý·Â : " << attackPower << "\n"
		<< " °æÇèÄ¡ : " << exp << " / 100\n"
		<< " °ñµå   : " << gold << " G\n"
		<< "========================================\n";
}

// ¾ÆÀÌÅÛ ´ã´ç ¿¬µ¿ ÇÔ¼ö (ÇöÀç´Â Æ²¸¸ Á¦°ø)
void Character::addItem(Item* item) { /* ¾ÆÀÌÅÛ ´ã´çÀÚ°¡ ±¸Çö ¿¹Á¤ */ }
void Character::useItem(Item* item) { /* ¾ÆÀÌÅÛ ´ã´çÀÚ°¡ ±¸Çö ¿¹Á¤ */ }
=======
		<< " [" << name << " ???íƒœ]\n"
		<< " ?ˆë²¨   : " << level << " (ìµœë? 10)\n"
		<< " ì²´ë ¥   : " << currentHP << " / " << maxHP << "\n"
		<< " ê³µê²©??: " << attackPower << "\n"
		<< " ê²½í—˜ì¹?: " << exp << " / 100\n"
		<< " ê³¨ë“œ   : " << gold << " G\n"
		<< "========================================\n";
}

// ?„ì´???´ë‹¹ ?°ë™ ?¨ìˆ˜ (?„ìž¬???€ë§??œê³µ)
void Character::addItem(Item* item) { /* ?„ì´???´ë‹¹?ê? êµ¬í˜„ ?ˆì • */ }
void Character::useItem(Item* item) { /* ?„ì´???´ë‹¹?ê? êµ¬í˜„ ?ˆì • */ }
>>>>>>> origin/feature/player
