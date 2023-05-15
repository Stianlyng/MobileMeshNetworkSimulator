#ifndef MESSAGE_H
#define MESSAGE_H

#include "Node.h"
#include <string>

class Message {
private:
    Node* source; // Source node
    Node* destination; // Destination node
    std::string data; // Data being transmitted

public:
    // Constructor
    Message(Node* source, Node* destination, const std::string& data);

    // Getters
    Node* getSource();
    Node* getDestination();
    std::string getData();
};

#endif // MESSAGE_H