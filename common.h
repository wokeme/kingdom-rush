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
    int award;
}EnemyProperties;
typedef struct TowerProperties{
    double range;
    int damage;
    int cost;
    QString path;
}TowerProperties;
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


#endif // COMMON_H

