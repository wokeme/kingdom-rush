#include "viewmodel.h"
#include<QDebug>

// viewmodel::viewmodel()
// {

// }
void viewmodel::UpdateTower(int x,int y,UpdateTowerType type,TowerType towerType){
    //type暂时没有用，因为目前只实现了建塔
    Tower temp;
    temp.SetCoord(std::make_pair(x,y));
    if(towerType==TURRET){
        temp.SetType(TURRET);
        temp.SetPath(":/pics/turret.png");
    }
        
    else if(towerType==ARCHER){
        temp.SetType(ARCHER);
        temp.SetPath(":/pics/archer.png");
    }
    else if(towerType==MAGE){
        temp.SetType(MAGE);
        temp.SetPath(":/pics/mage.png");
    }
    else
        temp.SetType(DEFAULTTYPE);
    M->addTower(temp);
    emit ShowTower(x,y,temp.GetPath());
}
