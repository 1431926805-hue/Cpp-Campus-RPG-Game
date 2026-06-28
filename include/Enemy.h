#ifndef ENEMY_H
#define ENEMY_H

#include <string>
#include <iostream>

class Enemy {
private:
    std::string name;
    int hp;
    int maxHp;
    int attack;
    std::string type;      // 怪物类型
    int expReward;         // 经验奖励
    int goldReward;        // 金币奖励

public:
    // 构造函数
    Enemy();
    Enemy(const std::string& enemyName, const std::string& enemyType,
          int health, int atk, int expRwd, int goldRwd);

    // 属性获取
    std::string getName() const;
    int getHp() const;
    int getMaxHp() const;
    int getAttack() const;
    std::string getType() const;
    int getExpReward() const;
    int getGoldReward() const;

    // 核心方法
    void takeDamage(int damage);
    bool isAlive() const;

    // 显示信息
    void displayInfo() const;
};

#endif