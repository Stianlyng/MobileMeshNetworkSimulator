#ifndef ROUTE_H
#define ROUTE_H

#include "Node.h" 

class Route {
private:
    int destinationId; 
    Node* nextHop; 
    int hopCount; 

public:
    Route(int destinationId, Node* nextHop, int hopCount);

    int getDestinationId();
    Node* getNextHop();
    int getHopCount();

    void setNextHop(Node* newNextHop);
    void setHopCount(int newHopCount);
};

#endif /* ROUTE_H */