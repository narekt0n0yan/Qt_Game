#include "Game.h"
#include <QTimer>
#include <QGraphicsItem>
#include <QFont>
#include "Enemy.h"
#include <QMediaPlayer>




Game::Game(QWidget *parent):
    QGraphicsView(parent)
{
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,800,600);

    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(800,600);

    player = new Player();
    player->setRect(0,0,100,100);
    player->setPos(400,500);

    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();
    scene->addItem(player);

    score = new Score();
    scene->addItem(score);
    health = new Health();
    health->setPos(health->x(),health->y() + 25);
    scene->addItem(health);

    QTimer * timer = new QTimer();
    QObject::connect(timer,SIGNAL(timeout()),player,SLOT(spawn()));
    timer->start(2000);

    // QMediaPlayer * music = new QMediaPlayer();
    // music->setMedia(QUrl("qrc:/ sounds/Михаил Круг - Девочка-Пай.mp3"));
    // music->play();

}
