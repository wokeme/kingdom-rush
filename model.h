#ifndef MODEL_H
#define MODEL_H
#include<vector>
#include"enemy.h"
#include"tower.h"
class Model
{
public:
    Model();
    ~Model(){};
    void addTower(const Tower& tower);
    void addEnemy(const Enemy& enemy);

    // 游戏状态更新的逻辑，例如检测敌人是否进入塔的射程范围
    // 遍历每个塔和敌人，进行攻击操作等
    void update();
private:
    std::vector<Tower> towers;
    std::vector<Enemy> enemys;
};

#endif // MODEL_H
