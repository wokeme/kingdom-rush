#ifndef ENEMY_H
#define ENEMY_H
#include<QString>
#include<iostream>
#include "enemypath.h"

class Enemy{
public:
    Enemy();
    virtual ~Enemy(){};
    bool move();
    bool check_status();
    void set_status(bool B);
    void Set_current_position(QPoint QP);
    void Set_current_route(Route *rt);
    QPoint Get_current_position();
    Route* Get_current_route();
    void set_speed(double _speed);
    double get_speed();
    void set_hp(double _hp);
    double get_hp();
    void set_max_hp(double _max_hp);
    double get_max_hp();
    void set_damage(int _damage);
    int get_damage();
    void set_path(QString _path){
        this->path = _path;
    }
    QString get_path();
    void set_delay(int _delay){
        this->delay = _delay;
    }
    int get_delay(){
        return this->delay;
    }
    void set_award(int _award){
        this->award = _award;
    }
    int get_award(){
        return award;
    }
protected:
    bool alive;
    bool dead;//一旦死亡，alive就无法再变为true
    double speed;
    double hp;
    double max_hp;
    QString path;
    int damage;//造成的伤害
    QPoint current_position;
    Route *current_route;
    int delay;//延迟，用于实现敌人的延迟出现
    int award;//击杀奖励
};
#endif // ENEMY_H
