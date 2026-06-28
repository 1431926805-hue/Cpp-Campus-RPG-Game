#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <iostream>

class Player {
private:
    std::string name;
    int hp;
    int maxHp;
    int level;
    int exp;
    int gold;

public:
    // 构造函数
    Player();
    Player(const std::string& playerName);

    // 基础属性获取
    std::string getName() const;
    int getHp() const;
    int getMaxHp() const;
    int getLevel() const;
    int getExp() const;
    int getGold() const;

    // 基础属性设置
    void setName(const std::string& playerName);
    void setGold(int amount);

    // 核心方法（战斗/成长必须）
    void takeDamage(int damage);      // 受伤
    void heal(int amount);            // 治疗
    void addExp(int amount);          // 增加经验
    void addGold(int amount);         // 增加金币
    bool spendGold(int amount);       // 花费金币
    bool isAlive() const;             // 是否存活
    void levelUp();                   // 升级

    // 显示信息
    void displayInfo() const;
};

#endif