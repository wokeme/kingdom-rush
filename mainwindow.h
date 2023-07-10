#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include"gamewindow.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr,gamewindow* game=nullptr);
    void paintEvent(QPaintEvent*);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    gamewindow* game;
};
#endif // MAINWINDOW_H
