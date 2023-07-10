#ifndef VIEWMODEL_H
#define VIEWMODEL_H
#include"model.h"
#include <QObject>

class viewmodel:public QObject
{
    Q_OBJECT
public:
    viewmodel();
    ~viewmodel(){};
public slots:
    void on_click_tower(int,int);
signals:
    void build_tower(int x,int y);
    void update_tower(int,int,QString);
    void kill_enemy();
    void enemy_reach(int);
    void game_over();
private:
    Model* M;
    //一些处理用户点击后的方法


};

#endif // VIEWMODEL_H
