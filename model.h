#ifndef MODEL_H
#define MODEL_H
#include <vector>
#include <map>
#include "enemy.h"
#include "tower.h"
#include "enemypath.h"
class Model{
public:
    Model();
    ~Model(){};
    void addTower(const Tower& tower);
    void addEnemy(const Enemy& enemy);

    // 游戏状态更新的逻辑，例如检测敌人是否进入塔的射程范围
    // 遍历每个塔和敌人，进行攻击操作等
    void update();
    std::map<std::pair<int,int>,Tower>* GetTowers(){return &towers;}
    std::vector<Enemy>* GetEnemys(){return &enemys;}
    EnemyPath* GetPath(){return &path;}
    // void addPath(const EnemyPath& path){paths.push_back(path);}
private:
    std::map<std::pair<int,int>,Tower> towers;
    std::vector<Enemy> enemys;
    EnemyPath path;
};

#endif // MODEL_H
