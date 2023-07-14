#ifndef COMMON_H
#define COMMON_H
#include "map.h"
#include<vector>
#include <QPaintEvent>
#include <iostream>
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
class common{
public:
    common();
    ~common();
private:
    std::vector<map> maps;

};


#endif // COMMON_H

