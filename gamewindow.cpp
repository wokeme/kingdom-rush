#include "gamewindow.h"
#include <QPainter>
#include <QApplication>
#include <QMainWindow>
#include <QVBoxLayout>
#include <QFile>
#include <QMessageBox>
#include <QTextStream>
#include <QtUiTools/QUiLoader>
#include <QDebug>

//#include <QUiLoader>

gamewindow::gamewindow(QWidget *parent){
    QApplication::setStyle(QStyleFactory::create("Fusion"));  // 启用样式表功能
    C=new common();
    setMouseTracking(true);

    // 加载游戏界面UI
    QFile file(":/gamewindow.ui");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::critical(this, "Error", "Failed to open game UI file.");
        return;
    }
    QUiLoader loader;
    QWidget *ui = loader.load(&file,this);
    file.close();
    if (!ui) {
        QMessageBox::critical(this, "Error", "Failed to load game UI from file.");
        return;
    }

    this->setLayout(new QVBoxLayout);
    this->layout()->addWidget(ui);
    this->setFixedSize(800,600);
//    //设置图标
    this->setWindowIcon(QPixmap(":/pics/9.png"));
    this->setWindowTitle("Kingdom rush");
//设置开始按钮
    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(tick_1s()));
    QPushButton* start=ui->findChild<QPushButton*>("start");
    connect(start,&QPushButton::clicked,[=]{
        timer->start(100);
    });
    QList<QObject*> children = ui->children();
        foreach(QObject* obj, children){
            // 判断对象是否为QPushButton类型
            QPushButton* button = qobject_cast<QPushButton*>(obj);
            if (button&&button->objectName()!="start"){
                // 对找到的按钮进行操作
                QPoint globalPos = button->mapToGlobal(QPoint(0, 0));
                int x=globalPos.x();
                int y=globalPos.y();
                
                int sizey=button->width();
                int sizex=button->height();
                buttons[std::make_pair(x+sizex/2,y+sizey/2)]=button;
                connect(button,&QPushButton::clicked,[=]{
                    emit pop_menu(x+sizex/2,y+sizey/2);
                });
                QPixmap pix;
                pix.load(":/pics/locate.png");
                QIcon temp(pix);
                button->setIconSize(pix.size());
                button->setGeometry(x-pix.height()/2,y-pix.width()/2,pix.width(),pix.height());
                button->setStyleSheet("QPushButton {"
                                          "    border-image: url(:/pics/locate.png);"
                                           "    background-color: transparent;"
                                          "    padding: 10px;"   // 根据需要调整间距
                                          "}");
            }
        }
    //enemy_labels的初始化
}
void gamewindow::paintEvent(int x,int y,QString tower_path,QPaintEvent* p=nullptr,bool push=false){
    if(push){
        QPainter painter(this);
        QString path(":/pics/7.bmp"); //背景图片
        painter.drawPixmap(0,0,this->width(),this->height(),path);
        //创建QPixmap对象
        QPixmap pix;
        pix.load(tower_path);
        //创建QIcon对象
        QIcon temp(pix);
        //设置按钮图标
        buttons[std::make_pair(x,y)]->setIcon(temp);
        //设置按钮图标大小
        buttons[std::make_pair(x,y)]->setIconSize(pix.size());
        //设置按钮大小
        buttons[std::make_pair(x,y)]->setGeometry(x-pix.height()/2,y-pix.width()/2,pix.width(),pix.height());
        //设置按钮背景透明
        buttons[std::make_pair(x,y)]->setStyleSheet("QPushButton {"
                                            "    border-image: url(tower_path);"
                                            "    background-color: transparent;"
                                            "    padding: 10px;"   // 根据需要调整间距
                                            "}");
    }
    for(auto it=(*enemys).begin();it!=(*enemys).end();it++){
        if(it->check_status()){
            QPixmap pix2;
            pix2.load(it->get_path());  
            if(enemy_labels.find(&(*it))==enemy_labels.end()){
                enemy_labels[&(*it)]=new QLabel(this);
            }
            QLabel *temp=enemy_labels[&(*it)];
            temp->setStyleSheet("background-color: transparent;");
            temp->setFixedSize(pix2.size());
            temp->move(it->Get_current_position().x(),it->Get_current_position().y());
            temp->setPixmap(pix2);
            temp->show();
        }
    }
}
gamewindow::~gamewindow(){
//    delete ui;
}
void gamewindow::ShowTower(int x,int y,QString path){
    this->paintEvent(x,y,path,nullptr,true);
}
void gamewindow::pop_menu(int x,int y){
    UpdateTowerType utType;
    TowerGrade tg;
    if((*towers).find(std::make_pair(x,y))==(*towers).end()){
        utType=UpdateTowerType::BUILD;
    }
    else{
        tg=(*towers)[std::make_pair(x,y)].GetGrade();
        if(tg==TowerGrade::TERTIARY){
            utType=UpdateTowerType::REMOVE;
        }
        else{
            utType=UpdateTowerType::UPGRADATION;
        }
    }
    if(utType==UpdateTowerType::UPGRADATION){
        QPushButton *button1 = new QPushButton(this);
        QPixmap buttonImage1(":/pics/upgrade.png");
        QIcon buttonIcon1(buttonImage1);
        button1->setIcon(buttonIcon1);
        button1->setIconSize(buttonImage1.size());
        button1->setGeometry(x-buttonImage1.width()/2-50, y-buttonImage1.height()/2-30,buttonImage1.width(),buttonImage1.height());
        button1->setStyleSheet("QPushButton {"
                              "    border-image: url(:/pics/upgrade.png);"
                              "    background-color: transparent;"
                              "    padding: 10px;"   // 根据需要调整间距
                              "}");
        connect(button1,&QPushButton::clicked,[=]{
            emit push_menu(x,y,UPGRADATION,DEFAULTTYPE);
        });
        QPushButton *button2 = new QPushButton(this);
        QPixmap buttonImage2(":/pics/sell.png");
        QIcon buttonIcon2(buttonImage2);
        button2->setIcon(buttonIcon2);
        button2->setIconSize(buttonImage2.size());
        button2->setGeometry(x-buttonImage2.width()/2+50, y-buttonImage2.height()/2-30,buttonImage2.width(),buttonImage2.height());
        button2->setStyleSheet("QPushButton {"
                              "    border-image: url(:/pics/sell.png);"
                              "    background-color: transparent;"
                              "    padding: 10px;"   // 根据需要调整间距
                              "}");
        connect(button2,&QPushButton::clicked,[=]{
            emit push_menu(x,y,REMOVE,DEFAULTTYPE);
        });
        auto buttonClicked = [this, button1, button2]() {
            delete button1;
            delete button2;
        };
        // 连接其他按钮的点击信号到槽函数
        connect(button1, &QPushButton::clicked, buttonClicked);
        connect(button2, &QPushButton::clicked, buttonClicked);
        button1->show();
        button2->show();
        return;
    }
    else if(utType==UpdateTowerType::REMOVE){
        QPushButton *button1 = new QPushButton(this);
        QPixmap buttonImage1(":/pics/sell.png");
        QIcon buttonIcon1(buttonImage1);
        button1->setIcon(buttonIcon1);
        button1->setIconSize(buttonImage1.size());
        button1->setGeometry(x-buttonImage1.width()/2-50, y-buttonImage1.height()/2-30,buttonImage1.width(),buttonImage1.height());
        button1->setStyleSheet("QPushButton {"
                              "    border-image: url(:/pics/sell.png);"
                              "    background-color: transparent;"
                              "    padding: 10px;"   // 根据需要调整间距
                              "}");
        connect(button1,&QPushButton::clicked,[=]{
            emit push_menu(x,y,REMOVE,DEFAULTTYPE);
        });
        auto buttonClicked = [this, button1]() {
            delete button1;
        };
        // 连接其他按钮的点击信号到槽函数
        connect(button1, &QPushButton::clicked, buttonClicked);
        button1->show();
        return;
    }
    // Tower tower=(*towers)[std::make_pair(x,y)];
    QPushButton *button1 = new QPushButton(this);
    QPixmap buttonImage1(":/pics/1.png");
    QIcon buttonIcon1(buttonImage1);
    button1->setIcon(buttonIcon1);
    button1->setIconSize(buttonImage1.size());
    button1->setGeometry(x-buttonImage1.width()/2-50, y-buttonImage1.height()/2-30,buttonImage1.width(),buttonImage1.height());
    button1->setStyleSheet("QPushButton {"
                          "    border-image: url(:/pics/1.png);"
                          "    background-color: transparent;"
                          "    padding: 10px;"   // 根据需要调整间距
                          "}");

    QPushButton *button2 = new QPushButton(this);

    QPixmap buttonImage2(":/pics/2.png");
    QIcon buttonIcon2(buttonImage2);
    button2->setIcon(buttonIcon2);
    button2->setIconSize(buttonImage2.size());
    button2->setGeometry(x-buttonImage1.width()/2, y-buttonImage1.height()/2-60,buttonImage2.width(),buttonImage2.height());
    button2->setStyleSheet("QPushButton {"
                           "    border-image: url(:/pics/2.png);"
                           "    background-color: transparent;"
                           "    padding: 10px;"   // 根据需要调整间距
                           "}");
    QPushButton *button3 = new QPushButton(this);

    QPixmap buttonImage3(":/pics/11.png");
    QIcon buttonIcon3(buttonImage3);
    button3->setIcon(buttonIcon3);
    button3->setIconSize(buttonImage3.size());
    button3->setGeometry(x-buttonImage1.width()/2+50, y-buttonImage1.height()/2-30,buttonImage3.width(),buttonImage3.height());
    button3->setStyleSheet("QPushButton {"
                           "    border-image: url(:/pics/11.png);"
                           "    background-color: transparent;"
                           "    padding: 10px;"   // 根据需要调整间距
                           "}");
    button1->show();
    button2->show();
    button3->show();
    connect(button1,&QPushButton::clicked,[=]{
        emit push_menu(x,y,BUILD,TURRET);
    });
    connect(button2,&QPushButton::clicked,[=]{
        emit push_menu(x,y,BUILD,MAGE);
    });
    connect(button3,&QPushButton::clicked,[=]{
        emit push_menu(x,y,BUILD,ARCHER);
    });
    auto buttonClicked = [this, button1, button2, button3]() {
        delete button1;
        delete button2;
        delete button3;
    };
    // 连接其他按钮的点击信号到槽函数
    connect(button1, &QPushButton::clicked, buttonClicked);
    connect(button2, &QPushButton::clicked, buttonClicked);
    connect(button3, &QPushButton::clicked, buttonClicked);
}
void gamewindow::push_menu(int x,int y,UpdateTowerType type,TowerType towerType){
    emit UpdateTower(x,y,type,towerType);
}
void gamewindow::tick_1s(){
    if(!this->enemys->empty()){
        emit MoveEnemy();
        this->paintEvent(0,0,"",nullptr);
    }
}

