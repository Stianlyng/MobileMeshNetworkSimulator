#include "Node.h"
#include "Message.h"
#include <string>

class Message {
private:
    Node* source; // Source node
    Node* destination; // Destination node
    std::string data; // Data being transmitted

public:
    // Constructor
    Message(Node* source, Node* destination, const std::string& data)
        : source(source), destination(destination), data(data) {}

    // Getters
    Node* getSource() { return source; }
    Node* getDestination() { return destination; }
    std::string getData() { return data; }
};