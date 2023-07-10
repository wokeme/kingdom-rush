#include "mainwindow.h"

#include <QApplication>
#include "gamewindow.h"
#include "viewmodel.h"

int main(int argc, char *argv[])
{
    
    QApplication a(argc, argv);
    gamewindow* game=new gamewindow();
    viewmodel* vm=new viewmodel();
    QLabel::connect(game,&gamewindow::towerButtonClicked,vm,&viewmodel::on_click_tower);
    QLabel::connect(vm,&viewmodel::build_tower,game,&gamewindow::on_build_tower);
    MainWindow *w=new MainWindow(nullptr,game);
    w->show();
    return a.exec();
}
//注释
//
