#include "NodeItem.h"
#include <QDebug>
#include <QGraphicsSceneMouseEvent>

NodeItem::NodeItem(Node* node, MainWindow* mainWindow)  // update the constructor
    : node(node), mainWindow(mainWindow) {
    this->setFlag(QGraphicsItem::ItemIsSelectable, true);
}

QRectF NodeItem::boundingRect() const {
    // The bounding box of the node has its center at the node's coordinates
    return QRectF(node->getX() - 10, node->getY() - 10, 20, 20);
}

void NodeItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    // Draw the node within the bounding rectangle
    painter->setBrush(QBrush(Qt::blue));
    painter->drawEllipse(boundingRect());
}

QPainterPath NodeItem::shape() const {
    QPainterPath path;
    path.addEllipse(boundingRect());
    return path;
}

void NodeItem::mousePressEvent(QGraphicsSceneMouseEvent *event) {
    // Handle mouse press event
    qDebug() << "Node " << node->getId() << " pressed.";
    // Display the node details here
    mainWindow->setInfoLabelText(QString("Node %1: x=%2, y=%3, range=%4, speed=%5, direction=%6")
        .arg(node->getId())
        .arg(node->getX())
        .arg(node->getY())
        .arg(node->getRange())
        .arg(node->getSpeed())
        .arg(node->getDirection()));
}