
#include "Score.h"
#include <QFont>

Score::Score(QGraphicsItem * parent)
    : QGraphicsTextItem(parent)
    , score(0)
{
    setDefaultTextColor(Qt::blue);
    setFont(QFont("times",16));
    setPlainText(QString("Score: 0"));
}

void Score::increase() {
    score++;
    setPlainText(QString("Score: ") + QString::number(score));
}

int Score::getScore() {
    return score;
}
