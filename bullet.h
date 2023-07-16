#ifndef BULLET_H
#define BULLET_H

#include "enemy.h"
#include "common.h"
#include <QPoint>
#include <QPixmap>
typedef std::pair<int,int> position;

class Bullet {
public:
    Bullet(const position startPos, Enemy* target, int damage, TowerType type)
        : m_currentPos(startPos), m_target(target), m_damage(damage), m_type(type){
        qDebug()<<"new construct bullet";
        if(type == TURRET){
            m_speed = 2;
            path = ":/pics/turret_bullet.png";
        }
        if(type == MAGE){
            m_speed = 3;
            path = ":/pics/mage_bullet.png";
        }
        if(type == ARCHER){
            m_speed = 4;
            path = ":/pics/archer_bullet.png";
        }
    }

    void move();

    void hitTarget() {
        qDebug() << "Damage:" << m_damage;
        m_target->set_hp(m_target->get_hp() - m_damage);
    }

    bool hasReachedTarget() const {
        QPixmap pix;
        pix.load(m_target->get_path());
        return (m_currentPos.first == m_target->Get_current_position().x()) && (m_currentPos.second == m_target->Get_current_position().y());
    }

    const position& getPosition() const {
        return m_currentPos;
    }

    QString get_path(){
        return path;
    }

private:
    position m_currentPos;
    Enemy* m_target;
    int m_speed;
    int m_damage;
    TowerType m_type;
    QString path;
};

#endif // BULLET_H
