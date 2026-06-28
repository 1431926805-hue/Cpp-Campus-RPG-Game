#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include "Player.h"
#include "Enemy.h"

class GameManager {
private:
    Player player;          // 玩家对象
    bool isRunning;         // 游戏运行状态

    // 菜单显示
    void displayMainMenu() const;
    void displayBattleMenu() const;
    void displayBagMenu() const;
    void displayShopMenu() const;

    // 菜单处理（先空着，只打印提示）
    void handleBattle();
    void handleBag();
    void handleShop();

public:
    GameManager();

    // 游戏主流程
    void initialize();      // 初始化游戏
    void run();             // 运行游戏主循环
};

#endif