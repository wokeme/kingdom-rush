#ifndef ENEMYPATH_H
#define ENEMYPATH_H
#include <QPoint>
#include <vector>
#include <QtMath>
#include <QDebug>

class Route{
private:
    QPoint pos;
    Route* next;
public:
    Route(QPoint _pos, Route *_next = NULL);
    ~Route();
    QPoint get_pos();
    Route* get_next();
    void set_next(Route *_next);
};

class EnemyPath{
private:
    std::vector<Route*> path;
public:
    EnemyPath();
    EnemyPath(EnemyPath &E);
    void add_route(Route *R);
    Route* Get_begin_route();
    void Set_begin_route(Route *R);
};

#endif // ENEMYPATH_H
