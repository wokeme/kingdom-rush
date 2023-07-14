#ifndef VIEWMODEL_H
#define VIEWMODEL_H
#include"model.h"
#include <QObject>
#include "common.h"

class viewmodel:public QObject{
    Q_OBJECT
public:
    viewmodel(Model* m):M(m){};
    ~viewmodel(){};
public slots:
    void UpdateTower(int,int,UpdateTowerType,TowerType=DEFAULTTYPE);
signals:
    void ShowTower(int,int,QString);
    void UpdateEnemy();//暂时未实现
private:
    Model* M;
    //一些处理用户点击后的方法
};

#endif // VIEWMODEL_H
