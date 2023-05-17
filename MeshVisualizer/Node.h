#ifndef NODE_H
#define NODE_H

#include <vector>
#include <string>
#include <algorithm>
#include <cmath>

class Message;

class Node {
private:
    int id; // Unik identifikator for noden
    double x, y; // Posisjonen til noden i et 2D-rom
    double range; // Kommunikasjonsrekkevidden til noden, bestemmer hvor langt den kan sende/motta meldinger
    double speed; // Hastigheten som noden beveger seg med
    double direction; // Retningen som noden beveger seg i, representert i radianer
    std::vector<Node*> neighbors; // Liste over nabo-noder innenfor kommunikasjonsrekkevidde

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
    void sendMessage(Message* message);
    void receiveMessage(Message* message);
};

#endif // NODE_H