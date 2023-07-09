#ifndef COMMON_H
#define COMMON_H

#include <QPaintEvent>
#include <iostream>
class common{
    int* Tower; //防御塔建立信息
    QString Path1; //背景图片
    QString Path2; //防御塔图片
public:
    common();
    ~common();
    void Set_Path1(QString &Q);
    void Set_Path2(QString &Q);
    void Set_Tower(int index, int p);
    QString Get_Path1();
    QString Get_Path2();
    int* Get_Tower() const;

};


#endif // COMMON_H

