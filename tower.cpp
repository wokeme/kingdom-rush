#include "tower.h"

Tower::Tower()
{

}
void Tower::SetCoord(position p){
    this->coord=p;
}
void Tower::SetPath(QString s){
    this->path=s;
}

bool Tower::Upgrade(){
    if(this->GetGrade() == PRIMARY){
        SetGrade(SECONDARY);
        return true;
    }
    if(this->GetGrade() == SECONDARY){
        SetGrade(TERTIARY);
        return true;
    }
    return false;
}
