#ifndef ENEMY_H
#define ENEMY_H

#include <QGraphicsRectItem>
#include <QObject>

class Enemy: public QObject, public QGraphicsRectItem{
    Q_OBJECT
public:
    Enemy(QObject* parent = nullptr);
public slots:
    void move();
};



#endif // ENEMY_H
