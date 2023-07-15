#include "enemy.h"

Enemy::Enemy(){
    alive = true;
    dead = false;
}

bool Enemy::move(){
    qDebug() << "Enemy::move()";
    if(this->check_status() == false){
        return false;
    }
    qDebug() << "Enemy::move() 2";
    double movement = speed;

    while(movement > 0){
        if(current_route->get_next() == NULL){
            return false;
        }
        double distance = qSqrt(qPow(current_position.x() - current_route->get_next()->get_pos().x(), 2) + qPow(current_position.y() - current_route->get_next()->get_pos().y(), 2));
        if(distance <= movement){
            current_route = current_route->get_next();
            current_position = current_route->get_pos();
            movement -= distance;
        }
        else{
            current_position.setX(current_position.x() + (speed / distance) * (current_route->get_next()->get_pos().x() - current_position.x()));
            current_position.setY(current_position.y() + (speed / distance) * (current_route->get_next()->get_pos().y() - current_position.y()));
            movement = 0;
        }
    }
    return true;
}

bool Enemy::check_status(){
    return this->alive;
}

void Enemy::set_status(bool B){
    this->alive = B;
}
void Enemy::Set_current_position(QPoint QP){
    this->current_position = QP;
}
void Enemy::Set_current_route(Route *rt){
    this->current_route = rt;
    this->current_position = rt->get_pos();
}
void Enemy::set_speed(double _speed){
    this->speed = _speed;
}
double Enemy::get_speed(){
    return this->speed;
}
void Enemy::set_hp(double _hp){
    this->hp = _hp;
}
double Enemy::get_hp(){
    return this->hp;
}
void Enemy::set_max_hp(double _max_hp){
    this->max_hp = _max_hp;
}
double Enemy::get_max_hp(){
    return this->max_hp;
}
void Enemy::set_damage(int _damage){
    this->damage = _damage;
}
int Enemy::get_damage(){
    return this->damage;
}
QString Enemy::get_path(){
    return this->path;
}
QPoint Enemy::Get_current_position(){
    return current_position;
}
Route* Enemy::Get_current_route(){
    return current_route;
}
