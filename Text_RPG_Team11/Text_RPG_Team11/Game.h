#pragma once

class Character;
class Monster;

class Game {
private:
    Character* player; // 게임 루프 동안 유지될 플레이어 객체

public:
    Game();
    ~Game();

    void initGame();   // 게임 시작 세팅 및 캐릭터 생성
    void run();        // 메인 루프 (마을 화면)
    void showMenu();   // C키 설정/로그 창
};