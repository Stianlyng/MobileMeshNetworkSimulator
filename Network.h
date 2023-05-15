#ifndef NETWORK_H
#define NETWORK_H

#include <vector>
#include "Node.h"
#include "Message.h"

class Network {
private:
    std::vector<Node*> nodes; 
    std::vector<Message*> messages; 

public:
    void addNode(Node* node);
    void removeNode(Node* node);

    void update();

    double computeThroughput();
    double computeLatency();
    double computePacketLoss();
};

#endif 