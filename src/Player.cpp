#include "../include/Player.h"

// 默认构造函数
Player::Player()
    : name("未命名"), hp(100), maxHp(100), level(1), exp(0), gold(100) {
}

// 带名字的构造函数
Player::Player(const std::string& playerName)
    : name(playerName), hp(100), maxHp(100), level(1), exp(0), gold(100) {
}

// ============ Getter方法 ============
std::string Player::getName() const {
    return name;
}

int Player::getHp() const {
    return hp;
}

int Player::getMaxHp() const {
    return maxHp;
}

int Player::getLevel() const {
    return level;
}

int Player::getExp() const {
    return exp;
}

int Player::getGold() const {
    return gold;
}

// ============ Setter方法 ============
void Player::setName(const std::string& playerName) {
    name = playerName;
}

void Player::setGold(int amount) {
    if (amount < 0) amount = 0;
    gold = amount;
}

// ============ 核心方法 ============
void Player::takeDamage(int damage) {
    if (damage < 0) damage = 0;
    hp -= damage;
    if (hp < 0) hp = 0;
    
    std::cout << name << " 受到 " << damage << " 点伤害！";
    std::cout << " (剩余HP: " << hp << "/" << maxHp << ")" << std::endl;
}

void Player::heal(int amount) {
    if (amount < 0) amount = 0;
    hp += amount;
    if (hp > maxHp) hp = maxHp;
    
    std::cout << name << " 恢复 " << amount << " 点生命值！";
    std::cout << " (当前HP: " << hp << "/" << maxHp << ")" << std::endl;
}

void Player::addExp(int amount) {
    exp += amount;
    std::cout << "获得 " << amount << " 点经验值！" << std::endl;
    
    // 简单升级判定：每100经验升一级
    while (exp >= 100) {
        levelUp();
        exp -= 100;
    }
}

void Player::addGold(int amount) {
    gold += amount;
    std::cout << "获得 " << amount << " 金币！ (总金币: " << gold << ")" << std::endl;
}

bool Player::spendGold(int amount) {
    if (gold >= amount) {
        gold -= amount;
        std::cout << "花费 " << amount << " 金币！ (剩余: " << gold << ")" << std::endl;
        return true;
    }
    std::cout << "金币不足！" << std::endl;
    return false;
}

bool Player::isAlive() const {
    return hp > 0;
}

void Player::levelUp() {
    level++;
    maxHp += 20;
    hp = maxHp;  // 升级回满血
    
    std::cout << "\n========== 升级！ ==========" << std::endl;
    std::cout << name << " 升级到 " << level << " 级！" << std::endl;
    std::cout << "最大生命值提升到 " << maxHp << std::endl;
    std::cout << "===========================\n" << std::endl;
}

void Player::displayInfo() const {
    std::cout << "\n========== 角色信息 ==========" << std::endl;
    std::cout << "名称: " << name << std::endl;
    std::cout << "等级: " << level << std::endl;
    std::cout << "HP: " << hp << "/" << maxHp << std::endl;
    std::cout << "经验: " << exp << "/100" << std::endl;
    std::cout << "金币: " << gold << std::endl;
    std::cout << "==============================\n" << std::endl;
}