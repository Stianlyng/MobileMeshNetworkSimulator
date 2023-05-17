#ifndef MESSAGE_H
#define MESSAGE_H

#include "Node.h"
#include <string>

class Message {
private:
    Node* source; 
    Node* destination; 
    std::string data; 

public:
    Message(Node* source, Node* destination, const std::string& data);

    Node* getSource();
    Node* getDestination();
    std::string getData();
};

#endif 
