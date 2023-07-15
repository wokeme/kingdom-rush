#include "model.h"

Model::Model(){
    QPoint PT(808,93*2);
    path.add_route(new Route(PT));
    PT.setX(292*2); PT.setY(91*2);
    path.add_route(new Route(PT));
    PT.setX(283*2); PT.setY(32*2);
    path.add_route(new Route(PT));
    PT.setX(209*2); PT.setY(42*2);
    path.add_route(new Route(PT));
    PT.setX(192*2); PT.setY(91*2);
    path.add_route(new Route(PT));
    PT.setX(92*2); PT.setY(107*2);
    path.add_route(new Route(PT));
    PT.setX(91*2); PT.setY(151*2);
    path.add_route(new Route(PT));
    PT.setX(248*2); PT.setY(151*2);
    path.add_route(new Route(PT));
    PT.setX(248*2); PT.setY(195*2);
    path.add_route(new Route(PT));
    PT.setX(173*2); PT.setY(215*2);
    path.add_route(new Route(PT));
    PT.setX(170*2); PT.setY(275*2);
    path.add_route(new Route(PT));
}
void Model::addTower(const Tower& t){
    towers[t.GetCoord()]=t;
}
void Model::addEnemy(const Enemy& e){
    enemys.push_back(e);
}
