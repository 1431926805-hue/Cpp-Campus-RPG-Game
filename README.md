# 校园RPG冒险游戏系统

## 项目信息
- 课程：2026程序设计课程设计
- 组名：[填写组名]
- GitHub：[填写仓库地址]

## 项目简介
基于C++开发的校园主题角色扮演游戏系统。

## 当前进度（第1天）
### ✅ 已完成
- [x] Player类（角色属性、受伤、升级）
- [x] Enemy类（怪物属性、受伤判定）
- [x] GameManager类（主菜单控制、游戏循环）
- [x] 程序可运行，显示游戏菜单

### 🔄 开发中
- [ ] 战斗系统
- [ ] 背包系统
- [ ] 商店系统

## 编译运行
```bash
# Windows
g++ -std=c++17 src/*.cpp -o CampusRPG.exe
./CampusRPG.exe

# Linux/Mac
g++ -std=c++17 src/*.cpp -o CampusRPG
./CampusRPG