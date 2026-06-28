
#include "../include/Enemy.h"

// 默认构造函数
Enemy::Enemy()
    : name("未知怪物"), hp(50), maxHp(50), attack(10), 
      type("普通"), expReward(20), goldReward(15) {
}

// 完整构造函数
Enemy::Enemy(const std::string& enemyName, const std::string& enemyType,
             int health, int atk, int expRwd, int goldRwd)
    : name(enemyName), hp(health), maxHp(health), attack(atk),
      type(enemyType), expReward(expRwd), goldReward(goldRwd) {
}

// ============ Getter方法 ============
std::string Enemy::getName() const {
    return name;
}

int Enemy::getHp() const {
    return hp;
}

int Enemy::getMaxHp() const {
    return maxHp;
}

int Enemy::getAttack() const {
    return attack;
}

std::string Enemy::getType() const {
    return type;
}

int Enemy::getExpReward() const {
    return expReward;
}

int Enemy::getGoldReward() const {
    return goldReward;
}

// ============ 核心方法 ============
void Enemy::takeDamage(int damage) {
    if (damage < 0) damage = 0;
    hp -= damage;
    if (hp < 0) hp = 0;
    
    std::cout << name << " 受到 " << damage << " 点伤害！";
    std::cout << " (剩余HP: " << hp << "/" << maxHp << ")" << std::endl;
}

bool Enemy::isAlive() const {
    return hp > 0;
}

void Enemy::displayInfo() const {
    std::cout << "\n========== 怪物信息 ==========" << std::endl;
    std::cout << "名称: " << name << std::endl;
    std::cout << "类型: " << type << std::endl;
    std::cout << "HP: " << hp << "/" << maxHp << std::endl;
    std::cout << "攻击力: " << attack << std::endl;
    std::cout << "奖励经验: " << expReward << std::endl;
    std::cout << "奖励金币: " << goldReward << std::endl;
    std::cout << "==============================\n" << std::endl;
}