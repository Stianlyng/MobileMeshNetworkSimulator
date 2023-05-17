#ifndef NETWORK_H
#define NETWORK_H

#include <vector>
#include "Node.h"
#include "Message.h"

class Network {
private:

    std::vector<Node*> nodes; // Liste over noder i nettverket. Hver node representerer en enhet i nettverket.
    std::vector<Message*> messages; // Kø av meldinger som skal overføres. Dette representerer dataene som skal sendes over nettverket.
    Network(); // fjern
    static Network* instance; // fjern

public:
    static Network* getInstance(); // fjern
    
    void addNode(Node* node);
    void removeNode(Node* node);
    std::vector<Node*> getNodes() const; // En liste over alle noder i nettverket. Brukes av GUI for å visualisere nettverket.
    void update();

    void addMessage(Message* message);

    double distance(Node* node1, Node* node2);

    double computeThroughput();
    double computeLatency();
    double computePacketLoss();
};

#endif 