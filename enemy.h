#ifndef ENEMY_H
#define ENEMY_H
#include<QString>

class Enemy
{
public:
    Enemy();
    virtual ~Enemy(){};
protected:
    double speed;
    double hp;
    int damage;//造成的伤害
    QString path;
};

#endif // ENEMY_H
