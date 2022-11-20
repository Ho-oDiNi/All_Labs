#include "graphicscene1.h"
#include <QtGlobal>
#include <cstdlib>
#include <time.h>

using namespace std;

graphicscene1::graphicscene1(QObject* parent): QGraphicsScene(parent)
{
    srand(time(NULL));
    Walls();
    Monkey = addPixmap(QPixmap("D:/QtReps/lab7/Monkey_King_Guide_Header.png"));
    QTransform tr = Monkey->transform();
    tr.translate(25.5, 25.5);
    Monkey->setTransform(tr);
    Monkey->setData(0, "Monkey");

    Tree=addPixmap(QPixmap("D:/QtReps/lab7/tree.png"));
    Tree->setFlags(QGraphicsItem::ItemIsMovable);
    Tree->setPos(90,90);
    Tree->setData(0, "Tree");

    setBackgroundBrush(QBrush(QColor(255,255,255), QPixmap("D:/QtReps/lab7/map.png")));

    srand(QTime(0, 0, 0).secsTo(QTime::currentTime()));
    randMove();
    QTimer* timer = new QTimer(this);

    connect(timer, SIGNAL(timeout()), this, SLOT(monkeyMove()));
    timer->start(100);
}

void graphicscene1::Walls()
{
    float walls[4][4] = {{19, 0, 1, 480},
                         {20, 0, 520, 1},
                         {539, 2, 1, 480},
                         {20, 480, 520, 1}};


    QBrush br(Qt::green, Qt::CrossPattern);
    QPen pen(Qt::black);
    for (int i = 0; i < 4; i++) {
    QGraphicsItem* item = addRect(QRectF(walls[i][0],
        walls[i][1],
        walls[i][2],
        walls[i][3]), pen, br);
        item->setData(0, "Wall");
    }
}

QGraphicsItem* graphicscene1::itemColidesWith(QGraphicsItem *item)
{

    QList<QGraphicsItem*> collisions = collidingItems(item);

    foreach (QGraphicsItem* it , collisions)
    { if (it == item) continue;
        return it;
    }

    return NULL;
}

void graphicscene1::monkeyMove()
{

    QPointF np; np.setX(0);
    np.setY(0);


    switch (move)
    {
    case 1: np.setX(-10);
        break;
    case 2: np.setX(+10);
        break;
    case 3: np.setY(-10);
        break;
    case 4: np.setY(+10);
        break;
    case 5: np.setX(-5);
            np.setY(-5);
        break;
    }

    QTransform tran = Monkey->transform();
    tran = Monkey->transform();
    tran.translate(np.x(), np.y());
    Monkey->setTransform(tran);
    QGraphicsItem* obstacle = itemColidesWith(Monkey);
    tran = Monkey->transform();

    if (obstacle)
    {
        tran.translate(-np.x(), -np.y());
        Monkey->setTransform(tran);
        randMove();
    }

}

void graphicscene1::randMove()
{
    move = (rand() % 5) + 1;
}
