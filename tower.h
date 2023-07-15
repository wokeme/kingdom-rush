#ifndef TOWER_H
#define TOWER_H
#include<iostream>
typedef std::pair<int,int> position;
#include<QString>
#include "common.h"
class Tower{
public:
    Tower();
    virtual ~Tower(){};
    void SetPath(QString);
    void SetRange(double);
    void SetCoord(position);
    QString GetPath(){return path;}
    double GetRange();
    position GetCoord() const{return coord;};
    TowerType GetType(){return type;}
    void SetType(TowerType t){type=t;}
    void SetGrade(TowerGrade g){grade=g;}
    TowerGrade GetGrade(){return grade;}
    bool Upgrade();
protected:
    TowerType type;
    QString path;
    double range;
    position coord;//坐标
    TowerGrade grade;
};

#endif // TOWER_H
