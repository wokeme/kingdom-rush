#include <QPaintEvent>
#include <iostream>
#include "common.h"

common::common(){
    Tower = (int*) malloc(sizeof(int) * 10);
    for(int i=0; i < 10; i++){
        Tower[i] = 0;
    }
}
common::~common(){ free(Tower);}
void common::Set_Path1(QString &Q){
    Path1 = Q;
}
void common::Set_Path2(QString &Q){
    Path2 = Q;
}
void common::Set_Tower(int index, int p){
    Tower[index] = p;
}
QString common::Get_Path1(){
    return Path1;
}
QString common::Get_Path2(){
    return Path2;
}
int* common::Get_Tower() const{
    return Tower;
}
