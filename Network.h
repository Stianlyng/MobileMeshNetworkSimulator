#ifndef NETWORK_H
#define NETWORK_H

#include <vector>
#include "Node.h"
#include "Message.h"

class Network {
private:

    std::vector<Node*> nodes; 
    std::vector<Message*> messages; 

    Network(); // fjern
    static Network* instance; // fjern

public:
    static Network* getInstance(); // fjern
    
    void addNode(Node* node);
    void removeNode(Node* node);

    void update();

    void addMessage(Message* message);

    double distance(Node* node1, Node* node2);

    double computeThroughput();
    double computeLatency();
    double computePacketLoss();
};

#endif 