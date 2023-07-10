#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QMainWindow>
#include <QPaintEvent>
#include <iostream>
#include "common.h"
#include<QLabel>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class gamewindow : public QMainWindow
{
    Q_OBJECT

public:
    gamewindow(QWidget *parent = nullptr);
    ~gamewindow();

private:
    common *C;
    QLabel* imageLabel;

protected:
    void paintEvent(QPaintEvent*,bool);
public slots:
    void on_pushButton_clicked();
    void on_build_tower(int x,int y);
    //    void on_pushButton_clicked(bool checked);
signals:
    void towerButtonClicked(int,int);
    //其他与用户交互的信号

};

#endif // GAMEWINDOW_H
