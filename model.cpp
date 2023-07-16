#include "model.h"

Model::Model(){
    QPoint PT(825,209);
    path.add_route(new Route(PT));
    PT.setX(606); PT.setY(203);
    path.add_route(new Route(PT));
    PT.setX(551); PT.setY(95);
    path.add_route(new Route(PT));
    PT.setX(439); PT.setY(99);
    path.add_route(new Route(PT));
    PT.setX(396); PT.setY(206);
    path.add_route(new Route(PT));
    PT.setX(247); PT.setY(214);
    path.add_route(new Route(PT));
    PT.setX(191); PT.setY(276);
    path.add_route(new Route(PT));
    PT.setX(271); PT.setY(335);
    path.add_route(new Route(PT));
    PT.setX(463); PT.setY(306);
    path.add_route(new Route(PT));
    PT.setX(521); PT.setY(366);
    path.add_route(new Route(PT));
    PT.setX(479); PT.setY(418);
    path.add_route(new Route(PT));
    PT.setX(373); PT.setY(447);
    path.add_route(new Route(PT));
    PT.setX(353); PT.setY(529);
    path.add_route(new Route(PT));
    PT.setX(358); PT.setY(640);
    path.add_route(new Route(PT));
}
void Model::addTower(const Tower& t){
    towers[t.GetCoord()]=t;
}
void Model::addEnemy(const Enemy& e){
    enemys.push_back(e);
}
void Model::addBullet(const Bullet& b){
    bullets.push_back(b);
}

void Model::attack(int timer) {
    
    if(timer % 10000 != 0) return;
    for(auto& pair : towers) {
        Tower& tower = pair.second;
        Enemy* closestEnemy = nullptr;
        double closestDistance = std::numeric_limits<double>::max();
        for(Enemy& enemy : enemys) {
            if(!enemy.check_status()){
                continue;
            }
            // Calculate distance between tower and enemy
            double dx = tower.GetCoord().first - enemy.Get_current_position().x();
            double dy = tower.GetCoord().second - enemy.Get_current_position().y();
            double distance = std::sqrt(dx * dx + dy * dy);

            // Check if enemy is within range and closer than the closest so far
            if(distance < tower.GetRange() && distance < closestDistance) {
                closestDistance = distance;
                closestEnemy = &enemy;
            }
        }
        // If an enemy is found, attack it
        if(closestEnemy != nullptr) {
            int damage;
            if(tower.GetType() == TURRET){
                if(tower.GetGrade() == PRIMARY){
                    damage = 20;
                }
                else if(tower.GetGrade() == SECONDARY){
                    damage = 31;
                }
                else{
                    damage = 63;
                }
            }
            else if(tower.GetType() == MAGE){
                if(tower.GetGrade() == PRIMARY){
                    damage = 18;
                }
                else if(tower.GetGrade() == SECONDARY){
                    damage = 29;
                }
                else{
                    damage = 51;
                }
            }
            else{
                if(tower.GetGrade() == PRIMARY){
                    damage = 14;
                }
                else if(tower.GetGrade() == SECONDARY){
                    damage = 25;
                }
                else{
                    damage = 37;
                }
            }
            Bullet bullet(tower.GetCoord(), closestEnemy, damage, tower.GetType());
            bullets.push_back(bullet);
        }
    }
}
