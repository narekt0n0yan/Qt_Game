

#include "Health.h"
#include <QFont>

Health::Health(QGraphicsItem * parent) : QGraphicsTextItem(parent) {
    health = 3;

    setPlainText(QString("Health: ") + QString::number(health));
    setDefaultTextColor(Qt::blue);
    setFont(QFont("times",16));


}

void Health::decrease() {
    health--;
    update(0,0,600,800);
    setPlainText(QString("Health: ") + QString::number(health));
}

int Health::getHealth() {
    return health  ;
}
