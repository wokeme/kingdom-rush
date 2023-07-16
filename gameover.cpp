#include "gameover.h"
//弹出一个gameover的窗口，显示游戏结束，显示输或者赢,同时根据玩家的选择进行下一步操作
gameover::gameover()
{

}
void gameover::gg(bool win){
    QDialog *dialog = new QDialog;
    dialog->setWindowTitle("Game Over");
    dialog->resize(300,200);
//    QPushButton *restart = new QPushButton("Restart",dialog);
    QPushButton *quit = new QPushButton("Quit",dialog);
    if(win){
        QLabel *label = new QLabel("You Win!",dialog);
        label->setGeometry(100,50,100,50);
    }
    else{
        QLabel *label = new QLabel("You Lose!",dialog);
        label->setGeometry(100,50,100,50);
    }
//    restart->setGeometry(50,100,100,50);
    quit->setGeometry(150,100,100,50);
//    QLabel::connect(restart,&QPushButton::clicked,[=](){emit RestartGame();});
    QLabel::connect(quit,&QPushButton::clicked,[=](){emit QuitGame();});
    // QLabel::connect(this,restart,this,SLOT(restart()));
    // QLabel::connect(this,quit,this,SLOT(quit()));
    dialog->exec();
}
