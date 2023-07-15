#ifndef VIEWMODEL_H
#define VIEWMODEL_H
#include"model.h"
#include <QObject>
#include "common.h"

class viewmodel:public QObject{
    Q_OBJECT
public:
    viewmodel(Model* m);
    ~viewmodel(){};
public slots:
    void UpdateTower(int,int,UpdateTowerType,TowerType=DEFAULTTYPE);
    void MoveEnemy();
signals:
    void ShowTower(int,int,QString);
    void UpdateEnemy();//暂时未实现
private:
    std::map<EnemyType,EnemyProperties> EnemyPropertiesMap = {
        {NORMAL,{2,100,100,2,":/pics/basicenemy.png"}},
        {FAST,{4,50,50,1,":/pics/fastenemy.png"}},
        {STRONG,{1,200,200,4,":/pics/strongenemy.png"}}
    };
    std::vector<std::pair<EnemyType,int>> EnemyWave = {
        {NORMAL,10},
        {FAST,10},
        {STRONG,10}
    };
    int timer;
    Model* M;
    //一些处理用户点击后的方法
};
#endif // VIEWMODEL_H
