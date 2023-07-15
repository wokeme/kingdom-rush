#ifndef COMMON_H
#define COMMON_H
#include "map.h"
#include <vector>
#include <QPaintEvent>
#include <iostream>
#include "enemypath.h"
#include <map>
#include <QTimer>
#define myposition std::pair<int,int>


enum EnemyType{
    NORMAL,FAST,STRONG,
    DEFAULTENEMYTYPE
};
enum TowerGrade{
    PRIMARY,SECONDARY,TERTIARY,
    DEFAULT
};
enum TowerType{
    TURRET,ARCHER,MAGE,
    DEFAULTTYPE
};
enum UpdateTowerType{
    BUILD,UPGRADATION,REMOVE
};
typedef struct EnemyProperties{
    double speed;
    double hp;
    double max_hp;
    int damage;
    QString path;
}EnemyProperties;

class common{
public:
    common();
    ~common();
    EnemyPath* GetPath(){return &path;}

    // static std::map<EnemyType,EnemyProperties> EnemyPropertiesMap0;
    // static std::vector<std::pair<EnemyType,int>> EnemyWave0;
private:
    std::vector<map> maps;
    EnemyPath path;
    // QTimer *timer;
};
//std::map<EnemyType,common::EnemyProperties> common::EnemyPropertiesMap0 = {
//    {NORMAL,{1,100,100,2,":/pics/basicenemy.png"}},
//    {FAST,{2,50,50,1,":/pics/fastenemy.png"}},
//    {STRONG,{0.5,200,200,4,":/pics/strongenemy.png"}}
//};
//std::vector<std::pair<EnemyType,int>> common::EnemyWave0 = {
//    {NORMAL,10},
//    {FAST,10},
//    {STRONG,10}
//};

#endif // COMMON_H

