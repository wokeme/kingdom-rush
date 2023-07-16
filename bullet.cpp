#include "bullet.h"

void Bullet::move() {
    QPixmap pix;
    pix.load(m_target->get_path());
    QPoint currentPos(m_currentPos.first, m_currentPos.second);
    QPoint targetPos = m_target->Get_current_position();
    QPoint direction = (targetPos - currentPos);
    double length = std::sqrt(QPoint::dotProduct(direction, direction));
    QPoint step = direction;
    if(length < m_speed) {
        m_currentPos.first = targetPos.x();
        m_currentPos.second = targetPos.y();
        return;
    }
    step *= (m_speed / length);
    currentPos += step;
    m_currentPos.first = currentPos.x();
    m_currentPos.second = currentPos.y();
}
