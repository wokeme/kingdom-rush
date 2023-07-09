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
    void paintEvent(QPaintEvent*);
private slots:
    void on_pushButton_clicked();
//    void on_pushButton_clicked(bool checked);

};

#endif // GAMEWINDOW_H
