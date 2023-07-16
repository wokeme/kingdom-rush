#ifndef GAMEOVER_H
#define GAMEOVER_H
#include <QObject>
#include <QDialog>
#include <QPushButton>
#include <QLabel>
#include <QWidget>
//弹出一个gameover的窗口，显示游戏结束，显示输或者赢,同时根据玩家的选择进行下一步操作

class gameover:public QWidget{
    Q_OBJECT
public:
    gameover();
    ~gameover(){};
    void show();
public slots:
    void gg(bool win);
signals:
    void RestartGame();
    void QuitGame();
};

#endif // GAMEOVER_H
