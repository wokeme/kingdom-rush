#include "viewmodel.h"
#include<QDebug>

viewmodel::viewmodel(Model* m):M(m){
    timer=0;
    int delay_cnt=0;
    for(auto i:EnemyWave){
        int num=i.second;
        while(num--){
            Enemy temp;
            temp.Set_current_route(M->GetPath()->Get_begin_route());
            temp.set_damage(EnemyPropertiesMap[i.first].damage);
            temp.set_hp(EnemyPropertiesMap[i.first].hp);
            temp.set_max_hp(EnemyPropertiesMap[i.first].max_hp);
            temp.set_speed(EnemyPropertiesMap[i.first].speed);
            temp.set_path(EnemyPropertiesMap[i.first].path);
            temp.set_delay(delay_cnt++*2000);
            M->addEnemy(temp);
        }
        delay_cnt+=5;
    }
};
void viewmodel::UpdateTower(int x,int y,UpdateTowerType type,TowerType towerType){
    Tower temp;
    temp.SetCoord(std::make_pair(x,y));
    if(type == BUILD){


        if(towerType==TURRET){
            temp.SetType(TURRET);
            temp.SetGrade(PRIMARY);
            temp.SetPath(":/pics/turret.png");
        }

        else if(towerType==ARCHER){
            temp.SetType(ARCHER);
            temp.SetGrade(PRIMARY);
            temp.SetPath(":/pics/archer.png");
        }
        else if(towerType==MAGE){
            temp.SetType(MAGE);
            temp.SetGrade(PRIMARY);
            temp.SetPath(":/pics/mage.png");
        }
        else
            temp.SetType(DEFAULTTYPE);
        M->addTower(temp);
        emit ShowTower(x,y,temp.GetPath());
        return;
    }
    if(type == UPGRADATION){
        //判断塔的等级，升级
        qDebug() << "UPGRADATION";
        Tower temp = (*(M->GetTowers()))[std::make_pair(x,y)];
        qDebug()<< temp.GetCoord().first <<temp.GetCoord().second << temp.GetType() << towerType;
        if(temp.Upgrade() == false){
            qDebug() << "unable to upgrade";
            emit ShowTower(x,y,temp.GetPath());
            return;
        }
        if(temp.GetType()==TURRET){
            qDebug() << "upgrade turret";
            temp.SetPath(":/pics/turret2.png");
            if(temp.GetGrade() != SECONDARY){
                temp.SetPath(":/pics/turret3.png");
            }
        }

        else if(temp.GetType()==ARCHER){
            qDebug() << "upgrade archer";
            temp.SetPath(":/pics/archer2.png");
            if(temp.GetGrade() != SECONDARY){
                temp.SetPath(":/pics/archer3.png");
            }
        }
        else if(temp.GetType()==MAGE){
            qDebug() << "upgrade mage";
            temp.SetPath(":/pics/mage2.png");
            if(temp.GetGrade() != SECONDARY){
                temp.SetPath(":/pics/mage3.png");
            }
        }
        else
            temp.SetType(DEFAULTTYPE);
        M->addTower(temp);
        emit ShowTower(x,y,temp.GetPath());
        return;
    }
    if(type == REMOVE){
        qDebug()<< "Remove";
        (*(M->GetTowers())).erase(std::make_pair(x,y));
        emit ShowTower(x,y,":/pics/locate.png");
    }
}
void viewmodel::MoveEnemy(){
    timer+=100;
    if(M->GetEnemys()->size()==0)return;
    for(auto it=M->GetEnemys()->begin();it!=M->GetEnemys()->end();it++){
        if(it->get_delay()>timer)
            continue;
        if(!it->move()){
            it->set_status(false);
        }
    }

    // for(auto it=M->GetEnemys()->begin();it!=M->GetEnemys()->end();it++){
    //     if(!it->move()){
    //         it->set_status(false);
    //     }
    // }
}
