#include "gamewindow.h"
#include <QPainter>
#include <QApplication>
#include <QMainWindow>
#include <QPushButton>
#include <QVBoxLayout>
#include <QFile>
#include <QMessageBox>
#include <QTextStream>
#include <QtUiTools/QUiLoader>
#include<QDebug>

//#include <QUiLoader>
gamewindow::gamewindow(QWidget *parent)
{
    C=new common();

    // 加载游戏界面UI
    QFile file(":/gamewindow.ui");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::critical(this, "Error", "Failed to open game UI file.");
        return;
    }

//    QTextStream stream(&file);
//    QString uiContents = stream.readAll();


//    // 创建游戏界面窗口并显示
//    QMainWindow *gameWindow = new QMainWindow;
//    QWidget *gameWidget = new QWidget(gameWindow);
//    gameWindow->setCentralWidget(gameWidget);

    QUiLoader loader;
    QWidget *ui = loader.load(&file,this);
    file.close();
    if (!ui) {
        QMessageBox::critical(this, "Error", "Failed to load game UI from file.");
        return;
    }

    this->setLayout(new QVBoxLayout);
    this->layout()->addWidget(ui);
    this->setFixedSize(400,300);
//    //设置图标
    this->setWindowIcon(QPixmap(":/pics/9.png"));
    this->setWindowTitle("Kingdom rush");
    QPushButton *button = ui->findChild<QPushButton*>("pushButton");
    connect(button,&QPushButton::clicked,this,&on_pushButton_clicked);
    imageLabel = new QLabel(this);
//    connect(button,&QPushButton::clicked,)
}
void gamewindow::paintEvent(QPaintEvent* p=nullptr,bool has=false)
{
//    std::cout<<"!!";
//    QPainter painter(this);
//    QString path(":/pics/7.bmp"); //背景图片
//    C->Set_Path1(path);
//    path = ":/33.jpg"; //防御塔图片
//    C->Set_Path2(path);
//    painter.drawPixmap(0,0,this->width(),this->height(),C->Get_Path1());//绘制背景图
//    if(C->Get_Tower()[0] != 0){ //防御塔是否建立？
//        painter.drawPixmap(260,290,70,50,C->Get_Path2());//绘制防御塔
//    }
    //创建画家，指定绘图设备

    QPainter painter(this);
    QString path(":/pics/7.bmp"); //背景图片
    painter.drawPixmap(0,0,this->width(),this->height(),path);
    std::cout<<"painter\n";
    //创建QPixmap对象
    QPixmap pix;
    //加载图片
    pix.load(":/pics/3.png");
    imageLabel->setStyleSheet("background-color: transparent;");
    // 调整 QLabel 大小以适应图片
    imageLabel->setFixedSize(pix.size());

    // 设置 QLabel 的位置为按钮所在的位置
    imageLabel->move(220,50);

    // 显示图片
    imageLabel->setPixmap(pix);
    if(has)imageLabel->show();
}
gamewindow::~gamewindow()
{
//    delete ui;
}


void gamewindow::on_pushButton_clicked()
{
    emit towerButtonClicked(220,50);
}
void gamewindow::on_build_tower(int x,int y)
{
    this->paintEvent(nullptr,true);
}


//void gamewindow::on_pushButton_clicked(bool checked)
//{

//}


