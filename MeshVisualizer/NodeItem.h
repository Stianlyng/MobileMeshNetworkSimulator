#ifndef NODEITEM_H
#define NODEITEM_H

#include <QGraphicsItem>
#include <QPainter>
#include "Node.h"
#include "mainwindow.h"
#include <QMessageBox>

class MainWindow;
class NodeItem : public QGraphicsItem
{
public:
    NodeItem(Node* node, MainWindow* mainWindow);  

    QRectF boundingRect() const override;

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    
    QPainterPath shape() const override;

private:
    Node* node;
    MainWindow* mainWindow;  
};

#endif // NODEITEM_H