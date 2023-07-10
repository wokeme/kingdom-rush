#ifndef TOWER_H
#define TOWER_H
#include<iostream>
typedef std::pair<int,int> position;
#include<QString>
class Tower
{
public:
    Tower();
    virtual ~Tower(){};
    void SetPath(QString);
    void SetRange(double);
    void SetCoord(position);
    QString GetPath();
    double GetRange();
    position GetCoord();
protected:
    QString path;
    double range;
    position coord;//坐标
};

#endif // TOWER_H
