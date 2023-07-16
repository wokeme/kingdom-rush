#ifndef MODEL_H
#define MODEL_H
#include <vector>
#include <map>
#include "enemy.h"
#include "tower.h"
#include "enemypath.h"
#include "bullet.h"
class Model{
public:
    Model();
    ~Model(){};
    void addTower(const Tower& tower);
    void addEnemy(const Enemy& enemy);
    void addBullet(const Bullet& bullet);
    // 游戏状态更新的逻辑，例如检测敌人是否进入塔的射程范围
    // 遍历每个塔和敌人，进行攻击操作等
    void update();
    std::map<std::pair<int,int>,Tower>* GetTowers(){return &towers;}
    std::vector<Enemy>* GetEnemys(){return &enemys;}
    EnemyPath* GetPath(){return &path;}
    std::vector<Bullet>* GetBullet(){return &bullets;}
    void attack(int timer);
    // void addPath(const EnemyPath& path){paths.push_back(path);}
private:
    std::map<std::pair<int,int>,Tower> towers;
    std::vector<Enemy> enemys;
    EnemyPath path;
    std::vector<Bullet> bullets;
};

#endif // MODEL_H
