
#include <Player.h>
#include <QGraphicsScene>
#include <QKeyEvent>
#include <Bullet.h>
#include <Enemy.h>
#include <QMediaPlayer>
#include <QDebug>
#include <iostream>


Player::Player(QGraphicsItem *parent)
    : QGraphicsRectItem(parent){
    bulletsound = new QMediaPlayer();
    bulletsound->setMedia(QUrl( "qrc:/ sounds/Михаил Круг - Владимирский Централ.mp3"));
}

void Player::keyPressEvent(QKeyEvent *event){
    if( event->key() == Qt::Key_Left){
        if (pos().x() > 0){
            setPos(x()-10,y());
        }
    }
    else if (event->key() == Qt::Key_Right){
        if (pos().x()+100 < 800){
            setPos(x()+10,y());
        }
    }
    else if (event->key() == Qt::Key_Space){
        Bullet * bullet = new Bullet();
        bullet->setPos(x(),y());
        scene()->addItem(bullet);

        bulletsound->stop();
        bulletsound->play();
        std::cout << "aaaaaaa" <<std::endl;
    }
}

void Player::spawn(){
    Enemy * enemy = new Enemy();
    scene()->addItem(enemy);
}
