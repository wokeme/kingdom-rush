#include "model.h"

Model::Model(){

}
void Model::addTower(const Tower& t){
    towers[t.GetCoord()]=t;
}
