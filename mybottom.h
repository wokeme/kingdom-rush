#ifndef MYBOTTOM_H
#define MYBOTTOM_H

#include<QPushButton>
class Mybottom : public QPushButton{
    Q_OBJECT
public:
    explicit Mybottom(QWidget *parent = nullptr){setParent(parent);}
    Mybottom(QString normalImg,QString pressImg="");
private:
    QString normalImgPath;
    QString pressedImgPath;
signals:

};

#endif // MYBOTTOM_H
