#include "viewmodel.h"
#include<QDebug>

viewmodel::viewmodel(Model* m):M(m){
    money=5000;
    heart=20;
    timer=0;
    timer2=0;
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
            if(i.first == STRONG){
                delay_cnt += 2;
            }
            temp.set_delay(delay_cnt++*2000);
            temp.set_award(EnemyPropertiesMap[i.first].award);
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
            if(money<TowerCostMap[TURRET][0]){
                emit ShowTower(x,y,":/pics/locate.png");
                return;
            }
            temp.SetType(TURRET);
            temp.SetGrade(PRIMARY);
            temp.SetRange(100);
            temp.SetPath(":/pics/turret.png");
            money-=TowerCostMap[TURRET][0];
        }

        else if(towerType==ARCHER){
            if(money<TowerCostMap[ARCHER][0]){
                emit ShowTower(x,y,":/pics/locate.png");
                return;
            }
            temp.SetType(ARCHER);
            temp.SetGrade(PRIMARY);
            temp.SetRange(120);
            temp.SetPath(":/pics/archer.png");
            money-=TowerCostMap[ARCHER][0];
        }
        else if(towerType==MAGE){
            if(money<TowerCostMap[MAGE][0]){
                emit ShowTower(x,y,":/pics/locate.png");
                return;
            }
            temp.SetType(MAGE);
            temp.SetGrade(PRIMARY);
            temp.SetRange(150);
            temp.SetPath(":/pics/mage.png");
            money-=TowerCostMap[MAGE][0];
        }
        else
            temp.SetType(DEFAULTTYPE);
        M->addTower(temp);
        emit ShowTower(x,y,temp.GetPath());
        return;
    }
    if(type == UPGRADATION){
        //判断塔的等级，升级
        Tower temp = (*(M->GetTowers()))[std::make_pair(x,y)];
        if(temp.Upgrade() == false){
            emit ShowTower(x,y,temp.GetPath());
            return;
        }
        if(temp.GetType()==TURRET){
            if(temp.GetGrade()==PRIMARY){
                if(money<TowerCostMap[TURRET][1]){
                    temp.SetGrade(SECONDARY);
                    emit ShowTower(x,y,temp.GetPath());
                    return;
                }
            }
            else if(temp.GetGrade()==SECONDARY){
                if(money<TowerCostMap[TURRET][2]){
                    temp.SetGrade(TERTIARY);
                    emit ShowTower(x,y,temp.GetPath());
                    return;
                }
            }
            temp.SetPath(":/pics/turret2.png");
            money-=TowerCostMap[TURRET][1];
            if(temp.GetGrade() != SECONDARY){
                temp.SetPath(":/pics/turret3.png");
                money=money-TowerCostMap[TURRET][2]+TowerCostMap[TURRET][1];
            }
        }

        else if(temp.GetType()==ARCHER){
            if(temp.GetGrade()==PRIMARY){
                if(money<TowerCostMap[ARCHER][1]){
                    temp.SetGrade(SECONDARY);
                    emit ShowTower(x,y,temp.GetPath());
                    return;
                }
            }
            else if(temp.GetGrade()==SECONDARY){
                if(money<TowerCostMap[ARCHER][2]){
                    temp.SetGrade(TERTIARY);
                    emit ShowTower(x,y,temp.GetPath());
                    return;
                }
            }
            temp.SetPath(":/pics/archer2.png");
            money-=TowerCostMap[ARCHER][1];
            if(temp.GetGrade() != SECONDARY){
                temp.SetPath(":/pics/archer3.png");
                money=money-TowerCostMap[ARCHER][2]+TowerCostMap[ARCHER][1];
            }
        }
        else if(temp.GetType()==MAGE){
            if(temp.GetGrade()==PRIMARY){
                if(money<TowerCostMap[MAGE][1]){
                    temp.SetGrade(SECONDARY);
                    emit ShowTower(x,y,temp.GetPath());
                    return;
                }
            }
            else if(temp.GetGrade()==SECONDARY){
                if(money<TowerCostMap[MAGE][2]){
                    temp.SetGrade(TERTIARY);
                    emit ShowTower(x,y,temp.GetPath());
                    return;
                }
            }
            temp.SetPath(":/pics/mage2.png");
            money-=TowerCostMap[MAGE][1];
            if(temp.GetGrade() != SECONDARY){
                temp.SetPath(":/pics/mage3.png");
                money=money-TowerCostMap[MAGE][2]+TowerCostMap[MAGE][1];
            }
        }
        else
            temp.SetType(DEFAULTTYPE);
        M->addTower(temp);
        emit ShowTower(x,y,temp.GetPath());
        return;
    }
    if(type == REMOVE){
        Tower temp = (*(M->GetTowers()))[std::make_pair(x,y)];
        money+=TowerCostMap[temp.GetType()][0]*0.7;
        if(temp.GetGrade()==SECONDARY || temp.GetGrade()==TERTIARY)money+=TowerCostMap[temp.GetType()][1]*0.6;
        if(temp.GetGrade()==TERTIARY)money+=TowerCostMap[temp.GetType()][2]*0.5;
        (*(M->GetTowers())).erase(std::make_pair(x,y));
        emit ShowTower(x,y,":/pics/locate.png");
    }
}
void viewmodel::MoveEnemy(){
    if(heart<=0){
        emit gg(false);
        return;
    }
    timer+=100;
    if(M->GetEnemys()->size()==0)return;
    bool _gameover = true;
    for(auto it=M->GetEnemys()->begin();it!=M->GetEnemys()->end();it++){
        if(!it->check_status()){
            continue;
        }
        _gameover = false;
        if(it->get_hp() <= 0){
            money += it->get_award();
            it->set_status(false);
        }
        if(it->get_delay()>timer)
            continue;
        if(!it->move()&&it->check_status()){
            it->set_status(false);
            heart-=it->get_damage();
        }
    }
    if(_gameover){
        emit gg(true);
    }
}
void viewmodel::MoveBullet(){
    timer2+=100;
    M->attack(timer2);


    if(M->GetBullet()->size() == 0){
        return;
    }
    int size=M->GetBullet()->size();
    bool alive[100];
    for(int i=0;i<size;i++){
        alive[i]=true;
    }
    for(int i=0;i<size;i++){
        (*M->GetBullet())[i].move();
        if((*M->GetBullet())[i].hasReachedTarget()){
            (*M->GetBullet())[i].hitTarget();
            alive[i]=false;
        }
    }
    for(int i=0;i<size;i++){
        if(alive[i]==false){
            M->GetBullet()->erase(M->GetBullet()->begin()+i);
            i--;
            size--;
        }
    }
}
