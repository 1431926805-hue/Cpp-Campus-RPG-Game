#include "../include/GameManager.h"

int main() {
    GameManager game;
    
    game.initialize();  // 创建角色
    game.run();         // 进入游戏主循环
    
    return 0;
}