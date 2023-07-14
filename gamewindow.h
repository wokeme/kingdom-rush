#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QMainWindow>
#include <QPaintEvent>
#include <iostream>
#include "common.h"
#include <QLabel>
#include <QPushButton>
#include "enemy.h"
#include <tower.h>
#include <vector>
#include <QMenu>
#include <QStyleFactory>
#include <QList>
#include <map>
#include <utility>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE
typedef struct MyButton{
    QPushButton* btn;
//    Status status;
}MyButton;
class gamewindow : public QMainWindow{
    Q_OBJECT

public:
    gamewindow(QWidget *parent = nullptr);
    ~gamewindow();
    void SetEnemys(std::vector<Enemy>* e){this->enemys=e;}
    void SetCommon(common* c){this->C=c;}
    void SetTowers(std::map<std::pair<int,int>,Tower>* t){this->towers=t;}
private:
    std::map<std::pair<int,int>,QPushButton*> buttons;
    // QList<QPushButton*> buttons;
    std::vector<Enemy> *enemys;
    std::map<std::pair<int,int>,Tower>* towers;
    common *C;
    QLabel* imageLabel;
    void paintEvent(int,int,QString,QPaintEvent*);
    void mousePressEvent(QMouseEvent *event){};//用于捕捉鼠标，可能需要点击敌人显示信息，暂时没实现
private slots:
    void pop_menu(int,int);//弹出菜单，在按下按钮后触发，是仅限于view层的
    void push_menu(int,int,UpdateTowerType,TowerType);
public slots:
    void ShowTower(int x,int y,QString path);//展示更新后的塔
    void UpdateEnemy(int x,int y){}//暂时未实现
    //    void on_pushButton_clicked(bool checked);
signals:
    void ButtonClicked();//view层自己用
    //其他与用户交互的信号
    void UpdateTower(int x,int y,UpdateTowerType t,TowerType tt=DEFAULTTYPE);//需要更新塔，传给viewmodel层
};

#endif // GAMEWINDOW_H
