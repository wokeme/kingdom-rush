#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPainter>
#include "mybottom.h"
#include <QDebug>
MainWindow::MainWindow(QWidget *parent,gamewindow* game)
    : QMainWindow(parent),game(game)
    , ui(new Ui::MainWindow)
{
//    std::cout<<"!!\n";
    ui->setupUi(this);
    this->setFixedSize(800,600);
    this->setWindowIcon(QPixmap(":/pics/9.png"));
    this->setWindowTitle("Kingdom rush");
    QPushButton * startBtn = new QPushButton(this);

    QPixmap buttonImage3(":/pics/start.png");
    QIcon buttonIcon3(buttonImage3);
    startBtn->setIcon(buttonIcon3);
    startBtn->setIconSize(buttonImage3.size());
    startBtn->setGeometry(this->width()*0.5-startBtn->width()*0.5,this->height()*0.7,buttonImage3.width(),buttonImage3.height());
    qDebug()<<this->width()*0.5-startBtn->width()*0.5<<this->height()*0.7<<buttonImage3.width()<<buttonImage3.height();
    startBtn->setStyleSheet("QPushButton {"
                           "    border-image: url(:/pics/start.png);"
                           "    background-color: transparent;"
                           "    padding: 10px;"   // 根据需要调整间距
                           "}");
//    Mybottom * startBtn = new Mybottom(":/pics/start.png");
//    startBtn->setParent(this);
//    startBtn->move(this->width()*0.5-startBtn->width()*0.5,this->height()*0.7);
//    gamewindow* game = new gamewindow();
    connect(startBtn,&QPushButton::clicked,[=](){
        this->hide();
        game->show();
    });

}
void MainWindow::paintEvent(QPaintEvent*)
{
    //创建画家，指定绘图设备
    QPainter painter(this);
    //创建QPixmap对象
    QPixmap pix;
    //加载图片
    pix.load(":/pics/8.bmp");
    //绘制背景图
    painter.drawPixmap(0,0,this->width(),this->height(),pix);
    //加载标题
    pix.load(":/pics/9.png");
    //缩放图片
    pix = pix.scaled(pix.width()*0.5,pix.height()*0.5);
    //绘制标题
    painter.drawPixmap( this->height()/2,this->width()/6,pix.width(),pix.height(),pix);

}
MainWindow::~MainWindow()
{
    delete ui;
}

