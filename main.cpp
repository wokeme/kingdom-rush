#include "mainwindow.h"

#include <QApplication>
#include "gamewindow.h"
#include "viewmodel.h"
#include "model.h"
#include "gameover.h"

int main(int argc, char *argv[]){
    QApplication a(argc, argv);
    Model* m=new Model();
    gamewindow* game=new gamewindow();
    viewmodel* vm=new viewmodel(m);
    gameover* over=new gameover();
    game->SetEnemys(m->GetEnemys());
    game->SetTowers(m->GetTowers());
    game->SetPaths(m->GetPath());
    game->SetMoney(vm->GetMoney());
    game->SetHeart(vm->GetHeart());
    game->SetBullet(m->GetBullet());
    QLabel::connect(game,&gamewindow::UpdateTower,vm,&viewmodel::UpdateTower);
    QLabel::connect(vm,&viewmodel::ShowTower,game,&gamewindow::ShowTower);
    QLabel::connect(game,&gamewindow::UpdateEnemy,vm,&viewmodel::UpdateEnemy);
    QLabel::connect(game,&gamewindow::MoveEnemy,vm,&viewmodel::MoveEnemy);
    QLabel::connect(game,&gamewindow::MoveBullet,vm,&viewmodel::MoveBullet);
    MainWindow *w=new MainWindow(nullptr,game);
    w->show();
    QLabel::connect(vm,&viewmodel::gg,over,&gameover::gg);
    QLabel::connect(over,&gameover::QuitGame,[=](){
        game->close();
    });
    return a.exec();
}
//注释
//
