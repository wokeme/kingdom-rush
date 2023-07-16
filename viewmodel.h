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
    int* GetMoney(){return &money;}
    int *GetHeart(){return &heart;}
public slots:
    void UpdateTower(int,int,UpdateTowerType,TowerType=DEFAULTTYPE);
    void MoveEnemy();
    void MoveBullet();
signals:
    void ShowTower(int,int,QString);
    void UpdateEnemy();//暂时未实现
    void gg(bool win);
private:
    int money;
    int heart;
    std::map<EnemyType,EnemyProperties> EnemyPropertiesMap = {
        {NORMAL,{2,100,100,2,":/pics/basicenemy.png",20}},
        {FAST,{4,50,50,1,":/pics/fastenemy.png",15}},
        {STRONG,{1.5,200,200,4,":/pics/strongenemy.png",40}}
    };
    std::vector<std::pair<EnemyType,int>> EnemyWave = {
        {NORMAL,10},
        {FAST,10},
        {STRONG,10}
    };
    std::map<TowerType,TowerProperties> TowerPropertiesMap = {
        {TURRET,{200,10,250,":/pics/turret.png"}},
        {ARCHER,{300,20,100,":/pics/archer.png"}},
        {MAGE,{400,30,120,":/pics/mage.png"}}
    };
    std::map<TowerType,std::vector<int>> TowerCostMap = {
        {TURRET,{250,300,350}},
        {ARCHER,{100,150,200}},
        {MAGE,{120,180,240}}
    };
    int timer;
    int timer2;
    Model* M;
    //一些处理用户点击后的方法
};
#endif // VIEWMODEL_H
