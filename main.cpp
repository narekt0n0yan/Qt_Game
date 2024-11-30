#include <QApplication>
#include <QGraphicsScene>
#include <MyRect.h>
#include <QGraphicsView>
#include <QTimer>



int main(int argc, char *argv[])
{

    QApplication a(argc, argv);

    // create a scene
    QGraphicsScene *scene = new QGraphicsScene();

    // create an item to put into the scene
    MyRect *player = new MyRect();
    player->setRect(0,0 , 100, 100);
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();



    // add item to the scene
    scene->addItem(player);

    // add a view
   QGraphicsView *view = new QGraphicsView(scene);
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->show();
    view->setFixedSize(800,600);
    scene->setSceneRect(0,0,800,600);

    player->setPos(view->width()/2,view->height()-player->rect().height());

    QTimer * timer = new QTimer();

    timer->start(2000);
    QObject::connect(timer,SIGNAL(timeout()), player, SLOT(spawn()));
    return a.exec();
}
