
#include "Bullet.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include <Enemy.h>
#include <Game.h>

extern Game * game;

Bullet::Bullet(QObject *parent)
    : QObject(parent), QGraphicsRectItem()
{
    //drew the rect
    setRect(0,0,10,50);

    //connect
    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    timer->start(50);
}

 void Bullet::move(){

     QList<QGraphicsItem*> colliding_Items = collidingItems();
     for ( int i = 0 , n = colliding_Items.size(); i < n; ++i){
         if (typeid(*colliding_Items[i]) == typeid(Enemy)){
             game->score->increase();

             scene()->removeItem(colliding_Items[i]);
             scene()->removeItem(this);

             delete colliding_Items[i];
             delete this;
             return;
         }
     }


    setPos(x(),y()-10);
     if (pos().y() + rect().height()<0){
        scene()->removeItem(this);
        delete this;

     }
}
