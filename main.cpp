#include "mainwindow.h"

#include <QApplication>
#include "gamewindow.h"
#include "viewmodel.h"
#include "model.h"

int main(int argc, char *argv[]){
    QApplication a(argc, argv);
    Model* m=new Model();
    gamewindow* game=new gamewindow();
    viewmodel* vm=new viewmodel(m);
    game->SetEnemys(m->GetEnemys());
    game->SetTowers(m->GetTowers());
    game->SetPaths(m->GetPath());
    QLabel::connect(game,&gamewindow::UpdateTower,vm,&viewmodel::UpdateTower);
    QLabel::connect(vm,&viewmodel::ShowTower,game,&gamewindow::ShowTower);
    QLabel::connect(game,&gamewindow::UpdateEnemy,vm,&viewmodel::UpdateEnemy);
    QLabel::connect(game,&gamewindow::MoveEnemy,vm,&viewmodel::MoveEnemy);
    MainWindow *w=new MainWindow(nullptr,game);
    w->show();
    return a.exec();
}
//注释
//
