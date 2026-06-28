#include "../include/GameManager.h"
#include <limits>

// 清屏（跨平台）
#ifdef _WIN32
    #include <windows.h>
    #define CLEAR() system("cls")
#else
    #include <cstdlib>
    #define CLEAR() system("clear")
#endif

GameManager::GameManager() : isRunning(false) {
}

void GameManager::initialize() {
    std::string playerName;
    
    CLEAR();
    std::cout << "====================================" << std::endl;
    std::cout << "    校园RPG冒险游戏 v1.0" << std::endl;
    std::cout << "====================================" << std::endl;
    std::cout << "\n请输入角色名称: ";
    std::getline(std::cin, playerName);
    
    player.setName(playerName);
    std::cout << "\n角色创建成功！欢迎你，" << playerName << "！" << std::endl;
    
    std::cout << "\n按回车键开始游戏...";
    std::cin.get();
}

void GameManager::displayMainMenu() const {
    CLEAR();
    std::cout << "\n====================================" << std::endl;
    std::cout << "    校园RPG冒险游戏 - 主菜单" << std::endl;
    std::cout << "====================================" << std::endl;
    std::cout << "    角色: " << player.getName();
    std::cout << " | 等级: " << player.getLevel();
    std::cout << " | HP: " << player.getHp() << "/" << player.getMaxHp() << std::endl;
    std::cout << "------------------------------------" << std::endl;
    std::cout << "    1. 战斗" << std::endl;
    std::cout << "    2. 背包" << std::endl;
    std::cout << "    3. 商店" << std::endl;
    std::cout << "    4. 角色信息" << std::endl;
    std::cout << "    0. 退出游戏" << std::endl;
    std::cout << "====================================" << std::endl;
    std::cout << "请选择操作: ";
}

void GameManager::displayBattleMenu() const {
    CLEAR();
    std::cout << "\n====================================" << std::endl;
    std::cout << "        战斗系统" << std::endl;
    std::cout << "====================================" << std::endl;
    std::cout << "    战斗系统开发中..." << std::endl;
    std::cout << "====================================" << std::endl;
}

void GameManager::displayBagMenu() const {
    CLEAR();
    std::cout << "\n====================================" << std::endl;
    std::cout << "        背包系统" << std::endl;
    std::cout << "====================================" << std::endl;
    std::cout << "    背包系统开发中..." << std::endl;
    std::cout << "====================================" << std::endl;
}

void GameManager::displayShopMenu() const {
    CLEAR();
    std::cout << "\n====================================" << std::endl;
    std::cout << "        商店系统" << std::endl;
    std::cout << "====================================" << std::endl;
    std::cout << "    商店系统开发中..." << std::endl;
    std::cout << "====================================" << std::endl;
}

void GameManager::handleBattle() {
    displayBattleMenu();
    std::cout << "\n按回车键返回...";
    std::cin.get();
}

void GameManager::handleBag() {
    displayBagMenu();
    std::cout << "\n按回车键返回...";
    std::cin.get();
}

void GameManager::handleShop() {
    displayShopMenu();
    std::cout << "\n按回车键返回...";
    std::cin.get();
}

void GameManager::run() {
    isRunning = true;
    
    while (isRunning) {
        displayMainMenu();
        
        int choice;
        std::cin >> choice;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        
        switch (choice) {
            case 1:
                handleBattle();
                break;
            case 2:
                handleBag();
                break;
            case 3:
                handleShop();
                break;
            case 4:
                CLEAR();
                player.displayInfo();
                std::cout << "按回车键返回...";
                std::cin.get();
                break;
            case 0:
                std::cout << "\n确定要退出游戏吗？(y/n): ";
                char confirm;
                std::cin >> confirm;
                if (confirm == 'y' || confirm == 'Y') {
                    std::cout << "感谢游玩！再见！" << std::endl;
                    isRunning = false;
                }
                break;
            default:
                std::cout << "\n无效选择！请重新输入。" << std::endl;
                std::cout << "按回车键继续...";
                std::cin.get();
        }
    }
}