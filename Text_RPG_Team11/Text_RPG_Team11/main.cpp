#include "Game.h"
#include <ctime>
#include <cstdlib>

int main() {
    srand(static_cast<unsigned int>(time(NULL))); // 전역 난수 초기화

    Game engine;
    engine.run(); // 게임 함수 실행


    return 0;
}