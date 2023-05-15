
#ifndef NODE_H
#define NODE_H

#include <vector>
#include <string>
#include <algorithm>
#include <cmath>

// todo; class Message;

class Node {
private:
    int id;
    double x, y;
    double range;
    double speed;
    double direction;
    std::vector<Node*> neighbors;

public:
    Node(int id, double x, double y, double range, double speed, double direction);

    int getId();
    double getX();
    double getY();
    double getRange();
    double getSpeed();
    double getDirection();
    std::vector<Node*> getNeighbors();

    void setX(double newX);
    void setY(double newY);
    void setRange(double newRange);
    void setSpeed(double newSpeed);
    void setDirection(double newDirection);

    void updatePosition();
    void addNeighbor(Node* neighbor);
    void removeNeighbor(Node* neighbor);
    // todo; void sendMessage(Message* message);
    // todo; void receiveMessage(Message* message);
};

#endif // NODE_H