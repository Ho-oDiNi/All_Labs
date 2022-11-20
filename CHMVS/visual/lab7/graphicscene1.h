#ifndef GRAPHICSCENE_H
#define GRAPHICSCENE_H

#include <QGraphicsScene>
#include <QGraphicsItem>

#include <QTimer>
#include <QTime>


class graphicscene1 : public QGraphicsScene
{
    Q_OBJECT
public:
    graphicscene1(QObject* parent = 0);

private:
    QGraphicsPixmapItem* Monkey;
    QGraphicsPixmapItem* Tree;
    QGraphicsLineItem* Figure;
    int move;
    void randMove();
    void Walls();

    QGraphicsItem* itemColidesWith(QGraphicsItem* item);
public slots:
    void monkeyMove();
};

#endif // GRAPHICSCENE_H
