#include "enemypath.h"

Route::Route(QPoint _pos, Route *_next){
    this->pos = _pos;
    this->next = _next;
}
Route::~Route(){

}
QPoint Route::get_pos(){
    return pos;
}

Route* Route::get_next(){
    return next;
}

void Route::set_next(Route *R){
    this->next = R;
}

EnemyPath::EnemyPath(){}
EnemyPath::EnemyPath(EnemyPath &E){
    this->path = E.path;
}
void EnemyPath::add_route(Route *R){
    if(path.size() != 0){
        path.back()->set_next(R);
    }
    path.push_back(R);
}
Route* EnemyPath::Get_begin_route(){
    return *path.begin();
}
void EnemyPath::Set_begin_route(Route *R){
    path.insert(path.begin(), R);
}
