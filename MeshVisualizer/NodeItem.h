#ifndef NODEITEM_H
#define NODEITEM_H

#include <QGraphicsItem>
#include <QPainter>
#include "Node.h"
#include <QMessageBox>

class NodeItem : public QGraphicsItem
{
public:
    NodeItem(Node* node);

    QRectF boundingRect() const override;

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    
    QPainterPath shape() const override;

private:
    Node* node;
};

#endif // NODEITEM_H